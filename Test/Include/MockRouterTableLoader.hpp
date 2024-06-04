#pragma once

#include "gmock/gmock.h"

#include "IRoutingTableLoader.hpp"

namespace Core::Test
{
class MockRoutingTableLoader : public Core::IRoutingTableLoader
{
public:
	MOCK_METHOD(std::vector<RouteMapping>, Load, (), (const, override));
};
}
