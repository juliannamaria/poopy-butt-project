#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Game.h"


using namespace std;

Game::Game()
{
    _num_players = 0;
    // _num_enemies = 0;
}

Game::Game(Entity players[], int num_players)
{
    if (num_players > 2)
    {
        _num_players = 2;
    }
    else if (num_players < 0)
    {
        _num_players = 0;
    }
    else
    {
        _num_players = num_players;
    }

    // if (num_enemies > 2)
    // {
    //     _num_enemies = 2;
    // }
    // else if (num_enemies < 0)
    // {
    //     _num_enemies = 0;
    // }
    // else
    // {
    //     _num_enemies = num_enemies;
    // }
    
    for (int i = 0; i < _num_players; i++)
    {
        _players[i] = players[i];
    }

    // for (int i = 0; i < _num_players; i++)
    // {
    //     _enemies[i] = enemies[i];
    // }
}

int Game::getNumPlayers()
{
    return _num_players;
}

// int Game::getNumEnemies()
// {
//     return _num_enemies;
// }

void Game::setPlayersList(Entity players[], int object)
{
    if (object > 2)
    {
        object = 2;
        _num_players = 2;
    }
    else
    {
        _num_players = object;
    }

    for (int i = 0; i < object; i++)
    {
        _players[i] = players[i];
    }
}

// void Game::setEnemiesList(Entity enemies[], int object)
// {
//     if (object > 2)
//     {
//         object = 2;
//         _num_enemies = 2;
//     }
//     else
//     {
//         _num_enemies = object;
//     }

//     for (int i = 0; i < object; i++)
//     {
//         _enemies[i] = enemies[i];
//     }
// }

bool Game::setPlayer(int index, Entity new_player)
{
    if (index < 0 || index > 2)
    {
        return false;
    }
    
    _players[index] = new_player;
    return true;
}

Entity Game::getPlayer(string name)
{
    for (int i = 0; i < 2; i++)
    {
        if (name == _players[i].getName())
        {
            return _players[i];
        }
    }

    Entity empty;
    return empty;
}

// bool Game::setEnemy(int index, Entity enemy)
// {
//     if (index < 0 || index > 2)
//     {
//         return false;
//     }
    
//     _enemies[index] = enemy;
//     return true;
// }

// Entity Game::getEnemy(string name)
// {
//     for (int i = 0; i < 2; i++)
//     {
//         if (name == _enemies[i].getName())
//         {
//             return _enemies[i];
//         }
//     }
// }

int Game::findPlayer(string name)
{
    for (int i = 0; i < 2; i++)
    {
        if (name == _players[i].getName())
        {
            return i;
        }
    }
    return -1;
}

// int Game::findEnemy(string name)
// {
//     for (int i = 0; i < 2; i++)
//     {
//         if (name == _enemies[i].getName())
//         {
//             return i;
//         }
//     }
//     return -1;
// }

void Game::printAllStats()
{
    for (int i = 0; i < 2; i++)
    {
        _players[i].printStats();
        cout << "----------------------------------------------" << endl;
    }

    // for (int i = 0; i < 2; i++)
    // {
    //     _enemies[i].printStats();
    //     cout << "----------------------------------------------" << endl;
    // }
}

int Game::combat(Entity player)
{
    //regulates gold intake if the enemy is defeated
    //return -1 if a player dies/forfeits
}

void Game::shop(Potion all_potions[], Equipment all_equip[])
{
    //takes in potion and equipment information to randomize shop availability
}

// void Game::loadEntity()
// {
//     //function controls displaying player/enemies stats, creates new entities and populates arrays of potion and equipment
//     ifstream file_in;

//     file_in.open("myEntity.txt");

//     if (file_in.is_open())
//     {
//         string line = "";
//         int line_idx = 0;
//         getline(file_in, line);

//         while (!file_in.eof())
//         {
//             getline(file_in, line);

//             cout << line_idx << ": " << line << endl;

//             line_idx++;
//         }
//     }

//     else
//     {
//         cout << "Could not open file" << endl;
//     }

//     file_in.close();
    
// }

void Game::playGame() 
{
    cout << "-----------------------------" << endl;
    cout << "WELCOME TO THE ODYSSEY!" << endl;
    cout << "-----------------------------" << endl;

    loadCharacters(); 

    loadCharacters();

    
    



    


}

bool Game::validateInt(string input)
{
    int length_input = input.length();

    if (length_input == 0)
    {
        return false;
    }

    for (int i = 0; i < length_input; i++)
    {
        if (input[i] == ' ')
        {
            return false;
        }
    }
    return true;

}

/* SPLIT FUNCTION */
int split(string line, char seperator, string words[], const int ARR_SIZE)
{
    if (line.empty())
    {
        return 0;
    }

    int size = 0;
    size_t pos = 0; 
    size_t found;

    while ((found = line.find(seperator, pos)) != string::npos)
    {
        if (size >= ARR_SIZE)
        {
            return -1;
        }
        words[size++] = line.substr(pos, found - pos);
        pos = found + 1;
    }

    if (pos < line.size())
    {
        if (size >= ARR_SIZE)
        {
            return -1; //Array is full
        }
        words[size++] = line.substr(pos);
    }

    if (size == 0)
    {
        words[size++] = line;
    }

    return size;
}

/* LOAD CHARACTERS */
bool loadCharacters(string filename, Entity characters[], const int CHARACTERS_SIZE, char type) {
    ifstream filein;
    string line;
    const static int arr_size = 11;
    string arr[arr_size];

    //?? i think so
    filein.open("myPlayers.txt");filename;

    if (!filein.is_open()) {
        return false;
    }

    getline(filein, line); // Ignore the header line

    //Iterates through playabale characters and their stats
    while (getline(filein, line))
    {
        for (int i = 0; i < CHARACTERS_SIZE; i++) 
        {
            //??
            if (!getline(filein, line)) // Read a line from the file
            break;

            split(line, '|', arr, arr_size); // Split the line by '|'

            Entity character_object;

            // Assign values to the character object
            character_object.setName(arr[0]);
            character_object.setType(arr[1][0]);
            character_object.setHP(stoi(arr[2]));
            character_object.setStamina(stoi(arr[3]));
            character_object.setDefense(stoi(arr[4]));
            character_object.setCondition(arr[5][0]);
            character_object.setAdvantage(arr[6] == "True");
            // character_object.setElementalWeakness(arr[7][0]);
            character_object.setGold(stoi(arr[8]));
            character_object.setStartingItems(arr[9]);
            character_object.setNumItems(stoi(arr[10]));
            // character_object.setUltimate(arr[11]);

            characters[i] = character_object; // Assign the character object to the array
        }
    }
    
    filein.close();
    return true;
}