#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Game.h"
#include "Entity.h"

using namespace std;

Game::Game()
{
    _num_players = 0;
    _num_enemies = 0;

}

Game::Game(Entity players[], Entity enemies[], int num_players, int num_enemies)
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

    if (num_enemies > 2)
    {
        _num_enemies = 2;
    }
    else if (num_enemies < 0)
    {
        _num_enemies = 0;
    }
    else
    {
        _num_enemies = num_enemies;
    }
    
    for (int i = 0; i < _num_players; i++)
    {
        _players[i] = players[i];
    }

    for (int i = 0; i < _num_players; i++)
    {
        _enemies[i] = enemies[i];
    }
}

int Game::getNumPlayers()
{
    return _num_players;
}

int Game::getNumEnemies()
{
    return _num_enemies;
}

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

void Game::setEnemiesList(Entity enemies[], int object)
{
    if (object > 2)
    {
        object = 2;
        _num_enemies = 2;
    }
    else
    {
        _num_enemies = object;
    }

    for (int i = 0; i < object; i++)
    {
        _enemies[i] = enemies[i];
    }
}

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

bool Game::setEnemy(int index, Entity enemy)
{
    if (index < 0 || index > 2)
    {
        return false;
    }
    
    _enemies[index] = enemy;
    return true;
}

Entity Game::getEnemy(string name)
{
    for (int i = 0; i < 2; i++)
    {
        if (name == _enemies[i].getName())
        {
            return _enemies[i];
        }
    }
}

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

int Game::findEnemy(string name)
{
    for (int i = 0; i < 2; i++)
    {
        if (name == _enemies[i].getName())
        {
            return i;
        }
    }
    return -1;
}

void Game::printAllStats()
{
    for (int i = 0; i < 2; i++)
    {
        _players[i].printStats();
        cout << "----------------------------------------------" << endl;
    }

    for (int i = 0; i < 2; i++)
    {
        _enemies[i].printStats();
        cout << "----------------------------------------------" << endl;
    }
}

int Game::combat(Entity player, Entity enemy)
{
    //regulates gold intake if the enemy is defeated
    //return -1 if a player dies/forfeits
}

void Game::shop(Potion all_potions[], Equipment all_equip[])
{
    //takes in potion and equipment information to randomize shop availability
}

void Game::loadEntity()
{
    //function controls displaying player/enemies stats, creates new entities and populates arrays of potion and equipment
    ifstream file_in;

    file_in.open("myEntity.txt");

    if (file_in.is_open())
    {
        string line = "";
        int line_idx = 0;
        getline(file_in, line);

        while (!file_in.eof())
        {
            getline(file_in, line);

            cout << line_idx << ": " << line << endl;

            line_idx++;
        }
    }

    else
    {
        cout << "Could not open file" << endl;
    }

    file_in.close();
    
}

void Game::playGame() 
{
    //function regulates gameplay and goes back and forth between player turns and user choices
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
bool loadCharacters(string filename, Entity characters[], const int CHARACTERS_SIZE, bool is_enemy)
{
    ifstream filein;
    string line;
    const static int arr_size = 3;
    string arr[arr_size];

    filein.open(filename);

    if (!filein.is_open())
    {
        return false;
    }

    for (int i = 0; i < 4; i++)
    {
        Entity temp;
        getline(filein, line);
        split(line, '|', arr, arr_size);
        //bob -> entity.name = arr[0]
        temp.setName(arr[0]);
        temp.setHP(arr[1]);
        temp.setCondition(arr[3]);
        temp.setGold(arr[2]);
        characters[i] = temp;
    }
}

