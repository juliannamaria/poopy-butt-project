#include <iostream>
#include "Entity.h"

using namespace std;

// struct Potion
// {
//     string name;
//     char type;
//     double effect_value;
//     int quantity;
// };

// struct Equipment
// {
//     string name;
//     char type;
//     char element;
//     double damage;
//     double defense;
//     double price;
// };

class Game
{
    public:
    Game(); //default constructor
    Game(Entity[], int);
    int getNumPlayers();
    // int getNumEnemies();
    void setPlayersList(Entity[], int);
    // void setEnemiesList(Entity[], int);
    bool setPlayer(int, Entity);
    Entity getPlayer(string);
    // bool setEnemy(int, Entity);
    // Entity getEnemy(string);
    int findPlayer(string);
    int findCharacterIndex(string);
    // int findEnemy(string);
    void printAllStats();
    //added
    int combat(Entity player);
    void shop(Potion all_potions[], Equipment all_equip[]);
    //void loadEntity();
    void playGame();
    bool gameEnd();
    bool validateInt(string);
    bool loadCharacters(string filename, Entity characters[], const int); 
    bool removeCharacter(string name);


    private:
    Entity _players[2];
    // Entity _enemies[2];
    int _num_players;
    Entity _characters[4];
    Entity _island_enemies[7];
    Entity _epic_enemies[3];
    // int _num_enemies;
    //added
    Potion _allPotions[4];
    Equipment _allEquip[4];
    int _num_characters;
    //Entity _possible_characters[4];

    //updated
    // vector <Entity> all_players;
    // vector <Entity> all_enemies;
    // vector <Potion> all_potions;
    // vector <Equipment> all_equipment;

};
