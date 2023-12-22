#ifndef JOURNAL_HPP
#define JOURNAL_HPP

#include <list>
#include <string>
#include <vector>

#include <stdexcept>

#include "Book.hpp"

class Journal
{
public:
    using Filter = bool (*)(const Book*, const Book*);

    std::vector<Book> m_all_books;

    void Display(Filter sort_filter, int read_status_filter = ENUM_ALL, int possession_filter = ENUM_ALL) const;
};

void Journal::Display(Filter sort_filter, int read_status_filter, int possession_filter) const
{
    if (sort_filter == nullptr)
        throw std::runtime_error("Journal::Display: Null filter provided");

    std::list<const Book*> sorted_books;

    for (const Book& book : m_all_books)
    {
        if ((book.m_read_status.m_property & read_status_filter) && (book.m_possession.m_property & possession_filter))
            sorted_books.push_back(&book);
    }
    
    sorted_books.sort(sort_filter);

    for (const Book* book : sorted_books)
    {
        book->Display();
        printf("###########################################################\n");
    }
}

#endif