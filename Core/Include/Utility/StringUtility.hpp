#pragma once

#include <bitset>
#include <string>

namespace Core::Utility {
/**
 * @class StringUtility
 *
 * @brief Provides utility functions for strings.
 */
class StringUtility final {
public:
    StringUtility() noexcept = delete;
    ~StringUtility() noexcept = delete;

public:
    /**
     * @brief Converts a bitset to a binary string.
     *
     * @param bitset The bitset to convert.
     * @param includeOctetSeparators Whether or not to include octet separators.
     *
     * @return The binary string.
     */
    static const std::string getBinaryString(const std::bitset<32>& bitset, const bool includeOctetSeparators) noexcept;

    /**
     * @brief Converts a bitset to a decimal string.
     *
     * @param bitset The bitset to convert.
     * @param includeOctetSeparators Whether or not to include octet separators.
     *
     * @return The decimal string.
     */
    static const std::string getDecimalString(const std::bitset<32>& bitset,
                                              const bool includeOctetSeparators) noexcept;

    static const std::string getHeaderBar() noexcept;

private:
    static constexpr std::size_t headerBarWidth {50};
    static constexpr char headerBarCharacter {'='};
};
}