#include "RateJsonParser.h"
#include <iostream>
#include <fstream>

std::list<OneMinuteBarDto> RateJsonParser::oneMinuteRateJsonParse(std::string &json)
{

	picojson::value jsonValue;
	picojson::array jsonArray;
	std::string err;

	// JSONÉpÅ[ÉX
	try {
		picojson::parse(jsonValue, json.begin(), json.end(), &err);
		if (err.empty()) throw 100;
		if (!jsonValue.is<picojson::object>()) throw 100;

		picojson::object jsonObj = jsonValue.get<picojson::object>();
		if (!jsonObj["quotes"].is<picojson::array>()) throw 100;

		jsonArray = jsonObj["quotes"].get<picojson::array>();
	}
	catch (int e) {
		throw e;
	}

	// DTOäiî[
	OneMinuteBarDto oneMinuteBarDto;
	std::list<OneMinuteBarDto> oneMinuteBarDtoList;

	picojson::array::reverse_iterator it;
	picojson::object jsonObj;
	for (it = jsonArray.rbegin(); it != jsonArray.rend(); it++) {
		if (!it->is<picojson::object>()) continue;

		jsonObj = it->get<picojson::object>();
		oneMinuteBarDto.setAsk(jsonObj["ask"].to_str());
		oneMinuteBarDto.setBid(jsonObj["bid"].to_str());
		oneMinuteBarDto.setHigh(jsonObj["high"].to_str());
		oneMinuteBarDto.setLow(jsonObj["low"].to_str());
		oneMinuteBarDto.setOpen(jsonObj["open"].to_str());

		oneMinuteBarDtoList.push_back(oneMinuteBarDto);
	}

	return oneMinuteBarDtoList;
}
