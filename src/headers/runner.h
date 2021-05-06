#pragma once
#include "parameters.h"
#include <map>

typedef void (*Command)(Parameters);

void execute(Parameters);


