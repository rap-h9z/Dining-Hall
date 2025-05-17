#ifndef PANEL_H_INCLUDED
#define PANEL_H_INCLUDED
#include <iostream>
#include "reservation.h"
#include"student.h"
using namespace std;
class Panel
{
    Student *_student;
    public:
    Panel(Student student):_student(&student){}
    void action(int);
    void showmenu();
    void showStudentInfo();
    void checkBalance();
    void viewReservations();
    void addToShoppingCart();
    void confirmShoppingCart();
    void removeShoppingCartItem();
    void increaseBalance();
    void viewRecentTransactions();
    void cancelReservation(int) ;
    void exit();
};
#endif