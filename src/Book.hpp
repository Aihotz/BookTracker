#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include <vector>
#include "nlohmann/json.hpp"

#include "Property.hpp"

enum class ePossession
{
	NOT_IN_POSSESSION,
	IN_POSSESSION
};

enum class eReadStatus
{
	NOT_READ,
	WANT_TO_READ,
	READING,
	READ
};

struct Book
{
	std::string m_name;
	std::vector<std::string> m_authors;

	Property<eReadStatus> m_read_status;
	Property<ePossession> m_possession;

	std::vector<Property<eReadStatus>> m_additional_read_status;
	std::vector<Property<ePossession>> m_additional_possessions;

	std::vector<Property<int>> m_ratings;

	friend nlohmann::json& operator<< (nlohmann::json& j, const Book& book);
	friend const nlohmann::json& operator>> (const nlohmann::json& j, Book& book);
};

#endif