/*
    File:    Date.cpp
    Author:  Aihotz Arruti
    Created: December 21, 2023
    
    Brief:   Implementation of the JSON serialization functions
	for the Date data structure
*/

#include "Date.hpp"

// save serialization for the Date data structure
nlohmann::json& operator<< (nlohmann::json& j, const Date& date)
{
	j["day"] = date.day;
	j["month"] = date.month;
	j["year"] = date.year;

	return j;
}

// load serialization for the Date data structure
const nlohmann::json& operator>> (const nlohmann::json& j, Date& date)
{
	date.day = j["day"];
	date.month = j["month"];
	date.year = j["year"];  

	return j;
}