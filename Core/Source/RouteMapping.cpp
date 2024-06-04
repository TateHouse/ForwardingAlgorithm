#include "RouteMapping.hpp"

#include <sstream>
#include <stdexcept>

#include "Utility/StringUtility.hpp"

namespace Core
{
RouteMapping::RouteMapping(const IPv4& ip, uint8_t prefixLength, const unsigned int port) :
	ip{ip},
	prefixLength{prefixLength},
	subnetMask{CalculateSubnetMask()},
	port{port}
{
}

std::ostream& operator<<(std::ostream& outputStream, const RouteMapping& routeMapping) noexcept
{
	const auto& address{routeMapping.GetIP().GetAddress()};

	outputStream << "IPv4 (Binary): " << Utility::StringUtility::GetBinaryString(address, true) << '\n';
	outputStream << "IPv4 (Decimal): " << Utility::StringUtility::GetDecimalString(address, true) << '\n';
	outputStream << "Prefix Length: " << static_cast<int>(routeMapping.GetPrefixLength()) << '\n';
	outputStream << "Subnet Mask (Binary): " << routeMapping.GetSubnetMaskInBinary(true) << '\n';
	outputStream << "Port: " << routeMapping.GetPort();

	return outputStream;
}

const std::bitset<32>& RouteMapping::GetSubnetMask() const noexcept
{
	return subnetMask;
}

std::string RouteMapping::GetSubnetMaskInBinary(const bool includeOctetSeparators) const noexcept
{
	std::ostringstream subnetMaskStream{};

	for (auto octetIndex{3}; octetIndex >= 0; --octetIndex)
	{
		for (auto bitIndex{7}; bitIndex >= 0; --bitIndex)
		{
			const auto index{bitIndex + (octetIndex * 8)};
			subnetMaskStream << subnetMask[index];
		}

		if (octetIndex > 0 && includeOctetSeparators)
		{
			subnetMaskStream << ' ';
		}
	}

	return subnetMaskStream.str();
}

const IPv4& RouteMapping::GetIP() const noexcept
{
	return ip;
}

uint8_t RouteMapping::GetPrefixLength() const noexcept
{
	return prefixLength;
}

unsigned int RouteMapping::GetPort() const noexcept
{
	return port;
}

std::bitset<32> RouteMapping::CalculateSubnetMask() const
{
	if (static constexpr auto maxPrefixLength{32}; prefixLength > maxPrefixLength)
	{
		throw std::invalid_argument{"Invalid Prefix: Prefix length must be in the range [0, 32]"};
	}

	std::bitset<32> subnetMask{};

	static constexpr auto lastBitIndex{31};
	for (auto bitIndex{0}; bitIndex < prefixLength; ++bitIndex)
	{
		subnetMask[lastBitIndex - bitIndex] = true;
	}

	return subnetMask;
}
}
