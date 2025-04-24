#ifndef MEAL_H_INCLUDED
#define MEAL_H_INCLUDED
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
enum MealT{Breakfast,Lunch,Dinner};
class Meal
{
    int _meal_id;
    string _name;
    float _price;
    MealT _meal_type;
    vector<string> _side_items;
    public:
    Meal();
    void print()const;
    void update_price(float new_price);
    void add_side_item(string item);

    //setters()
    void setmealid(int mealid)
    {
        _meal_id=((mealid>=0)?mealid:0);
    }
    void setname(string name){_name=name;}
    void setprice(float price)
    {
        _price=((price>=0)?price:0);
    }
    void setmealtype(MealT mealtype){_meal_type=mealtype;}
    void setsideitems(vector<string> sideitem){_side_items=sideitem;}

    //getters()
    int getmealid()const{return _meal_id;}
    string getname()const{return _name;}
    float getprice()const{return _price;}
    MealT getmealtype()const{return _meal_type;}
    vector<string> getsideitems()const{return _side_items;}
};
#endif