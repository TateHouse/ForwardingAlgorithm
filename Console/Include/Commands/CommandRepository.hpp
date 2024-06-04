#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "ICommand.hpp"
#include "Context.hpp"

namespace Console::Commands
{
/**
 * @class CommandRepository
 *
 * @brief The repository of commands.
 */
class CommandRepository final
{
public:
	/**
	 * @brief Constructs a CommandRepository instance.
	 *
	 * @param context The shared application context.
	 */
	explicit CommandRepository(Context& context);
	CommandRepository(const CommandRepository& other) = default;
	CommandRepository(CommandRepository&& other) noexcept = default;
	~CommandRepository() noexcept = default;

public:
	CommandRepository& operator=(const CommandRepository& other) = delete;
	CommandRepository& operator=(CommandRepository&& other) noexcept = delete;

public:
	/**
	 * @brief Executes a command.
	 *
	 * @param command The command to execute.
	 */
	[[nodiscard]] bool Execute(const std::string_view command) const noexcept;

private:
	Context& context;
	std::unordered_map<std::string, std::unique_ptr<ICommand>> commands{};
};
}
