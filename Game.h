#include <iostream>
#include "Entity.h"

using namespace std;

struct Potion
{
    string name;
    char type;
    double effect_value;
    int quantity;
};

struct Equipment
{
    string name;
    char type;
    char element;
    double damage;
    double defense;
    double price;
};


class Game
{
    public:
    Game(); //default constructor
    Game(Entity[], Entity[], int, int);
    int getNumPlayers();
    int getNumEnemies();
    void setPlayersList(Entity[], int);
    void setEnemiesList(Entity[], int);
    bool setPlayer(int, Entity);
    Entity getPlayer(string);
    bool setEnemy(int, Entity);
    Entity getEnemy(string);
    int findPlayer(string);
    int findEnemy(string);
    void printAllStats();
    //added
    int combat(Entity player, Entity enemy);
    void shop(Potion all_potions[], Equipment all_equip[]);
    void loadEntity();
    void playGame();

    private:
    Entity _players[2];
    Entity _enemies[2];
    int _num_players;
    int _num_enemies;
    //added
    Potion _allPotions[9];
    Equipment _allEquip[17];

};