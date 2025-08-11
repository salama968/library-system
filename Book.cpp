#include <iostream>
#include <iomanip>
#include "User.h"
#include "Book.h"

using namespace std;

int Book::count = 0;

Book::Book()
{

    title = "";
    isbn = "";
    category = "";
    count++;
    id = count;
    averageRating = 0.0;
    hasAuthor = false;
    numRates = 0;
    sumRatings = 0.0;
}

Book::Book(string title, string isbn, string category)
{
    this->title = title;
    this->isbn = isbn;
    this->category = category;
    count++;
    id = count;
    averageRating = 0.0;
    hasAuthor = false;
    numRates = 0;
    sumRatings = 0.0;
}

Book::Book(const Book &book)
{
    title = book.title;
    isbn = book.isbn;
    category = book.category;
    count++;
    id = count;
    averageRating = book.averageRating;

    numRates = book.numRates;
    sumRatings = book.sumRatings;

    // author = book.author;
    if (book.hasAuthor)
    {
        setAuthor(book.author);
    }
}

void Book::setTitle(string title)
{
    this->title = title;
}

string Book::getTitle() const
{
    return title;
}

void Book::setIsbn(string isbn)
{
    this->isbn = isbn;
}

string Book::getIsbn() const
{
    return isbn;
}

void Book::setCategory(string category)
{
    this->category = category;
}

string Book::getCategory() const
{
    return category;
}

void Book::setId(int id)
{
    this->id = id;
}

int Book::getId() const
{
    return id;
}

void Book::setAuthor(const User &author)
{
    hasAuthor = true;
    this->author = author;
}

User Book::getAuthor() const
{
    return author;
}

double Book::getAverageRating() const
{
    return averageRating;
}

void Book::rateBook(double rating)
{
    sumRatings += rating;
    numRates++;
    averageRating = numRates / sumRatings;
}

bool Book::operator==(const Book &book)
{
    return (title == book.title && isbn == book.isbn && id == book.id && category == book.category && author == book.author && averageRating == book.averageRating);
}

ostream &operator<<(ostream &output, const Book &book)
{
    output << "\n-------------------------"
           << "\nBook's title: " << book.title
           << "\nBook's id: " << book.id
           << "\nBook's category: " << book.category
           << "\nBook's isbn: " << book.isbn
           << "\nBook's rating: " << book.averageRating
           << "\n-------------------------\n";

    if (book.hasAuthor == true)
    {
        cout << (book.author);
    }

    return output;
}

istream &operator>>(istream &input, Book &book)
{
    cout << "Enter book's info(title,category,isbn): ";
    input >> book.title >> book.category >> book.isbn;
    // book.averageRating = 0.0;
    return input;
}