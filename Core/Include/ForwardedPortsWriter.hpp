#pragma once

namespace Core {
class ForwardedPortsWriter {
public:
    virtual ~ForwardedPortsWriter() = default;

public:
    virtual void write() const = 0;
};
}