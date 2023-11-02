#pragma once

#include <vector>

#include "IPv4.hpp"

namespace Core {
class IPv4Loader {
public:
    virtual ~IPv4Loader() = default;

public:
    [[nodiscard]] virtual const std::vector<IPv4> load() const = 0;
};
}