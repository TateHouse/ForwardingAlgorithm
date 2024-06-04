#pragma once

#include "Commands/CommandRepository.hpp"

namespace Console
{
/**
 * @class Application
 *
 * @brief The console application.
 */
class Application final
{
public:
	Application() noexcept = default;
	Application(const Application& other) = delete;
	Application(Application&& other) noexcept = default;
	~Application() noexcept = default;

public:
	Application& operator=(const Application& other) = delete;
	Application& operator=(Application&& other) = delete;

public:
	/**
	 * @brief Initializes the application.
	 */
	static void Initialize() noexcept;

	/**
	 * @brief Runs the application.
	 */
	void Update() const noexcept;

	/**
	 * @brief Shuts down the application.
	 */
	static void Shutdown() noexcept;

	[[nodiscard]] bool GetIsRunning() const noexcept;

private:
	Context context{};
	Commands::CommandRepository commandRepository{context};
};
}
