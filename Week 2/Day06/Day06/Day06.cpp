// Day06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <iomanip>


enum class Weapon
{
    Sword, Axe, Spear, Mace
};

void PrintGrades(const std::map<std::string, double>& grades)
{
    std::cout << "\nJLA Academy\n";
    for (auto& [student,grade] : grades)
    {
        std::cout << std::setw(10) << std::left << student;
        std::cout << std::setw(6) << std::right << std::fixed << std::setprecision(2) << grade << "\n";
    }
}

int main()
{

    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Removing a key and its value from a map  ]

        erase(iterator) -- returns an iterator that points to the first item AFTER the ones that were removed OR end() if no element exist
        erase(key) -- returns the # of items removed

    */
    std::map<Weapon, int> dorasbackpack;
    auto inserted = dorasbackpack.insert(std::make_pair(Weapon::Sword, 5));
    dorasbackpack[Weapon::Axe] = 3;

    size_t numberRemoved = dorasbackpack.erase(Weapon::Spear);
    if (numberRemoved > 0)
        std::cout << "The Spear were removed.\n";
    else
        std::cout << "Spear was not found in the map.\n";

    std::map<Weapon, int>::iterator found = dorasbackpack.find(Weapon::Axe);
    if (found != dorasbackpack.end())
    {
        dorasbackpack.erase(found);
        std::cout << "The Axes were removed.\n";
    }
    else
        std::cout << "Axe was not found in the map.\n";





    /*
        CHALLENGE 1:

                    print the students and grades below
                        use std::setw and std::left and std::right to format the output
                    ask for the name of the student to drop from the grades map
                        use std::getline to get the user's input
                    remove the student from the map
                    print message indicating what happened
                    if not found print an error message
                    else print the map again and print that the student was removed


    */
    srand((unsigned int)time(NULL));
    std::map<std::string, double> grades;
    grades["Bruce"] = (rand() % 10001) / 100.0;
    grades["Dick"] = rand() % 10001 / 100.0;
    grades["Diana"] = rand() % 10001 / 100.0;
    grades["Alfred"] = rand() % 10001 / 100.0;
    grades["Clark"] = rand() % 10001 / 100.0;
    grades["Arthur"] = rand() % 10001 / 100.0;
    grades["Barry"] = rand() % 10001 / 100.0;

    std::string name;
    do
    {
        PrintGrades(grades);
        std::cout << "Who should be dropped? ";
        std::getline(std::cin, name);
        if (name.size() == 0) break;

        if (grades.erase(name) > 0) std::cout << name << " was removed!\n";
        else std::cout << name << " is not in the academy.\n";

    } while (true);
}