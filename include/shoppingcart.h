#ifndef SHOPPINGCART_H_INCLUDED
#define SHOPPINGCART_H_INCLUDED
#include <iostream>
#include "reservation.h"
using namespace std;
class Shoppingcart
{
    vector<Reservation> _reservations;

    public:
    //transaction confirm;
    void addreservation(Reservation reservation);
    void removereservation(int ID);
    void viewshoppingcartitems();
    void clear();
    vector<Reservation> getreservations()const{return _reservations;}
};
#endif
