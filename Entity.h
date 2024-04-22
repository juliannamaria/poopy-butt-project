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
    Entity(string, double, int, char, bool);
    string getName();
    double getHP();
    char getCondition();
    int getGold();
    bool getIsEnemy();
    void setName(string name);
    void setHP(double HP);
    void setCondition(char condition);
    void setGold(int gold);
    void setIsEnemy(bool is_enemy);
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
    bool _is_enemy;
    //added
    double _stamina;
    double _defense;
};