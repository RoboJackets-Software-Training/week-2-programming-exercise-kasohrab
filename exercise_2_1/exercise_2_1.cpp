#include <iostream>
#include <vector>
#include "convolution.h"

std::vector<double> readInVector(std::string s) {
  int prev_location = 0;
  int next_location = 0;
  std::vector<double> result;
  while(s.find(',', prev_location) != std::string::npos) {
    next_location = s.find(',', prev_location);
    result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
    next_location++;
    prev_location = next_location;
  }
  result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
  return result;
}


int main() {
  //take user input for vectors
  std::vector<double> x;
  std::vector<double> w;
  std::string s;
  std::cin >> s;
  if(s == "false") {
    bool pack_with_zeros = false;
  }
  std::cin >> s;
  x = readInVector(s);
  std::cin >> s;
  w = readInVector(s);

  //configured result
  applyConvolution(x,w,true);
  //oppposite
  applyConvolution(x,w,false);

  return 0;
}
