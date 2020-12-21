﻿#include <iostream>
#include <locale.h>
#include <string>

using namespace std;

class Animal
{
protected:
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
        printf("Animal хотел что-то сказать\n");
    }

    virtual void sound2()
    {
        printf("Animal попытался издать другой звук\n");
    }

    virtual string className()
    {
        return "Animal";
    }

    virtual bool isA(string className)
    {
        return className == "Animal";
    }

    virtual ~Animal()
    {
        printf("~Animal()");
    }
};

class WildAnimal :public Animal
{
public:
    WildAnimal()
    {
        printf("WildAnimal()\n");
    }

    WildAnimal(int age, int weight, string name = "")
        :Animal(age, weight, name) 
    {
        printf("WildAnimal(int age, int weight, string name = "")\n");
    }

    void sound()
    {
        printf("Raaaaarrrr\n");
    }

    void sound2()
    {
        printf("R-r-r-r-r-r\n");
    }

    void chase()
    {
        printf("Дикое животное начало погоню\n");
    }

    string className()
    {
        return "WildAnimal";
    }

    bool isA(string className)
    {
        return className == "WildAnimal";
    }

    ~WildAnimal()
    {
        printf("~WildAnimal()");
    }
};

class Base
{
public:
    int n = 10;
    Base()
    {
        printf("Base()\n");
    }

    Base(Base* obj)
    {
        printf("Base(Base* obj)\n");
    }

    Base(const Base& obj)
    {
        printf("Base(Base& obj)\n");
    }
    
    ~Base()
    {
        printf("~Base()\n");
    }
};

class Desc :public Base
{
public:
    Desc()
    {
        printf("Desc()\n");
    }

    Desc(Desc* obj)
    {
        printf("Desc(Desc* obj)\n");
    }

    Desc(const Desc& obj)
    {
        printf("Desc(Desc& obj)\n");
    }

    ~Desc()
    {
        printf("~Desc()\n");
    }
};

void func1(Base obj)
{
    printf("void func1(Base obj)\n");
}

void func2(Base* obj)
{
    printf("void func2(Base* obj)\n");
}

void func3(Base& obj)
{
    printf("void func3(Base& obj)\n");
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Animal* animal1 = new Animal(5, 4, "Кот");
    WildAnimal* wildAnimal1 = new WildAnimal(8, 160, "Тигр");
    Animal* animal2 = new WildAnimal(10, 190, "Лев");
    printf("\n\n");

    // Перекрываемые методы
    animal1->sound();
    wildAnimal1->sound();
    printf("\n\n");

    // Виртуальные методы
    animal1->sound2();
    wildAnimal1->sound2();
    animal2->sound2();
    printf("\n\n");

    // Проверка на принадлежность классу
    if (animal2->className() == "WildAnimal")
        printf("WildAnimal\n");
    if (animal2->isA("WildAnimal"))
        printf("WildAnimal\n");
    printf("\n\n");

    // Безопасное приведение типов (dynamic_cast)
    WildAnimal* temp = dynamic_cast<WildAnimal*>(animal2);
    if (temp)
        temp->chase();
    printf("\n\n");

    // Безопасное приведение типов (вручную)
    if (animal2->isA("WildAnimal"))
        ((WildAnimal*)animal2)->chase();
    printf("\n\n");

    // Передача объектов как параметров в функции
    Base* base = new Base();
    Desc* desc = new Desc();
    desc->n = 20;
    printf("\n");
    func1(base);
    func2(base);
    func3(*base);
    printf("\n");
    func1(desc);
    func2(desc);
    func3(*desc);
    
}
