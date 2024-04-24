#include <iostream>


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

class Entity
{
    public:
    Entity(); //default constructor
    Entity(string name, double hp, int gold, char condition, char type, double stamina, double defense, bool advantage, string starting_items, int num_items);

    string getName();
    void setName(string name);

    double getHP();
    void setHP(double HP);

    char getCondition();
    void setCondition(char condition);

    int getGold();
    void setGold(int gold);

    // bool getIsEnemy();
    // void setIsEnemy(bool is_enemy);

    /* ADDED */
    char getType();
    void setType(char type);

    double getStamina();
    void setStamina(double stamina);

    double getDefense();
    void setDefense(double defense);

    bool getAdvantage();
    void setAdvantage(char type);

    string getStartingItems();
    void setStartingItems(string newStartingItems);

    int getNumItems();
    void setNumItems(int newNumItems);

    bool validateInt(string);

    void printStats(); 

    //added
    void swap(int userChoice);
    void drop(int userChoice);
    void usePotion(int userChoice);
    void updateEquipment(int equipIndex, Equipment weapon);

    private:
    string _name;
    double _hp;
    int _gold;
    char _condition;
    char _type;
    // bool _is_enemy;
    //added
    double _stamina;
    double _defense;
    bool _advantage;
    string _starting_items;
    int _num_items;

};
