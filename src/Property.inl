/*
    File:    Property.inl
    Author:  Aihotz Arruti
    Created: December 21, 2023
    
    Brief:   Implementation of the JSON serialization functions
	of the templated class Property<T>
*/

#ifndef PROPERTY_INL
#define PROPERTY_INL

// forward declaration for functions in Serialization.hpp

// std::optional
template <class T> nlohmann::json& operator<< (nlohmann::json& j, const std::optional<T>& optional);
template <class T> const nlohmann::json& operator>> (const nlohmann::json& j, std::optional<T>& optional);

// std::vector
template <class T> nlohmann::json& operator<< (nlohmann::json& j, const std::vector<T>& list);
template <class T> const nlohmann::json& operator>> (const nlohmann::json& j, std::vector<T>& list);

// std::string
nlohmann::json& operator<< (nlohmann::json& j, const std::string& str);
const nlohmann::json& operator>> (const nlohmann::json& j, std::string& str);

// save serialization function for the Property<T> data structure
template <class T>
nlohmann::json& operator<< (nlohmann::json& j, const Property<T>& property)
{
	// store data as an int
	j["value"] = static_cast<int>(property.m_property);

	j["note"] << property.m_note;
	j["date"] << property.m_date;

	return j;
}

// load serialization function for the Property<T> data structure
template <class T>
const nlohmann::json& operator>> (const nlohmann::json& j, Property<T>& property)
{
	// read data as an int and cast it
	int property_value = j["value"];
	property.m_property = static_cast<T>(property_value);

	j["note"] >> property.m_note;
	j["date"] >> property.m_date;

	return j;
}

#endif