/**
 * @author rayzhang
 * @brief
 * @date 2024-03-19
 */
#pragma once
#include <regex>

namespace ry
{
class RyRegularExpressionMatch
{
public:
    RyRegularExpressionMatch(const std::smatch& matches);

    // 返回捕获组的数量
    size_t count() const;

    // 返回指定捕获组的文本
    std::string at(size_t index) const;
    std::string captured(size_t index) const;
    std::string operator[](size_t index) const;

    // 返回所有捕获组的文本
    std::vector<std::string> capturedTexts() const;

    // 判断是否有匹配
    bool hasMatch() const;

private:
    std::smatch m_matches;
};

class RyRegularExpression
{
public:
    enum : int
    {
        CaseInsensitiveOption = std::regex_constants::icase,
        ECMAScript            = std::regex_constants::ECMAScript
    };

    // 构造函数，初始化正则表达式
    explicit RyRegularExpression(const std::string& pattern, int flags = std::regex_constants::ECMAScript); // 开启ECMAScript语法以及大小写不敏感选项

    // 设置正则表达式模式
    void setPattern(const std::string& pattern);

    // 匹配函数，返回一个包含所有捕获组的vector
    RyRegularExpressionMatch match(const std::string& text) const;

    // 搜索函数，返回一个包含所有捕获组的vector
    RyRegularExpressionMatch search(const std::string& text) const;

    // 替换函数，返回替换后的字符串
    std::string replace(const std::string& text, const std::string& replacement) const;

    // 分割函数，返回分割后的字符串
    std::vector<std::string> split(const std::string& text) const;

    // 移除
    std::string remove(const std::string& text) const;

    static void handleException();

private:
    std::regex m_regex; // 存储正则表达式对象
};
} // namespace ry
