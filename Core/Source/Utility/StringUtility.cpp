#include "Utility/StringUtility.hpp"

#include <sstream>

namespace Core::Utility {
const std::string StringUtility::getBinaryString(const std::bitset<32>& bitset,
                                                 const bool includeOctetSeparators) noexcept {
    std::ostringstream stringStream {};

    for (auto octetIndex {3}; octetIndex >= 0; --octetIndex) {
        for (auto bitIndex {7}; bitIndex >= 0; --bitIndex) {
            const auto index {bitIndex + (octetIndex * 8)};
            stringStream << bitset[index];
        }

        if (octetIndex > 0 && includeOctetSeparators) {
            stringStream << ' ';
        }
    }

    return stringStream.str();
}

const std::string StringUtility::getDecimalString(const std::bitset<32>& bitset,
                                                  const bool includeOctetSeparators) noexcept {
    std::ostringstream stringStream {};

    for (auto octetIndex {3}; octetIndex >= 0; --octetIndex) {
        auto octetDecimal {0};

        for (auto bitIndex {0}; bitIndex < 8; ++bitIndex) {
            const auto index {bitIndex + (octetIndex * 8)};

            if (bitset[index]) {
                octetDecimal |= (1 << bitIndex);
            }
        }

        stringStream << octetDecimal;

        if (octetIndex > 0 && includeOctetSeparators) {
            stringStream << '.';
        }
    }

    return stringStream.str();
}

const std::string StringUtility::getHeaderBar() noexcept {
    std::string headerBar {};

    for (auto index {0}; index < headerBarWidth; ++index) {
        headerBar += headerBarCharacter;
    }

    return headerBar;
}
}