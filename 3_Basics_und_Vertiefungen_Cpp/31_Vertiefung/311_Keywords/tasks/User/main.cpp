#include <string>
#include <iostream>
#include <vector>

class User
{
public:
   User(){};

   User(const std::string name)
       : m_name{name}
   {
      m_id = nextID;
      nextID++;
   };

   void printInfo() const
   {
      std::cout << "Name: " << m_name << std::endl;
      std::cout << "ID: " << m_id << std::endl;
   }

private:
   std::string m_name;
   int m_id;

   static int nextID;
};

int User::nextID = 1;

int main()
{
   std::cout << "--- Heute wurde von folgenden usern eine Vorstellung gehalten:" << std::endl;
   std::vector<User> myUser;
   myUser.push_back(User("Erik C."));
   myUser.push_back(User("Paul M."));
   myUser.push_back(User("Dennis G."));
   myUser.push_back(User("Lukas F."));
   myUser.push_back(User("Lars P."));

   for (auto &user : myUser)
   {
      user.printInfo();
   }

   return 0;
}