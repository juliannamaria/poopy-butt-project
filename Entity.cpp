#include <iostream>
#include <iomanip>
#include "Entity.h"

using namespace std;

Entity::Entity()
{
    _gold = 0;
    _hp = 0;
    _name = "";
    _condition = 'H';
    _is_enemy = false; 
}

Entity::Entity(string name, double hp, int gold, char condition, bool enemy)
{

    _name = name;
    _is_enemy = enemy;

    //check hp
    if (hp > 0)
    {
        _hp = hp;
    }
    else if (hp <= 0)
    {
        _hp = 0;
    }

    //check gold
    if (gold > 0)
    {
        _gold = gold;
    }
    else if (gold <= 0)
    {
        _gold = 0;
    }

    //check condition
    if (condition != 'H' && condition && 'D' || condition && 'P')
    {
        _condition = 'H';
    }
    else if (condition == 'H')
    {
        _condition == 'H';
    }
    else if (condition == 'D')
    {
        _condition == 'D';
    }
    else if (condition == 'P')
    {
        _condition == 'P';
    }
}

string Entity::getName()
{
    return _name;
}

double Entity::getHP()
{
    return _hp;
}

char Entity::getCondition()
{
    return _condition;
}

int Entity::getGold()
{
    return _gold;
}

bool Entity::getIsEnemy()
{
    return _is_enemy;
}

void Entity::setName(string name)
{
    _name = name;
}

//unsure from this point on
void Entity::setHP(double hp)
{
    if (hp > 0)
    {
        _hp = hp;
    }
}

void Entity::setCondition(char condition)
{
    if (condition == 'H' || condition == 'D' || condition == 'P')
    {
        _condition = condition;
    }
}

void Entity::setGold(int gold)
{
    if (gold > 0)
    {
        _gold = gold;
    }
}

void Entity::setIsEnemy(bool is_enemy)
{
    _is_enemy = is_enemy;
}

void Entity::printStats()
{
    
    cout << _name << "'s stats:" << endl;

    cout << fixed << setprecision(2) << "HP: " << _hp << endl;
    cout << "Condition: " << _condition << endl;
    cout << fixed << setprecision(2) << "Gold: " << _gold << endl;
    
    //check if enemy 
    if (getIsEnemy() == true)
    {
        cout << "Is Enemy: Yes" << endl;
    }
    else 
    {
        cout << "Is Enemy: No" << endl;
    }
}

void Entity::swap(int userChoice)
{
    //function call allows user to change weapons or potions depending on the input choice
    

}

void Entity::drop(int userChoice)
{
    //function call allows user to drop weapons or potions depending on the input choice
}

void Entity::usePotion(int userChoice)
{
    //function call allows user to sort through potion choices and decide which to use
}

void Entity::updateEquipment(int equipIndex, Equipment weapon)
{
    //function call allows user to update status of equipment being used; use index of weapons 
} 



