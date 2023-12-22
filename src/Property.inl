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

template <class T>
nlohmann::json& operator<< (nlohmann::json& j, const Property<T>& property)
{
	j["value"] = static_cast<int>(property.m_property);
	j["note"] << property.m_note;
	j["date"] << property.m_date;

	return j;
}

template <class T>
const nlohmann::json& operator>> (const nlohmann::json& j, Property<T>& property)
{
	int property_value = j["value"];
	property.m_property = static_cast<T>(property_value);

	j["note"] >> property.m_note;
	j["date"] >> property.m_date;

	return j;
}

#endif