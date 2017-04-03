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

#include "CPACSPlasticityCurvePoint.h"
#include "CPACSPostFailure.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSPostFailure::CPACSPostFailure(){}
        CPACSPostFailure::~CPACSPostFailure() {}
        
        void CPACSPostFailure::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element name
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/name")) {
                m_name = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/name");
            }
            
            // read element description
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/description")) {
                m_description = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/description");
            }
            
            // read element materialLaw
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/materialLaw")) {
                m_materialLaw = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/materialLaw");
            }
            
            // read element plasticEliminationStrain
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/plasticEliminationStrain")) {
                m_plasticEliminationStrain_choice1 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/plasticEliminationStrain");
            }
            
            // read element plasticityCurvePoint
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/plasticityCurvePoint")) {
                tixihelper::TixiReadElements(tixiHandle, xpath + "/plasticityCurvePoint", m_plasticityCurvePoint_choice1s);
            }
            
            // read element initialEquivalentShearStrain
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/initialEquivalentShearStrain")) {
                m_initialEquivalentShearStrain_choice2 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/initialEquivalentShearStrain");
            }
            
            // read element intermediateEquivalentShearStrain
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/intermediateEquivalentShearStrain")) {
                m_intermediateEquivalentShearStrain_choice2 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/intermediateEquivalentShearStrain");
            }
            
            // read element ultimateEquivalentShearStrain
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/ultimateEquivalentShearStrain")) {
                m_ultimateEquivalentShearStrain_choice2 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/ultimateEquivalentShearStrain");
            }
            
            // read element intermediateDamage
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/intermediateDamage")) {
                m_intermediateDamage_choice2 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/intermediateDamage");
            }
            
            // read element ultimateDamage
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/ultimateDamage")) {
                m_ultimateDamage_choice2 = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/ultimateDamage");
            }
            
        }
        
        void CPACSPostFailure::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element name
            if (m_name) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/name");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/name", *m_name);
            }
            
            // write element description
            if (m_description) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/description");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/description", *m_description);
            }
            
            // write element materialLaw
            if (m_materialLaw) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/materialLaw");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/materialLaw", *m_materialLaw);
            }
            
            // write element plasticEliminationStrain
            if (m_plasticEliminationStrain_choice1) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/plasticEliminationStrain");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/plasticEliminationStrain", *m_plasticEliminationStrain_choice1);
            }
            
            // write element plasticityCurvePoint
            tixihelper::TixiSaveElements(tixiHandle, xpath + "/plasticityCurvePoint", m_plasticityCurvePoint_choice1s);
            
            // write element initialEquivalentShearStrain
            if (m_initialEquivalentShearStrain_choice2) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/initialEquivalentShearStrain");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/initialEquivalentShearStrain", *m_initialEquivalentShearStrain_choice2);
            }
            
            // write element intermediateEquivalentShearStrain
            if (m_intermediateEquivalentShearStrain_choice2) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/intermediateEquivalentShearStrain");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/intermediateEquivalentShearStrain", *m_intermediateEquivalentShearStrain_choice2);
            }
            
            // write element ultimateEquivalentShearStrain
            if (m_ultimateEquivalentShearStrain_choice2) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/ultimateEquivalentShearStrain");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/ultimateEquivalentShearStrain", *m_ultimateEquivalentShearStrain_choice2);
            }
            
            // write element intermediateDamage
            if (m_intermediateDamage_choice2) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/intermediateDamage");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/intermediateDamage", *m_intermediateDamage_choice2);
            }
            
            // write element ultimateDamage
            if (m_ultimateDamage_choice2) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/ultimateDamage");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/ultimateDamage", *m_ultimateDamage_choice2);
            }
            
        }
        
        bool CPACSPostFailure::HasName() const
        {
            return static_cast<bool>(m_name);
        }
        
        const std::string& CPACSPostFailure::GetName() const
        {
            return *m_name;
        }
        
        void CPACSPostFailure::SetName(const std::string& value)
        {
            m_name = value;
        }
        
        bool CPACSPostFailure::HasDescription() const
        {
            return static_cast<bool>(m_description);
        }
        
        const std::string& CPACSPostFailure::GetDescription() const
        {
            return *m_description;
        }
        
        void CPACSPostFailure::SetDescription(const std::string& value)
        {
            m_description = value;
        }
        
        bool CPACSPostFailure::HasMaterialLaw() const
        {
            return static_cast<bool>(m_materialLaw);
        }
        
        const std::string& CPACSPostFailure::GetMaterialLaw() const
        {
            return *m_materialLaw;
        }
        
        void CPACSPostFailure::SetMaterialLaw(const std::string& value)
        {
            m_materialLaw = value;
        }
        
        bool CPACSPostFailure::HasPlasticEliminationStrain_choice1() const
        {
            return static_cast<bool>(m_plasticEliminationStrain_choice1);
        }
        
        const double& CPACSPostFailure::GetPlasticEliminationStrain_choice1() const
        {
            return *m_plasticEliminationStrain_choice1;
        }
        
        void CPACSPostFailure::SetPlasticEliminationStrain_choice1(const double& value)
        {
            m_plasticEliminationStrain_choice1 = value;
        }
        
        const std::vector<unique_ptr<CPACSPlasticityCurvePoint> >& CPACSPostFailure::GetPlasticityCurvePoint_choice1s() const
        {
            return m_plasticityCurvePoint_choice1s;
        }
        
        std::vector<unique_ptr<CPACSPlasticityCurvePoint> >& CPACSPostFailure::GetPlasticityCurvePoint_choice1s()
        {
            return m_plasticityCurvePoint_choice1s;
        }
        
        bool CPACSPostFailure::HasInitialEquivalentShearStrain_choice2() const
        {
            return static_cast<bool>(m_initialEquivalentShearStrain_choice2);
        }
        
        const double& CPACSPostFailure::GetInitialEquivalentShearStrain_choice2() const
        {
            return *m_initialEquivalentShearStrain_choice2;
        }
        
        void CPACSPostFailure::SetInitialEquivalentShearStrain_choice2(const double& value)
        {
            m_initialEquivalentShearStrain_choice2 = value;
        }
        
        bool CPACSPostFailure::HasIntermediateEquivalentShearStrain_choice2() const
        {
            return static_cast<bool>(m_intermediateEquivalentShearStrain_choice2);
        }
        
        const double& CPACSPostFailure::GetIntermediateEquivalentShearStrain_choice2() const
        {
            return *m_intermediateEquivalentShearStrain_choice2;
        }
        
        void CPACSPostFailure::SetIntermediateEquivalentShearStrain_choice2(const double& value)
        {
            m_intermediateEquivalentShearStrain_choice2 = value;
        }
        
        bool CPACSPostFailure::HasUltimateEquivalentShearStrain_choice2() const
        {
            return static_cast<bool>(m_ultimateEquivalentShearStrain_choice2);
        }
        
        const double& CPACSPostFailure::GetUltimateEquivalentShearStrain_choice2() const
        {
            return *m_ultimateEquivalentShearStrain_choice2;
        }
        
        void CPACSPostFailure::SetUltimateEquivalentShearStrain_choice2(const double& value)
        {
            m_ultimateEquivalentShearStrain_choice2 = value;
        }
        
        bool CPACSPostFailure::HasIntermediateDamage_choice2() const
        {
            return static_cast<bool>(m_intermediateDamage_choice2);
        }
        
        const double& CPACSPostFailure::GetIntermediateDamage_choice2() const
        {
            return *m_intermediateDamage_choice2;
        }
        
        void CPACSPostFailure::SetIntermediateDamage_choice2(const double& value)
        {
            m_intermediateDamage_choice2 = value;
        }
        
        bool CPACSPostFailure::HasUltimateDamage_choice2() const
        {
            return static_cast<bool>(m_ultimateDamage_choice2);
        }
        
        const double& CPACSPostFailure::GetUltimateDamage_choice2() const
        {
            return *m_ultimateDamage_choice2;
        }
        
        void CPACSPostFailure::SetUltimateDamage_choice2(const double& value)
        {
            m_ultimateDamage_choice2 = value;
        }
        
    }
}