#include <gmock/gmock.h>

#include <filesystem>
#include <format>
#include <fstream>
#include <stdexcept>

#include "CSVRoutingTableLoader.hpp"
#include "Utility/StringUtility.hpp"

namespace Core::Test {
class CSVRoutingTableLoaderTest : public testing::Test {
public:
    CSVRoutingTableLoaderTest() = default;
    ~CSVRoutingTableLoaderTest() override;

protected:
    static const std::filesystem::path createTemporaryPathWithUniqueName(const std::string& name,
                                                                         const std::string& extension);

    const std::vector<RouteMapping> populateRoutingTableFile(const bool hasHeaderRow);

protected:
    std::filesystem::path path;
};

CSVRoutingTableLoaderTest::~CSVRoutingTableLoaderTest() {
    if (path.empty()) {
        return;
    }

    std::filesystem::remove(path);
}

const std::filesystem::path CSVRoutingTableLoaderTest::createTemporaryPathWithUniqueName(const std::string& name,
                                                                                         const std::string& extension) {
    const auto now {std::chrono::system_clock::now()};
    const auto nowMilliseconds {std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch())};
    const auto directory {std::filesystem::temp_directory_path()};

    if (extension.empty()) {
        const auto uniqueName {std::format("{}_{}", name, nowMilliseconds.count())};

        return directory / uniqueName;
    }

    const auto uniqueName {std::format("{}_{}.{}", name, nowMilliseconds.count(), extension)};

    return directory / uniqueName;
}

const std::vector<RouteMapping> CSVRoutingTableLoaderTest::populateRoutingTableFile(const bool hasHeaderRow) {
    path = CSVRoutingTableLoaderTest::createTemporaryPathWithUniqueName("Load", "csv");
    auto fileStream {std::ofstream {path}};

    if (hasHeaderRow) {
        const auto headerRow {"IPv4,Prefix Length,Port\n"};
        fileStream << headerRow;
    }

    const auto routeA {RouteMapping {IPv4 {"152.20.192.0"}, 19, 2}};
    const auto routeB {RouteMapping {IPv4 {"65.0.0.0"}, 8, 3}};
    const auto routeC {RouteMapping {IPv4 {"152.15.242.0"}, 23, 4}};

    std::vector routeMappings {routeA, routeB, routeC};

    for (const auto& routeMapping : routeMappings) {
        const auto ipString {Utility::StringUtility::getDecimalString(routeMapping.getIp().getAddress(), true)};
        const auto prefixLengthString {routeMapping.getPrefixLength()};
        const auto portString {routeMapping.getPort()};
        const auto routeMappingString {std::format("{},{},{}\n", ipString, prefixLengthString, portString)};

        fileStream << routeMappingString;
    }

    fileStream.close();

    return routeMappings;
}

TEST_F(CSVRoutingTableLoaderTest, GivenFileThatDoesNotExist_WhenConstruct_ThenThrowsInvalidArgument) {
    path = CSVRoutingTableLoaderTest::createTemporaryPathWithUniqueName("DoesNotExist", "csv");

    EXPECT_THROW(Core::CSVRoutingTableLoader(path, true), std::invalid_argument);
}

TEST_F(CSVRoutingTableLoaderTest, GivenFileThatIsNotRegularFile_WhenConstruct_ThenThrowsInvalidArgument) {
    path = CSVRoutingTableLoaderTest::createTemporaryPathWithUniqueName("IsNotRegularFile", "");

    EXPECT_THROW(Core::CSVRoutingTableLoader(path, true), std::invalid_argument);
}

TEST_F(CSVRoutingTableLoaderTest, GivenFileThatDoesNotHaveCSVExtension_WhenConstruct_ThenThrowsInvalidArgument) {
    path = CSVRoutingTableLoaderTest::createTemporaryPathWithUniqueName("DoesNotHaveCSVExtension", "txt");

    EXPECT_THROW(Core::CSVRoutingTableLoader(path, true), std::invalid_argument);
}

TEST_F(CSVRoutingTableLoaderTest, GivenEmptyFile_WhenLoad_ThenReturnsEmptyVector) {
    path = CSVRoutingTableLoaderTest::createTemporaryPathWithUniqueName("Empty", "csv");
    auto fileStream {std::ofstream {path}};

    fileStream.close();

    const auto csvRoutingTableLoader {Core::CSVRoutingTableLoader {path, true}};
    const auto loadedRouteMappings {csvRoutingTableLoader.load()};

    EXPECT_THAT(loadedRouteMappings, testing::IsEmpty());
}

TEST_F(CSVRoutingTableLoaderTest, GivenFileWithHeaderRow_WhenLoad_ThenReturnsVectorOfRouteMappings) {
    const auto expectedRouteMappings {populateRoutingTableFile(true)};
    const auto csvRoutingTableLoader {Core::CSVRoutingTableLoader {path, true}};
    const auto loadedRouteMappings {csvRoutingTableLoader.load()};

    EXPECT_THAT(loadedRouteMappings, testing::Eq(expectedRouteMappings));
}

TEST_F(CSVRoutingTableLoaderTest, GivenFileWithoutHeaderRow_WhenLoad_ThenReturnsVectorOfRouteMappings) {
    const auto expectedRouteMappings {populateRoutingTableFile(false)};
    const auto csvRoutingTableLoader {Core::CSVRoutingTableLoader {path, false}};
    const auto loadedRouteMappings {csvRoutingTableLoader.load()};

    EXPECT_THAT(loadedRouteMappings, testing::Eq(expectedRouteMappings));
}
}