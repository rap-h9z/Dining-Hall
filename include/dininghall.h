#ifndef DINING_HALL_H_INCLUDED
#define DINING_HALL_H_INCLUDED
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
class DiningHall
{
    int _hall_id;
    string _name;
    string _address;
    int _capacity;
    public:
    DiningHall();
    void print()const;

    //setters()
    void sethallid(int hallid)
    {
        _hall_id=(hallid>0&&hallid<11)?hallid:0;
    }
    void setname(string name){_name=name;}
    void setadd(string add){_address=add;}
    void setcapacity(int capacity){_capacity=(capacity>=0)?capacity:0;}

    //getters()
    int gethallid()const{return _hall_id;}
    string getname()const{return _name;}
    string getadd()const{return _address;}
    int getcapacity()const{return _capacity;}
};
#endif