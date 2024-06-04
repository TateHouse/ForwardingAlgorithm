#include "Router.hpp"

namespace Core
{
Router::Router(const Core::IRoutingTableLoader& routingTableLoader) :
	routingTable{routingTableLoader.Load()}
{
}

unsigned int Router::GetForwardingPort(const Core::IPv4& destination) const noexcept
{
	unsigned int bestPrefixLengthMatch{0};
	unsigned int bestPortMatch{1};

	for (const auto& routeMapping : routingTable)
	{
		const auto subnetMask{routeMapping.GetSubnetMask()};

		if ((destination & subnetMask) == (routeMapping.GetIP() & subnetMask))
		{
			const unsigned int prefixLength{routeMapping.GetPrefixLength()};

			if (prefixLength > bestPrefixLengthMatch)
			{
				bestPrefixLengthMatch = prefixLength;
				bestPortMatch = routeMapping.GetPort();
			}
		}
	}

	return bestPortMatch;
}
}
