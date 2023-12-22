#ifndef PROPERTY_HPP
#define PROPERTY_HPP

#include <string>
#include <optional>
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

#include "Property.inl"

#endif