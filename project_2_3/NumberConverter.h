#include <iostream>
#include <vector>
#include <string>
#pragma once
using namespace std;
class NumberConverter {
public:

  vector<double> readInVector(std::string s);

  int hexCharToNumber(char input);

  char numberToHexChar(int input);
  int binaryToDecimal(std::string input);
  int hexToDecimal(std::string input);
  string decimalToHex(int input);
  string binaryToHex(std::string input);
};
