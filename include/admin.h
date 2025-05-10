#ifndef USER_H
#define USER_H
#include <iostream>
#include "user.h"
using namespace std;
class Admin:public User
{
    public:
    void print()const;
    void getType();
};
#endif