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
#include "tigl_internal.h"

namespace tigl
{
namespace generated
{
    // This class is used in:
    // CPACSControlSurfaceBorderTrailingEdge

    // generated from /xsd:schema/xsd:complexType[971]
    /// @brief xsiIsoLineType
    /// 
    /// Iso line described by point of same xsi coordinate.
    /// Can be either segment or component segment coordinates.
    /// 
    class CPACSXsiIsoLine
    {
    public:
        TIGL_EXPORT CPACSXsiIsoLine();
        TIGL_EXPORT virtual ~CPACSXsiIsoLine();

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const double& GetXsi() const;
        TIGL_EXPORT virtual void SetXsi(const double& value);

        TIGL_EXPORT virtual const std::string& GetReferenceUID() const;
        TIGL_EXPORT virtual void SetReferenceUID(const std::string& value);

    protected:
        /// Relative spanwise position. Xsi refers to the segment or componentSegment depending on the referenced uID.
        double      m_xsi;

        /// This reference uID determines the reference coordinate system.
        /// If it points to a segment, then the eta value is considered to be in segment
        /// eta coordinate; if it points to a componentSegment,
        /// then componentSegment eta coordinate is used.
        std::string m_referenceUID;

    private:
#ifdef HAVE_CPP11
        CPACSXsiIsoLine(const CPACSXsiIsoLine&) = delete;
        CPACSXsiIsoLine& operator=(const CPACSXsiIsoLine&) = delete;

        CPACSXsiIsoLine(CPACSXsiIsoLine&&) = delete;
        CPACSXsiIsoLine& operator=(CPACSXsiIsoLine&&) = delete;
#else
        CPACSXsiIsoLine(const CPACSXsiIsoLine&);
        CPACSXsiIsoLine& operator=(const CPACSXsiIsoLine&);
#endif
    };
} // namespace generated

// Aliases in tigl namespace
#ifdef HAVE_CPP11
using CCPACSXsiIsoLine = generated::CPACSXsiIsoLine;
#else
typedef generated::CPACSXsiIsoLine CCPACSXsiIsoLine;
#endif
} // namespace tigl
