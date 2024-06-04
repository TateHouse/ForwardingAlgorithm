#pragma once

#include <bitset>
#include <iostream>

#include "IPv4.hpp"

namespace Core
{
/**
 * @class RouteMapping
 *
 * @brief A class that represents a routing table entry. The prefix length is used to calculate the subnet mask.
 */
class RouteMapping final
{
public:
	/**
	 * @brief Construct a new Route Mapping instance.
	 *
	 * @param ip An IPv4 address.
	 * @param prefixLength The prefix length.
	 * @param port The port.
	 */
	RouteMapping(const IPv4& ip, uint8_t prefixLength, const unsigned int port);
	RouteMapping(const RouteMapping& other) = default;
	RouteMapping(RouteMapping&& other) noexcept = default;
	~RouteMapping() noexcept = default;

public:
	RouteMapping& operator=(const RouteMapping& other) = default;
	RouteMapping& operator=(RouteMapping&& other) noexcept = default;
	[[nodiscard]] bool operator==(const RouteMapping& other) const noexcept = default;
	friend std::ostream& operator<<(std::ostream& os, const RouteMapping& routeMapping) noexcept;

public:
	[[nodiscard]] const std::bitset<32>& GetSubnetMask() const noexcept;
	[[nodiscard]] std::string GetSubnetMaskInBinary(const bool includeOctetSeparators) const noexcept;
	[[nodiscard]] const IPv4& GetIP() const noexcept;
	[[nodiscard]] uint8_t GetPrefixLength() const noexcept;
	[[nodiscard]] unsigned int GetPort() const noexcept;

private:
	/**
	 * @brief Calculates the subnet mask based on the prefix length.
	 *
	 * @return The subnet mask.
	 *
	 * @throws std::invalid_argument If the prefix length is invalid.
	 */
	[[nodiscard]] std::bitset<32> CalculateSubnetMask() const;

private:
	IPv4 ip;
	uint8_t prefixLength;
	std::bitset<32> subnetMask;
	unsigned int port;
};
}
