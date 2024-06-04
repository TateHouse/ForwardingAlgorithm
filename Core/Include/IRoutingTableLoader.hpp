#pragma once

#include <vector>

#include "RouteMapping.hpp"

namespace Core
{
/**
 * @class IRoutingTableLoader
 *
 * @brief An interface for loading routing table.
 */
class IRoutingTableLoader
{
public:
	IRoutingTableLoader() noexcept = default;
	IRoutingTableLoader(const IRoutingTableLoader& other) = default;
	IRoutingTableLoader(IRoutingTableLoader&& other) noexcept = default;
	virtual ~IRoutingTableLoader() noexcept = default;

public:
	IRoutingTableLoader& operator=(const IRoutingTableLoader& other) = default;
	IRoutingTableLoader& operator=(IRoutingTableLoader&& other) noexcept = default;

public:
	/**
	 * @brief Loads routing table.
	 *
	 * @return A vector of route mappings which is the routing table.
	 */
	[[nodiscard]] virtual std::vector<RouteMapping> Load() const = 0;
};
}
