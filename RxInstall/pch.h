#pragma once

#include "framework.h"
#include <msi.h>
#include <msiquery.h>
#include <string>
#include <filesystem>

#pragma comment( lib , "msi.lib" )

#define MYDEBUGMODE

template <typename Out>
constexpr inline void split(const std::wstring& s, wchar_t delim, Out result) noexcept {
	std::wistringstream iss(s);
	std::wstring item;
	while (std::getline(iss, item, delim)) {
		*result++ = item;
	}
}

constexpr inline void split(const std::wstring& s, wchar_t delim, std::vector<std::wstring>& elems) noexcept {
	split(s, delim, std::back_inserter(elems));
}

constexpr inline void ltrim(std::wstring& s, wchar_t chr) noexcept {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [&](wchar_t ch) {
		return chr != ch;
		}));
}

constexpr inline void rtrim(std::wstring& s, wchar_t chr) noexcept {
	s.erase(std::find_if(s.rbegin(), s.rend(), [&](wchar_t ch) {
		return chr != ch;
		}).base(), s.end());
}

constexpr inline void trim(std::wstring& s, wchar_t chr) noexcept {
	ltrim(s, chr);
	rtrim(s, chr);
}
