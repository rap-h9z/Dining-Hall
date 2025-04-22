#ifndef MEAL_H_INCLUDED
#define MEAL_H_INCLUDED
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
class Meal
{
    int _meal_id;
    string _name;
    float _price;
    Enum _meal_type;
    vector<string> _side_items;
    public:
    Meal();
    void print()const;
    void update_price(float new_price);
    void add_side_item(string item);

    //setters()
    void setmealid(int mealid);
    void setname(string name);
    void setprice(float price);
    void setenum(Enum mealtype);
    void setsideitems(vector<string> sideitem);

    //getters()
    int getmealid(){return _meal_id;}
    string getname(){return _name;}
    float getprice(){return _price;}
    Enum getmealtype(){return _meal_type;}
    vector<string> getsideitems(){return _side_items;}
};
#endif