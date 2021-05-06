#pragma once
#include "parameters.h"
#include <optional>

struct ParseResult {
  optional<Parameters> result;
  optional<string> error;
};

ParseResult parse(int arg_count, vector<string> args);
  