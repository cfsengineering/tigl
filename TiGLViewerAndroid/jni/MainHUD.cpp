/*
* Copyright (C) 2007-2014 German Aerospace Center (DLR/SC)
*
* Created: 2014-06-11 Mahmoud Aly <Mahmoud.Aly@dlr.de>
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

#include <osg/Geometry>
#include <osg/Geode>
#include <osg/LineWidth>
#include <osg/BlendFunc>
#include <iostream>
#include "mainHUD.h"
#include "FadeOutCallBack.h"



MainHUD::MainHUD(int screenWidth, int screenHeight)
{
    _screenWidth = screenWidth;
    _screenHeight = screenHeight;
    centerCross = NULL;
    init();
}
MainHUD::~MainHUD(){}

void MainHUD::init()
{
    setClearMask( GL_DEPTH_BUFFER_BIT );
    setRenderOrder( osg::Camera::POST_RENDER, 1 );
    setReferenceFrame( osg::Transform::ABSOLUTE_RF );
    setName("mainHUD");
    setAllowEventFocus(false);
    setViewport(0 , 0 , _screenWidth , _screenHeight);
    updateViewPort(_screenWidth, _screenHeight);
}
void MainHUD::updateViewPort(int screenWidth, int screenHeight)
{
    _screenWidth = screenWidth;
    _screenHeight = screenHeight;
    centerCross = NULL;
    setViewport(0 , 0 , _screenWidth , _screenHeight);

    double ar = _screenWidth/ (double) _screenHeight;
    if (_screenWidth > _screenHeight) {
        // landscape
        setProjectionMatrixAsOrtho2D(-ar, ar , -1.0 , 1.0);
    }
    else {
        // portrait
        setProjectionMatrixAsOrtho2D(-1., 1., -1./ar, 1/ar);
    }
}
void MainHUD::showCenterCross()
{
    if (!centerCross) {
        createCenterCross();
    }

    osg::StateSet* stateset = centerCross->getOrCreateStateSet();
    centerCross->setUpdateCallback(new FadeOutCallback((osg::Material *)stateset->getAttribute(osg::StateAttribute::MATERIAL)));
}
void MainHUD::createCenterCross()
{
    float vlineLength;
    float hlineLength;

    vlineLength = 0.04 ;
    hlineLength = vlineLength;


    //Line Width
    osg::LineWidth *  lw = new osg::LineWidth();
    lw->setWidth(3.0f);

    //Draw Top Line
    osg::Vec3 top_line_1(0.0f,0.03f,0.0f);
    osg::Vec3 top_line_2(0.0f,0.03f + vlineLength,0.0f);

    osg::Geometry* top_line = new osg::Geometry;
    osg::Vec3Array* v_top_line = new osg::Vec3Array(2);
    (* v_top_line)[0] = top_line_1;
    (* v_top_line)[1] = top_line_2;
    top_line->setVertexArray(v_top_line);

    osg::Vec4Array* colors = new osg::Vec4Array(1);
    (*colors)[0].set(1.0f,1.0f,0.0f,1.0f);
    top_line->setColorArray(colors, osg::Array::BIND_OVERALL);

    top_line->addPrimitiveSet(new osg::DrawArrays(GL_LINES,0,2));

    //Draw Bottom Line
    osg::Vec3 bottom_line_1(0.0f,-0.03f,0.0f);
    osg::Vec3 bottom_line_2(0.0f,-1*(0.03f+vlineLength),0.0f);

    osg::Geometry* bottom_line = new osg::Geometry;
    osg::Vec3Array* v_bottom_line = new osg::Vec3Array(2);
    (* v_bottom_line)[0] = bottom_line_1;
    (* v_bottom_line)[1] = bottom_line_2;
    bottom_line->setVertexArray(v_bottom_line);
    bottom_line->setColorArray(colors, osg::Array::BIND_OVERALL);
    bottom_line->addPrimitiveSet(new osg::DrawArrays(GL_LINES,0,2));

    //Draw Left Line
    osg::Vec3 left_line_1(-0.03f,0.0f,0.0f);
    osg::Vec3 left_line_2(-1*(0.03f+hlineLength),0.0f,0.0f);

    osg::Geometry* left_line = new osg::Geometry;
    osg::Vec3Array* v_left_line = new osg::Vec3Array(2);
    (* v_left_line)[0] = left_line_1;
    (* v_left_line)[1] = left_line_2;
    left_line->setVertexArray(v_left_line);
    left_line->setColorArray(colors, osg::Array::BIND_OVERALL);
    left_line->addPrimitiveSet(new osg::DrawArrays(GL_LINES,0,2));


    //Draw Right Line
    osg::Vec3 right_line_1(0.03f,0.0f,0.0f);
    osg::Vec3 right_line_2(0.03f+hlineLength,0.0f,0.0f);

    osg::Geometry* right_line = new osg::Geometry;
    osg::Vec3Array* v_right_line = new osg::Vec3Array(2);
    (* v_right_line)[0] = right_line_1;
    (* v_right_line)[1] = right_line_2;
    right_line->setVertexArray(v_right_line);
    right_line->setColorArray(colors, osg::Array::BIND_OVERALL);
    right_line->addPrimitiveSet(new osg::DrawArrays(GL_LINES,0,2));

    // Add geometries to the node
    osg::Geode* crossgeode = new osg::Geode;
    crossgeode->addDrawable(top_line);
    crossgeode->addDrawable(bottom_line);
    crossgeode->addDrawable(left_line);
    crossgeode->addDrawable(right_line);

    osg::StateSet* stateset = crossgeode->getOrCreateStateSet();
    stateset->setAttributeAndModes(new osg::BlendFunc(osg::BlendFunc::SRC_ALPHA, osg::BlendFunc::ONE_MINUS_SRC_ALPHA));
    stateset->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);

    osg::ref_ptr<osg::Material> material = new osg::Material();
    material->setDiffuse(osg::Material::FRONT_AND_BACK, osg::Vec4(1.f, 0.f, 0.25f, 1.0f));

    stateset->setAttribute(lw);
    stateset->setAttribute(material,osg::StateAttribute::OVERRIDE);

    centerCross = (osg::ref_ptr<Node>) crossgeode;
    addChild(centerCross);
}
