#pragma once

#include <list>

#include "OneMinuteBarDto.h"
#include "picojson.h"

class RateJsonParser
{
public:

	static std::list<OneMinuteBarDto> oneMinuteRateJsonParse(std::string &json);
};
