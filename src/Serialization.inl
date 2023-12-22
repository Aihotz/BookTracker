#ifndef SERIALIZATION_INL
#define SERIALIZATION_INL

template <class T>
nlohmann::json& operator<< (nlohmann::json& j, const std::optional<T>& optional)
{
	int has_value = static_cast<int>(optional.has_value());
	j["has_value"] = has_value;

	if (static_cast<bool>(has_value))
		j << optional.value();

	return j;
}

template <class T>
const nlohmann::json& operator>> (const nlohmann::json& j, std::optional<T>& optional)
{
	int has_value = j["has_value"];

	optional.reset();
	if (static_cast<bool>(has_value))
	{
		T value;
		j >> value;
		optional = value;
	}

	return j;
}

template <class T>
nlohmann::json& operator<< (nlohmann::json& j, const std::vector<T>& list)
{
	for (const T& element : list)
	{
		nlohmann::json local_j{};
		local_j << element;

		j.push_back(local_j);
	}

	return j;
}

template <class T>
const nlohmann::json& operator>> (const nlohmann::json& j, std::vector<T>& list)
{
	list.clear();

	for (const auto& element_j : j)
	{
		T local_element{};
		element_j >> local_element;

		list.push_back(local_element);
	}

	return j;
}

nlohmann::json& operator<< (nlohmann::json& j, const std::string& str)
{
	j = str;

	return j;
}

const nlohmann::json& operator>> (const nlohmann::json& j, std::string& str)
{
	str = j;

	return j;
}

#endif