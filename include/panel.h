#ifndef PANEL_H_INCLUDED
#define PANEL_H_INCLUDED
#include <iostream>
#include "reservation.h"
using namespace std;
class Panel
{
    public:
    void _action(int);
    void showmenu();
    void showStudentInfo();
    void checkBalance();
    void viewReservations();
    void addReservation(Reservation);
    void addToShoppingCart();
    void confirmShoppingCart();
    void removeShoppingCartItem();
    void increaseBalance();
    void viewRecentTransactions();
    void cancelReservation(int) ;
    void exit();
};
#endif