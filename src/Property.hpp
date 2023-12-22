/*
    File:    Property.hpp
    Author:  Aihotz Arruti
    Created: December 21, 2023
    
    Brief:   A data structure that stores some data and then
	some additional user data: a user-defined note (string) and
	optionally a date.
*/

#ifndef PROPERTY_HPP
#define PROPERTY_HPP

// stl
#include <string>
#include <optional>

// serialization
#include "nlohmann/json.hpp"

#include "Date.hpp"

// we have to declare this so that the friend templated ones are specializations of these
template <class T> struct Property;
template <class T> nlohmann::json& operator<< (nlohmann::json& j, const Property<T>& property);
template <class T> const nlohmann::json& operator>> (const nlohmann::json& j, Property<T>& property);

template <class T>
struct Property
{
	T					m_property;
	std::string			m_note;
	std::optional<Date> m_date;

	friend nlohmann::json& operator<< <>(nlohmann::json& j, const Property<T>& property);
	friend const nlohmann::json& operator>> <>(const nlohmann::json& j, Property<T>& property);
};

// template implementation of Property<T>
#include "Property.inl"

#endif