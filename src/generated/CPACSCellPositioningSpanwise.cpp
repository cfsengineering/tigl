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
#include "CCPACSWingCell.h"
#include "CPACSCellPositioningSpanwise.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSCellPositioningSpanwise::CPACSCellPositioningSpanwise(CCPACSWingCell* parent)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSCellPositioningSpanwise::~CPACSCellPositioningSpanwise()
    {
    }

    const CCPACSWingCell* CPACSCellPositioningSpanwise::GetParent() const
    {
        return m_parent;
    }

    CCPACSWingCell* CPACSCellPositioningSpanwise::GetParent()
    {
        return m_parent;
    }

    void CPACSCellPositioningSpanwise::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element eta1
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/eta1")) {
            m_eta1_choice1 = tixi::TixiGetElement<double>(tixiHandle, xpath + "/eta1");
        }

        // read element eta2
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/eta2")) {
            m_eta2_choice1 = tixi::TixiGetElement<double>(tixiHandle, xpath + "/eta2");
        }

        // read element ribNumber
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/ribNumber")) {
            m_ribNumber_choice2 = tixi::TixiGetElement<int>(tixiHandle, xpath + "/ribNumber");
        }

        // read element ribDefinitionUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/ribDefinitionUID")) {
            m_ribDefinitionUID_choice2 = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/ribDefinitionUID");
            if (m_ribDefinitionUID_choice2->empty()) {
                LOG(WARNING) << "Optional element ribDefinitionUID is present but empty at xpath " << xpath;
            }
        }

        if (!ValidateChoices()) {
            LOG(ERROR) << "Invalid choice configuration at xpath " << xpath;
        }
    }

    void CPACSCellPositioningSpanwise::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element eta1
        if (m_eta1_choice1) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/eta1");
            tixi::TixiSaveElement(tixiHandle, xpath + "/eta1", *m_eta1_choice1);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/eta1")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/eta1");
            }
        }

        // write element eta2
        if (m_eta2_choice1) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/eta2");
            tixi::TixiSaveElement(tixiHandle, xpath + "/eta2", *m_eta2_choice1);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/eta2")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/eta2");
            }
        }

        // write element ribNumber
        if (m_ribNumber_choice2) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/ribNumber");
            tixi::TixiSaveElement(tixiHandle, xpath + "/ribNumber", *m_ribNumber_choice2);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/ribNumber")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/ribNumber");
            }
        }

        // write element ribDefinitionUID
        if (m_ribDefinitionUID_choice2) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/ribDefinitionUID");
            tixi::TixiSaveElement(tixiHandle, xpath + "/ribDefinitionUID", *m_ribDefinitionUID_choice2);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/ribDefinitionUID")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/ribDefinitionUID");
            }
        }

    }

    bool CPACSCellPositioningSpanwise::ValidateChoices() const
    {
        return
        (
            (
                (
                    // mandatory elements of this choice must be there
                    m_eta1_choice1.is_initialized()
                    &&
                    m_eta2_choice1.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_ribNumber_choice2.is_initialized()
                        ||
                        m_ribDefinitionUID_choice2.is_initialized()
                    )
                )
                +
                (
                    // mandatory elements of this choice must be there
                    m_ribNumber_choice2.is_initialized()
                    &&
                    m_ribDefinitionUID_choice2.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_eta1_choice1.is_initialized()
                        ||
                        m_eta2_choice1.is_initialized()
                    )
                )
                == 1
            )
        )
        ;
    }

    const boost::optional<double>& CPACSCellPositioningSpanwise::GetEta1_choice1() const
    {
        return m_eta1_choice1;
    }

    void CPACSCellPositioningSpanwise::SetEta1_choice1(const boost::optional<double>& value)
    {
        m_eta1_choice1 = value;
    }

    const boost::optional<double>& CPACSCellPositioningSpanwise::GetEta2_choice1() const
    {
        return m_eta2_choice1;
    }

    void CPACSCellPositioningSpanwise::SetEta2_choice1(const boost::optional<double>& value)
    {
        m_eta2_choice1 = value;
    }

    const boost::optional<int>& CPACSCellPositioningSpanwise::GetRibNumber_choice2() const
    {
        return m_ribNumber_choice2;
    }

    void CPACSCellPositioningSpanwise::SetRibNumber_choice2(const boost::optional<int>& value)
    {
        m_ribNumber_choice2 = value;
    }

    const boost::optional<std::string>& CPACSCellPositioningSpanwise::GetRibDefinitionUID_choice2() const
    {
        return m_ribDefinitionUID_choice2;
    }

    void CPACSCellPositioningSpanwise::SetRibDefinitionUID_choice2(const boost::optional<std::string>& value)
    {
        m_ribDefinitionUID_choice2 = value;
    }

} // namespace generated
} // namespace tigl
