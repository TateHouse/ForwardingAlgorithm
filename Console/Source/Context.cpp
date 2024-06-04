#include "Context.hpp"

namespace Console
{
bool Context::GetIsRunning() const noexcept
{
	return isRunning;
}

void Context::SetIsNotRunning() noexcept
{
	isRunning = false;
}

const std::unique_ptr<Core::Router>& Context::GetRouter() const
{
	if (!router)
	{
		throw std::runtime_error{"The router has not been set"};
	}

	return router;
}

void Context::SetRouter(const Core::IRoutingTableLoader& routingTableLoader) noexcept
{
	router = std::make_unique<Core::Router>(routingTableLoader);
}

void Context::AddForwardedPort(const Core::IPv4& ip, const unsigned int port) noexcept
{
	routedPorts.emplace_back(ip, port);
}

const std::vector<std::pair<Core::IPv4, unsigned int>>& Context::GetForwardedPorts() const noexcept
{
	return routedPorts;
}
}
