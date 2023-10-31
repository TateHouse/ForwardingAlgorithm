#pragma once

#include <vector>

#include "RouteMapping.hpp"
#include "RoutingTableLoader.hpp"

namespace Core {
class Router final {
public:
    explicit Router(const RoutingTableLoader& routingTableLoader);

public:
    [[nodiscard]] const unsigned int getForwardingPort(const IPv4& destination) const;

private:
    const std::vector<RouteMapping> routingTable;
};
}