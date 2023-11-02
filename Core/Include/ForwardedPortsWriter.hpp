#pragma once

namespace Core {
/**
 * @class ForwardedPortsWriter
 *
 * @brief This class is an interface for writing forwarded ports.
 */
class ForwardedPortsWriter {
public:
    virtual ~ForwardedPortsWriter() = default;

public:
    /**
     * @brief Writes the forwarded ports.
     */
    virtual void write() const = 0;
};
}