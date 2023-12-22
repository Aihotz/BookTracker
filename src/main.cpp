#include <fstream>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

#include "Book.hpp"
#include "nlohmann/json.hpp"
#include "Journal.hpp"

void SimpleBook()
{
    Book simple_book;

    simple_book.m_name = "1984";
    simple_book.m_authors.push_back("George Orwell");
    simple_book.m_authors.push_back("Samantha Hudson");
    simple_book.m_authors.push_back("Margaret Thatcher");

    SeriesPart general_series {};
    general_series.name = "Oldies goldies";
    general_series.number.integral_part = 14;

    SeriesPart specific_series {};
    specific_series.name = "Apocaliptics";
    specific_series.number.integral_part = 3;
    specific_series.number.decimal_part  = 5;
    simple_book.m_series.push_back(general_series);
    simple_book.m_series.push_back(specific_series);

    simple_book.m_read_status.m_property = eReadStatus::READ;
    simple_book.m_read_status.m_note     = "twice";
    simple_book.m_read_status.m_date     = Date { 3, 6, 2002 };

    simple_book.m_possession.m_property = ePossession::IN_POSSESSION;

    Property<int> rating;
    rating.m_property = 8;
    simple_book.m_ratings.push_back(rating);

    Property<eReadStatus> additional_read;
    additional_read.m_property = eReadStatus::READ;
    additional_read.m_note     = "Read it again!";
    simple_book.m_additional_read_status.push_back(additional_read);

    Property<eReadStatus> want_to_read_yet_again;
    want_to_read_yet_again.m_property = eReadStatus::WANT_TO_READ;
    want_to_read_yet_again.m_note     = "I want to read it yet again...";
    simple_book.m_additional_read_status.push_back(want_to_read_yet_again);

    nlohmann::json book_json;
    book_json << simple_book;

    std::ofstream book_file("book.json");
    if (!book_file)
        return;

    book_file << std::setw(4) << book_json;
    book_file.close();

    simple_book.Display();
}

void InputOutputCompare()
{
    std::ifstream json_file("book.json");
    if (!json_file)
        return;

    nlohmann::json book_json;
    json_file >> book_json;

    json_file.close();

    Book book;
    book_json >> book;

    std::ofstream json_out("book2.json");
    if (!json_out)
        return;

    nlohmann::json book_json2;
    book_json2 << book;

    json_out << std::setw(4) << book_json2;

    json_out.close();
}

void MultipleBooks()
{
    // in possession, read
    Book book_1984;
    {
        book_1984.m_name = "1984";
        book_1984.m_authors.push_back("George Orwell");

        book_1984.m_read_status.m_property = eReadStatus::READ;
        book_1984.m_possession.m_property = ePossession::IN_POSSESSION;

        Property<int> rating;
        rating.m_property = 8;
        book_1984.m_ratings.push_back(rating);
    }

    // in possession, want to read
    Book book_dorian;
    {
        book_dorian.m_name = "The picture of Dorian Gray";
        book_dorian.m_authors.push_back("Gay");

        book_dorian.m_read_status.m_property = eReadStatus::WANT_TO_READ;
        book_dorian.m_possession.m_property  = ePossession::IN_POSSESSION;

        Property<int> rating;
        rating.m_property = 6;
        book_dorian.m_ratings.push_back(rating);
    }

    // digital, read
    Book book_winx;
    {
        book_winx.m_name = "Winx";
        book_winx.m_authors.push_back("Fairies");

        book_winx.m_read_status.m_property  = eReadStatus::READ;
        book_winx.m_possession.m_property  = ePossession::DIGITAL_COPY;

        Property<int> rating;
        rating.m_property = 6;
        book_winx.m_ratings.push_back(rating);
    }

    // digital, want to read
    Book book_lyoko;
    {
        book_lyoko.m_name = "Code Lyoko";
        book_lyoko.m_authors.push_back("Aelita");

        book_lyoko.m_read_status.m_property = eReadStatus::WANT_TO_READ;
        book_lyoko.m_possession.m_property  = ePossession::DIGITAL_COPY;

        Property<int> rating;
        rating.m_property = 7;
        book_lyoko.m_ratings.push_back(rating);

    }
    
    // not in possession, want to read
    Book book_atuan;
    {
        book_atuan.m_name = "Tombs of Atuan";
        book_atuan.m_authors.push_back("Ursula K. Leguin");

        book_atuan.m_read_status.m_property = eReadStatus::WANT_TO_READ;
        book_atuan.m_possession.m_property = ePossession::NOT_IN_POSSESSION;

        Property<int> rating;
        rating.m_property = 10;
        book_atuan.m_ratings.push_back(rating);
    }

    Journal all_journal;
    all_journal.m_all_books.push_back(book_1984);
    all_journal.m_all_books.push_back(book_dorian);
    all_journal.m_all_books.push_back(book_winx);
    all_journal.m_all_books.push_back(book_lyoko);
    all_journal.m_all_books.push_back(book_atuan);

    auto predicate = [](const Book* lhs, const Book* rhs)
    { return lhs->m_ratings.front().m_property > rhs->m_ratings.front().m_property; };
    
    // all
    all_journal.Display(predicate);
    std::cout << std::endl << std::endl;
    
    // read/want to read
    all_journal.Display(predicate, eReadStatus::READ | eReadStatus::WANT_TO_READ);
    std::cout << std::endl << std::endl;
    
    // in possession
    all_journal.Display(predicate, ENUM_ALL, ePossession::IN_POSSESSION);
    std::cout << std::endl << std::endl;
    
    // read/want to read not in possession
    all_journal.Display(predicate, eReadStatus::READ | eReadStatus::WANT_TO_READ, ePossession::NOT_IN_POSSESSION);
    std::cout << std::endl << std::endl;
}

int main(void)
{
    MultipleBooks();
    //SimpleBook();
    //InputOutputCompare();

    return 0;
}