#include "Commands/ICommand.hpp"

namespace Console::Commands
{
ICommand::ICommand(Console::Context& context) noexcept:
	context{context}
{
}
}
