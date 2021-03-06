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
#include "CCPACSWingRibsDefinition.h"
#include "CPACSWingRibsPositioning.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSWingRibsPositioning::CPACSWingRibsPositioning(CCPACSWingRibsDefinition* parent)
        : m_ribRotation(reinterpret_cast<CCPACSWingRibsPositioning*>(this))
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSWingRibsPositioning::~CPACSWingRibsPositioning()
    {
    }

    const CCPACSWingRibsDefinition* CPACSWingRibsPositioning::GetParent() const
    {
        return m_parent;
    }

    CCPACSWingRibsDefinition* CPACSWingRibsPositioning::GetParent()
    {
        return m_parent;
    }

    void CPACSWingRibsPositioning::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element ribReference
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/ribReference")) {
            m_ribReference = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/ribReference");
            if (m_ribReference.empty()) {
                LOG(WARNING) << "Required element ribReference is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required element ribReference is missing at xpath " << xpath;
        }

        // read element ribStart
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/ribStart")) {
            m_ribStart = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/ribStart");
            if (m_ribStart.empty()) {
                LOG(WARNING) << "Required element ribStart is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required element ribStart is missing at xpath " << xpath;
        }

        // read element ribEnd
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/ribEnd")) {
            m_ribEnd = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/ribEnd");
            if (m_ribEnd.empty()) {
                LOG(WARNING) << "Required element ribEnd is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required element ribEnd is missing at xpath " << xpath;
        }

        // read element ribCrossingBehaviour
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/ribCrossingBehaviour")) {
            m_ribCrossingBehaviour = stringToCPACSRibCrossingBehaviour(tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/ribCrossingBehaviour"));
        }
        else {
            LOG(ERROR) << "Required element ribCrossingBehaviour is missing at xpath " << xpath;
        }

        // read element ribRotation
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/ribRotation")) {
            m_ribRotation.ReadCPACS(tixiHandle, xpath + "/ribRotation");
        }
        else {
            LOG(ERROR) << "Required element ribRotation is missing at xpath " << xpath;
        }

        // read element etaStart
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/etaStart")) {
            m_etaStart_choice1 = tixi::TixiGetElement<double>(tixiHandle, xpath + "/etaStart");
        }

        // read element elementStartUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/elementStartUID")) {
            m_elementStartUID_choice2 = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/elementStartUID");
            if (m_elementStartUID_choice2->empty()) {
                LOG(WARNING) << "Optional element elementStartUID is present but empty at xpath " << xpath;
            }
        }

        // read element sparPositionStartUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/sparPositionStartUID")) {
            m_sparPositionStartUID_choice3 = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/sparPositionStartUID");
            if (m_sparPositionStartUID_choice3->empty()) {
                LOG(WARNING) << "Optional element sparPositionStartUID is present but empty at xpath " << xpath;
            }
        }

        // read element etaEnd
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/etaEnd")) {
            m_etaEnd_choice1 = tixi::TixiGetElement<double>(tixiHandle, xpath + "/etaEnd");
        }

        // read element elementEndUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/elementEndUID")) {
            m_elementEndUID_choice2 = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/elementEndUID");
            if (m_elementEndUID_choice2->empty()) {
                LOG(WARNING) << "Optional element elementEndUID is present but empty at xpath " << xpath;
            }
        }

        // read element sparPositionEndUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/sparPositionEndUID")) {
            m_sparPositionEndUID_choice3 = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/sparPositionEndUID");
            if (m_sparPositionEndUID_choice3->empty()) {
                LOG(WARNING) << "Optional element sparPositionEndUID is present but empty at xpath " << xpath;
            }
        }

        // read element spacing
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/spacing")) {
            m_spacing_choice1 = tixi::TixiGetElement<double>(tixiHandle, xpath + "/spacing");
        }

        // read element numberOfRibs
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/numberOfRibs")) {
            m_numberOfRibs_choice2 = tixi::TixiGetElement<int>(tixiHandle, xpath + "/numberOfRibs");
        }

        if (!ValidateChoices()) {
            LOG(ERROR) << "Invalid choice configuration at xpath " << xpath;
        }
    }

    void CPACSWingRibsPositioning::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element ribReference
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/ribReference");
        tixi::TixiSaveElement(tixiHandle, xpath + "/ribReference", m_ribReference);

        // write element ribStart
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/ribStart");
        tixi::TixiSaveElement(tixiHandle, xpath + "/ribStart", m_ribStart);

        // write element ribEnd
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/ribEnd");
        tixi::TixiSaveElement(tixiHandle, xpath + "/ribEnd", m_ribEnd);

        // write element ribCrossingBehaviour
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/ribCrossingBehaviour");
        tixi::TixiSaveElement(tixiHandle, xpath + "/ribCrossingBehaviour", CPACSRibCrossingBehaviourToString(m_ribCrossingBehaviour));

        // write element ribRotation
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/ribRotation");
        m_ribRotation.WriteCPACS(tixiHandle, xpath + "/ribRotation");

        // write element etaStart
        if (m_etaStart_choice1) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/etaStart");
            tixi::TixiSaveElement(tixiHandle, xpath + "/etaStart", *m_etaStart_choice1);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/etaStart")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/etaStart");
            }
        }

        // write element elementStartUID
        if (m_elementStartUID_choice2) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/elementStartUID");
            tixi::TixiSaveElement(tixiHandle, xpath + "/elementStartUID", *m_elementStartUID_choice2);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/elementStartUID")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/elementStartUID");
            }
        }

        // write element sparPositionStartUID
        if (m_sparPositionStartUID_choice3) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/sparPositionStartUID");
            tixi::TixiSaveElement(tixiHandle, xpath + "/sparPositionStartUID", *m_sparPositionStartUID_choice3);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/sparPositionStartUID")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/sparPositionStartUID");
            }
        }

        // write element etaEnd
        if (m_etaEnd_choice1) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/etaEnd");
            tixi::TixiSaveElement(tixiHandle, xpath + "/etaEnd", *m_etaEnd_choice1);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/etaEnd")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/etaEnd");
            }
        }

        // write element elementEndUID
        if (m_elementEndUID_choice2) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/elementEndUID");
            tixi::TixiSaveElement(tixiHandle, xpath + "/elementEndUID", *m_elementEndUID_choice2);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/elementEndUID")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/elementEndUID");
            }
        }

        // write element sparPositionEndUID
        if (m_sparPositionEndUID_choice3) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/sparPositionEndUID");
            tixi::TixiSaveElement(tixiHandle, xpath + "/sparPositionEndUID", *m_sparPositionEndUID_choice3);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/sparPositionEndUID")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/sparPositionEndUID");
            }
        }

        // write element spacing
        if (m_spacing_choice1) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/spacing");
            tixi::TixiSaveElement(tixiHandle, xpath + "/spacing", *m_spacing_choice1);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/spacing")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/spacing");
            }
        }

        // write element numberOfRibs
        if (m_numberOfRibs_choice2) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/numberOfRibs");
            tixi::TixiSaveElement(tixiHandle, xpath + "/numberOfRibs", *m_numberOfRibs_choice2);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/numberOfRibs")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/numberOfRibs");
            }
        }

    }

    bool CPACSWingRibsPositioning::ValidateChoices() const
    {
        return
        (
            (
                (
                    // mandatory elements of this choice must be there
                    m_etaStart_choice1.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_elementStartUID_choice2.is_initialized()
                        ||
                        m_sparPositionStartUID_choice3.is_initialized()
                    )
                )
                +
                (
                    // mandatory elements of this choice must be there
                    m_elementStartUID_choice2.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_etaStart_choice1.is_initialized()
                        ||
                        m_sparPositionStartUID_choice3.is_initialized()
                    )
                )
                +
                (
                    // mandatory elements of this choice must be there
                    m_sparPositionStartUID_choice3.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_etaStart_choice1.is_initialized()
                        ||
                        m_elementStartUID_choice2.is_initialized()
                    )
                )
                == 1
            )
            &&
            (
                (
                    // mandatory elements of this choice must be there
                    m_etaEnd_choice1.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_elementEndUID_choice2.is_initialized()
                        ||
                        m_sparPositionEndUID_choice3.is_initialized()
                    )
                )
                +
                (
                    // mandatory elements of this choice must be there
                    m_elementEndUID_choice2.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_etaEnd_choice1.is_initialized()
                        ||
                        m_sparPositionEndUID_choice3.is_initialized()
                    )
                )
                +
                (
                    // mandatory elements of this choice must be there
                    m_sparPositionEndUID_choice3.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_etaEnd_choice1.is_initialized()
                        ||
                        m_elementEndUID_choice2.is_initialized()
                    )
                )
                == 1
            )
            &&
            (
                (
                    // mandatory elements of this choice must be there
                    m_spacing_choice1.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_numberOfRibs_choice2.is_initialized()
                    )
                )
                +
                (
                    // mandatory elements of this choice must be there
                    m_numberOfRibs_choice2.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_spacing_choice1.is_initialized()
                    )
                )
                == 1
            )
        )
        ;
    }

    const std::string& CPACSWingRibsPositioning::GetRibReference() const
    {
        return m_ribReference;
    }

    void CPACSWingRibsPositioning::SetRibReference(const std::string& value)
    {
        m_ribReference = value;
    }

    const std::string& CPACSWingRibsPositioning::GetRibStart() const
    {
        return m_ribStart;
    }

    void CPACSWingRibsPositioning::SetRibStart(const std::string& value)
    {
        m_ribStart = value;
    }

    const std::string& CPACSWingRibsPositioning::GetRibEnd() const
    {
        return m_ribEnd;
    }

    void CPACSWingRibsPositioning::SetRibEnd(const std::string& value)
    {
        m_ribEnd = value;
    }

    const CPACSRibCrossingBehaviour& CPACSWingRibsPositioning::GetRibCrossingBehaviour() const
    {
        return m_ribCrossingBehaviour;
    }

    void CPACSWingRibsPositioning::SetRibCrossingBehaviour(const CPACSRibCrossingBehaviour& value)
    {
        m_ribCrossingBehaviour = value;
    }

    const CCPACSWingRibRotation& CPACSWingRibsPositioning::GetRibRotation() const
    {
        return m_ribRotation;
    }

    CCPACSWingRibRotation& CPACSWingRibsPositioning::GetRibRotation()
    {
        return m_ribRotation;
    }

    const boost::optional<double>& CPACSWingRibsPositioning::GetEtaStart_choice1() const
    {
        return m_etaStart_choice1;
    }

    void CPACSWingRibsPositioning::SetEtaStart_choice1(const boost::optional<double>& value)
    {
        m_etaStart_choice1 = value;
    }

    const boost::optional<std::string>& CPACSWingRibsPositioning::GetElementStartUID_choice2() const
    {
        return m_elementStartUID_choice2;
    }

    void CPACSWingRibsPositioning::SetElementStartUID_choice2(const boost::optional<std::string>& value)
    {
        m_elementStartUID_choice2 = value;
    }

    const boost::optional<std::string>& CPACSWingRibsPositioning::GetSparPositionStartUID_choice3() const
    {
        return m_sparPositionStartUID_choice3;
    }

    void CPACSWingRibsPositioning::SetSparPositionStartUID_choice3(const boost::optional<std::string>& value)
    {
        m_sparPositionStartUID_choice3 = value;
    }

    const boost::optional<double>& CPACSWingRibsPositioning::GetEtaEnd_choice1() const
    {
        return m_etaEnd_choice1;
    }

    void CPACSWingRibsPositioning::SetEtaEnd_choice1(const boost::optional<double>& value)
    {
        m_etaEnd_choice1 = value;
    }

    const boost::optional<std::string>& CPACSWingRibsPositioning::GetElementEndUID_choice2() const
    {
        return m_elementEndUID_choice2;
    }

    void CPACSWingRibsPositioning::SetElementEndUID_choice2(const boost::optional<std::string>& value)
    {
        m_elementEndUID_choice2 = value;
    }

    const boost::optional<std::string>& CPACSWingRibsPositioning::GetSparPositionEndUID_choice3() const
    {
        return m_sparPositionEndUID_choice3;
    }

    void CPACSWingRibsPositioning::SetSparPositionEndUID_choice3(const boost::optional<std::string>& value)
    {
        m_sparPositionEndUID_choice3 = value;
    }

    const boost::optional<double>& CPACSWingRibsPositioning::GetSpacing_choice1() const
    {
        return m_spacing_choice1;
    }

    void CPACSWingRibsPositioning::SetSpacing_choice1(const boost::optional<double>& value)
    {
        m_spacing_choice1 = value;
    }

    const boost::optional<int>& CPACSWingRibsPositioning::GetNumberOfRibs_choice2() const
    {
        return m_numberOfRibs_choice2;
    }

    void CPACSWingRibsPositioning::SetNumberOfRibs_choice2(const boost::optional<int>& value)
    {
        m_numberOfRibs_choice2 = value;
    }

} // namespace generated
} // namespace tigl
