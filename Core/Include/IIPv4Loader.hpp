#pragma once

#include <vector>

#include "IPv4.hpp"

namespace Core
{
/**
 * @class IIPv4Loader
 *
 * @brief An interface for loading IPv4 addresses.

 */
class IIPv4Loader
{
public:
	IIPv4Loader() noexcept = default;
	IIPv4Loader(const IIPv4Loader& other) = default;
	IIPv4Loader(IIPv4Loader&& other) noexcept = default;
	virtual ~IIPv4Loader() noexcept = default;

public:
	IIPv4Loader& operator=(const IIPv4Loader& other) = default;
	IIPv4Loader& operator=(IIPv4Loader&& other) noexcept = default;

public:
	/**
	 * @brief Loads IPv4 addresses.
	 *
	 * @return A vector of IPv4 addresses.
	 */
	[[nodiscard]] virtual std::vector<IPv4> Load() const = 0;
};
}
