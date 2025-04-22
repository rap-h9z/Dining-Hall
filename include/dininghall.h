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
    void sethallid(int hallid);
    void setname(string name);
    void setadd(string add);
    void setcapacity(int capacity);

    //getters()
    int gethallid(){return _hall_id;}
    string getname(){return _name;}
    string getadd(){return _address;}
    int getcapacity(){return _capacity;}
};
#endif