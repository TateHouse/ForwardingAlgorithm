#include "TextIPv4Loader.hpp"

#include <fstream>
#include <sstream>
#include <string>

#include "Utility/PathUtility.hpp"

namespace Core {
TextIPv4Loader::TextIPv4Loader(const std::filesystem::path& path) :
        path {Utility::PathUtility::validatePath(path, ".txt")} {

}

const std::vector<IPv4> TextIPv4Loader::load() const {
    std::ifstream fileStream {path};
    std::string line {};

    if (!fileStream.is_open()) {
        throw std::filesystem::filesystem_error {"Text IPv4 Loader: Failed to open file.",
                                                 path,
                                                 std::make_error_code(std::errc::io_error)};
    }

    if (fileStream.peek() == std::ifstream::traits_type::eof()) {
        return {};
    }

    std::vector<IPv4> ipAddresses {};

    while (std::getline(fileStream, line)) {
        if (line.empty()) {
            continue;
        }

        std::istringstream lineStream {line};
        std::string address {};

        std::getline(lineStream, address);

        ipAddresses.emplace_back(address);
    }

    return ipAddresses;
}
}