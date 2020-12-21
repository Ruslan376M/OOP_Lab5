#include <iostream>
#include <string>

using namespace std;

class Animal
{
private:
    int age;
    int weight;
    string name;

public:
    Animal()
    {
        age = 0;
        weight = 0;
        name = "";
        printf("Animal()\n");
    }
    
    Animal(int age, int weight, string name = "")
    {
        this->age = age;
        this->weight = weight;
        this->name = name;
        printf("Animal(int age, int weight, string name)\n");
    }

    Animal(const Animal& animal)
    {
        this->age = animal.age;
        this->weight = animal.weight;
        this->name = animal.name;
        printf("Animal(const Animal& animal)\n");
    }

    int getAge()
    {
        return age;
    }

    int getWeight()
    {
        return weight;
    }

    string getName()
    {
        return name;
    }

    void sound()
    {
        printf("Animal хотело что-то сказать\n");
    }

    virtual ~Animal()
    {
        printf("~Animal()");
    }
};

class wildAnimal :public Animal
{
    wildAnimal()
    {
        printf("wildAnimal()\n");
    }

    wildAnimal(int age, int weight, string name = "")
        :Animal(age, weight, name) 
    {
        printf("wildAnimal(int age, int weight, string name = "")\n");
    }

    ~wildAnimal()
    {
        printf("~wildAnimal()");
    }
};

int main()
{
    
}
