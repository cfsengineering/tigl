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

#include <cassert>
#include <CCPACSTrailingEdgeDevice.h>
#include "CCPACSControlSurfaces.h"
#include "CPACSTrailingEdgeDevices.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSTrailingEdgeDevices::CPACSTrailingEdgeDevices(CCPACSControlSurfaces* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSTrailingEdgeDevices::~CPACSTrailingEdgeDevices()
    {
    }

    CCPACSControlSurfaces* CPACSTrailingEdgeDevices::GetParent() const
    {
        return m_parent;
    }

    CTiglUIDManager& CPACSTrailingEdgeDevices::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSTrailingEdgeDevices::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSTrailingEdgeDevices::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element trailingEdgeDevice
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/trailingEdgeDevice")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/trailingEdgeDevice", m_trailingEdgeDevices, reinterpret_cast<CCPACSTrailingEdgeDevices*>(this), m_uidMgr);
        }

    }

    void CPACSTrailingEdgeDevices::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element trailingEdgeDevice
        tixi::TixiSaveElements(tixiHandle, xpath + "/trailingEdgeDevice", m_trailingEdgeDevices);

    }

    const std::vector<unique_ptr<CCPACSTrailingEdgeDevice> >& CPACSTrailingEdgeDevices::GetTrailingEdgeDevices() const
    {
        return m_trailingEdgeDevices;
    }

    std::vector<unique_ptr<CCPACSTrailingEdgeDevice> >& CPACSTrailingEdgeDevices::GetTrailingEdgeDevices()
    {
        return m_trailingEdgeDevices;
    }

    CCPACSTrailingEdgeDevice& CPACSTrailingEdgeDevices::AddTrailingEdgeDevice()
    {
        m_trailingEdgeDevices.push_back(make_unique<CCPACSTrailingEdgeDevice>(reinterpret_cast<CCPACSTrailingEdgeDevices*>(this), m_uidMgr));
        return *m_trailingEdgeDevices.back();
    }

    void CPACSTrailingEdgeDevices::RemoveTrailingEdgeDevice(CCPACSTrailingEdgeDevice& ref)
    {
        for (std::size_t i = 0; i < m_trailingEdgeDevices.size(); i++) {
            if (m_trailingEdgeDevices[i].get() == &ref) {
                m_trailingEdgeDevices.erase(m_trailingEdgeDevices.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl