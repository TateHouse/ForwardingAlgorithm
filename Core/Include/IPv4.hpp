#pragma once

#include <bitset>
#include <iostream>

namespace Core {
class IPv4 final {
public:
    explicit IPv4(const std::string& address);

public:
    [[nodiscard]] const bool operator==(const IPv4& other) const noexcept;
    [[nodiscard]] const std::bitset<32> operator&(const std::bitset<32>& other) const noexcept;

public:
    [[nodiscard]] const std::bitset<32>& getAddress() const;

private:
    static const std::bitset<32> parse(const std::string& address);

private:
    const std::bitset<32> address;
};
}