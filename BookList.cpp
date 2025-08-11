#include "BookList.h"

BookList::BookList()
{
    capacity = 0;
    booksCount = 0;
}

BookList::BookList(int capacity)
{
    this->capacity = capacity;

    books = new Book[capacity];
    booksCount = 0;
    Book::count = Book::count - capacity;
}

void BookList::addBook(const Book &book)
{
    if (capacity >= booksCount)
    {
        books[booksCount] = book;
        booksCount++;
    }
}

Book *BookList::searchBook(string name)
{
    for (int i = 0; i < booksCount; i++)
    {
        if (books[i].getTitle() == name)
        {
            return &books[i];
        }
    }
    return nullptr;
}
Book *BookList::searchBook(int id)
{
    for (int i = 0; i < booksCount; i++)
    {
        if (books[i].getId() == id)
        {
            return &books[i];
        }
    }
    return nullptr;
}
void BookList::deleteBook(int id)
{
    for (int i = 0; i < booksCount; i++)
    {
        if (books[i].getId() == id)
        {
            while (i < booksCount - 1)
            {
                books[i] = books[i + 1];
                // i won't change the id
                i++;
            }
            booksCount--;
            break;
        }
    }
}

ostream &operator<<(ostream &output, const BookList &bookList)
{
    for (int i = 0; i < bookList.booksCount; i++)
    {
        output << bookList.books[i];
    }
    return output;
}

BookList::~BookList()
{
    delete[] books;
}

Book BookList::getTheHighestRatedBook()
{
    int index = 0;
    double highest = -1;

    for (int i = 0; i < booksCount; i++)
    {
        if (books[i].getAverageRating() < highest)
        {
            highest = books[i].getAverageRating();
            index = i;
        }
    }
    return books[index];
}
void BookList::getBooksForUser(const User &user)
{

    for (int i = 0; i < booksCount; i++)
    {
        if (books[i].getAuthor() == user)
        {
            cout << books[i];
        }
    }
}
Book &BookList::operator[](int index)
{
    if (index < 0 || index >= capacity)
    {
        cout << "wrong index" << endl;
        exit(1);
    }
    return books[index];
}