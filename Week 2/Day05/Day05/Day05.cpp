// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

enum class Weapon
{
    Sword, Axe, Spear, Mace
};

/// <summary>
/// Finds the index of an item in the vector.
/// </summary>
/// <param name="numbers">The vector to search.</param>
/// <param name="itemToFind">The number to find.</param>
/// <returns>returns the index if found. returns -1 if not found.</returns>
int LinearSearch(std::vector<int> numbers, int itemToFind)
{
    int foundIndex = -1;
    for (size_t index = 0; index < numbers.size(); index++)
    {
        if (numbers[index] == itemToFind)
        {
            foundIndex = index;
            break;
        }
    }
    return foundIndex;//-1 is not a valid index.
}

void PrintGrades(const std::map<std::string, double>& course)
{
    std::cout << "\n\nPG2 Grades for 2404\n";
    for (auto& [student,grade] : course)
    {
        std::cout << std::setw(15) << std::left << student << " ";
        std::cout << std::setw(8) << std::right << std::fixed << std::setprecision(2) << grade << "\n";
    }
}

int main()
{
    /*
        ╔═════════╗
        ║Searching║
        ╚═════════╝

        There are 2 ways to search a vector: linear search or binary search

        CHALLENGE 1:

            write a method to linear search the numbers list.
                The method should take 2 parameters: vector of ints to search, int to search for.
                The method should return -1 if NOT found or the index if found.

            The algorithm:
                1) start at the beginning of the vector
                2) compare each item in the vector to the search item
                3) if found, return the index
                4) if reach the end of the vector, return -1 which means not found

    */
    std::vector<int> numbers = { 0,1,2,3,4,5,6 };
    int searchNumber = 15;
    int foundIndex = LinearSearch(numbers, searchNumber);
    if (foundIndex != -1)
        std::cout << "The number " << searchNumber << " was found at index " << foundIndex << "\n";
    else
        std::cout << "The number " << searchNumber << " was NOT found. \n";




    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Creating a map  ]

        map<TKey, TValue>  - an associative collection.
            TKey is a placeholder for the type of the keys.
            TValue is a placeholder for the type of the values.

        When you want to create a map variable,
            1) replace TKey with whatever type of data you want to use for the keys
            2) replace TValue with the type you want to use for the values


        [  Adding items to a map  ]

        There are 2 ways to add items to a Dictionaruy:
        1) using the insert method.
        3) using [key] = value
    */
    std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

    //returns an iterator and a bool. 
    //if the key is already in the map, it will NOT insert it -- the bool will be false.
    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
    if (inserted.second == false) //meaning not inserted
        std::cout << "The key was already in the map. It was not inserted.\n";
    else
        std::cout << "The key was inserted in the map.\n";

    dorasBackpack[Weapon::Axe] = 3;
    dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map


    std::map<std::string, double> menu;

    //1) use the insert method
    auto pair = std::make_pair("Cheese Burger", 9.99);
    auto result = menu.insert(pair);
    if (result.second)//was it inserted?
    {
    }

    pair.second = 11.99;
    result = menu.insert(pair);//will NOT insert it AND will NOT overwrite the value
    auto iter = result.first;
    bool wasInsert = result.second;
    std::string key = iter->first;
    double value = iter->second;
    std::cout << key << " costs " << value << "\n";

    //2) use [key] = value
    menu["Bacon Cheeseburger"] = 11.99;
    menu["Bacon Cheeseburger"] = 15.99;//overwrite the value

    std::cout << menu["Impossible Burger"] << "\n";//what will it print?

    /*
        CHALLENGE 2:

            Create a map that stores names (string) and grades. Call the variable grades.
            Add students and grades to your map.

    */

    std::vector<std::string> students{
        "Angel 1", "Cassandra", "Hector", "Kaylen", "Mikale", "Theo 1", "Tim", "Wesley",
        "John", "Austin", "Rashid", "Clark", "Jacob", "Reki",
        "Brandon", "Erick", "Eysue", "William", "Josean",
        "Angel 2", "Joshua", "Theo 2", "Jason", "Max",
        "Harold", "Jeremy"
    };
    std::map<std::string, double> grades;
    srand(time(NULL));
    for (auto& name : students)
    {
        grades[name] = rand() % 10001 / 100.0;
    }







    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Looping over a map  ]

        You should use a ranged-based for loop when needing to loop over the entire map.

    */
    for (auto const& [key, val] : dorasBackpack) //requires C++ 20
    {
        switch (key)
        {
        case Weapon::Sword:
            std::cout << "Sword: ";
            break;
        case Weapon::Axe:
            std::cout << "Axe: ";
            break;
        case Weapon::Spear:
            std::cout << "Spear: ";
            break;
        case Weapon::Mace:
            std::cout << "Mace: ";
            break;
        default:
            break;
        }
        std::cout << val << "\n";
    }


    std::cout << "\nWelcome to Programmer's Haven\n";
    for (const auto& [menuItem,itemPrice] : menu)
    {
        //itemPrice += 5;
        std::cout << std::setw(20) << std::left << menuItem << " ";
        std::cout << std::setw(7) << std::right << itemPrice << "\n";
    }
    std::cout << "\nWelcome to Programmer's Haven\n";
    for (auto i = menu.begin(); i != menu.end(); i++)
    {
        std::cout << std::setw(20) << std::left << i->first << " ";
        std::cout << std::setw(7) << std::right << i->second << "\n";
    }
    std::cout << "\n\n";

    /*
        CHALLENGE 4:

            Loop over your grades map and print each student name and grade.

    */
    PrintGrades(grades);



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Checking for a key in a map  ]

        use the find method to check if the key is in the map

        will return map.end() if NOT found.

    */
    std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
    if (foundIter == dorasBackpack.end()) //meaning it was NOT found
    {
        std::cout << "Dora did not find any maces.\n";
    }
    else
    {
        //can safely grab the value for the key
        std::cout << "Dora found " << foundIter->second << " Maces\n";
    }


    std::string itemToFind = "Chicken Nuggies";
    auto foundIterator = menu.find(itemToFind);
    if (foundIterator == menu.end()) //did not find
        std::cout << itemToFind << " is not on the menu. I suggest you go to McDonald's\n";
    else
        std::cout << itemToFind << " costs " << foundIterator->second << "\n";

    itemToFind = "Bacon Cheeseburger";
    foundIterator = menu.find(itemToFind);
    if (foundIterator == menu.end()) //did not find
        std::cout << itemToFind << " is not on the menu. I suggest you go to McDonald's\n";
    else
    {
        double oldPrice = foundIterator->second;
        std::cout << itemToFind << " used to costs " << oldPrice << ".\n";
        //foundIterator->second += 5;
        menu[itemToFind] += 5;//overwrites the old value
        std::cout << "Now it costs " << menu[itemToFind] << "!! Thanks Putin.\n";
    }

    //DO NOT LOOP to find something in a map

    /*
        CHALLENGE 5:

            look for a specific student in the map.
            If the student is found, print out the student's grade
            else print out a message that the student was not found

        CHALLENGE 6:

            Pick any student and curve the grade (add 5) that is stored in the grades map

    */
    std::string nameOfStudent;
    do
    {
        std::cout << "Student to find and curve: ";
        std::getline(std::cin, nameOfStudent);
        if (nameOfStudent.size() == 0) break;

        auto foundStudent = grades.find(nameOfStudent);
        if (foundStudent != grades.end())
        {
            double oldGrade = foundStudent->second;
            foundStudent->second = std::min(100.0, oldGrade + 5);
            std::cout << nameOfStudent << " had a grade of " << oldGrade << ". It is now " <<
                grades[nameOfStudent] << "\n";
            PrintGrades(grades);
        }
        else
            std::cout << nameOfStudent << " was not found.\n";
    } while (true);




    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Updating a value for a key in a map  ]

        To update an existing value in the map, use the [ ]


    */
    dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe


}