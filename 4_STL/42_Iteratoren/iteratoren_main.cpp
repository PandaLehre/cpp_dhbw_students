#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>

void printHelper(std::string &InputString) {
    std::cout << InputString;
}

int main()
{
    std::vector<std::string> myContainer;
    myContainer = {"Hello", ",", " ", "World", "!"};

    // a) range-based-for loop
    myContainer.push_back(" - range-based-for loop");
    for (std::string &str : myContainer)
    {
        std::cout << str;
    }
    std::cout << std::endl;
    myContainer.pop_back();


    //iterator access
    auto container_iterator = myContainer.begin();
    std::cout << "First element: " << *container_iterator << std::endl;
    std::cout << "Second element: " << *(++container_iterator) << std::endl;



    // b) iterator-based loop
    myContainer.push_back(" - iterator-based loop");
    for (auto it = myContainer.begin(); it < myContainer.end(); it++)
    {
        std::cout << *it;
    }
    std::cout << std::endl;
    myContainer.pop_back();


    // c1) for_each loop
    myContainer.push_back(" - for_each loop");
    std::for_each(myContainer.begin(), myContainer.end(), printHelper);
    std::cout << std::endl;
    // c2) for_each loop with lambda
    std::for_each(myContainer.begin(), myContainer.end(), [](std::string &str) {std::cout << str;});
    std::cout << std::endl;

    return 0;
}
