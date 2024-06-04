#include "Application.hpp"

#include <iostream>

#include "Utility/StringUtility.hpp"

namespace Console
{
void Application::Initialize() noexcept
{
	std::cout << Core::Utility::StringUtility::GetPrimaryHeaderBar() << '\n';
	std::cout << "Forwarding Algorithm" << '\n';
	std::cout << Core::Utility::StringUtility::GetPrimaryHeaderBar() << '\n';
	std::cout << "Please enter 'help' for a list of commands." << '\n';
}

void Application::Update() const noexcept
{
	std::cout << Core::Utility::StringUtility::GetPrimaryHeaderBar() << '\n';

	std::cout << "Please enter a command: ";
	std::string input{};
	std::cin >> input;

	if (const auto result{commandRepository.Execute(input)}; !result)
	{
		std::cout << "Invalid command. Please enter 'help' for a list of commands." << '\n';
	}

	std::cout << Core::Utility::StringUtility::GetPrimaryHeaderBar() << '\n';
}

void Application::Shutdown() noexcept
{
	std::cout << Core::Utility::StringUtility::GetPrimaryHeaderBar() << '\n';
	std::cout << "Shutting down..." << '\n';
	std::cout << Core::Utility::StringUtility::GetPrimaryHeaderBar() << '\n';
}

[[nodiscard]] bool Application::GetIsRunning() const noexcept
{
	return context.GetIsRunning();
}
}
