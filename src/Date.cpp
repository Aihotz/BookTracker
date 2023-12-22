#include "Date.hpp"

nlohmann::json& operator<< (nlohmann::json& j, const Date& date)
{
	j["day"] = date.day;
	j["month"] = date.month;
	j["year"] = date.year;

	return j;
}

const nlohmann::json& operator>> (const nlohmann::json& j, Date& date)
{
	date.day = j["day"];
	date.month = j["month"];
	date.year = j["year"];  

	return j;
}