#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <iostream>
#include <string.h>
#include <algorithm>
#include"user.h"
#include "meal.h"
#include "reservation.h"
using namespace std;

class Student:public User
{
    int _user_id;
    string _student_id;
    string _name;
    string _email;
    string _phone;
    float _balance;
    bool _is_active;
    vector<Reservation> _reservations;
    public:
    Student();
    void print()const;
    void reserve_meal(Meal);
    bool cancel_reservation(Reservation);
    bool isactive();
    void activated();
    void deavtivated();
    void getType();

    //setters()
    void setuserid(int userid)
    {
       if (userid>=10000000)
          _user_id=userid;
        else
            throw runtime_error("User ID must be at least 8 digits.");  
       
    }
    void setstudentid(string studentid)
    {
        if (studentid.length()==10&& all_of(studentid.begin(),studentid.end(),::isdigit))
            _student_id=studentid;
        else
        {
            throw runtime_error("Student ID must be 10 digits.");
        }
    }
    void setname(string name){_name=name;}
    void setemail(string email)
    {
        if(email.find('@gimail.com')!=string::npos)
           _email=email;
        else 
           throw runtime_error("INVALID !!");

    }
    void setphone(string phone)
    {
        if (phone.length()==11)
            _phone=phone;
        else
            throw runtime_error("INVALID phone number!!");   
    }
    void setbalance(float balance){_balance=(balance>=0)?balance:0;}
    void setactive(bool active){_is_active=active;}
    void setreservations(vector<Reservation> reservations){_reservations=reservations;}

    //getters()
    int getuserid()const{return _user_id;}
    string getstudentid()const{return _student_id;}
    string getname()const{return _name;}
    string getemail()const{return _email;}
    float getbalance()const{return _balance;}
    bool getactive()const{return _is_active;}
    vector<Reservation> getreservations()const{return _reservations;}
};
#endif