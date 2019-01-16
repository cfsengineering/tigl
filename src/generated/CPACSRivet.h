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

#include <boost/optional.hpp>
#include <boost/utility/in_place_factory.hpp>
#include <string>
#include <tixi.h>
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;

namespace generated
{
    // This class is used in:
    // CPACSRivets

    // generated from /xsd:schema/xsd:complexType[761]
    /// @brief rivetType
    /// 
    /// Rivet type, containing a rivet
    /// 
    class CPACSRivet
    {
    public:
        TIGL_EXPORT CPACSRivet(CTiglUIDManager* uidMgr);
        TIGL_EXPORT virtual ~CPACSRivet();

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const std::string& value);

        TIGL_EXPORT virtual const boost::optional<std::string>& GetName() const;
        TIGL_EXPORT virtual void SetName(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const boost::optional<std::string>& GetDescription() const;
        TIGL_EXPORT virtual void SetDescription(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const double& GetTensileStrength() const;
        TIGL_EXPORT virtual void SetTensileStrength(const double& value);

        TIGL_EXPORT virtual const double& GetShearStrength() const;
        TIGL_EXPORT virtual void SetShearStrength(const double& value);

    protected:
        CTiglUIDManager* m_uidMgr;

        std::string                  m_uID;

        /// Name of the rivet type
        boost::optional<std::string> m_name;

        /// Description of the rivet type
        boost::optional<std::string> m_description;

        /// Tensile Strength of the rivet type
        double                       m_tensileStrength;

        /// Shear Strength of the rivet type
        double                       m_shearStrength;

    private:
#ifdef HAVE_CPP11
        CPACSRivet(const CPACSRivet&) = delete;
        CPACSRivet& operator=(const CPACSRivet&) = delete;

        CPACSRivet(CPACSRivet&&) = delete;
        CPACSRivet& operator=(CPACSRivet&&) = delete;
#else
        CPACSRivet(const CPACSRivet&);
        CPACSRivet& operator=(const CPACSRivet&);
#endif
    };
} // namespace generated

// Aliases in tigl namespace
#ifdef HAVE_CPP11
using CCPACSRivet = generated::CPACSRivet;
#else
typedef generated::CPACSRivet CCPACSRivet;
#endif
} // namespace tigl
