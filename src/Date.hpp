#ifndef DATE_HPP
#define DATE_HPP

#include "nlohmann/json.hpp"

struct Date
{
	int day;
	int month;
	int year;

	friend nlohmann::json& operator<< (nlohmann::json& j, const Date& date);
	friend const nlohmann::json& operator>> (const nlohmann::json& j, Date& date);
};

#endif