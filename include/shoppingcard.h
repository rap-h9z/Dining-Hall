#ifndef SHOPPINGCARDS_H_INCLUDED
#define SHOPPINGCARDS_H_INCLUDED
#include <iostream>
#include "reservation.h"
using namespace std;
class Shoppingcard
{
    vector<Reservation> _reservations;
    public:
    //transaction confirm;
    void addreservation(Reservation reservation);
    void removereservation(int ID);
    void viewshoppingcarditems();
    void clear();
    vector<Reservation> getreservations()const;
};
#endif
