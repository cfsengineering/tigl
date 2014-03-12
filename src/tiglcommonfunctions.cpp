/*
* Copyright (C) 2007-2013 German Aerospace Center (DLR/SC)
*
* Created: 2013-06-01 Martin Siggel <Martin.Siggel@dlr.de>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

/**
 * @brief This file implements some commonly used functions/algorithms on opencascade
 * data structures.
 */

#include "tiglcommonfunctions.h"

#include "CTiglError.h"

#include "Geom_Curve.hxx"
#include "BRep_Tool.hxx"
#include "BRepTools_WireExplorer.hxx"
#include "TopExp_Explorer.hxx"
#include "TopoDS.hxx"
#include "GeomAdaptor_Curve.hxx"
#include "BRepAdaptor_CompCurve.hxx"
#include "BRepAdaptor_Curve.hxx"
#include "GCPnts_AbscissaPoint.hxx"
#include "BRepBuilderAPI_MakeWire.hxx"
#include "BRepBuilderAPI_MakeEdge.hxx"
#include "GeomAPI_ProjectPointOnCurve.hxx"

// calculates a wire's circumference
Standard_Real GetWireLength(const TopoDS_Wire& wire)
{
    BRepAdaptor_CompCurve aCompoundCurve(wire, Standard_True);
    return GCPnts_AbscissaPoint::Length( aCompoundCurve );
}

unsigned int GetNumberOfEdges(const TopoDS_Shape& shape)
{
    TopExp_Explorer edgeExpl(shape, TopAbs_EDGE);
    unsigned int iEdges = 0;
    for (; edgeExpl.More(); edgeExpl.Next()) {
        iEdges++;
    }

    return iEdges;
}

// Gets a point on the wire line in dependence of a parameter alpha with
// 0.0 <= alpha <= 1.0. For alpha = 0.0 this is the line starting point,
// for alpha = 1.0 the last point on the intersection line.
gp_Pnt WireGetPoint(const TopoDS_Wire& wire, double alpha)
{
    gp_Pnt point;
    gp_Vec tangent;
    WireGetPointTangent(wire, alpha, point, tangent);
    return point;
}

void WireGetPointTangent(const TopoDS_Wire& wire, double alpha, gp_Pnt& point, gp_Vec& tangent)
{
    if (alpha < 0.0 || alpha > 1.0) {
        throw tigl::CTiglError("Error: Parameter alpha not in the range 0.0 <= alpha <= 1.0 in WireGetPoint", TIGL_ERROR);
    }

    //TopoDS_Wire wire;
    double length = GetWireLength(wire) * alpha;

    // Get the first edge of the wire
    BRepTools_WireExplorer wireExplorer( wire );
    if (!wireExplorer.More()) {
        throw tigl::CTiglError("Error: Not enough edges found in CTiglIntersectionCalculation::GetPoint", TIGL_ERROR);
    }

    Standard_Real firstParam, lastParam;
    TopoDS_Edge edge = wireExplorer.Current();
    wireExplorer.Next();
    Handle(Geom_Curve) curve = BRep_Tool::Curve(edge, firstParam, lastParam);

    // Length of current edge
    GeomAdaptor_Curve adaptorCurve;
    adaptorCurve.Load(curve, firstParam, lastParam);
    double currLength = GCPnts_AbscissaPoint::Length(adaptorCurve);

    // Length of complete wire up to now
    double sumLength = currLength;

    while (length > sumLength) {
        if (!wireExplorer.More()) {
            break;
        }

        edge = wireExplorer.Current();
        wireExplorer.Next();

        curve = BRep_Tool::Curve(edge, firstParam, lastParam);
        adaptorCurve.Load(curve, firstParam, lastParam);

        // Length of current edge
        currLength = GCPnts_AbscissaPoint::Length(adaptorCurve);

        // Length of complete wire up to now
        sumLength += currLength;
    }

    // Distance of searched point from end point of current edge
    double currEndDelta = std::max((sumLength - length), 0.0);

    // Distance of searched point from start point of current edge
    double currDist = std::max((currLength - currEndDelta), 0.0);

    GCPnts_AbscissaPoint abscissaPoint(adaptorCurve, currDist, adaptorCurve.FirstParameter());
    adaptorCurve.D1(abscissaPoint.Parameter(), point, tangent);
}


