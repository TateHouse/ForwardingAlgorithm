#pragma once

#include <vector>

#include "RouteMapping.hpp"

namespace Core {
class RoutingTableLoader {
public:
    virtual ~RoutingTableLoader() = default;

public:
    [[nodiscard]] virtual const std::vector<RouteMapping> load() const = 0;
};
}