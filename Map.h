#ifndef MAP_H
#define MAP_H

#include <iostream>
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
#include<ctime>


using namespace std;

// class Map
// {
//     public:
//     Map(); //Default constructor
//     Map(int players_num, int size); // Parametrized constructor

//     //Setter-Getter pair for map position
//     void setMapPos(string value, int playerID, int index);
//     string getMapPos(int playerID, int index);

//     //Alter to produce correct ratios of map tiles
//     void initializeMap();
//     void displayMap(int player1_pos);

//     private:
//     //2 for 2 players, 50 for 50 tiles per lane
//     string m_mapArr[2][50] = {};
// };


/*NEW*/
class Map
{
    public:
    Map(); //Default constructor
    Map(int players_num, int size); // Parametrized constructor

    //Setter-Getter pair for map position
    void setMapPos(string value, int playerID, int index);
    string getMapPos(int playerID, int index);

    //Alter to produce correct ratios of map tiles
    void initializeMap();
    void displayMap();
    //void displayMap(int player1_pos);

    //move and update player position
    void movePlayerPosition(int playerID, int steps);

    void movePlayer(int playerID);

    private:
    //2 for 2 players, 50 for 50 tiles per lane
    string m_mapArr[2][50] = {};

    // map positioning for two players 
    int _player_position[2]; // <- remove incase break

    
};

#endif