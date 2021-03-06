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
    // CPACSCutOutProfiles

    // generated from /xsd:schema/xsd:complexType[699]
    /// @brief outerCutOutProfileType
    /// 
    /// 
    /// 
    class CPACSOuterCutOutProfile
    {
    public:
        TIGL_EXPORT CPACSOuterCutOutProfile();
        TIGL_EXPORT virtual ~CPACSOuterCutOutProfile();

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetProfileUID() const;
        TIGL_EXPORT virtual void SetProfileUID(const std::string& value);

        TIGL_EXPORT virtual const double& GetRotZ() const;
        TIGL_EXPORT virtual void SetRotZ(const double& value);

    protected:
        std::string m_profileUID;
        double      m_rotZ;

    private:
#ifdef HAVE_CPP11
        CPACSOuterCutOutProfile(const CPACSOuterCutOutProfile&) = delete;
        CPACSOuterCutOutProfile& operator=(const CPACSOuterCutOutProfile&) = delete;

        CPACSOuterCutOutProfile(CPACSOuterCutOutProfile&&) = delete;
        CPACSOuterCutOutProfile& operator=(CPACSOuterCutOutProfile&&) = delete;
#else
        CPACSOuterCutOutProfile(const CPACSOuterCutOutProfile&);
        CPACSOuterCutOutProfile& operator=(const CPACSOuterCutOutProfile&);
#endif
    };
} // namespace generated

// Aliases in tigl namespace
#ifdef HAVE_CPP11
using CCPACSOuterCutOutProfile = generated::CPACSOuterCutOutProfile;
#else
typedef generated::CPACSOuterCutOutProfile CCPACSOuterCutOutProfile;
#endif
} // namespace tigl
