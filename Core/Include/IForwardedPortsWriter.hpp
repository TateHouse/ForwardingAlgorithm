#pragma once

namespace Core
{
/**
 * @class IForwardedPortsWriter
 *
 * @brief This class is an interface for writing forwarded ports.
 */
class IForwardedPortsWriter
{
public:
	IForwardedPortsWriter() noexcept = default;
	IForwardedPortsWriter(const IForwardedPortsWriter& other) = default;
	IForwardedPortsWriter(IForwardedPortsWriter&& other) noexcept = default;
	virtual ~IForwardedPortsWriter() noexcept = default;

public:
	IForwardedPortsWriter& operator=(const IForwardedPortsWriter& other) = default;
	IForwardedPortsWriter& operator=(IForwardedPortsWriter&& other) noexcept = default;

public:
	/**
	 * @brief Writes the forwarded ports.
	 */
	virtual void Write() const = 0;
};
}
