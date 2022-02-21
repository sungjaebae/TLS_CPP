
#pragma once
#include<string>
#include<istream>
#include<vector>
#include<json/json.h>
#include<gmpxx.h>

std::string base64_encode(std::vector<unsigned char> v);
std::vector<unsigned char> base64_decode(std::string s);