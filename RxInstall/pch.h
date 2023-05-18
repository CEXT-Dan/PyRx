#pragma once

#include "framework.h"
#include <msi.h>
#include <msiquery.h>
#include <string>
#include <filesystem>

template <typename Out>
constexpr inline void splitA(const std::string& s, char delim, Out result) noexcept {
	std::istringstream iss(s);
	std::string item;
	while (std::getline(iss, item, delim)) {
		*result++ = item;
	}
}

constexpr inline void splitA(const std::string& s, char delim, std::vector<std::string>& elems) noexcept {
	splitA(s, delim, std::back_inserter(elems));
}

constexpr inline void ltrim(std::string& s, char chr) noexcept {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [&](char ch) {
		return chr != ch;
		}));
}

constexpr inline void rtrim(std::string& s, char chr) noexcept {
	s.erase(std::find_if(s.rbegin(), s.rend(), [&](char ch) {
		return chr != ch;
		}).base(), s.end());
}

constexpr inline void trim(std::string& s, char chr) noexcept {
	ltrim(s, chr);
	rtrim(s, chr);
}