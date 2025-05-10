#ifndef USER_H_INCLUDED
#define USER_H_iNCLUDED
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