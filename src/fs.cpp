#include "headers/fs.h"
#include <fstream>
#include <filesystem>
#include <vector>

using namespace std;

namespace fs {
  void write_file(string file_name, string content) {
  ofstream file (file_name);
  file << content;
  file.close();
}

  string read_file(string file_name) {
    ifstream file;
    file.open(file_name); 
    stringstream strStream;
    strStream << file.rdbuf();
    return strStream.str();
  }

  void create_directories(string src) {
    std::filesystem::create_directories(src);
  };
}