gp_Pnt WireGetPoint2(const TopoDS_Wire& wire, double alpha)
{
    gp_Pnt point;
    gp_Vec tangent;
    WireGetPointTangent2(wire, alpha, point, tangent);
    return point;
}

void WireGetPointTangent2(const TopoDS_Wire& wire, double alpha, gp_Pnt& point, gp_Vec& tangent)
{
    if (alpha < 0.0 || alpha > 1.0) {
        throw tigl::CTiglError("Error: Parameter alpha not in the range 0.0 <= alpha <= 1.0 in WireGetPointTangent2", TIGL_ERROR);
    }
    // ETA 3D point
    BRepAdaptor_CompCurve aCompoundCurve(wire, Standard_True);

    Standard_Real len =  GCPnts_AbscissaPoint::Length( aCompoundCurve );
    GCPnts_AbscissaPoint algo(aCompoundCurve, len*alpha, aCompoundCurve.FirstParameter());
    if (algo.IsDone()) {
        double par = algo.Parameter();
        aCompoundCurve.D1( par, point, tangent );
        // normalize tangent to length of the curve
        tangent = len*tangent/tangent.Magnitude();
    }
    else {
        throw tigl::CTiglError("WireGetPointTangent2: Cannot compute point on curve.", TIGL_MATH_ERROR);
    }
}

Standard_Real ProjectPointOnWire(const TopoDS_Wire& wire, gp_Pnt p)
{
    double smallestDist = DBL_MAX;
    double alpha  = 0.;
    int edgeIndex = 0;

    // find edge with closest dist to point p
    BRepTools_WireExplorer wireExplorer;
    int iwire = 0;
    for (wireExplorer.Init(wire); wireExplorer.More(); wireExplorer.Next(), iwire++) {
        Standard_Real firstParam, lastParam;
        TopoDS_Edge edge = wireExplorer.Current();
        Handle(Geom_Curve) curve = BRep_Tool::Curve(edge, firstParam, lastParam);

        GeomAPI_ProjectPointOnCurve proj(p, curve, firstParam, lastParam);
        if (proj.NbPoints() > 0 && proj.LowerDistance() < smallestDist) {
            smallestDist = proj.LowerDistance();
            edgeIndex = iwire;
            alpha = proj.LowerDistanceParameter();
        }
    }

    // compute partial length of wire until projection point is reached
    wireExplorer.Init(wire);
    double partLength = 0.;
    for (int iwire = 0; iwire <= edgeIndex; ++iwire) {
        Standard_Real firstParam;
        Standard_Real lastParam;
        TopoDS_Edge edge = wireExplorer.Current();
        Handle(Geom_Curve) curve = BRep_Tool::Curve(edge, firstParam, lastParam);
        GeomAdaptor_Curve adaptorCurve(curve, firstParam, lastParam);
        if (iwire == edgeIndex) {
            lastParam = alpha;
        }

        partLength += GCPnts_AbscissaPoint::Length(adaptorCurve, firstParam, lastParam);
        wireExplorer.Next();
    }

    // return relative coordinate
    return partLength/GetWireLength(wire);
}

// projects a point onto the line (lineStart<->lineStop) and returns the projection parameter
Standard_Real ProjectPointOnLine(gp_Pnt p, gp_Pnt lineStart, gp_Pnt lineStop)
{
    return gp_Vec(lineStart, p) * gp_Vec(lineStart, lineStop) / gp_Vec(lineStart, lineStop).SquareMagnitude();
}
