/**
 * @author rayzhang
 * @brief
 * @date 2024-03-19
 */
#include "RyRegularExpresson.h"

#include <iostream>
#include <ostream>

namespace ry
{
RyRegularExpressionMatch::RyRegularExpressionMatch(const std::smatch& matches)
    : m_matches(matches)
{ }

size_t RyRegularExpressionMatch::count() const
{
    return m_matches.size();
}

std::string RyRegularExpressionMatch::at(size_t index) const
{
    return m_matches[index].str();
}

std::string RyRegularExpressionMatch::captured(size_t index) const
{
    return at(index);
}

std::string RyRegularExpressionMatch::operator[](size_t index) const
{
    return m_matches[index].str();
}

std::vector<std::string> RyRegularExpressionMatch::capturedTexts() const
{
    std::vector<std::string> capturedTexts;

    // 从1开始，因为matches[0]包含的是整个匹配的字符串
    for (size_t i = 1; i < m_matches.size(); ++i) {
        // 添加捕获的文本到结果vector中
        capturedTexts.push_back(m_matches[i].str());
    }

    return capturedTexts;
}

bool RyRegularExpressionMatch::hasMatch() const
{
    return !m_matches.empty();
}

RyRegularExpression::RyRegularExpression(const std::string& pattern, int flags)
    : m_regex(pattern, static_cast<std::regex_constants::syntax_option_type>(flags) | std::regex_constants::icase)
{ }

void RyRegularExpression::setPattern(const std::string& pattern)
{
    m_regex = std::regex(pattern, m_regex.flags());
}

RyRegularExpressionMatch RyRegularExpression::match(const std::string& text) const
{
    std::smatch matches;
    try {
        std::regex_match(text, matches, m_regex);
    }
    catch (...) {
        handleException();
    }
    return RyRegularExpressionMatch(matches);
}

RyRegularExpressionMatch RyRegularExpression::search(const std::string& text) const
{
    std::smatch matches;
    try {
        std::regex_search(text, matches, m_regex);
    }
    catch (...) {
        handleException();
    }
    return RyRegularExpressionMatch(matches);
}

std::string RyRegularExpression::replace(const std::string& text, const std::string& replacement) const
{
    try {
        return std::regex_replace(text, m_regex, replacement);
    }
    catch (...) {
        handleException();
    }
    return text;
}

std::vector<std::string> RyRegularExpression::split(const std::string& text) const
{
    try {
        return std::vector<std::string>{std::sregex_token_iterator(text.begin(), text.end(), m_regex, -1), std::sregex_token_iterator()};
    }
    catch (...) {
        handleException();
    }
    return {};
}

std::string RyRegularExpression::remove(const std::string& text) const
{
    return replace(text, "");
}

void RyRegularExpression::handleException()
{
    try {
        throw;
    }
    catch (const std::regex_error& e) {
        std::cerr << "Regex error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error" << std::endl;
    }
}
} // namespace ry
