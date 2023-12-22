/*
    File:    Book.hpp
    Author:  Aihotz Arruti
    Created: December 21, 2023
    
    Brief:   A Book data structure contains information to identify a book.
    This information includes:
    - Name
    - Author(s)
    - Series the book belongs to (optional)

    Additionally, there is user-related information used for journaling them:
    - Read status (want to read, reading, read...)          (one or many statuses)
    - Possession  (whether the user has the book or not)    (one or many possessions)
    - Rating      (once or many)

    For the user-related properties, the user can also leave a note and a date.
*/

#ifndef BOOK_HPP
#define BOOK_HPP

// stl
#include <string>
#include <vector>

// serialization
#include "nlohmann/json.hpp"

#include "Property.hpp"

// whether the user has the book
enum ePossession
{
    NOT_IN_POSSESSION = 0b00000001,
    IN_POSSESSION     = 0b00000010,
    DIGITAL_COPY      = 0b00000100,
};

enum eReadStatus
{
    NOT_READ     = 0b00000001,
    WANT_TO_READ = 0b00000010,
    READING      = 0b00000100,
    READ         = 0b00001000,
};

static constexpr int ENUM_ALL = 0b11111111;

// used to track book series
struct SeriesPart
{
    std::string name;

    // because some books are the #3.5 of a saga....
    struct
    {
        int                integral_part;
        std::optional<int> decimal_part;
    } number;

    // serialization
    friend nlohmann::json&       operator<<(nlohmann::json& j, const SeriesPart& series);
    friend const nlohmann::json& operator>>(const nlohmann::json& j, SeriesPart& series);
};

struct Book
{
    std::string              m_name;
    std::vector<std::string> m_authors;

    // the serie(s) the book belongs to
    std::vector<SeriesPart> m_series;

    // read status(es)
    Property<eReadStatus>              m_read_status;
    std::vector<Property<eReadStatus>> m_additional_read_status;

    // possession(s)
    Property<ePossession>              m_possession;
    std::vector<Property<ePossession>> m_additional_possessions;

    // user ratings (if any)
    std::vector<Property<int>> m_ratings;

    void Display() const;

    // serialization
    friend nlohmann::json&       operator<<(nlohmann::json& j, const Book& book);
    friend const nlohmann::json& operator>>(const nlohmann::json& j, Book& book);
};

#endif