#include "gmock/gmock.h"

#include "RoutingTableLoader.hpp"

namespace Core::Test {
class MockRoutingTableLoader : public Core::RoutingTableLoader {
public:
    MOCK_METHOD(const std::vector<RouteMapping>, load, (), (const, override));
};
}