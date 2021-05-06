#include <iostream>
#include <fstream>
#include "headers/parser.h"
#include "headers/runner.h"
#include "headers/parameters.h"

using namespace std;

int main(int argc, char** argv) {
  std::vector<string> args;

  cout 
    << "You have entered " 
    << argc
    << " arguments:" 
    << "\n";

  for (int i = 0; i < argc; ++i) {
    args.push_back(argv[i]);
    cout 
      << i 
      << " " 
      << args[i] 
      << "\n";
  }

  ParseResult parsed = parse(argc, args);
  if (parsed.error != nullopt) {
    cout << parsed.error.value() << endl;
  } else {
    Parameters params = parsed.result.value();
    cout << "command: "<< params.command << endl;
    cout << "params: "<< endl;
    for (int i = 0; i < params.options.size(); ++i) {
      cout << " " << params.options[i] << endl;
    }
    execute(params);
  }

  return 0;
}
