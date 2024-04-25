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
    // all_equip = {};
    // all_potions = {};
    // generatePotions();
    // generateEquip();
}

Game::Game(Entity players[], int num_players)
{
    // all_equip = {};
    // all_potions = {};
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

void Game::displayShop()
{
    int numPotions = 3;
    int numEquip = 3;
    
    cout << "Welcome to the shop! Here are the available potions and equipment:" << endl;
    cout << "-----------------------------" << endl;
    for (int i = 0; i < numPotions && i < _all_potions.size(); i++)
    {
        cout << i + 1 << ". " << _all_potions[i].name << endl;
        cout << "Description: " << _all_potions[i].descrption << endl;
        cout << "Effect: " << _all_potions[i].effect_value << endl;
        cout << "Type: " << _all_potions[i].type << endl;
        cout << "Price: " << _all_potions[i].price << " gold" << endl;
        cout << " " << endl;
    }
    cout << "-----------------------------" << endl;
    for (int i = 0; i < numEquip && i < _all_equip.size(); i++)
    {
        cout << i + 1 << ". " << _all_equip[i].name << endl;
        cout << "Description: " << _all_equip[i].descrption << endl;
        cout << "Effect: " << _all_equip[i].effect_value << endl;
        cout << "Type: " << _all_equip[i].type << endl;
        cout << "Price: " << _all_equip[i].price << " gold" << endl;
        cout << " " << endl;
    }
    cout << "-----------------------------" << endl;

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
    cout << "Let's begin!" << endl;


    // cout << "-----------------------------" << endl;

    /*PRINT MAP*/
    // Initialize random seed

    // Map starterMap = Map(); 

    // //Initialize tiles
    // starterMap.initializeMap();
    // starterMap.displayMap();

    // cout << "-----------------------------" << endl;
    // cout << "Let's begin!" << endl;
    // cout << " " << endl;

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
    // cout << "ATTEMPTING TO LOAD CHARACTERS" << endl;
    // loadCharacters("myIslandEnemies.txt", _island_enemies, 7);
    
    // loadCharacters("myEpicEnemies.txt", _epic_enemies, 3);
    // cout << "DONE LOAD CHARACTERS" << endl;


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

    if (!filein.is_open()) 
    {
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

/*LOAD ISLAND ENEMIES*/
bool Game::loadIslandEnemies(string filename, Entity islandEnemies[], const int CHARACTERS_SIZE)
{
    ifstream filein;
    string line;
    const static int arr_size = 11;
    string arr[arr_size];

    //?? i think so
    filein.open("myIslandEnemies.txt");

    if (!filein.is_open()) 
    {
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

        Entity islandEnemy_object;

        // Assign values to the character object
        islandEnemy_object.setName(arr[0]);
        islandEnemy_object.setType(arr[1][0]);
        islandEnemy_object.setHP(stoi(arr[2]));
        islandEnemy_object.setStamina(stoi(arr[3]));
        islandEnemy_object.setDefense(stoi(arr[4]));
        islandEnemy_object.setCondition(arr[5][0]);
        islandEnemy_object.setAdvantage(arr[6] == "True");
        // character_object.setElementalWeakness(arr[7][0]);
        islandEnemy_object.setGold(stoi(arr[8]));
        islandEnemy_object.setStartingItems(arr[9]);
        islandEnemy_object.setNumItems(stoi(arr[10]));
        // character_object.setUltimate(arr[11]);

        islandEnemies[i] = islandEnemy_object; // Assign the character object to the array

        i++;
    }
    
    filein.close();
    return true;
}

/*LOAD EPIC ENEMIES*/
bool Game::loadEpicEnemies(string filename, Entity epicEnemies[], const int CHARACTERS_SIZE)
{
    ifstream filein;
    string line;
    const static int arr_size = 11;
    string arr[arr_size];

    //?? i think so
    filein.open("myEpicEnemies.txt");

    if (!filein.is_open()) 
    {
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

        Entity epicEnemy_object;

        // Assign values to the character object
        epicEnemy_object.setName(arr[0]);
        epicEnemy_object.setType(arr[1][0]);
        epicEnemy_object.setHP(stoi(arr[2]));
        epicEnemy_object.setStamina(stoi(arr[3]));
        epicEnemy_object.setDefense(stoi(arr[4]));
        epicEnemy_object.setCondition(arr[5][0]);
        epicEnemy_object.setAdvantage(arr[6] == "True");
        // character_object.setElementalWeakness(arr[7][0]);
        epicEnemy_object.setGold(stoi(arr[8]));
        epicEnemy_object.setStartingItems(arr[9]);
        epicEnemy_object.setNumItems(stoi(arr[10]));
        // character_object.setUltimate(arr[11]);

        epicEnemies[i] = epicEnemy_object; // Assign the character object to the array

        i++;
    }
    
    filein.close();
    return true;
}

void displayVector(vector <Equipment> poop)
{
    int length = poop.size();
    for(int i = 0; i < length; i++)
    {
        cout << poop.at(i).name << " ";
    }
    cout << endl;
}


/*LATER*/
// bool Game::loadItems()
// {
//     ifstream filein;
//     string line;
//     const static int arr_size = 6;
//     string arr[arr_size];

//     //?? i think so
//     filein.open("myItems.txt");
    
//     if (!filein.is_open()) 
//     {
//         return false;
//     }

//     getline(filein, line); // Ignore the header line
//     // int i = 0;

//     //Iterates through playabale characters and their stats
//     while (getline(filein, line))
//     {
//         //??
//         // if (!getline(filein, line)) // Read a line from the file
//         // break;

//         split(line, '|', arr, arr_size); // Split the line by '|'
        
//         if (arr[2][0] == 'P')
//         {
//             cout << "LOADING ITEMS P" << endl;
//             Potion initial_p;
//             initial_p.name = arr[0];
//             initial_p.type = arr[2][0];
//             initial_p.effect_value = stod(arr[3]);
//             initial_p.price = stod(arr[5]);
//             initial_p.descrption = arr[1];

//             all_potions.push_back(initial_p);
//         }

//         else if (arr[2][0] == 'D' || arr[2][0] == 'S')
//         {
//             cout << "LOADING ITEMS D S" << endl;
//             Equipment initial_e;
            
//             initial_e.name = arr[0];
            
//             initial_e.type = arr[2][0];
//             initial_e.effect_value = stod(arr[3]);
            
//             initial_e.price = stod(arr[5]);
//             initial_e.descrption = arr[1];
            
//             // all_equip.push_back(initial_e);
//             cout << "A" << endl;
//         }
//         cout << (int)all_equip.size() << endl;
//         // displayVector(all_equip);
//         cout << "DISPLAY" << endl;
//         // Entity items_object;

//         // // Assign values to the character object
//         // epicEnemy_object.setName(arr[0]);
//         // epicEnemy_object.setType(arr[1][0]);
//         // epicEnemy_object.setHP(stoi(arr[2]));
//         // epicEnemy_object.setStamina(stoi(arr[3]));
//         // epicEnemy_object.setDefense(stoi(arr[4]));
//         // epicEnemy_object.setCondition(arr[5][0]);
//         // epicEnemy_object.setAdvantage(arr[6] == "True");
//         // // character_object.setElementalWeakness(arr[7][0]);
//         // epicEnemy_object.setGold(stoi(arr[8]));
//         // epicEnemy_object.setStartingItems(arr[9]);
//         // epicEnemy_object.setNumItems(stoi(arr[10]));
//         // // character_object.setUltimate(arr[11]);

//         // epicEnemies[i] = epicEnemy_object; // Assign the character object to the array

//         // i++;
//     }
    
//     filein.close();
//     return true;
// }

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


// bool Game::loadPotions()
// {

// }

// bool Game::loadEquip()
// {

// }


// bool Game::getRandomPotion(string potion_name)
// {

// }

// bool Game::getRandomEquip(string equip_name)
// {

// }

void Game::generatePotions()
{
    _all_potions.push_back(Potion {"Lesser Health Potion", "Restore HP by 10", 'P', 10, 25});
    _all_potions.push_back(Potion {"Greater Health Potion", "Restore HP by 25", 'P', 25, 50});
    _all_potions.push_back(Potion {"Lesser Stamina Potion", "Restore stamina by 10", 'P', 10, 25});
    _all_potions.push_back(Potion {"Greater Stamina Potion", "Restore stamina by 25", 'P', 25, 50});
    _all_potions.push_back(Potion {"Cleansing Potion", "Cleanse player of either Disease or Poison", 'P', 0, 150});
    _all_potions.push_back(Potion {"Greater Rejuvenation Potion", "Restore HP by 25 and stamina by 25", 'P', 25, 100});
    _all_potions.push_back(Potion {"Lesser Rejuvenation Potion", "Restore HP by 10 and stamina by 10", 'P', 10, 50});
    _all_potions.push_back(Potion {"Minor Strength Potion", "Permanently increase weapon damage by 2", 'P', 2, 50});
    _all_potions.push_back(Potion {"Major Strength Potion", "Permanently increase weapon damage by 5", 'P', 5, 75});

    // shuffles the available potions using rand()
    int n = _all_potions.size();

    for (int i = n - 1; i > 0; --i) 
    {
        int j = rand() % (i + 1);
        swap(_all_potions[i], _all_potions[j]); //swaps the values of a and b
    }
}

void Game::generateEquip()
{
    _all_equip.push_back(Equipment {"Bow of Odysseus", "Increases damage by 10", 'D', 10, 100});
    _all_equip.push_back(Equipment {"Sword of Achilles", "Increases damage by 10", 'D', 10, 100});
    _all_equip.push_back(Equipment {"Circe's Wand", "Increases damage by 15", 'D', 15, 125});
    _all_equip.push_back(Equipment {"Argos' Fangs", "Increases damage by 20", 'D', 20, 125});
    _all_equip.push_back(Equipment {"Helios' Luninous Shield", "Increases defense by 50", 'S', 50, 350});
    _all_equip.push_back(Equipment {"Trident of Poseidon", "Increases damage by 50", 'D', 50, 350});
    _all_equip.push_back(Equipment {"Demeter's Harvest Armor", "Increases defense by 25", 'S', 25, 350});
    _all_equip.push_back(Equipment {"King's Blade", "Increases damage by 60", 'D', 60, 0});
    _all_equip.push_back(Equipment {"Fangs of Scylla", "Increases damage by 60", 'D', 60, 0});
    _all_equip.push_back(Equipment {"Cyclops Gaze", "Increases defense by 50", 'S', 50, 0});
    _all_equip.push_back(Equipment {"Maul of the Giants", "Increases damage by 12", 'D', 10, 75});
    _all_equip.push_back(Equipment {"Tidal Charm of the Sirens", "Increases damage by 12", 'D', 10, 75});
    _all_equip.push_back(Equipment {"Ciconian Spear", "Increases damage by 10", 'D', 10, 75});
    _all_equip.push_back(Equipment {"Lotus Staff", "Increases damage by 10", 'D', 10, 80});
    _all_equip.push_back(Equipment {"Laestrygonian Club", "Increases damage by 15", 'D', 15, 90});
    _all_equip.push_back(Equipment {"Enchanted Want", "Increases damage by 10", 'D', 10, 100});
    
    // shuffles the available equipment using rand()
    int n = _all_equip.size();

    for (int i = n - 1; i > 0; --i) 
    {
        int j = rand() % (i + 1);
        swap(_all_equip[i], _all_equip[j]); //swaps the values of a and b
    }
}


