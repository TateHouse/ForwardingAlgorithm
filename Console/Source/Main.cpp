#include "Application.hpp"

int main(int argc, char* argv[])
{
	Console::Application application{};
	Console::Application::Initialize();

	while (application.GetIsRunning())
	{
		application.Update();
	}

	Console::Application::Shutdown();

	return 0;
}
