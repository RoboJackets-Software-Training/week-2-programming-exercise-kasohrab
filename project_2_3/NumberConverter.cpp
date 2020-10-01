#include "NumberConverter.h"

#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

/**
 * returns a number 0-15 based off of a hex char
 * This uses ascii to figure out number it corresponds to
 * @param input
 * @return
 */
int NumberConverter::hexCharToNumber(char input) {
  // this means it is [A,B,C,D,E,F]
  if(input > 57) {
    return input - (65 - 10);
  } else {
    // this is a digit in ascii
    return input - 48;
  }
}

/**
 * returns the character that is the given hex number
 * only valid on 0-15
 * @param input
 * @return
 */
char NumberConverter::numberToHexChar(int input) {
  if(input < 10) {
    // it is a digit
    return input + 48;
  } else {
    return (input - 10) + 65;
  }
}

std::vector<double> NumberConverter::readInVector(std::string s) {
  int prev_location = 0;
  int next_location = 0;
  std::vector<double> result;
  while(s.find(',', prev_location) != std::string::npos) {
    next_location = s.find(',', prev_location);
    //std::cout << "prev_location: " << prev_location << std::endl;
    //std::cout << "next_location: " << next_location << std::endl;
    // substr [,]
    //std::cout << s.substr(prev_location, next_location - prev_location) << std::endl;
    result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
    next_location++;
    prev_location = next_location;
  }
  result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
  return result;
}

int NumberConverter::binaryToDecimal(std::string input) {
  int total = 0;
  for (int i = 0; i < input.length(); i++) {
    total += pow(input.at(i) * 2, i);
  }
  return total;
}
int NumberConverter::hexToDecimal(std::string input) {
  int total = 0;
  for (int i = 0; i < input.length(); i++) {
    total += hexCharToNumber(input.at(i)) * pow(16, i);
  }
  return total;
}

std::string NumberConverter::decimalToHex(int input) {
  std::string temp;
  int test = 0;
  std::string hexString;
  do {
    temp = std::to_string((input % 16));
    hexString.append(temp);
    input /= 16;
    if (input < 16) {
      test++;
    }
  }
  while (input % 16 > 16 && test == 0);

  return std::reverse(hexString.begin(), hexString.end());
}

std::string NumberConverter::binaryToHex(std::string input) {
  std::string hexString;
  int addZeros = input.length() % 4;
  if (addZeros != 0) {
    for(int i = 0; i <= addZeros; i++) {
      input.append("0");
    }
  }
  int index = 0;
  while (index < input.length()) {
    hexString.append(decimalToHex(binaryToDecimal(input.substr(index, index + 3))));
    index += 4;
  }

  return std::reverse(hexString.begin(), hexString.end());
}
