#pragma once

#include <bitset>

#include "IPv4.hpp"

namespace Core {
class RouteMapping final {
public:
    RouteMapping(const IPv4& ip, uint8_t prefixLength, const unsigned int port);

public:
    [[nodiscard]] const std::bitset<32> getSubnetMask() const noexcept;
    [[nodiscard]] const IPv4& getIp() const noexcept;
    [[nodiscard]] uint8_t getPrefixLength() const noexcept;
    [[nodiscard]] uint8_t getPort() const noexcept;

private:
    const IPv4 ip;
    const uint8_t prefixLength;
    const unsigned int port;
};
}