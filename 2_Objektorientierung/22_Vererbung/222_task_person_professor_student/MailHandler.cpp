#include "MailHandler.hpp"
#include <iostream>

void MailHandler::writeMail(Person receiver, std::string mailText)
{
    std::cout << "--- Writing Mail to: " << receiver.getName() << std::endl;
    std::cout << "Text: " << std::endl;
    std::cout << mailText << std::endl << "---" << std::endl;
}
