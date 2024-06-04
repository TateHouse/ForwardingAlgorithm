#include "Commands/GetForwardingPortsCommand.hpp"

#include <algorithm>
#include <random>

#include "Utility/StringUtility.hpp"
#include "TextIPv4Loader.hpp"

namespace Console::Commands
{
GetForwardingPortsCommand::GetForwardingPortsCommand(Context& context) noexcept:
	ICommand{context}
{
}

void GetForwardingPortsCommand::Execute()
{
	try
	{
		std::cout
		<< "Enter the path to the text file containing the IPv4 addresses to forward (must contain .txt extension): ";
		std::string path{};
		std::cin >> path;

		std::unique_ptr<Core::IIPv4Loader> loader{std::make_unique<Core::TextIPv4Loader>(path)};
		auto addresses{loader->Load()};

		std::cout << "Do you want to shuffle the addresses loaded from the file? (y/n): ";
		std::string shuffleInput{};
		std::cin >> shuffleInput;

		while (shuffleInput != "y" && shuffleInput != "n")
		{
			std::cout << "Invalid input. Please enter either y or n: ";
			std::cin >> shuffleInput;
		}

		if (shuffleInput == "y")
		{
			std::random_device randomDevice{};
			std::mt19937 randomEngine{randomDevice()};
			std::ranges::shuffle(addresses, randomEngine);
		}
		else
		{
			std::cout << "The addresses loaded from the file will not be shuffled." << '\n';
		}

		std::vector<unsigned int> ports{};
		for (const auto& address : addresses)
		{
			const auto port{context.GetRouter()->GetForwardingPort(address)};
			ports.emplace_back(port);
			context.AddForwardedPort(address, port);
		}

		std::cout << "Ports: " << '\n';
		for (const auto& port : ports)
		{
			std::cout << port << '\n';
		}
	}
	catch (std::invalid_argument& exception)
	{
		std::cout << Core::Utility::StringUtility::GetSecondaryHeaderBar() << '\n';
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

std::string GetForwardingPortsCommand::GetName() const noexcept
{
	return "ports";
}

std::string GetForwardingPortsCommand::GetDescription() const noexcept
{
	return "Gets the ports to forward the given IPv4 addresses from a text file to.";
}
}
