#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <iostream>
#include <string.h>
#include "meal.h"
#include "reservation.h"
using namespace std;

class Student
{
    int _user_id;
    string _student_id;
    string _name;
    string _email;
    float _balance;
    bool _is_active;
    public:
    Student();
    void print()const;
    void reserve_meal(Meal);
    bool cancel_reservation(Reservation);

    //setters()
    void setuserid(int userid);
    void setstudentid(string studentid);
    void setname(string name){_name=name;}
    void setemail(string email);
    void setbalance(float balance){_balance=(balance>=0)?balance:0;}
    void setactive(bool active){_is_active=active;}

    //getters()
    int getuserid(){return _user_id;}
    string getstudentid(){return _student_id;}
    string getname(){return _name;}
    string getemail(){return _email;}
    float getbalance(){return _balance;}
    bool getactive(){return _is_active;}
};
#endif