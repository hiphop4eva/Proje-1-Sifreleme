#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <Windows.h>
#include <ShObjIdl.h>

std::wstring widenString(const std::string& as);
std::string narrowenString(const std::wstring& as);

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