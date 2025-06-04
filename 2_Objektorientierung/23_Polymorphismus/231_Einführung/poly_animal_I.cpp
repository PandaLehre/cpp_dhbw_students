#include <iostream>
#include <vector>
#include <string>

class Animal
{
public:
    Animal(int age, std::string name) : m_age(age), m_name(name) {}

    virtual ~Animal() // virtual destructor for proper cleanup in derived classes (heap allocation)
    {
        std::cout << "...bye bye animal..." << std::endl;
    }

    void introduceYourself()
    {
        makeSound();
        std::cout << "I am " << m_name << " and I am " << m_age << " years old." << std::endl;
    }

private:
    int m_age;
    std::string m_name;

    virtual void makeSound() // virtual for polymorphism
    {
        std::cout << "...some generic animal sound..." << std::endl;
    }

    int getAge() const
    {
        return m_age;
    }
};

class Dog : public Animal
{
public:
    Dog(int age, const std::string name) : Animal(age, name) {}

    ~Dog() // Destructor for Dog class
    {
        std::cout << "...bye bye dog..." << std::endl;
    }

    void makeSound() override
    {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal
{
public:
    Cat(int age, const std::string name) : Animal(age, name) {}

    ~Cat() // Destructor for Cat class
    {
        std::cout << "...bye bye cat..." << std::endl;
    }

    void makeSound() override
    {
        std::cout << "Meow!" << std::endl;
    }
};

void printAnimalSound(std::vector<Animal *> animalContainer);

int main()
{
    Animal animal1(5, "Generic Animal");
    auto dog1 = new Dog(3, "Buddy");
    Cat cat1(2, "Whiskers");

    auto animalContainer = std::vector<Animal *>{&animal1, dog1, &cat1};
    printAnimalSound(animalContainer);

    delete dog1; // Clean up dynamically allocated memory
    return 0;
}

void printAnimalSound(std::vector<Animal *> animals)
{
    for (auto animal : animals)
    {
        animal->introduceYourself(); // Calls the appropriate introduceYourself() method based on the actual object type
    }
}
