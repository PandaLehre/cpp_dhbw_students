#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cmath>

bool yourWayToSort(std::string strA, std::string strB)
{
    return (strA.length() < strB.length());
}

bool myWayToSort(std::string strA, std::string strB)
{
    return (strA.length() > strB.length());
}

void printContainer(std::vector<std::string> container)
{
    // ranged-based-for loop
    for (std::string &str : container)
    {
        std::cout << str << " ";
    }
    std::cout << std::endl;
}

void printContainer(std::vector<int> container)
{
    // ranged-based-for loop
    for (int &str : container)
    {
        std::cout << str << " ";
    }
    std::cout << std::endl;
}

int main()
{

    std::vector<std::string> myContainer;
    myContainer = {"Hello", ",", "World", "!", "I", "love", "std::sort", "for these Numbers: "};
    printContainer(myContainer);
    std::cout << std::endl;

    
    std::vector<int> numbers(5);
    std::fill(numbers.begin(), numbers.end(), 3); // Add some numbers to the container
    printContainer(numbers);
    
    std::iota(numbers.begin(), numbers.end(), -2); // Fill with numbers -2 to 2
    printContainer(numbers);

    std::transform(numbers.begin(), numbers.end(), numbers.begin(),
                   [](int n) { return std::pow(n,3); }); //Apply mathematical operations
    printContainer(numbers);

    //Accumulate all numbers and find minimum element
    std::cout << "Accumulated sum of numbers: " << std::accumulate(numbers.begin(), numbers.end(), 0) << std::endl;
    std::cout << "Minimum Element: " << *std::min_element(numbers.begin(), numbers.end()) << std::endl;
    auto index = std::distance(numbers.begin(), std::min_element(numbers.begin(), numbers.end())); //Get Index
    std::cout << "Index: " << index << std::endl;

    // Convert numbers to strings
    std::vector<std::string> numberStrings;
    numberStrings.reserve(numbers.size());
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(numberStrings),
                   [](int n) { return std::to_string(n); });

    // Move the strings into myContainer
    std::move(numberStrings.begin(), numberStrings.end(), std::back_inserter(myContainer));
    printContainer(myContainer);

    //Sort string container using the yourWayToSort function
    std::sort(myContainer.begin(), myContainer.end(), yourWayToSort);
    printContainer(myContainer);

    //Sort string container using the myWayToSort function
    std::sort(myContainer.begin(), myContainer.end(), myWayToSort);
    printContainer(myContainer);

    return 0;
}