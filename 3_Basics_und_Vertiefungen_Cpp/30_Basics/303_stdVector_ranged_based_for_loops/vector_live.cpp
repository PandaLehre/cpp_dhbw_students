#include <iostream>
#include <vector>

void print_vector_ranged_for_loop(std::vector<std::string> vec)
{
    if (vec.empty())
    {
        std::cout << "VECTOR IS EMPTY" << std::endl;
        return;
    }
    for (std::string &element : vec)
    {
        std::cout << element;
    }
    std::cout << std::endl;
}

void print_vector_c_style(std::vector<std::string> vec)
{
    if (vec.empty())
    {
        std::cout << "VECTOR IS EMPTY" << std::endl;
        return;
    }
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i];
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> vec;

    print_vector_c_style(vec);

    vec.push_back("Hello");
    vec.push_back(" ");
    vec.push_back("World");
    vec.push_back("!");
    vec.push_back(" This is my first std::vector.");

    print_vector_c_style(vec);

    std::cout << "Vectorsize: " << vec.size() << std::endl;
    std::cout << "Vectorkapacity: " << vec.capacity() << std::endl;

    print_vector_ranged_for_loop(vec);

    return 0;
}