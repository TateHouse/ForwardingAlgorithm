#pragma once

#include <bitset>
#include <iostream>

#include "IPv4.hpp"

namespace Core {
/**
 * @class RouteMapping
 *
 * @brief A class that represents a routing table entry. The prefix length is used to calculate the subnet mask.
 */
class RouteMapping final {
public:
    /**
     * @brief Construct a new Route Mapping instance.
     *
     * @param ip An IPv4 address.
     * @param prefixLength The prefix length.
     * @param port The port.
     */
    RouteMapping(const IPv4& ip, uint8_t prefixLength, const unsigned int port);

public:
    [[nodiscard]] const bool operator==(const RouteMapping& other) const noexcept;
    friend std::ostream& operator<<(std::ostream& os, const RouteMapping& routeMapping) noexcept;

public:
    [[nodiscard]] const std::bitset<32>& getSubnetMask() const noexcept;
    [[nodiscard]] const std::string getSubnetMaskInBinary(const bool includeOctetSeparators) const noexcept;
    [[nodiscard]] const IPv4& getIp() const noexcept;
    [[nodiscard]] const uint8_t getPrefixLength() const noexcept;
    [[nodiscard]] const unsigned int getPort() const noexcept;

private:
    /**
     * @brief Calculates the subnet mask based on the prefix length.
     *
     * @return The subnet mask.
     *
     * @throws std::invalid_argument If the prefix length is invalid.
     */
    [[nodiscard]] const std::bitset<32> calculateSubnetMask() const;

private:
    const IPv4 ip;
    const uint8_t prefixLength;
    const std::bitset<32> subnetMask;
    const unsigned int port;
};
}