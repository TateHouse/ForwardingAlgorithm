#pragma once

#include <filesystem>

#include "IForwardedPortsWriter.hpp"
#include "IPv4.hpp"

namespace Core
{
/**
 * @class TextForwardedPortsWriter
 *
 * @brief Writes forwarded ports to a text file.
 */
class TextForwardedPortsWriter : public IForwardedPortsWriter
{
public:
	/**
	 * @brief Construct a new TextForwardedPortsWriter instance.
	 *
	 * @param file The file to write to (will be created if it doesn't exist).
	 * @param forwardedPorts The forwarded ports to write.
	 *
	 * @throws std::invalid_argument If the extension is invalid.
	 * @throws std::filesystem::filesystem_error If the file could not be created or overridden.
	 */
	TextForwardedPortsWriter(const std::filesystem::path& file,
							 const std::vector<std::pair<IPv4, unsigned int>>& forwardedPorts);
	TextForwardedPortsWriter(const TextForwardedPortsWriter& other) = default;
	TextForwardedPortsWriter(TextForwardedPortsWriter&& other) noexcept = default;
	~TextForwardedPortsWriter() noexcept override = default;

public:
	TextForwardedPortsWriter& operator=(const TextForwardedPortsWriter& other) = default;
	TextForwardedPortsWriter& operator=(TextForwardedPortsWriter&& other) noexcept = default;

public:
	void Write() const override;

private:
	std::filesystem::path path;
	std::vector<std::pair<IPv4, unsigned int>> forwardedPorts;
};
}
