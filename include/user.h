#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include<iostream>
#include<string.h>
using namespace std;
class User
{
    int _user_ID;
    string _name;
    string _last_name;
    string _hashedpassword;
    public:
    User(int userid=000000,string name=" ",string lastname=" ",string hashedpass=" ");
    virtual void print()const;
    virtual void getType();

    //setters
    void setuserid(int userid){_user_ID=userid;}
    void setname(string name){_name=name;}
    void setlastname(string lastname){_last_name=lastname;}
    void sethashedpass(string hashedpass){_hashedpassword=hashedpass;}

    //getters
    int getuserid()const{return _user_ID;}
    string getname()const{return _name;}
    string getlastname()const{return _last_name;}
    string gethashedpass()const{return _hashedpassword;}

};
#endif