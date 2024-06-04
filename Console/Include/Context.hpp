#pragma once

#include <memory>
#include <vector>
#include <utility>

#include "IPv4.hpp"
#include "Router.hpp"
#include "IRoutingTableLoader.hpp"

namespace Console
{
/**
 * @class Context
 *
 * @brief A class that holds the shared state of the application.
 */
class Context final
{
public:
	Context() = default;
	Context(const Context& other) = delete;
	Context(Context&& other) noexcept = default;
	~Context() noexcept = default;

public:
	Context& operator=(const Context& other) = delete;
	Context& operator=(Context&& other) noexcept = default;

public:
	[[nodiscard]] bool GetIsRunning() const noexcept;
	void SetIsNotRunning() noexcept;
	[[nodiscard]] const std::unique_ptr<Core::Router>& GetRouter() const;
	void SetRouter(const Core::IRoutingTableLoader& routingTableLoader) noexcept;
	void AddForwardedPort(const Core::IPv4& ip, const unsigned int port) noexcept;
	[[nodiscard]] const std::vector<std::pair<Core::IPv4, unsigned int>>& GetForwardedPorts() const noexcept;

private:
	bool isRunning{true};
	std::unique_ptr<Core::Router> router{nullptr};
	std::vector<std::pair<Core::IPv4, unsigned int>> routedPorts{};
};
}
