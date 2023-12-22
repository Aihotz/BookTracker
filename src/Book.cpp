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

#include <iostream>

void Book::Display() const
{
    std::cout << "Name: " << m_name << std::endl;

    std::cout << "Authors: ";
    for (std::vector<std::string>::const_iterator it = m_authors.begin(); it != m_authors.end(); it++)
    {
        if (it != m_authors.begin())
            std::cout << ", ";

        std::cout << *it;
    }
    std::cout << std::endl;

    for (const SeriesPart& series : m_series)
    {
        std::cout << "Part " << series.number.integral_part;
        if (series.number.decimal_part.has_value())
            std::cout << "." << series.number.decimal_part.value();

        std::cout << " of the series: " << series.name << std::endl;
    }

    std::cout << "Read status: ";
    switch (m_read_status.m_property)
    {
    case eReadStatus::NOT_READ:
        std::cout << "Not read" << std::endl;
        break;
    case eReadStatus::READ:
        std::cout << "Read" << std::endl;
        break;
    case eReadStatus::READING:
        std::cout << "Reading" << std::endl;
        break;
    case eReadStatus::WANT_TO_READ:
        std::cout << "Want to read" << std::endl;
        break;
    }
    if (m_read_status.m_note.empty() == false)
        std::cout << "Note: " << m_read_status.m_note << std::endl;
    if (m_read_status.m_date.has_value())
        std::cout << "Date: " << m_read_status.m_date.value().day << "/" << m_read_status.m_date.value().month << "/" << m_read_status.m_date.value().year << std::endl;

    for (const Property<eReadStatus>& read_status : m_additional_read_status)
    {
        std::cout << "Additional read status: ";
        switch (read_status.m_property)
        {
        case eReadStatus::NOT_READ:
            std::cout << "Not read" << std::endl;
            break;
        case eReadStatus::READ:
            std::cout << "Read" << std::endl;
            break;
        case eReadStatus::READING:
            std::cout << "Reading" << std::endl;
            break;
        case eReadStatus::WANT_TO_READ:
            std::cout << "Want to read" << std::endl;
            break;
        }

        if (read_status.m_note.empty() == false)
            std::cout << "Note: " << read_status.m_note << std::endl;
        if (read_status.m_date.has_value())
            std::cout << "Date: " << read_status.m_date.value().day << "/" << read_status.m_date.value().month << "/" << read_status.m_date.value().year << std::endl;
    }

    std::cout << "Possession: ";
    switch (m_possession.m_property)
    {
    case ePossession::NOT_IN_POSSESSION:
        std::cout << "Not in possession" << std::endl;
        break;
    case ePossession::IN_POSSESSION:
        std::cout << "In possession" << std::endl;
        break;
    case ePossession::DIGITAL_COPY:
        std::cout << "Digital Copy" << std::endl;
        break;
    }
    if (m_possession.m_note.empty() == false)
        std::cout << "Note: " << m_possession.m_note << std::endl;
    if (m_possession.m_date.has_value())
        std::cout << "Date: " << m_possession.m_date.value().day << "/" << m_possession.m_date.value().month << "/" << m_possession.m_date.value().year << std::endl;

    for (const Property<ePossession>& possession : m_additional_possessions)
    {
        std::cout << "Additional possession: ";
        switch (possession.m_property)
        {
        case ePossession::NOT_IN_POSSESSION:
            std::cout << "Not in possession" << std::endl;
            break;
        case ePossession::IN_POSSESSION:
            std::cout << "In possession" << std::endl;
            break;
        case ePossession::DIGITAL_COPY:
            std::cout << "Digital Copy" << std::endl;
            break;
        }
        if (possession.m_note.empty() == false)
            std::cout << "Note: " << possession.m_note << std::endl;
        if (possession.m_date.has_value())
            std::cout << "Date: " << possession.m_date.value().day << "/" << possession.m_date.value().month << "/" << possession.m_date.value().year << std::endl;
    }

    for (const Property<int>& rating : m_ratings)
    {
        std::cout << "Rating: " << rating.m_property << "/10" << std::endl;

        if (rating.m_note.empty() == false)
            std::cout << "Note: " << rating.m_note << std::endl;
        if (rating.m_date.has_value())
            std::cout << "Date: " << rating.m_date.value().day << "/" << rating.m_date.value().month << "/" << rating.m_date.value().year << std::endl;
    }
}

// save serialization for the SeriesPart data structure
nlohmann::json& operator<<(nlohmann::json& j, const SeriesPart& series)
{
    j["series_name"] << series.name;

    j["number_integral"] = series.number.integral_part;
    j["number_decimal"] << series.number.decimal_part;

    return j;
}

// load serialization for the SeriesPart data structure
const nlohmann::json& operator>>(const nlohmann::json& j, SeriesPart& series)
{
    j["series_name"] >> series.name;

    series.number.integral_part = j["number_integral"];
    j["number_decimal"] >> series.number.decimal_part;

    return j;
}

// save serialization for the Book data structure
nlohmann::json& operator<<(nlohmann::json& j, const Book& book)
{
    // name
    j["name"] << book.m_name;

    // authors
    j["authors"] << book.m_authors;

    // series
    j["series"] << book.m_series;

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
const nlohmann::json& operator>>(const nlohmann::json& j, Book& book)
{
    // name
    j["name"] >> book.m_name;

    // authors
    j["authors"] >> book.m_authors;

    // series
    j["series"] >> book.m_series;

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