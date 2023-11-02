#include "Router.hpp"

namespace Core {
Router::Router(const Core::RoutingTableLoader& routingTableLoader) : routingTable {routingTableLoader.load()} {

}

const unsigned int Router::getForwardingPort(const Core::IPv4& destination) const noexcept {
    unsigned int bestPrefixLengthMatch {0};
    unsigned int bestPortMatch {1};

    for (const auto& routeMapping : routingTable) {
        const auto subnetMask {routeMapping.getSubnetMask()};

        if ((destination & subnetMask) == (routeMapping.getIp() & subnetMask)) {
            const unsigned int prefixLength {routeMapping.getPrefixLength()};

            if (prefixLength > bestPrefixLengthMatch) {
                bestPrefixLengthMatch = prefixLength;
                bestPortMatch = routeMapping.getPort();
            }
        }
    }

    return bestPortMatch;
}
}
