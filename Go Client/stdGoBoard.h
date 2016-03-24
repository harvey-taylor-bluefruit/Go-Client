#pragma once

#include <stdint.h>
#include <vector>

typedef unsigned char stone;

#define white (1)
#define black (2)
#define empty (0)

typedef std::vector<std::vector<stone>> board;

struct coordinate
{
	uint8_t x;
	uint8_t y;
};
