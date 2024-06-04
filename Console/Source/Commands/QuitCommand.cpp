#include "Commands/QuitCommand.hpp"

#include <iostream>
#include <memory>

#include "Utility/StringUtility.hpp"
#include "TextForwardedPortsWriter.hpp"

namespace Console::Commands
{
QuitCommand::QuitCommand(Context& context) noexcept:
	ICommand{context}
{
}

void QuitCommand::Execute()
{
	try
	{
		context.SetIsNotRunning();

		std::cout << "Do you want to save the forwarded ports? (y/n): ";
		char answer{};
		std::cin >> answer;

		if (answer != 'y')
		{
			return;
		}

		std::cout
		<< "Enter the path to the file where the forwarded ports will be saved (must contain .txt extension): ";
		std::string path{};
		std::cin >> path;

		std::unique_ptr<Core::IForwardedPortsWriter> forwardedPortsWriter{
			std::make_unique<Core::TextForwardedPortsWriter>(path, context.GetForwardedPorts())
		};

		forwardedPortsWriter->Write();
	}
	catch (const std::invalid_argument& exception)
	{
		std::cout << Core::Utility::StringUtility::GetSecondaryHeaderBar() << '\n';
		std::cout << exception.what() << '\n';
		std::cout << Core::Utility::StringUtility::GetSecondaryHeaderBar() << '\n';
	}
	catch (const std::filesystem::filesystem_error& exception)
	{
		std::cout << Core::Utility::StringUtility::GetSecondaryHeaderBar() << '\n';
		std::cout << exception.what() << '\n';
		std::cout << Core::Utility::StringUtility::GetSecondaryHeaderBar() << '\n';
	}
}

std::string QuitCommand::GetName() const noexcept
{
	return "quit";
}

std::string QuitCommand::GetDescription() const noexcept
{
	return "Quits the console application and allows the user to save the forwarded ports to a file.";
}
}
