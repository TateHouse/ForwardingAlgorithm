#pragma once

#include <filesystem>

#include "ForwardedPortsWriter.hpp"
#include "IPv4.hpp"

namespace Core {
class TextForwardedPortsWriter : public ForwardedPortsWriter {
public:
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