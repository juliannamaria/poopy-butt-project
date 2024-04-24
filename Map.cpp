#include "Map.h"

#define RED "\033[41m" 
#define GREEN "\033[42m"
#define BLUE "\033[44m"
#define MAGENTA "\033[45m"
#define CYAN "\033[46m"
#define RESET "\033[0m"

Map::Map(){}

Map::Map(int players_num, int size)
{
    m_mapArr[players_num][size] = {};
}

//Setter for position on map given the value and which player and then the index for their lane
void Map::setMapPos(string value, int playerID, int index)
{
    m_mapArr[playerID][index] = value;
}

//Getter for position on map given which player and then the index for their lane
string Map::getMapPos(int playerID, int index)
{
    return m_mapArr[playerID][index];
}

void Map::initializeMap()
{
    int rand_num1, rand_num2;
    int lane_1_red = 0, lane_1_green = 0, lane_2_red = 0, lane_2_green = 0;

    for (int i = 0; i < 50; i++)
    {
        //Generate secret number between 1 and 10
        rand_num1 = rand() % 100 + 1;
        rand_num2 = rand() % 100 + 1;

        if (rand_num1 <= 25 && lane_1_red < 4 && i > 0 && m_mapArr[0][i-1] != RED)
        {
            m_mapArr[0][i] = RED;
            lane_1_red++;
        }
        else if (rand_num1 > 25 && rand_num1 <= 50 && lane_1_green < 3 && i > 0 && m_mapArr[0][i-1] != GREEN)
        {
            m_mapArr[0][i] = GREEN;
            lane_1_green++;
        }
        else
        {
            m_mapArr[0][i] = BLUE;
        }

        if (rand_num2 <= 25 && lane_2_red < 4 && i > 0 && m_mapArr[1][i-1] != RED)
        {
            m_mapArr[1][i] = RED;
            lane_2_red++;
        }
        else if (rand_num2 > 25 && rand_num2 <= 50 && lane_2_green < 3 && i > 0 && m_mapArr[1][i-1] != GREEN)
        {
            m_mapArr[1][i] = GREEN;
            lane_2_green++;
        }
        else
        {
            m_mapArr[1][i] = BLUE;
        }
    }

    _player_position[0] = 0;
    _player_position[1] = 0;
    m_mapArr[0][49] = MAGENTA;
    m_mapArr[1][49] = MAGENTA;
}

// void Map::displayMap(int player1_pos)
// {
//     for (int i = 0; i < 50; i++)
//     {
//         if (player1_pos == i)
//         {
//             cout << getMapPos(0, i) << "1 " << RESET << " ";
//         }
//         else 
//         {
//             cout << getMapPos(0, i) << " " << RESET << " ";
//         }
//     }
//     cout << endl << endl;
//     for (int i = 0; i < 50; i++)
//     {
//         cout << getMapPos(1, i) << " " << RESET << " ";
//     }
//     //Use RESET to convert back to the default terminal text color when done
//     cout << RESET << endl;
//     cout << endl;
// }

void Map::displayMap()
{
    // cout << "POSITION : " << _player_position[0] << ", " << _player_position[1] << endl;
    //Player 1 movement
    for (int i = 0; i < 50; i++)
    {
        if (_player_position[0] == i)
        {
            cout << getMapPos(0, i) << "1" << " " << RESET;
        }
        else 
        {
            cout << getMapPos(0, i) << " " << " " << RESET;
        }
    }

    cout << endl;

    //Player 2 movement
    for (int i = 0; i < 50; i++)
    {
        if (_player_position[1] == i)
        {
            cout << getMapPos(1, i) << "2" << " " << RESET;
        }
        else 
        {
            cout << getMapPos(1, i) << " " << " " << RESET;
        }
    }

    cout << RESET << endl;
 
}

void Map::movePlayerPosition(int playerID, int steps)
{
    _player_position[playerID] += steps;
}


void Map::movePlayer(int playerID) 
{
    // Roll a 6-sided die
    int steps = rand() % 6 + 1; // Generates a random number between 1 and 6 inclusive

    // Move the player
    movePlayerPosition(playerID, steps);
}

