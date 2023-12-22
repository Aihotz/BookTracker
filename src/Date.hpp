/*
    File:    Date.hpp
    Author:  Aihotz Arruti
    Created: December 21, 2023
    
    Brief:   A data structure used to represent a date
*/

#ifndef DATE_HPP
#define DATE_HPP

// serialization
#include "nlohmann/json.hpp"

struct Date
{
	int day;
	int month;
	int year;

	// serialization
	friend nlohmann::json& operator<< (nlohmann::json& j, const Date& date);
	friend const nlohmann::json& operator>> (const nlohmann::json& j, Date& date);
};

#endif