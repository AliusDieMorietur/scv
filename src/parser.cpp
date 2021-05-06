#include "headers/parser.h"
#include "headers/parameters.h"

using namespace std;

ParseResult parse(int arg_count, vector<string> args) {
  ParseResult parsed { Parameters { "new", vector<string> {}}, nullopt };
  if (arg_count == 1) return ParseResult { nullopt, "Not enough arguments" };
  else 
    return ParseResult { 
      Parameters { 
        args[1], 
        { args.begin() + 2, args.end() }
      },
      nullopt 
      };
};