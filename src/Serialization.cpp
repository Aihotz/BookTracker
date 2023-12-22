/*
    File:    Serialization.cpp
    Author:  Aihotz Arruti
    Created: December 21, 2023
    
    Brief:   Implementation of the JSON serialization functions for
    common non-templated data types.
    Data types include:
    - std::string
*/

#include "Serialization.hpp"

// save serialization function for std::string
// operator= is defined, but operator<< is used for consistency
// with other templated data types (such as std::vector)
nlohmann::json& operator<<(nlohmann::json& j, const std::string& str)
{
    j = str;

    return j;
}

// load serialization function for std::string
// operator= is defined, but operator>> is used for consistency
// with other templated data types (such as std::vector)
const nlohmann::json& operator>>(const nlohmann::json& j, std::string& str)
{
    str = j;

    return j;
}