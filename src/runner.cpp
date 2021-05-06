#include "headers/runner.h"
#include "headers/fs.h"
#include "headers/utils.h"
#include <string>
#include <iostream>

string src_basic = 
  "#include <iostream>\n\n"
  "int main() {\n" 
  "  std::cout << \"Hello, world!\" << std::endl;\n"
  "}"; 

void create(Parameters params) {
  if (params.options.size() == 0) {
    cout << "[create]Not enough arguments" << endl;
    return;
  }
  string project = params.options.back();
  std::cout << project << endl;
  string src = project + "/src/";
  fs::create_directories(src);
  fs::write_file(project + "/config.txt", project + "\n17");
  fs::write_file(src + "/main.cpp", src_basic);
}

void run(Parameters params) {
  string content = fs::read_file("config.txt");
  vector<string> lines = utils::split_string(content);
  string command = "g++ -std=gnu++" + lines[1] + " src/*.cpp -o " + lines[0];
  cout << command << "\n";
  system(command.c_str());
}

map<string, Command> commands = {
  { "new", create },
  { "run", run }
};

void execute(Parameters params) {
  if (commands.count(params.command)) commands[params.command](params);
  else cout << "No such command" << "\n";
};