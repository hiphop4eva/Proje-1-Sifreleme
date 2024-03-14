#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include <Windows.h>
#include <ShObjIdl.h>

std::wstring widenString(const std::string& as);
std::string narrowenString(const std::wstring& as);

namespace vieg {

	std::string sifrele(std::string& metin, std::string& sifre, std::string& alfabe);
	std::string sifreCozumu(std::string& metin, std::string& sifre, std::string& alfabe);
	int bul(std::string& alfabe, char aranan);

}

class Ceasar {
public:
	std::string metin;
	std::string sifrelimetin;
	std::string desifrelimetin;
	const char* alfabe = "abcdefghijklmnopqrstuvwxyz";
	int kayma = 3;

	void sifrele();
	void desifrele();
};