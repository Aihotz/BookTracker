/*
    File:    Book.cpp
    Author:  Aihotz Arruti
    Created: December 21, 2023
    
    Brief:   Implementation of the JSON serialization functions
	for the Book and SeriesPart data structures
*/

#include "Book.hpp"

// serialization of std::vector and std::string
#include "Serialization.hpp"

// save serialization for the SeriesPart data structure
nlohmann::json& operator<< (nlohmann::json& j, const SeriesPart& series)
{
    j["series_name"] << series.name;

	j["number_integral"] = series.number.integral_part;
    j["number_decimal"] << series.number.decimal_part;
}

// load serialization for the SeriesPart data structure
const nlohmann::json& operator>>(const nlohmann::json& j, SeriesPart& series)
{
    j["series_name"] >> series.name;

	series.number.integral_part = j["number_integral"];
    j["number_decimal"] >> series.number.decimal_part;
}

// save serialization for the Book data structure
nlohmann::json& operator<< (nlohmann::json& j, const Book& book)
{
	// name
	j["name"] << book.m_name;

	// authors
	j["authors"] << book.m_authors;

	// read status
	j["read_status"] << book.m_read_status;
	j["additional_read_status"] << book.m_additional_read_status;

	// possession
	j["possession"] << book.m_possession;
	j["additional_possessions"] << book.m_additional_possessions;

	// ratings
	j["ratings"] << book.m_ratings;

	return j;
}

// load serialization for the Book data structure
const nlohmann::json& operator>> (const nlohmann::json& j, Book& book)
{
	// name
	j["name"] >> book.m_name;

	// authors
	j["authors"] >> book.m_authors;

	// read status
	j["read_status"] >> book.m_read_status;
	j["additional_read_status"] >> book.m_additional_read_status;

	// possession
	j["possession"] >> book.m_possession;
	j["additional_possessions"] >> book.m_additional_possessions;

	// ratings
	j["ratings"] >> book.m_ratings;

	return j;
}