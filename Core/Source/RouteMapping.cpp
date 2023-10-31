#include "RouteMapping.hpp"

#include <stdexcept>

namespace Core {
RouteMapping::RouteMapping(const IPv4& ip, uint8_t prefixLength, const unsigned int port)
        : ip {ip}, prefixLength {prefixLength}, port {port} {
    static constexpr auto maxPrefixLength {32};

    if (prefixLength > maxPrefixLength) {
        throw std::invalid_argument {"Invalid Prefix: Prefix length must be in the range [0, 32]"};
    }
}

const std::bitset<32> RouteMapping::getSubnetMask() const noexcept {
    std::bitset<32> subnetMask;

    static constexpr auto lastBitIndex {31};
    for (auto bitIndex {0}; bitIndex < prefixLength; ++bitIndex) {
        subnetMask[lastBitIndex - bitIndex] = true;
    }

    return subnetMask;
}

const IPv4& RouteMapping::getIp() const noexcept {
    return ip;
}

uint8_t RouteMapping::getPrefixLength() const noexcept {
    return prefixLength;
}

uint8_t RouteMapping::getPort() const noexcept {
    return port;
}
}