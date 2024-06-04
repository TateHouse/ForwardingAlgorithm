#pragma once

#include <bitset>
#include <string>

namespace Core::Utility
{
/**
 * @class StringUtility
 *
 * @brief Provides utility functions for strings.
 */
class StringUtility final
{
public:
	StringUtility() noexcept = delete;
	StringUtility(const StringUtility& other) = delete;
	StringUtility(StringUtility&& other) noexcept = delete;
	~StringUtility() noexcept = delete;

public:
	StringUtility& operator=(const StringUtility& other) = delete;
	StringUtility& operator=(StringUtility&& other) noexcept = delete;

public:
	/**
	 * @brief Converts a bitset to a binary string.
	 *
	 * @param bitset The bitset to convert.
	 * @param includeOctetSeparators Whether or not to include octet separators.
	 *
	 * @return The binary string.
	 */
	static std::string GetBinaryString(const std::bitset<32>& bitset, const bool includeOctetSeparators) noexcept;

	/**
	 * @brief Converts a bitset to a decimal string.
	 *
	 * @param bitset The bitset to convert.
	 * @param includeOctetSeparators Whether or not to include octet separators.
	 *
	 * @return The decimal string.
	 */
	static std::string GetDecimalString(const std::bitset<32>& bitset, const bool includeOctetSeparators) noexcept;

	static std::string GetPrimaryHeaderBar() noexcept;
	static std::string GetSecondaryHeaderBar() noexcept;

private:
	static constexpr std::size_t primaryHeaderBarLength{50};
	static constexpr std::size_t secondaryHeaderBarLength{50};
	static constexpr char primaryHeaderBarCharacter{'='};
	static constexpr char secondaryHeaderBarCharacter{'-'};
};
}
