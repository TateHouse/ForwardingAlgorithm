#pragma once

#include <bitset>
#include <iostream>

namespace Core {
/**
 * @class IPv4
 *
 * @brief Stores an IPv4 address.
 */
class IPv4 final {
public:
    /**
     * @brief Constructs a new IPv4 address.
     *
     * @param address The IPv4 address as a string in the format "xxx.xxx.xxx.xxx".
     *
     * An address is invalid if it does not contain three octet separators, a '.' character, if it contains more
     * than four octets, or if any octet is empty or contains more than three digits.
     *
     * @throws std::invalid_argument If the address is invalid.
     */
    explicit IPv4(const std::string& address);

public:
    [[nodiscard]] const bool operator==(const IPv4& other) const noexcept;
    [[nodiscard]] const std::bitset<32> operator&(const std::bitset<32>& other) const noexcept;

public:
    [[nodiscard]] const std::bitset<32>& getAddress() const;

private:
    /**
     * @brief Parses an IPv4 address from a string into a bitset.
     *
     * @param address The IPv4 address as a string in the format "xxx.xxx.xxx.xxx".
     *
     * @return The address as a bitset.
     */
    static const std::bitset<32> parse(const std::string& address);

private:
    std::bitset<32> address;
};
}