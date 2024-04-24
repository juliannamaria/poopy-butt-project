#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Game.h"
#include "Map.h"


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
    return 0;
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
    cout << "Loading in playable characters and stats..." << endl;
    cout << "-----------------------------" << endl;

    //Call function to load playable characters
    loadCharacters("myPlayers.txt", _characters, 4);
    _num_characters = 4;

    // Print character choices
    for(int i = 0; i < _num_characters; i++)
    {
        _characters[i].printStats();
        cout << "-----------------------------" << endl;
    }
    
    //Character selection
    string chosen_one;
    cout << "Player 1, please select your character!" << endl;
    getline(cin, chosen_one); 

    // Find character in the character array with the chosen name
    int chosen_index = findCharacterIndex(chosen_one);

    // Assume that the index is correct (not -1)

    // Set character for player 1
    _players[0] = _characters[chosen_index];
    cout << "Player 1 has selected: " << chosen_one << endl;
    cout << " " << endl;
    cout << "Remaining characters:" << endl;
    cout << "-----------------------------" << endl;

    // Remove the character with the chosen name from _character array
    removeCharacter(chosen_one);

    // Print character
    for(int i = 0; i < _num_characters; i++)
    {
        _characters[i].printStats();
        cout << "-----------------------------" << endl;
    }

    // Ask for player 2 choice as name of character
    cout << "Player 2, please select your character!" << endl;
    getline(cin, chosen_one); 

    // Find character in the character array with the chosen name
    chosen_index = findCharacterIndex(chosen_one);

    // Set character for player 2
    _players[1] = _characters[chosen_index];
    cout << "Player 2 has selected: " << chosen_one << endl;
    cout << " " << endl;
    cout << "Loading map..." << endl;
    cout << "-----------------------------" << endl;

    /*PRINT MAP*/
    //Initialize random seed
    srand (time(NULL));

    Map starterMap = Map(); 

    //Initialize tiles
    starterMap.initializeMap();
    starterMap.displayMap();

    cout << "-----------------------------" << endl;
    cout << "Let's begin!" << endl;
    cout << " " << endl;








    // cout << _characters[0].getName() << "'s Stats:" << endl;
    // cout << "HP: " << _characters[0].getHP() << endl;
    // cout << "Stamina: " << _characters[0].getStamina() << endl;
    // cout << "Condition: " << _characters[0].getCondition() << endl;
    // cout << "Gold: " << _characters[0].getGold() << endl;
    // cout << "Advantage: " << _characters[0].getAdvantage() << endl;
    // cout << "Starting Items: " << _characters[0].getStartingItems() << endl;

    // cout << "-----------------------------" << endl;

    // cout << _characters[1].getName() << "'s Stats:" << endl;
    // cout << "HP: " << _characters[1].getHP() << endl;
    // cout << "Stamina: " << _characters[1].getStamina() << endl;
    // cout << "Condition: " << _characters[1].getCondition() << endl;
    // cout << "Gold: " << _characters[1].getGold() << endl;
    // cout << "Advantage: " << _characters[1].getAdvantage() << endl;
    // cout << "Starting Items: " << _characters[1].getStartingItems() << endl;

    // cout << "-----------------------------" << endl;

    // cout << _characters[2].getName() << "'s Stats:" << endl;
    // cout << "HP: " << _characters[2].getHP() << endl;
    // cout << "Stamina: " << _characters[2].getStamina() << endl;
    // cout << "Condition: " << _characters[2].getCondition() << endl;
    // cout << "Gold: " << _characters[2].getGold() << endl;
    // cout << "Advantage: " << _characters[2].getAdvantage() << endl;
    // cout << "Starting Items: " << _characters[2].getStartingItems() << endl;

    // cout << "-----------------------------" << endl;

    // cout << _characters[3].getName() << "'s Stats:" << endl;
    // cout << "HP: " << _characters[3].getHP() << endl;
    // cout << "Stamina: " << _characters[3].getStamina() << endl;
    // cout << "Condition: " << _characters[3].getCondition() << endl;
    // cout << "Gold: " << _characters[3].getGold() << endl;
    // cout << "Advantage: " << _characters[3].getAdvantage() << endl;
    // cout << "Starting Items: " << _characters[3].getStartingItems() << endl;
    
    // cout << "-----------------------------" << endl;


    //call function to load island and epic enemies 
    loadCharacters("myIslandEnemies.txt", _island_enemies, 7);

    loadCharacters("myEpicEnemies.txt", _epic_enemies, 3);



    // while (!gameEnd())
    // {

    // }

}

bool Game::gameEnd()
{
    cout << "-----------------------------" << endl;
    cout << "YAY! You have completed THE ODYSSEY!" << endl;
    cout << "-----------------------------" << endl;
    cout << "Congratulations to the winner! Want to play again?" << endl;
    cout << "-----------------------------" << endl;
    return true;
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
bool Game::loadCharacters(string filename, Entity characters[], const int CHARACTERS_SIZE) 
{
    ifstream filein;
    string line;
    const static int arr_size = 11;
    string arr[arr_size];

    //?? i think so
    filein.open("myPlayers.txt");
    // ^^ ASK QUESTION

    if (!filein.is_open()) {
        return false;
    }

    getline(filein, line); // Ignore the header line
    int i = 0;

    //Iterates through playabale characters and their stats
    while (getline(filein, line))
    {
        //??
        // if (!getline(filein, line)) // Read a line from the file
        // break;

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

        i++;
    }
    
    filein.close();
    return true;
}

int Game::findCharacterIndex(string character_name)
{
    for(int i = 0; i < _num_characters;i++)
    {
        if(_characters[i].getName() == character_name)
        {
            return i;
        }
    }
    return -1;
}

bool Game::removeCharacter(string character_name)
{
    // 1 2 3 4 5
    // target index is 2

    // 1 2 4 5
    int target_index = findCharacterIndex(character_name);
    if(target_index == -1)
    {
        return false;
    }

    for(int i = target_index + 1; i < _num_characters; i++)
    {
        _characters[i-1] = _characters[i];
    }
    _num_characters--;
    return true;
}

