#include "Map.h"
#include <ctype.h>
#include <fstream>
#include "Game.h"

#define RED "\033[41m" 
#define GREEN "\033[42m"
#define BLUE "\033[44m"
#define MAGENTA "\033[45m"
#define CYAN "\033[46m"
#define RESET "\033[0m"

using namespace std;

int main()
{
    /*CALL PLAY GAME FUNCTION HERE*/
    srand (time(NULL));

    int choice;
    bool end_game = false;
    const int NUM_PLAYERS = 2; // Assuming 2 players
    bool same_turn = false;
    int currentPlayer = 0; // To keep track of the current player


    Game game; 

    game.playGame();
    Map starterMap = Map(); 

    //Initialize tiles
    starterMap.initializeMap();
    starterMap.displayMap();
    

    while (end_game == false) 
    {
    cout << "Player x's turn." << endl;
    cout << "Please enter a valid choice (1, 2, 3)." << endl;
    cout << "1. Move " << endl;
    cout << "2. Swap/Drop Weapon" << endl;
    cout << "3. Use potion" << endl;
    cout << "4. Print Player Stats" << endl;
    cout << "5. Quit" << endl;


    //error handling for menu choice
    cin >> choice;
        do
        {
        if (choice < 1 || choice > 5) 
        {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid choice. Please enter a valid number." << endl;
        cin >> choice;
        }
        } while (choice < 1 || choice > 5);





    //player 1's turn
    if (currentPlayer == 0)
    {
        if(choice == 1)
        {
        starterMap.movePlayer((0));
        starterMap.displayMap();


        // if (players[0].getPosition() >= 82) 
        // {
            //figure out how to use getname function
            //from my driver file
            // cout << players[currentPlayer].getName() << " wins! Hooray!" << endl;
            // cout << "-----------------------------------" << endl;
            // cout << "Here are your final stats: " << endl;
            // cout << "Player name: " << players[0].getName() << endl; 
            // cout << "Character: " << players[0].getChosenCharacter() << endl;
            // cout << "Stamina: " << players[0].getStamina() << endl;
            // cout << "Gold: " << players[0].getGold() << endl;
            // cout << "-----------------------------------" << endl;
            // displayMainMenu = false;
            // end_game = true;
            // break;
        // }
        }
    }






    //player 2's turn
    if (currentPlayer == 1)
    {
        if(choice == 1)
    {
        starterMap.movePlayer((1));
        starterMap.displayMap();

    }
    }





    //statement for player turn ending and going to next player
            if (same_turn)
            {
            currentPlayer = (currentPlayer + 2) % NUM_PLAYERS; // keeps same turn
            }
        else
            {
            currentPlayer = (currentPlayer + 1) % NUM_PLAYERS; // Move to the next player after the turn
            }


    
    }
    // /*PRINT MAP*/
    // //Initialize random seed
    // srand (time(NULL));

    // Map starterMap = Map(); 
    
    // //Initialize tiles
    // starterMap.initializeMap();

    // starterMap.displayMap();
    /*TEMPORARY SILENCE*/

    // //Demonstrate tiles
    // //Top lane corresponds to Player 1
    // for (int i = 0; i < 50; i++)
    // {
    //     cout << starterMap.getMapPos(0, i) << "1" << " " << RESET;
    // }
    // cout << endl;

    // //Bottom lane corresponds to Player 2
    // for (int i = 0; i < 50; i++)
    // {
    //     cout << starterMap.getMapPos(1, i) << "2" << " " << RESET;
    // }

    // cout << RESET << endl;
    //end of map print


    /* CONTINUE REST OF MENU HERE */


    return 0;

}

