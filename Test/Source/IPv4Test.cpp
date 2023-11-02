#include <gmock/gmock.h>

#include "IPv4.hpp"

namespace Core::Test {
class IPv4Test : public ::testing::Test {
public:
    IPv4Test() = default;
    ~IPv4Test() override = default;

protected:
    IPv4 ip {"152.20.192.0"};
};

TEST_F(IPv4Test, GivenValidIPv4String_WhenConstruct_ThenConvertsStringToBinary) {
    const std::bitset<32> expected {0b10011000'00010100'11000000'00000000};

    EXPECT_THAT(ip.getAddress(), testing::Eq(expected));
}

TEST_F(IPv4Test, GivenIPv4StringWithTooFewOctetSeparators_WhenConstruct_ThenThrowsInvalidArgument) {
    EXPECT_THROW(IPv4 {"152.20.192"}, std::invalid_argument);
}

TEST_F(IPv4Test, GivenIPv4StringWithTooManyOctets_WhenConstruct_ThenThrowsInvalidArgument) {
    EXPECT_THROW(IPv4 {"152.20.192.20.0"}, std::invalid_argument);
}

TEST_F(IPv4Test, GivenIPv4StringWithOctetWithTooManyDigits_WhenConstruct_ThenThrowsInvalidArgument) {
    EXPECT_THROW(IPv4 {"152.20.192.0000"}, std::invalid_argument);
}

TEST_F(IPv4Test, GivenIPv4StringWithOctetWithTooFewDigits_WhenConstruct_ThenThrowsInvalidArgument) {
    EXPECT_THROW(IPv4 {"152.20..192"}, std::invalid_argument);
}

TEST_F(IPv4Test, GivenIPv4StringWithOctetGreaterThanTwoHundredFiftyFive_WhenConstruct_ThenThrowsInvalidArgument) {
    EXPECT_THROW(IPv4 {"152.20.192.300"}, std::invalid_argument);
}

TEST_F(IPv4Test, GivenTwoEqualIPv4_WhenCompare_ThenReturnsTrue) {
    const IPv4 other {"152.20.192.0"};

    EXPECT_THAT(ip, testing::Eq(other));
}

TEST_F(IPv4Test, GivenTwoNonEqualIPv4_WhenCompare_ThenReturnsFalse) {
    const IPv4 other {"65.0.0.0"};

    EXPECT_THAT(ip, testing::Ne(other));
}
}