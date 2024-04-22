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

//insert 'bool LoadCharacters' function here 

