#pragma once

#include <stdint.h>
#include <vector>

enum class stone
{
	EMPTY,
	WHITE,
	BLACK
};

typedef std::vector<std::vector<stone>> board;