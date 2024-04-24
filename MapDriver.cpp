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
    Game game; 

    game.playGame();

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

