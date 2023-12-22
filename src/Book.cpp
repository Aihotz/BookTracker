#include "Book.hpp"
#include "Serialization.hpp"

nlohmann::json& operator<< (nlohmann::json& j, const Book& book)
{
	// name
	j["name"] << book.m_name;

	// authors
	j["authors"] << book.m_authors;

	// read status
	j["read_status"] << book.m_read_status;
	j["additional_read_status"] << book.m_additional_read_status;

	// possession
	j["possession"] << book.m_possession;
	j["additional_possessions"] << book.m_additional_possessions;

	// ratings
	j["ratings"] << book.m_ratings;

	return j;
}

const nlohmann::json& operator>> (const nlohmann::json& j, Book& book)
{
	// name
	j["name"] >> book.m_name;

	// authors
	j["authors"] >> book.m_authors;

	// read status
	j["read_status"] >> book.m_read_status;
	j["additional_read_status"] >> book.m_additional_read_status;

	// possession
	j["possession"] >> book.m_possession;
	j["additional_possessions"] >> book.m_additional_possessions;

	// ratings
	j["ratings"] >> book.m_ratings;

	return j;
}