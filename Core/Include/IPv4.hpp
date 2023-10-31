#pragma once

#include <bitset>
#include <iostream>

namespace Core {
class IPv4 final {
public:
    explicit IPv4(const std::string& address);

public:
    [[nodiscard]] const std::bitset<32>& getAddress() const;

private:
    static const std::bitset<32> parse(const std::string& address);

private:
    const std::bitset<32> address;
};
}