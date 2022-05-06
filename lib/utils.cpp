#include "utils.hpp"

std::string utils::read_file(const char* filename){
    std::fstream my_file;
    std::string text;
    my_file.open(filename, std::ios::in);
    if (!my_file) {
      std::cout << "No such file";
    }
    else {
      char ch;
      while (1) {
        ch = my_file.get();
        text += std::string(1, ch);
        if (my_file.eof())
          break;
      }

    }
    my_file.close();
    return text;
}
