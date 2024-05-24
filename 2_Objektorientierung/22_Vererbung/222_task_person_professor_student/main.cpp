#include <iostream>
#include <string>

class Person
{
public:
   Person(std::string name, std::string address, std::string email)
       : m_name(name), m_address(address), m_email(email)
   {
   }

   ~Person()
   {
   }

   std::string getName()
   {
      return m_name;
   }

protected:
   std::string m_name;
   std::string m_address;
   std::string m_email;
};

class Professor : public Person
{
public:
   Professor(std::string name, std::string address, std::string email)
         : Person(name, address, email) {}

private:
   std::string m_iban;
};

class Student : public Person
{
public:
   Student(std::string name, std::string address, std::string email)
         : Person(name, address, email){}

private:
   double m_averageGrade;
};

class MailHandler
{
public:
   void writeMail(Person receiver, std::string mailText)
   {
      std::cout << "--- Writing Mail to: " << receiver.getName() << std::endl;
      std::cout << "Text: " << std::endl;
      std::cout << mailText << std::endl
                << "---" << std::endl;
   }
};

int main()
{
   Person Frank("Frank", "Hellweg 3", "frank@web.de");
   Professor Nina("Nina", "Sofienstraße 1", "nina@web.de");
   Student Kai("Kai", "Tollweg 12", "kai@web.de");

   MailHandler myMailHandler;

   myMailHandler.writeMail(Frank, "Hallo Frank, wie geht es dir?");
   myMailHandler.writeMail(Nina, "gut, und dir?");
   myMailHandler.writeMail(Kai, "Hi :)");

   return 0;
}

// Wer findet das Easter Egg? :D