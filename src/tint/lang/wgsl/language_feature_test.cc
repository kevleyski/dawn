// Copyright 2023 The Dawn & Tint Authors
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its
//    contributors may be used to endorse or promote products derived from
//    this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

////////////////////////////////////////////////////////////////////////////////
// File generated by 'tools/src/cmd/gen' using the template:
//   src/tint/lang/wgsl/language_feature_test.cc.tmpl
//
// To regenerate run: './tools/run gen'
//
//                       Do not modify this file directly
////////////////////////////////////////////////////////////////////////////////

#include "src/tint/lang/wgsl/language_feature.h"

#include <gtest/gtest.h>

#include <string>

#include "src/tint/utils/text/string.h"

namespace tint::wgsl {
namespace {

namespace parse_print_tests {

struct Case {
    const char* string;
    LanguageFeature value;
};

inline std::ostream& operator<<(std::ostream& out, Case c) {
    return out << "'" << std::string(c.string) << "'";
}

static constexpr Case kValidCases[] = {
    {"chromium_testing_experimental", LanguageFeature::kChromiumTestingExperimental},
    {"chromium_testing_shipped", LanguageFeature::kChromiumTestingShipped},
    {"chromium_testing_shipped_with_killswitch",
     LanguageFeature::kChromiumTestingShippedWithKillswitch},
    {"chromium_testing_unimplemented", LanguageFeature::kChromiumTestingUnimplemented},
    {"chromium_testing_unsafe_experimental", LanguageFeature::kChromiumTestingUnsafeExperimental},
    {"packed_4x8_integer_dot_product", LanguageFeature::kPacked4X8IntegerDotProduct},
    {"pointer_composite_access", LanguageFeature::kPointerCompositeAccess},
    {"readonly_and_readwrite_storage_textures",
     LanguageFeature::kReadonlyAndReadwriteStorageTextures},
    {"sized_binding_array", LanguageFeature::kSizedBindingArray},
    {"texel_buffers", LanguageFeature::kTexelBuffers},
    {"texture_sample_level_1d", LanguageFeature::kTextureSampleLevel1D},
    {"unrestricted_pointer_parameters", LanguageFeature::kUnrestrictedPointerParameters},
};

static constexpr Case kInvalidCases[] = {
    {"chccomium_esting_experimental", LanguageFeature::kUndefined},
    {"cr3mium_testlg_experimentl", LanguageFeature::kUndefined},
    {"cVromium_testing_experimental", LanguageFeature::kUndefined},
    {"1hromium_testing_shipped", LanguageFeature::kUndefined},
    {"chromium_testing_hJpqqed", LanguageFeature::kUndefined},
    {"cllromium_te77ting_shipped", LanguageFeature::kUndefined},
    {"chromippm_testing_sHHipped_with_kqqlswitch", LanguageFeature::kUndefined},
    {"chromicm_esting_shippvd_with_kilsitch", LanguageFeature::kUndefined},
    {"chrbmium_testing_shGpped_wih_killswitch", LanguageFeature::kUndefined},
    {"chromium_testing_iinimplemevted", LanguageFeature::kUndefined},
    {"chromiumWWtesting_unimp8emented", LanguageFeature::kUndefined},
    {"chxxoium_tMsting_unimplemented", LanguageFeature::kUndefined},
    {"chXggmium_testing_unsafe_expermental", LanguageFeature::kUndefined},
    {"Xhomiuu_testng_unsafe_experimental", LanguageFeature::kUndefined},
    {"chromium_3esting_unsafe_experimental", LanguageFeature::kUndefined},
    {"packed_4x8_integer_Eot_product", LanguageFeature::kUndefined},
    {"paked_4x8_integePP_dTTt_product", LanguageFeature::kUndefined},
    {"packed_4x8_integxxrdot_pddoduct", LanguageFeature::kUndefined},
    {"44ointer_composite_access", LanguageFeature::kUndefined},
    {"VVSSinter_composite_access", LanguageFeature::kUndefined},
    {"poinR2er_compRsite_acess", LanguageFeature::kUndefined},
    {"readonlF_and_readwrite_st9rage_textues", LanguageFeature::kUndefined},
    {"readonly_and_radwrite_storage_textures", LanguageFeature::kUndefined},
    {"readonly_and_readwrite_sOOrage_tVxRRures", LanguageFeature::kUndefined},
    {"sized_indiyg_array", LanguageFeature::kUndefined},
    {"llGznnd_bin77ing_rrrray", LanguageFeature::kUndefined},
    {"sized_bindin4_00rray", LanguageFeature::kUndefined},
    {"teool_bffer", LanguageFeature::kUndefined},
    {"exezz_uffers", LanguageFeature::kUndefined},
    {"texel_bii11eps", LanguageFeature::kUndefined},
    {"textXXre_sample_level_1d", LanguageFeature::kUndefined},
    {"texnnure99samIIle_level_155", LanguageFeature::kUndefined},
    {"texaSSurre_sample_lHHvel_Yd", LanguageFeature::kUndefined},
    {"unkkestrictd_poiter_parameter", LanguageFeature::kUndefined},
    {"jnrestricted_pRinter_paramtgrs", LanguageFeature::kUndefined},
    {"unrestrbted_ponter_parameters", LanguageFeature::kUndefined},
};

using LanguageFeatureParseTest = testing::TestWithParam<Case>;

TEST_P(LanguageFeatureParseTest, Parse) {
    const char* string = GetParam().string;
    LanguageFeature expect = GetParam().value;
    EXPECT_EQ(expect, ParseLanguageFeature(string));
}

INSTANTIATE_TEST_SUITE_P(ValidCases, LanguageFeatureParseTest, testing::ValuesIn(kValidCases));
INSTANTIATE_TEST_SUITE_P(InvalidCases, LanguageFeatureParseTest, testing::ValuesIn(kInvalidCases));

using LanguageFeaturePrintTest = testing::TestWithParam<Case>;

TEST_P(LanguageFeaturePrintTest, Print) {
    LanguageFeature value = GetParam().value;
    const char* expect = GetParam().string;
    EXPECT_EQ(expect, ToString(value));
}

INSTANTIATE_TEST_SUITE_P(ValidCases, LanguageFeaturePrintTest, testing::ValuesIn(kValidCases));

}  // namespace parse_print_tests

}  // namespace
}  // namespace tint::wgsl
