#pragma once

#include <stdint.h>
#include <vector>

typedef unsigned char stone;

#define empty (0)
#define white (1)
#define black (2)

typedef std::vector<std::vector<stone>> board;