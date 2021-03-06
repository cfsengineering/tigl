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
#include <vector>
#include "tigl_internal.h"
#include "UniquePtr.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSRotorcraftModel;

namespace generated
{
    // This class is used in:
    // CPACSVehicles

    // generated from /xsd:schema/xsd:complexType[792]
    /// @brief rotorcraftType
    /// 
    /// Rotorcraft type, containing all the rotorcraft models.
    /// Most of the extensions used in the rotorcraft type have
    /// been defined as part of the work in the DLR project RIDE
    /// (Rotorcraft Integrated Design and Evaluation, 2009-2012).
    /// Therefore some of the definitions and conventions are tightly
    /// coupled to the RIDE toolchain and tools. Further generalization
    /// and assimilation of these parts to the definitions for fixed-wing
    /// aircraft is planned for the near future.
    /// 
    class CPACSRotorcraft
    {
    public:
        TIGL_EXPORT CPACSRotorcraft(CTiglUIDManager* uidMgr);
        TIGL_EXPORT virtual ~CPACSRotorcraft();

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::vector<unique_ptr<CCPACSRotorcraftModel> >& GetModels() const;
        TIGL_EXPORT virtual std::vector<unique_ptr<CCPACSRotorcraftModel> >& GetModels();

        TIGL_EXPORT virtual CCPACSRotorcraftModel& AddModel();
        TIGL_EXPORT virtual void RemoveModel(CCPACSRotorcraftModel& ref);

    protected:
        CTiglUIDManager* m_uidMgr;

        std::vector<unique_ptr<CCPACSRotorcraftModel> > m_models;

    private:
#ifdef HAVE_CPP11
        CPACSRotorcraft(const CPACSRotorcraft&) = delete;
        CPACSRotorcraft& operator=(const CPACSRotorcraft&) = delete;

        CPACSRotorcraft(CPACSRotorcraft&&) = delete;
        CPACSRotorcraft& operator=(CPACSRotorcraft&&) = delete;
#else
        CPACSRotorcraft(const CPACSRotorcraft&);
        CPACSRotorcraft& operator=(const CPACSRotorcraft&);
#endif
    };
} // namespace generated

// Aliases in tigl namespace
#ifdef HAVE_CPP11
using CCPACSRotorcraft = generated::CPACSRotorcraft;
#else
typedef generated::CPACSRotorcraft CCPACSRotorcraft;
#endif
} // namespace tigl
