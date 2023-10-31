#include <gmock/gmock.h>

#include <sstream>

#include "RouteMapping.hpp"

namespace Core::Test {
class RouteMappingTest : public testing::Test {
public:
    RouteMappingTest() noexcept = default;
    ~RouteMappingTest() noexcept override = default;

protected:
    RouteMapping routeMapping {IPv4 {"152.20.192.0"}, 19, 2};
};

TEST_F(RouteMappingTest, GivenIPv4AndPrefixLength_WhenConstruct_ThenReturnsExpectedSubnetMask) {
    const auto expectedSubnetMask {std::bitset<32> {"11111111111111111110000000000000"}};

    EXPECT_THAT(routeMapping.getSubnetMask(), testing::Eq(expectedSubnetMask));
}

TEST_F(RouteMappingTest, GivenPrefixGreaterThanThirtyTwo_WhenConstruct_ThenThrowsInvalidArgument) {
    const auto ip {IPv4 {"152.20.192.0"}};

    EXPECT_THROW(RouteMapping(ip, 33, 2), std::invalid_argument);
}

TEST_F(RouteMappingTest, WhenInsertionOperator_ThenReturnsExpectedString) {
    std::ostringstream resultStream {};
    resultStream << routeMapping;

    std::ostringstream expectedStream {};
    expectedStream << "IPv4 (Binary): 10011000 00010100 11000000 00000000" << '\n';
    expectedStream << "IPv4 (Decimal): 152.20.192.0" << '\n';
    expectedStream << "Prefix Length: 19" << '\n';
    expectedStream << "Subnet Mask (Binary): 11111111 11111111 11100000 00000000" << '\n';
    expectedStream << "Port: 2";

    EXPECT_THAT(resultStream.str(), testing::Eq(expectedStream.str()));
}
}