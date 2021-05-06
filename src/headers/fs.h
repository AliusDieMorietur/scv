#pragma once
#include <string>

using namespace std;

namespace fs {
  void write_file(string file_name, string content);

  string read_file(string file_name);

  void create_directories(string src);
}
