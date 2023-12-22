#include <vector>
#include <string>
#include <optional>
#include <iostream>
#include <fstream>

#include "nlohmann/json.hpp"
#include "Book.hpp"

int main(void)
{
	//Book simple_book;

	//simple_book.m_name = "1984";
	//simple_book.m_authors.push_back("George Orwell");

	//simple_book.m_read_status.m_property = eReadStatus::READ;
	//simple_book.m_read_status.m_note = "twice";
	//simple_book.m_read_status.m_date = Date{ 3,6,2002 };

	//simple_book.m_possession.m_property = ePossession::IN_POSSESSION;

	//Property<int> rating;
	//rating.m_property = 8;
	//simple_book.m_ratings.push_back(rating);


	//Property<eReadStatus> additional_read;
	//additional_read.m_property = eReadStatus::READ;
	//additional_read.m_note = "Read it again!";
	//simple_book.m_additional_read_status.push_back(additional_read);

	//Property<eReadStatus> want_to_read_yet_again;
	//want_to_read_yet_again.m_property = eReadStatus::WANT_TO_READ;
	//want_to_read_yet_again.m_note = "I want to read it yet again...";
	//simple_book.m_additional_read_status.push_back(want_to_read_yet_again);

	//nlohmann::json book_json;
	//book_json << simple_book;
	
	std::ifstream json_file("book.json");
	if (!json_file)
		return -1;
	
	nlohmann::json book_json;
	json_file >> book_json;
	
	json_file.close();

	Book book;
	book_json >> book;

	std::ofstream json_out("book2.json");
	if (!json_out)
		return -1;

	nlohmann::json book_json2;
	book_json2 << book;

	json_out << std::setw(4) << book_json2;

	json_out.close();

	return 0;
}