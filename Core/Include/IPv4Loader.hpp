#pragma once

#include <vector>

#include "IPv4.hpp"

namespace Core {
/**
 * @class IPv4Loader
 *
 * @brief An interface for loading IPv4 addresses.

 */
class IPv4Loader {
public:
    virtual ~IPv4Loader() = default;

public:
    /**
     * @brief Loads IPv4 addresses.
     *
     * @return A vector of IPv4 addresses.
     */
    [[nodiscard]] virtual const std::vector<IPv4> load() const = 0;
};
}