#pragma once

#include <filesystem>

#include "ForwardedPortsWriter.hpp"
#include "IPv4.hpp"

namespace Core {
/**
 * @class TextForwardedPortsWriter
 *
 * @brief Writes forwarded ports to a text file.
 */
class TextForwardedPortsWriter : public ForwardedPortsWriter {
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
    virtual ~TextForwardedPortsWriter() = default;

public:
    virtual void write() const override;

private:
    const std::filesystem::path path;
    const std::vector<std::pair<IPv4, unsigned int>> forwardedPorts;
};
}