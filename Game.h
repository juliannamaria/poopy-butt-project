#include <iostream>
#include <vector>
#include "Entity.h"
#include "Map.h"

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
    bool removeCharacter(string name);
    // int findEnemy(string);
    void printAllStats();
    //added
    int combatIsland(int player_idx, Entity island_enemy);
    int combatEpic(int player_idx, Entity epic_enemy);
    void displayShop();
    //void loadEntity();
    void playGame();
    bool gameEnd();
    bool validateInt(string);
    bool loadCharacters(string filename, Entity characters[], const int); 
    bool loadIslandEnemies(string filename, Entity islandEnemies[], const int);
    bool loadEpicEnemies(string filename, Entity epicEnemies[], const int);
    // bool getIslandEnemy();
    // bool getEpicEnemy();



    
    // bool loadPotions(string filename, Potion all_potions[], const int);
    // bool loadEquip();

    void generatePotions();
    void generateEquip();

    // bool loadItems();

//vectors passed by value


    private:
    Entity _players[2];
    // Entity _enemies[2];
    int _num_players;
    Entity _characters[4];
    Entity _island_enemies[7];
    Entity _epic_enemies[3];
    // int _num_enemies;
    //added
    // Potion all_potions[4];
    // Equipment all_equip[4];
    int _num_characters;
    int _num_island;
    int _num_epic;
    Map _map;
    //Entity _possible_characters[4];
    

    //updated
    vector <Potion> _all_potions;
    vector <Equipment> _all_equip;

};
