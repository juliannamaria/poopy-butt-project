#include "Map.h"
#include <ctype.h>
#include <fstream>

#define RED "\033[41m" 
#define GREEN "\033[42m"
#define BLUE "\033[44m"
#define MAGENTA "\033[45m"
#define CYAN "\033[46m"
#define RESET "\033[0m"

using namespace std;

// void readCharacters(string file_name)
// {
//     ifstream infile(file_name);

//     //error handling
//     if (infile.fail())
//     {
//         cout << "Could not open file." << endl;
//     }

//     cout << "------------------------------" << endl;
//     cout << "Welcome to the Odyssey!" << endl;
//     cout << "------------------------------" << endl; 

//     string line;
//     string 



// }

// void readCharacters(string file_name)
// {
//     ifstream infile(file_name);

//     if (infile.fail())
//     {
//         cout << "Failed to open file" << endl;
//     }
//     cout << "-----------------------------------------------" << endl;
//     cout << "WELCOME TO CANDYLAND!!!! Here is the list of characters a player can select from: " << endl;
//     cout << "-----------------------------------------------" << endl;

//     string line;
//     string candiesString;
//     while (getline(infile, line)) 
//     {
//         if (line.empty()) 
//         {
//             continue;
//         }
//         stringstream ss(line);
//         Character characters_object;

//         getline(ss, characters_object.name, '|');
//         getline(ss, characters_object.stamina, '|');
//         getline(ss, characters_object.gold, '|');

//         cout << "Name: " << characters_object.name << endl;
//         cout << "Stamina: " << characters_object.stamina << endl;
//         cout << "Gold: " << characters_object.gold << endl;
//         cout << "Candies: " << endl;
//         getline(ss, candiesString);

//         stringstream candy_ss(candiesString);
//         vector<string> characterCandies;

//         for (int i = 0; i < 9; i++)
//         {
//             string candy;
//             getline(candy_ss, candy, ',');
//             if(candy == "")
//             {
//                 break;
//             }
//             characterCandies.push_back(candy); 
//         }
        
//         for (int i = 0; i < 9; i+=3)
//         {
//             cout << "[" << characterCandies[i] << "]   [" << characterCandies[i+1] << "]   [" << characterCandies[i+2] << "]" << endl;
//         }
//         cout << "-----------------------------------------------------------" << endl;
        
//     }
//     infile.close();
// }

int main()
{
    //Print map
    //Initialize random seed
    srand (time(NULL));

    Map starterMap = Map();
    
    //Initialize tiles
    starterMap.initializeMap();

    starterMap.displayMap();

    // //Demonstrate tiles
    // //Top lane corresponds to Player 1
    // for (int i = 0; i < 50; i++)
    // {
    //     cout << starterMap.getMapPos(0, i) << "1" << " " << RESET;
    // }
    // cout << endl;

    // //Bottom lane corresponds to Player 2
    // for (int i = 0; i < 50; i++)
    // {
    //     cout << starterMap.getMapPos(1, i) << "2" << " " << RESET;
    // }

    // cout << RESET << endl;
    //end of map print


    /* CONTINUE REST OF MENU HERE */

    return 0;

}

