#include <gmock/gmock.h>

#include "RouteMapping.hpp"

namespace Core::Test {
class RouteMappingTest : public testing::Test {
public:
    RouteMappingTest() noexcept = default;
    ~RouteMappingTest() noexcept override = default;

protected:
    RouteMapping routeMapping {IPv4 {"152.20.192.0"}, 19, 2};
};

TEST_F(RouteMappingTest, WhenGetSubnetMask_ThenReturnsExpectedSubnetMask) {
    const auto subnetMask {routeMapping.getSubnetMask()};
    const auto expectedSubnetMask {std::bitset<32> {"11111111111111111110000000000000"}};

    EXPECT_THAT(subnetMask, testing::Eq(expectedSubnetMask));
}
}