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

TEST_F(IPv4Test, WhenGetAddressInBinaryWithoutOctetSeparators_ThenReturnsBinaryStringWithoutOctetSeparators) {
    const std::string expected {"10011000000101001100000000000000"};

    EXPECT_THAT(ip.getAddressInBinary(false), testing::Eq(expected));
}

TEST_F(IPv4Test, WhenGetAddressInBinaryWithOctetSeparators_ThenReturnsBinaryStringWithOctetSeparators) {
    const std::string expected {"10011000 00010100 11000000 00000000"};

    EXPECT_THAT(ip.getAddressInBinary(true), testing::Eq(expected));
}
}