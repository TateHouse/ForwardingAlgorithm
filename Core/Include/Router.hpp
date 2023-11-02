#pragma once

#include <vector>

#include "RouteMapping.hpp"
#include "RoutingTableLoader.hpp"

namespace Core {
/**
 * @class Router
 *
 * @brief A router that is able to get which port to forward given an IPv4 address.
 */
class Router final {
public:
    /**
     * @brief Construct a new Router instance.
     *
     * @param routingTableLoader A routing table loader.
     */
    explicit Router(const RoutingTableLoader& routingTableLoader);

public:
    /**
     * @brief Get the port to forward the given IPv4 address to.
     *
     * The port is determined by the longest prefix match.
     *
     * For each route mapping in the routing table, the subnet mask is applied to the destination address and the
     * route mapping's IP address using a bitwise AND operation. If the result is the same, the prefix length is
     * compared to the best prefix length match. If it is greater, the prefix length becomes the best prefix length
     * match and the route mapping's port becomes the best port match.
     *
     * @param destination The destination IPv4 address.
     *
     * @return The port to forward the given IPv4 address to.
     */
    [[nodiscard]] const unsigned int getForwardingPort(const IPv4& destination) const noexcept;

private:
    const std::vector<RouteMapping> routingTable;
};
}