#pragma once

#include <vector>

#include "RouteMapping.hpp"

namespace Core {
/**
 * @class RoutingTableLoader
 *
 * @brief An interface for loading routing table.
 */
class RoutingTableLoader {
public:
    virtual ~RoutingTableLoader() = default;

public:
    /**
     * @brief Loads routing table.
     *
     * @return A vector of route mappings which is the routing table.
     */
    [[nodiscard]] virtual const std::vector<RouteMapping> load() const = 0;
};
}