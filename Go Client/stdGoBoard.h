#pragma once

#include <stdint.h>
#include <vector>

enum class stone
{
	empty,
	white,
	black
};

typedef std::vector<std::vector<stone>> board;