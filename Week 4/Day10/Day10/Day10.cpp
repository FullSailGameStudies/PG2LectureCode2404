// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Player.h"



/*
    ╔══════════╗
    ║ File I/O ║
    ╚══════════╝

    3 things are required for File I/O:
    1) Open the file
    2) read/write to the file
    3) close the file



*/
int main()
{
    std::cout << "Hello PG2!\n";

    std::string path = "C:\\temp\\2404\\";
    std::string fileName = "2404.txt";
    std::string fullPath = path + fileName;
    char delimiter = '$';
    std::ofstream outFile(fullPath);
    if (outFile.is_open())
    {
        outFile << "Hello Gotham!\n" << delimiter << 5 << delimiter << 12.7;
    }
    else
        std::cout << "That file could not be opened: " << fullPath << "\n";
    outFile.close();

    std::string line;
    std::ifstream infile(fullPath);
    if (infile.is_open())
    {
        while (std::getline(infile, line))
        {
            std::cout << line << "\n";

            std::string lineData;
            //getline uses streams
            std::stringstream lineStream(line);
            while (std::getline(lineStream, lineData, delimiter))
            {
                std::cout << lineData << "\n";
            }
        }
    }
    else
        std::cout << "That file could not be opened: " << fullPath << "\n";
    infile.close();


    {
        Player steev("Steve", 20, 20, 20);
        std::ofstream playerFile("Player.csv");
        if (playerFile.is_open())
        {
            steev.Serialize(playerFile, '$');
        }
        else
            std::cout << "That file could not be opened\n";

    }

    std::ifstream inPlayer("Player.csv");
    if (inPlayer.is_open())
    {
        std::string playerLine;
        std::getline(inPlayer, playerLine);
        Player alex = Player::Deserialize('$', playerLine);
        //Player alex(playerLine, '$');
        //std::cout << alex.GamerTag() << " " << alex.Armor() << "\n";

        alex.Serialize(std::cout, '\n');
    }
    else
        std::cout << "That file could not be opened\n";

    /*

        ╔════════════════╗
        ║ write csv data ║
        ╚════════════════╝

        [  Open the file  ]
        [  Write to the file  ]
        [  Close the file  ]

        you need the path to the file
            use full path ( drive + directories + filename )
            or use relative path ( directories + filename )
            or current directory ( filename )

        Make sure to separate the data in the file with a delimiter.
        The delimiter is important because it is used
            to separate the data when reading the file back in.


        Lecture code: set a filePath variable, open an output file, write some csv data to it
    */


    /*

        ╔═══════════════╗
        ║ read csv data ║
        ╚═══════════════╝

        [  Open the file  ]
        [  read the file  ]
        [  Close the file  ]

        Lecture code: using the filePath variable, open an input file, use getline to read a line, print the line
    */


    /*

        ╔═════════════════════╗
        ║ parsing csv strings ║
        ╚═════════════════════╝
        
        use getline on a string stream instead of a file stream

        Lecture code: 
            using the line read in above, use a stringstream to split the line using getline.
            store the separate items in a vector
            parse each item in the vector to an appropriate variable.
        

    */





    /*

        CHALLENGE:

        Parse the multi csv string (below) to get the data.
        NOTE: the data is a collection of object data.
        There are multiple delimiters.
        Separate on the first delimiter (collectionSeparator) to get the csv data for each object.
        Then, separate the object csv data on objectSeparator to get the details of the object.

        EX: hero#hero#hero   each hero is separated by a #
            name^secret^age  the details of each hero is separated by a ^

    */
    std::string multi = "Batman^Bruce Wayne^35#Superman^Clark Kent^25#Wonder Woman^Diana Prince^25#Aquaman^Arthur Curry^12";
    char collectionSeparator = '#';
    char objectSeparator = '^';
}