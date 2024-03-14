#include "header.h"

std::wstring widenString(const std::string& as)
{
    if (as.empty())    return std::wstring();
    size_t reqLength = MultiByteToWideChar(CP_UTF8, 0, as.c_str(), (int)as.length(), 0, 0);
    std::wstring ret(reqLength, L'\0');

    MultiByteToWideChar(CP_UTF8, 0, as.c_str(), (int)as.length(), &ret[0], (int)ret.length());

    return ret;
}

std::string narrowenString(const std::wstring& as)
{
    if (as.empty())    return std::string();
    size_t reqLength = WideCharToMultiByte(CP_UTF8, 0, as.c_str(), (int)as.length(), 0, 0, 0, 0);
    std::string ret(reqLength, '\0');

    WideCharToMultiByte(CP_UTF8, 0, as.c_str(), (int)as.length(), &ret[0], (int)ret.length(), 0, 0);

    return ret;
}