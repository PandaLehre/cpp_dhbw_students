#ifndef MAILHANDLER_HPP
#define MAILHANDLER_HPP

#include <string>
#include "Person.hpp"

class MailHandler
{
public:
    void writeMail(Person receiver, std::string mailText);
};

#endif // !MAILHANDLER_HPP