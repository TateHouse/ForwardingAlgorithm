#include "Commands/GetForwardingPortCommand.hpp"

#include "Utility/StringUtility.hpp"
#include "IPv4.hpp"

namespace Console::Commands
{
GetForwardingPortCommand::GetForwardingPortCommand(Context& context) noexcept:
	ICommand{context}
{
}

void GetForwardingPortCommand::Execute() noexcept
{
	try
	{
		std::cout << "Enter the IPv4 address to forward: ";
		std::string addressInput{};
		std::cin >> addressInput;

		const Core::IPv4 address{addressInput};
		const auto port{context.GetRouter()->GetForwardingPort(address)};

		std::cout << "Port: " << port << '\n';
		context.AddForwardedPort(address, port);
	}
	catch (const std::invalid_argument& exception)
	{
		std::cout << Core::Utility::StringUtility::GetSecondaryHeaderBar() << '\n';
		std::cout << exception.what() << '\n';
		std::cout << Core::Utility::StringUtility::GetSecondaryHeaderBar() << '\n';
	}
	catch (const std::runtime_error& exception)
	{
		std::cout << Core::Utility::StringUtility::GetSecondaryHeaderBar() << '\n';
		std::cout << exception.what() << '\n';
		std::cout << Core::Utility::StringUtility::GetSecondaryHeaderBar() << '\n';
	}
}

std::string GetForwardingPortCommand::GetName() const noexcept
{
	return "port";
}

std::string GetForwardingPortCommand::GetDescription() const noexcept
{
	return "Gets the port to forward the given IPv4 address to.";
}
}
