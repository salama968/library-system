#include <iostream>
#include <iomanip>
#include "User.h"

int User::count = 0;

User::User()
{
    name = "";
    age = 0;
    password = "";
    email = "";
    count++;
    id = count;
}

User::User(string name, int age, string password, string email)
{
    this->name = name;
    this->age = age;
    this->password = password;
    this->email = email;
    count++;
    id = count;
}

User::User(const User &toBe)
{
    name = toBe.name;
    age = toBe.age;
    password = toBe.password;
    email = toBe.email;
    id = toBe.id;
}

bool User::operator==(const User &u)
{
    if (name != u.name || id != u.id || age != u.age || email != u.email)
        return false;
    return true;
}

void User::setName(string name)
{
    this->name = name;
}

string User::getName() const
{
    return name;
}

void User::setPassword(string password)
{
    this->password = password;
}

string User::getPassword() const
{
    return password;
}

void User::setEmail(string email)
{
    this->email = email;
}

string User::getEmail() const
{
    return email;
}

void User::setAge(int age)
{
    this->age = age;
}

int User::getAge() const
{
    return age;
}

void User::setId(int id)
{
    this->id = id;
}

int User::getId() const
{
    return id;
}

void User::Display()
{
    cout << "\n-------------------------" << setw(16)
         << "\nUser name: " << name
         << "\nUser ID: " << id
         << "\nUser email: " << email
         << "\nUser Age: " << age
         << "\n-------------------------\n";
}

ostream &operator<<(ostream &output, const User &user)
{
    output << "\n-------------------------"
           << "\nUser name: " << user.name
           << "\nUser ID: " << user.id
           << "\nUser email: " << user.email
           << "\nUser Age: " << user.age
           << "\n-------------------------\n";
    return output;
}

istream &operator>>(istream &input, User &user)
{
    cout << "\nEnter User's info(name,email,password,age) space seperated: ";
    input >> user.name >> user.email >> user.password >> user.age;
    return input;
}

// void User::operator=(const User& user){
//     name=user.name;
//     age=user.age;
//     password=user.password;
//     email=user.email;

// }