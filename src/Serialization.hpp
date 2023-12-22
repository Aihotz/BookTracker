#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <optional>
#include <vector>
#include <string>
#include "nlohmann/json.hpp"

// std::optional
template <class T> nlohmann::json& operator<< (nlohmann::json& j, const std::optional<T>& optional);
template <class T> const nlohmann::json& operator>> (const nlohmann::json& j, std::optional<T>& optional);

// std::vector
template <class T> nlohmann::json& operator<< (nlohmann::json& j, const std::vector<T>& list);
template <class T> const nlohmann::json& operator>> (const nlohmann::json& j, std::vector<T>& list);

// std::string
nlohmann::json& operator<< (nlohmann::json& j, const std::string& str);
const nlohmann::json& operator>> (const nlohmann::json& j, std::string& str);

#include "Serialization.inl"

#endif