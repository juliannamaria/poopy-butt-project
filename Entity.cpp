#include <iostream>
#include <iomanip>
#include "Entity.h"

using namespace std;

Entity::Entity()
{
    _gold = 0;
    _hp = 0.0;
    _name = "";
    _condition = 'H'; 
    _type = ' ';
    _stamina = 0.0;
    _defense = 0.0;
    _advantage = false; 
    _starting_items = ""; 
    _num_items = 0; 

}

Entity::Entity(string name, double hp, int gold, char condition, char type, double stamina, double defense, bool advantage, char elemental_weakness, string starting_items, int num_items)
{

    _name = name;

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
    if (condition != 'H' && condition != 'D' && condition != 'P')
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

    //check type 
    if (type != 'P' && type != 'I' && type != 'E')
    {
        _type = 'P';
    }
    else if (type == 'P')
    {
        _type = 'P';
    }
    else if (condition == 'I')
    {
        _type = 'I';
    }
    else if (condition == 'E')
    {
        _type = 'E';
    }

    //check stamina 


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

char Entity::getType()
{
    return _type;
}

double Entity::getStamina()
{
    return _stamina;
}

double Entity::getDefense()
{
    return _defense;
}

bool Entity::getAdvantage()
{
    return _advantage;
}

string Entity::getStartingItems()
{
    return _starting_items;
}

int Entity::getNumItems()
{
    return _num_items;
}


void Entity::setName(string name)
{
    _name = name;
}

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

/* NEW STUFF */
void Entity::setType(char type)
{
    if (type == 'P' || type == 'I' || type == 'E')
    {
        _type = type;
    }
}

void Entity::setStamina(double stamina)
{
    if (stamina > 0)
    {
        _stamina = stamina;
    }
}

void Entity::setDefense(double defense)
{
    if (defense > 0)
    {
        _defense = defense;
    }
}

//WHAT THE FUC
void Entity::setAdvantage(bool advantage)
{
    char type = ' ';
    if (type = 'P')
    {
        _advantage = advantage;
    }
}

void Entity::setStartingItems(const string newStartingItems) 
{
    _starting_items = newStartingItems;
}

void Entity::setNumItems(int newNumItems) 
{
    _num_items = newNumItems;
}

void Entity::printStats()
{
    
    cout << _name << "'s stats:" << endl;

    cout << fixed << setprecision(2) << "HP: " << _hp << endl;
    cout << "Condition: " << _condition << endl;
    cout << fixed << setprecision(2) << "Gold: " << _gold << endl;
    
    //check if enemy 
    // if (getIsEnemy() == true)
    // {
    //     cout << "Is Enemy: Yes" << endl;
    // }
    // else 
    // {
    //     cout << "Is Enemy: No" << endl;
    // }
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



