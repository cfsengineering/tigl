// Copyright (c) 2016 RISC Software GmbH
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

#include "CPACSAircraftModel.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSAircraftModel::CPACSAircraftModel(CTiglUIDManager* uidMgr) :
            m_uidMgr(uidMgr) {}
        
        CPACSAircraftModel::~CPACSAircraftModel()
        {
            if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
        }
        
        CTiglUIDManager& CPACSAircraftModel::GetUIDManager()
        {
            return *m_uidMgr;
        }
        
        const CTiglUIDManager& CPACSAircraftModel::GetUIDManager() const
        {
            return *m_uidMgr;
        }
        
        void CPACSAircraftModel::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read attribute uID
            if (tixi::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                m_uID = tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
                if (m_uID.empty()) {
                    LOG(WARNING) << "Required attribute uID is empty at xpath " << xpath;
                }
            }
            else {
                LOG(ERROR) << "Required attribute uID is missing at xpath " << xpath;
            }
            
            // read element name
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/name")) {
                m_name = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/name");
                if (m_name.empty()) {
                    LOG(WARNING) << "Required element name is empty at xpath " << xpath;
                }
            }
            else {
                LOG(ERROR) << "Required element name is missing at xpath " << xpath;
            }
            
            // read element description
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/description")) {
                m_description = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/description");
                if (m_description->empty()) {
                    LOG(WARNING) << "Optional element description is present but empty at xpath " << xpath;
                }
            }
            
            // read element fuselages
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/fuselages")) {
                m_fuselages = boost::in_place(reinterpret_cast<CCPACSAircraftModel*>(this), m_uidMgr);
                try {
                    m_fuselages->ReadCPACS(tixiHandle, xpath + "/fuselages");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read fuselages at xpath " << xpath << ": " << e.what();
                    m_fuselages = boost::none;
                }
            }
            
            // read element wings
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/wings")) {
                m_wings = boost::in_place(reinterpret_cast<CCPACSAircraftModel*>(this), m_uidMgr);
                try {
                    m_wings->ReadCPACS(tixiHandle, xpath + "/wings");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read wings at xpath " << xpath << ": " << e.what();
                    m_wings = boost::none;
                }
            }
            
            // read element genericGeometryComponents
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/genericGeometryComponents")) {
                m_genericGeometryComponents = boost::in_place(reinterpret_cast<CCPACSAircraftModel*>(this), m_uidMgr);
                try {
                    m_genericGeometryComponents->ReadCPACS(tixiHandle, xpath + "/genericGeometryComponents");
                } catch(const std::exception& e) {
                    LOG(ERROR) << "Failed to read genericGeometryComponents at xpath " << xpath << ": " << e.what();
                    m_genericGeometryComponents = boost::none;
                }
            }
            
            if (m_uidMgr && !m_uID.empty()) m_uidMgr->RegisterObject(m_uID, *this);
        }
        
        void CPACSAircraftModel::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write attribute uID
            tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);
            
            // write element name
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/name");
            tixi::TixiSaveElement(tixiHandle, xpath + "/name", m_name);
            
            // write element description
            if (m_description) {
                tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/description");
                tixi::TixiSaveElement(tixiHandle, xpath + "/description", *m_description);
            } else {
                if (tixi::TixiCheckElement(tixiHandle, xpath + "/description")) {
                    tixi::TixiRemoveElement(tixiHandle, xpath + "/description");
                }
            }
            
            // write element fuselages
            if (m_fuselages) {
                tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/fuselages");
                m_fuselages->WriteCPACS(tixiHandle, xpath + "/fuselages");
            } else {
                if (tixi::TixiCheckElement(tixiHandle, xpath + "/fuselages")) {
                    tixi::TixiRemoveElement(tixiHandle, xpath + "/fuselages");
                }
            }
            
            // write element wings
            if (m_wings) {
                tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/wings");
                m_wings->WriteCPACS(tixiHandle, xpath + "/wings");
            } else {
                if (tixi::TixiCheckElement(tixiHandle, xpath + "/wings")) {
                    tixi::TixiRemoveElement(tixiHandle, xpath + "/wings");
                }
            }
            
            // write element genericGeometryComponents
            if (m_genericGeometryComponents) {
                tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/genericGeometryComponents");
                m_genericGeometryComponents->WriteCPACS(tixiHandle, xpath + "/genericGeometryComponents");
            } else {
                if (tixi::TixiCheckElement(tixiHandle, xpath + "/genericGeometryComponents")) {
                    tixi::TixiRemoveElement(tixiHandle, xpath + "/genericGeometryComponents");
                }
            }
            
        }
        
        const std::string& CPACSAircraftModel::GetUID() const
        {
            return m_uID;
        }
        
        void CPACSAircraftModel::SetUID(const std::string& value)
        {
            if (m_uidMgr) {
                m_uidMgr->TryUnregisterObject(m_uID);
                m_uidMgr->RegisterObject(value, *this);
            }
            m_uID = value;
        }
        
        const std::string& CPACSAircraftModel::GetName() const
        {
            return m_name;
        }
        
        void CPACSAircraftModel::SetName(const std::string& value)
        {
            m_name = value;
        }
        
        const boost::optional<std::string>& CPACSAircraftModel::GetDescription() const
        {
            return m_description;
        }
        
        void CPACSAircraftModel::SetDescription(const std::string& value)
        {
            m_description = value;
        }
        
        void CPACSAircraftModel::SetDescription(const boost::optional<std::string>& value)
        {
            m_description = value;
        }
        
        const boost::optional<CCPACSFuselages>& CPACSAircraftModel::GetFuselages() const
        {
            return m_fuselages;
        }
        
        boost::optional<CCPACSFuselages>& CPACSAircraftModel::GetFuselages()
        {
            return m_fuselages;
        }
        
        const boost::optional<CCPACSWings>& CPACSAircraftModel::GetWings() const
        {
            return m_wings;
        }
        
        boost::optional<CCPACSWings>& CPACSAircraftModel::GetWings()
        {
            return m_wings;
        }
        
        const boost::optional<CCPACSExternalObjects>& CPACSAircraftModel::GetGenericGeometryComponents() const
        {
            return m_genericGeometryComponents;
        }
        
        boost::optional<CCPACSExternalObjects>& CPACSAircraftModel::GetGenericGeometryComponents()
        {
            return m_genericGeometryComponents;
        }
        
        CCPACSFuselages& CPACSAircraftModel::GetFuselages(CreateIfNotExistsTag)
        {
            if (!m_fuselages)
                m_fuselages = boost::in_place(reinterpret_cast<CCPACSAircraftModel*>(this), m_uidMgr);
            return *m_fuselages;
        }
        
        void CPACSAircraftModel::RemoveFuselages()
        {
            m_fuselages = boost::none;
        }
        
        CCPACSWings& CPACSAircraftModel::GetWings(CreateIfNotExistsTag)
        {
            if (!m_wings)
                m_wings = boost::in_place(reinterpret_cast<CCPACSAircraftModel*>(this), m_uidMgr);
            return *m_wings;
        }
        
        void CPACSAircraftModel::RemoveWings()
        {
            m_wings = boost::none;
        }
        
        CCPACSExternalObjects& CPACSAircraftModel::GetGenericGeometryComponents(CreateIfNotExistsTag)
        {
            if (!m_genericGeometryComponents)
                m_genericGeometryComponents = boost::in_place(reinterpret_cast<CCPACSAircraftModel*>(this), m_uidMgr);
            return *m_genericGeometryComponents;
        }
        
        void CPACSAircraftModel::RemoveGenericGeometryComponents()
        {
            m_genericGeometryComponents = boost::none;
        }
        
    }
}