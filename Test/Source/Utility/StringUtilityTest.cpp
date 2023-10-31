#include <gmock/gmock.h>

#include "Utility/StringUtility.hpp"

namespace Core::Utility::Test {
class StringUtilityTest : public testing::Test {
public:
    StringUtilityTest() noexcept = default;
    ~StringUtilityTest() noexcept override = default;

protected:
    std::bitset<32> bitset {"10011000000101001100000000000000"};
};

TEST_F(StringUtilityTest, WhenGetBinaryStringWithOctetSeparators_ThenReturnsExpectedString) {
    const std::string expected {"10011000 00010100 11000000 00000000"};

    EXPECT_THAT(StringUtility::getBinaryString(bitset, true), testing::Eq(expected));
}

TEST_F(StringUtilityTest, WhenGetBinaryStringWithoutOctetSeparators_ThenReturnsExpectedString) {
    const std::string expected {"10011000000101001100000000000000"};

    EXPECT_THAT(StringUtility::getBinaryString(bitset, false), testing::Eq(expected));
}

TEST_F(StringUtilityTest, WhenGetDecimalStringWithOctetSeparators_ThenReturnsExpectedString) {
    const std::string expected {"152.20.192.0"};

    EXPECT_THAT(StringUtility::getDecimalString(bitset, true), testing::Eq(expected));
}

TEST_F(StringUtilityTest, WhenGetDecimalStringWithoutOctetSeparators_ThenReturnsExpectedString) {
    const std::string expected {"152201920"};

    EXPECT_THAT(StringUtility::getDecimalString(bitset, false), testing::Eq(expected));
}
}