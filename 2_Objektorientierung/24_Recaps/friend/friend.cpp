#include <iostream>

class Friendsearcher
{
public:
    Friendsearcher() : m_mySecretForMyFriends(42)
    {
        std::cout << "I am a friend searcher\n";
    };
    ~Friendsearcher()
    {
        std::cout << "I was a friend searcher\n";
    };

    friend class MyFriend;

private:
    int m_mySecretForMyFriends;
};

class MyFriend
{
public:
    MyFriend()
    {
        std::cout << "I will be your friend\n";
    };
    ~MyFriend()
    {
        std::cout << "I was your friend\n";
    };

    void printSecret(Friendsearcher &fs)
    {
        std::cout << "--- My friend's secret is: " << fs.m_mySecretForMyFriends << "\n";
    }
};

int main()
{
    Friendsearcher fs;
    MyFriend mf;

    mf.printSecret(fs);

    return 0;
}