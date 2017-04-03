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

#pragma once

#include <tixi.h>
#include <string>
#include <boost/optional.hpp>
#include <boost/utility/in_place_factory.hpp>
#include "CTiglError.h"
#include <typeinfo>
#include "tigl_internal.h"

namespace tigl
{
    namespace generated
    {
        // This class is used in:
        // CPACSCst2D
        // CPACSPointListRelXYZVector
        // CPACSPointListXYZVector
        // CPACSRotorBladeAttachment
        
        // generated from /xsd:schema/xsd:complexType[807]
        class CPACSStringVectorBase
        {
        public:
            TIGL_EXPORT CPACSStringVectorBase();
            TIGL_EXPORT virtual ~CPACSStringVectorBase();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT const std::string& GetMapType() const;
            TIGL_EXPORT void SetMapType(const std::string& value);
            
            TIGL_EXPORT bool HasUncertaintyFunctionName() const;
            TIGL_EXPORT const std::string& GetUncertaintyFunctionName() const;
            TIGL_EXPORT void SetUncertaintyFunctionName(const std::string& value);
            
            TIGL_EXPORT bool HasMu() const;
            TIGL_EXPORT const std::string& GetMu() const;
            TIGL_EXPORT void SetMu(const std::string& value);
            
            TIGL_EXPORT bool HasDelta() const;
            TIGL_EXPORT const std::string& GetDelta() const;
            TIGL_EXPORT void SetDelta(const std::string& value);
            
            TIGL_EXPORT bool HasA() const;
            TIGL_EXPORT const std::string& GetA() const;
            TIGL_EXPORT void SetA(const std::string& value);
            
            TIGL_EXPORT bool HasB() const;
            TIGL_EXPORT const std::string& GetB() const;
            TIGL_EXPORT void SetB(const std::string& value);
            
            TIGL_EXPORT bool HasC() const;
            TIGL_EXPORT const std::string& GetC() const;
            TIGL_EXPORT void SetC(const std::string& value);
            
            TIGL_EXPORT bool HasV() const;
            TIGL_EXPORT const std::string& GetV() const;
            TIGL_EXPORT void SetV(const std::string& value);
            
            TIGL_EXPORT bool HasW() const;
            TIGL_EXPORT const std::string& GetW() const;
            TIGL_EXPORT void SetW(const std::string& value);
            
            TIGL_EXPORT const std::string& GetSimpleContent() const;
            TIGL_EXPORT void SetSimpleContent(const std::string& value);
            
        protected:
            std::string                  m_mapType;
            boost::optional<std::string> m_uncertaintyFunctionName;
            boost::optional<std::string> m_mu;
            boost::optional<std::string> m_delta;
            boost::optional<std::string> m_a;
            boost::optional<std::string> m_b;
            boost::optional<std::string> m_c;
            boost::optional<std::string> m_v;
            boost::optional<std::string> m_w;
            std::string                  m_simpleContent;
            
        private:
            #ifdef HAVE_CPP11
            CPACSStringVectorBase(const CPACSStringVectorBase&) = delete;
            CPACSStringVectorBase& operator=(const CPACSStringVectorBase&) = delete;
            
            CPACSStringVectorBase(CPACSStringVectorBase&&) = delete;
            CPACSStringVectorBase& operator=(CPACSStringVectorBase&&) = delete;
            #else
            CPACSStringVectorBase(const CPACSStringVectorBase&);
            CPACSStringVectorBase& operator=(const CPACSStringVectorBase&);
            #endif
        };
    }
    
    // Aliases in tigl namespace
    // CPACSStringVectorBase is customized, use type CCPACSStringVector directly
}