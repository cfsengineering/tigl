// Copyright (c) 2018 RISC Software GmbH
//
// This file was generated by CPACSGen from CPACS XML Schema (c) German Aerospace Center (DLR/SC).
// Do not edit, all changes are lost when files are re-generated.
//
// Licensed under the Apache License, Version 2.0 (the "License")
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <string>
#include <tixi.h>
#include <typeinfo>
#include <vector>
#include "CTiglError.h"
#include "tigl_internal.h"
#include "UniquePtr.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSGuideCurve;

namespace generated
{
    // This class is used in:
    // CPACSFuselageSegment
    // CPACSWingSegment

    // generated from /xsd:schema/xsd:complexType[442]
    /// @brief Guide Curves Type
    /// 
    /// Guide Curve type. This type is used to describe guide
    /// curves that enable designers to create a geometry that deviates
    /// from a standard loft.
    /// 
    class CPACSGuideCurves
    {
    public:
        TIGL_EXPORT CPACSGuideCurves(CTiglUIDManager* uidMgr);
        TIGL_EXPORT virtual ~CPACSGuideCurves();

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::vector<unique_ptr<CCPACSGuideCurve> >& GetGuideCurves() const;
        TIGL_EXPORT virtual std::vector<unique_ptr<CCPACSGuideCurve> >& GetGuideCurves();

        TIGL_EXPORT virtual CCPACSGuideCurve& AddGuideCurve();
        TIGL_EXPORT virtual void RemoveGuideCurve(CCPACSGuideCurve& ref);

    protected:
        CTiglUIDManager* m_uidMgr;

        std::vector<unique_ptr<CCPACSGuideCurve> > m_guideCurves;

    private:
#ifdef HAVE_CPP11
        CPACSGuideCurves(const CPACSGuideCurves&) = delete;
        CPACSGuideCurves& operator=(const CPACSGuideCurves&) = delete;

        CPACSGuideCurves(CPACSGuideCurves&&) = delete;
        CPACSGuideCurves& operator=(CPACSGuideCurves&&) = delete;
#else
        CPACSGuideCurves(const CPACSGuideCurves&);
        CPACSGuideCurves& operator=(const CPACSGuideCurves&);
#endif
    };
} // namespace generated

// CPACSGuideCurves is customized, use type CCPACSGuideCurves directly
} // namespace tigl
