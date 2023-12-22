/*
    File:    Serialization.hpp
    Author:  Aihotz Arruti
    Created: December 21, 2023
    
    Brief:   Several functions for serializing common data types.
    Data types include:
    - std::optional
    - std::vector
    - std::string
    - int
*/

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

// stl
#include <optional>
#include <vector>
#include <string>

// serialization
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

// int
nlohmann::json& operator<< (nlohmann::json& j, int value);
const nlohmann::json& operator>> (const nlohmann::json& j, int& value);

// templated implementation (std::optional, std::vector)
#include "Serialization.inl"

#endif