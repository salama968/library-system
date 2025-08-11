#include "UserList.h"

UserList::UserList()
{
    capacity = 0;
    usersCount = 0;
}

UserList::UserList(int capacity)
{
    this->capacity = capacity;
    usersCount = 0;
    users = new User[capacity];

    User::count = User::count - capacity;
}

void UserList::addUser(User &user)
{

    if (usersCount < capacity)
    {
        users[usersCount] = user;

        // users[usersCount].setId(usersCount + 1);   // warning

        usersCount++;
    }
    else
    {
        cout << "Users limit exceeded!!!" << endl;
    }
}

User *UserList::searchUser(string name)
{

    for (int i = 0; i < usersCount; i++)
    {
        if (users[i].getName() == name)
        {
            return &users[i];
        }
    }

    return nullptr;
}
User *UserList::searchUser(int id)
{
    for (int i = 0; i < usersCount; i++)
    {
        if (users[i].getId() == id)
        {
            return &users[i];
        }
    }

    return nullptr;
}
void UserList::deleteUser(int id)
{
    for (int i = 0; i < usersCount; i++)
    {
        if (users[i].getId() == id)
        {
            while (i < usersCount - 1)
            {
                users[i] = users[i + 1];
                // i won't change the id
                i++;
            }
            usersCount--;
            // i won't decrease the capacity
            break;
        }
    }
}

ostream &operator<<(ostream &output, const UserList &userList)
{
    for (int i = 0; i < userList.usersCount; i++)
    {
        output << userList.users[i];
    }
    return output;
}

UserList::~UserList()
{
    delete[] users;
}