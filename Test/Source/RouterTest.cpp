#include <gmock/gmock.h>

#include "MockRouterTableLoader.hpp"
#include "Router.hpp"

namespace Core::Test {
class RouterTest : public testing::Test {
public:
    RouterTest() noexcept = default;
    ~RouterTest() noexcept override = default;

protected:
    MockRoutingTableLoader mockRoutingTableLoader;
};

TEST_F(RouterTest, WhenGetForwardingPortAndOnlyOneDestinationMatches_ThenReturnsForwardingPort) {
    std::vector<RouteMapping> routingTable {
            RouteMapping {IPv4 {"192.168.1.0"}, 24, 2},
            RouteMapping {IPv4 {"192.168.2.0"}, 24, 3}
    };

    EXPECT_CALL(mockRoutingTableLoader, load()).WillOnce(testing::Return(routingTable));

    const auto router {Router {mockRoutingTableLoader}};
    const auto forwardingPort {router.getForwardingPort(IPv4 {"192.168.2.0"})};

    EXPECT_THAT(forwardingPort, testing::Eq(3));
}

TEST_F(RouterTest, WhenGetForwardingPortAndMultipleDestinationsMatch_ThenReturnsForwardingPortOfLongestMatch) {
    std::vector<RouteMapping> routingTable {
            RouteMapping {IPv4 {"192.168.0.0"}, 16, 2},
            RouteMapping {IPv4 {"192.168.1.0"}, 24, 3}
    };

    EXPECT_CALL(mockRoutingTableLoader, load()).WillOnce(testing::Return(routingTable));

    const auto router {Router {mockRoutingTableLoader}};
    const auto forwardingPort {router.getForwardingPort(IPv4 {"192.168.1.1"})};

    EXPECT_THAT(forwardingPort, testing::Eq(3));
}

TEST_F(RouterTest, WhenGetForwardingPortAndNoDestinationMatches_ThenReturnsDefaulPort) {
    std::vector<RouteMapping> routingTable {
            RouteMapping {IPv4 {"192.168.1.0"}, 24, 2},
            RouteMapping {IPv4 {"192.168.2.0"}, 24, 3}
    };

    EXPECT_CALL(mockRoutingTableLoader, load()).WillOnce(testing::Return(routingTable));

    const auto router {Router {mockRoutingTableLoader}};
    const auto forwardingPort {router.getForwardingPort(IPv4 {"192.168.3.1"})};

    EXPECT_THAT(forwardingPort, testing::Eq(1));
}
}