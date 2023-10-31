#include "IPv4.hpp"

#include <sstream>
#include <stdexcept>

namespace Core {
IPv4::IPv4(const std::string& address) : address {parse(address)} {

}

const bool IPv4::operator==(const IPv4& other) const noexcept {
    return address == other.address;
}

const std::bitset<32>& IPv4::getAddress() const {
    return address;
}

const std::bitset<32> IPv4::parse(const std::string& address) {
    static constexpr auto octetSeparator {'.'};
    auto octetSeparatorCount {0};

    for (auto character : address) {
        if (character == octetSeparator) {
            ++octetSeparatorCount;
        }
    }

    if (static constexpr auto expectedOctetSeparatorCount {3}; octetSeparatorCount != expectedOctetSeparatorCount) {
        throw std::invalid_argument {
                "Invalid IPv4: There must be 3 octet separators, a '.' character, in the address."};
    }

    std::bitset<32> addressBits {};
    std::stringstream addressStream {address};
    std::string octet {};

    for (auto octetIndex {3}; octetIndex >= 0; --octetIndex) {
        if (!std::getline(addressStream, octet, octetSeparator)) {
            throw std::invalid_argument {"Invalid IPv4: There must be 4 octets in the address."};
        }

        if (octet.empty() || octet.length() > 3) {
            throw std::invalid_argument {"Invalid IPv4: Each octet must be 1 to 3 digits long."};
        }

        std::bitset<8> octetBits {static_cast<unsigned long long>(std::stoul(octet))};

        for (auto bitIndex {0}; bitIndex < 8; ++bitIndex) {
            const auto index {bitIndex + (octetIndex * 8)};
            addressBits[index] = octetBits[bitIndex];
        }
    }

    return addressBits;
}
}