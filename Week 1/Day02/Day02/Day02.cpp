// Day02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

bool postFix(std::string& hero)
{
    srand((unsigned int)time(NULL));
    int postFixNumber = rand() % 1000;
    hero = hero + "-" + std::to_string(postFixNumber);
    return postFixNumber % 2 == 0;
}

float average(const std::vector<int>& scores)
{
    //scores.push_back(5); //not allowed because it is marked as const
    float sum = 0;
    for (auto score : scores)
        sum += score;

    return sum / scores.size();
}

void print(const std::vector<int>& scores)
{
    std::cout << "----SCORES----\n";
    int index = 1;
    for (int score : scores)
        std::cout << index++ << ". " << score << "\n";
}

void printInfo(const std::vector<int>& scores)
{
    std::cout << "size: " << scores.size() << "\tcapacity: " << scores.capacity() << "\n";
}

void DifferentScope(int& aDifferentName)//slight performance benefit
{
    aDifferentName += 10;
    std::cout << aDifferentName << "\n";
}
void Get2ReturnValues(int& number, std::string& name)
{
    number++;
    name += std::to_string(number);
}

void FillGrades(std::vector<float>& course)
{
    for (size_t i = 0; i < 10; i++)
    {
        //rand() is c way of getting random numbers
        //rand() returns a random number from 0 - 32767 (short value)
        // % gives the remainder after dividing
        float random = (rand() % 10001)/100.0F;//0-10000 (inclusive)
        course.push_back(random);
    }
}

//pass by ref to prevent a copy (better performance)
//add const to prevent modification
void PrintGrades(const std::vector<float>& course)
{
    //course.clear();
    std::cout << "\n\nPG2 Grades for 2404\n";
    for (size_t i = 0; i < course.size(); i++)
    {
        std::cout << course.at(i) << "\n";
    }
}
void Stats(float& min, float& max, const std::vector<float>& fullSailCourse)
{
    if (!fullSailCourse.empty())
    {
        min = max = fullSailCourse[0];
        for (size_t i = 1; i < fullSailCourse.size(); i++)
        {
           /* if (min > fullSailCourse[i])
                min = fullSailCourse[i];
            if (max < fullSailCourse[i])
                max = fullSailCourse[i];*/
            min = std::min(min, fullSailCourse[i]);
            max = std::max(max, fullSailCourse[i]);
        }
    }
}
int main()
{

    int aNumber = 5;
    std::string original = "Batman";
    Get2ReturnValues(aNumber, original);
    DifferentScope(aNumber);
    //use & to create a reference variable
    int& sameNumber = aNumber;//sameNumber is an alias to aNumber
    sameNumber += 10;
    std::cout << aNumber << "\n";

    std::vector<std::string> names{ "Batman", "Aquaman","Aquaman", "The Dark Knight", "The Best","Aquaman"};
    //for (size_t i = 0; i < names.size();)
    //{
    //    if (_stricmp(names[i].c_str(), "Aquaman") == 0)
    //    {
    //        names.erase(names.begin() + i);
    //    }
    //    else
    //        i++;
    //}
    ////OR...
    //for (int i = names.size() - 1; i >= 0; i--)//a reverse for loop
    //{
    //    if (_stricmp(names[i].c_str(), "Aquaman") == 0)
    //    {
    //        names.erase(names.begin() + i);
    //    }
    //}
    for (auto iter = names.begin(); iter != names.end(); )
    {
        if (_stricmp(iter->c_str(), "Aquaman") == 0)
        {
            iter = names.erase(iter);
        }
        else
            iter++;
    }


    std::cout << "\nThe Justice League\n";
    for (auto& name : names)
    {
        std::cout << name << "\n";
    }

    
    /*
        ╔══════════════════════════════╗
        ║Parameters: Pass by Reference.║
        ╚══════════════════════════════╝
        Sends the variable itself to the method. The method parameter gives the variable a NEW name (i.e. an alias)

        NOTE: if the method assigns a new value to the parameter, the variable used when calling the method will change too.
            This is because the parameter is actually just a new name for the other variable.
    */
    std::string spider = "Spiderman";
    bool isEven = postFix(spider);
    std::string evenResult = (isEven) ? "TRUE" : "FALSE";
    std::cout << spider << "\n" << "Is Even postfix? " << evenResult << "\n";


    /*
        CHALLENGE 1:

            Write a method to fill the vector of floats with grades.
            1) pass it in by reference
            2) add 10 grades to the vector
            3) print the grades in main after calling the method

    */
    std::vector<float> grades;
    FillGrades(grades);
    PrintGrades(grades);


    /*
        ╔══════════════════╗
        ║ const parameters ║
        ╚══════════════════╝
        const is short for constant. It prevents the variable from being changed in the method.

        This is the way you pass by reference and prevent the method from changing the variable.
    */
    std::vector<int> highScores;
    highScores.reserve(10);
    printInfo(highScores);//size: 0?  capacity: 32767
    for (int i = 0; i < 10; ++i)
    {
        highScores.push_back(rand());
        printInfo(highScores);
    }
    float avg = average(highScores);



    /*
        CHALLENGE 2:

            Write a method to calculate the stats on a vector of grades
            1) create a method to calculate the min, max. 
                pass the grades vector as a const reference. Use ref parameters for min and max.
            2) call the method in main and print out the min, max.

    */
    float minGrade, maxGrade;
    Stats(minGrade, maxGrade, grades);
    std::cout << "Low Grade: " << minGrade << "\nHigh Grade: " << maxGrade << "\n";




    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  Removing from a vector  ]

        clear() - removes all elements from the vector
        erase(position) - removes the element at the position
        erase(starting position, ending position) - removes a range of elements. the end position is not erased.

    */
    print(highScores);

    for (size_t i = 0; i < highScores.size();)
    {
        if (highScores[i] < 2500)
            highScores.erase(highScores.begin() + i);
        else
            ++i;
    }


    /*
        INTERMEDIATE LEVEL...
        a way using std::remove_if and a lambda
    highScores.erase(
        std::remove_if(highScores.begin(),
            highScores.end(),
            [](int score) { return score < 2500; }),
        highScores.end());
    */


    print(highScores);



    /*
        CHALLENGE 3:

            Using the vector of grades you created.
            Remove all the failing grades (grades < 59.5).
            Print the grades.
    */
    PrintGrades(grades);
    for (size_t i = 0; i < grades.size(); )
    {
        if (grades[i] < 59.5)
            grades.erase(grades.begin() + i);
        else
            i++;
    }
    PrintGrades(grades);




    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        
        size(): # of items that have been ADDED
        capacity(): length of the internal array
        reserve(n): presizes the internal array
    */
    std::vector<int> scores;
    scores.reserve(10); //makes the internal array to hold 10 items.

    printInfo(scores);
}