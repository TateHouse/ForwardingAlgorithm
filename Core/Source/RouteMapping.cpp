#include "RouteMapping.hpp"

#include <sstream>
#include <stdexcept>

#include "Utility/StringUtility.hpp"

namespace Core {
RouteMapping::RouteMapping(const IPv4& ip, uint8_t prefixLength, const unsigned int port)
        : ip {ip}, prefixLength {prefixLength}, subnetMask {calculateSubnetMask()}, port {port} {

}

const bool RouteMapping::operator==(const RouteMapping& other) const noexcept {
    return ip == other.ip && prefixLength == other.prefixLength && subnetMask == other.subnetMask && port == other.port;
}

std::ostream& operator<<(std::ostream& outputStream, const RouteMapping& routeMapping) noexcept {
    const auto& address {routeMapping.getIp().getAddress()};

    outputStream << "IPv4 (Binary): " << Utility::StringUtility::getBinaryString(address, true) << '\n';
    outputStream << "IPv4 (Decimal): " << Utility::StringUtility::getDecimalString(address, true) << '\n';
    outputStream << "Prefix Length: " << static_cast<int>(routeMapping.getPrefixLength()) << '\n';
    outputStream << "Subnet Mask (Binary): " << routeMapping.getSubnetMaskInBinary(true) << '\n';
    outputStream << "Port: " << routeMapping.getPort();

    return outputStream;
}

const std::bitset<32>& RouteMapping::getSubnetMask() const noexcept {
    return subnetMask;
}

const std::string RouteMapping::getSubnetMaskInBinary(const bool includeOctetSeparators) const noexcept {
    std::ostringstream subnetMaskStream {};

    for (auto octetIndex {3}; octetIndex >= 0; --octetIndex) {
        for (auto bitIndex {7}; bitIndex >= 0; --bitIndex) {
            const auto index {bitIndex + (octetIndex * 8)};
            subnetMaskStream << subnetMask[index];
        }

        if (octetIndex > 0 && includeOctetSeparators) {
            subnetMaskStream << ' ';
        }
    }

    return subnetMaskStream.str();
}

const IPv4& RouteMapping::getIp() const noexcept {
    return ip;
}

const uint8_t RouteMapping::getPrefixLength() const noexcept {
    return prefixLength;
}

const unsigned int RouteMapping::getPort() const noexcept {
    return port;
}

const std::bitset<32> RouteMapping::calculateSubnetMask() const {
    if (static constexpr auto maxPrefixLength {32}; prefixLength > maxPrefixLength) {
        throw std::invalid_argument {"Invalid Prefix: Prefix length must be in the range [0, 32]"};
    }

    std::bitset<32> subnetMask {};

    static constexpr auto lastBitIndex {31};
    for (auto bitIndex {0}; bitIndex < prefixLength; ++bitIndex) {
        subnetMask[lastBitIndex - bitIndex] = true;
    }

    return subnetMask;
}

}