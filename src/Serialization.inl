/*
    File:    Serialization.inl
    Author:  Aihotz Arruti
    Created: December 21, 2023
    
    Brief:   Implementation of the JSON serialization functions
	for the templated data types.
	Data types include:
	- std::optional
	- std::vector
*/

#ifndef SERIALIZATION_INL
#define SERIALIZATION_INL

// save serialization function for std::optional
template <class T>
nlohmann::json& operator<< (nlohmann::json& j, const std::optional<T>& optional)
{
	// whether the std::optional has a value set
	int has_value = static_cast<int>(optional.has_value());
	j["has_value"] = has_value;

	// if the value is set, store it
	if (static_cast<bool>(has_value))
		j << optional.value();

	return j;
}

// load serialization function for std::optional
template <class T>
const nlohmann::json& operator>> (const nlohmann::json& j, std::optional<T>& optional)
{
	// whether there is a value stored
	int has_value = j["has_value"];

	// store the value inside the std::optional
	optional.reset();
	if (static_cast<bool>(has_value))
	{
		T value;
		j >> value;
		optional = value;
	}

	return j;
}

// save serialization function for std::vector
template <class T>
nlohmann::json& operator<< (nlohmann::json& j, const std::vector<T>& list)
{
	// loop on the elements of the std::vector
	for (const T& element : list)
	{
		// serialize each individual element
		nlohmann::json local_j{};
		local_j << element;
		
		// create a JSON array
		j.push_back(local_j);
	}

	return j;
}

// load serialization function for std::vector
template <class T>
const nlohmann::json& operator>> (const nlohmann::json& j, std::vector<T>& list)
{
	list.clear();

	// for each element in the JSON array
	for (const auto& element_j : j)
	{
		// extract each individual JSON element
		T local_element{};
		element_j >> local_element;

		// add each element to the std::vector
		list.push_back(local_element);
	}

	return j;
}

#endif