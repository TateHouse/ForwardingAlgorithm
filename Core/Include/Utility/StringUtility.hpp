#pragma once

#include <bitset>
#include <string>

namespace Core::Utility {
class StringUtility final {
public:
    StringUtility() noexcept = delete;
    ~StringUtility() noexcept = delete;

public:
    static const std::string getBinaryString(const std::bitset<32>& bitset, const bool includeOctetSeparators);
    static const std::string getDecimalString(const std::bitset<32>& bitset, const bool includeOctetSeparators);
};
}