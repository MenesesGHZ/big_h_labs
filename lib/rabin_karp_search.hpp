#pragma once

#define d 256

#include <tuple>
#include <vector>
#include <string>
#include <cstring>
#include "utils.hpp"

namespace rabin_karp {
  typedef std::vector<std::tuple<int, int>> my_tuple;
  my_tuple search(const char*, const char*, int);
}

//typedef std::vector<std::tuple<int, int>> my_tuple rabin_karp(char* palabra, char* linea, int numero_linea);