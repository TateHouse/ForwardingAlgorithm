#include "TextForwardedPortsWriter.hpp"

#include <fstream>

#include "Utility/PathUtility.hpp"
#include "Utility/StringUtility.hpp"

namespace Core {
TextForwardedPortsWriter::TextForwardedPortsWriter(const std::filesystem::path& file,
                                                   const std::vector<std::pair<IPv4, unsigned int>>& forwardedPorts) :
        path {Utility::PathUtility::createFile(file, file.extension().string())}, forwardedPorts {forwardedPorts} {

}

void TextForwardedPortsWriter::write() const {
    std::ofstream fileStream {path, std::ios::out};

    if (!fileStream.is_open()) {
        throw std::runtime_error {"Failed to open file " + path.string()};
    }
    fileStream << "==================================================" << '\n';
    fileStream << "Forwarded Ports" << '\n';
    fileStream << "==================================================" << '\n';

    for (const auto& forwardedPort : forwardedPorts) {
        const auto [ip, port] = forwardedPort;

        fileStream << "IPv4: " << Utility::StringUtility::getDecimalString(ip.getAddress(), true) << " Port: " << port
                   << '\n';
    }

    fileStream << "==================================================" << '\n';
}
}