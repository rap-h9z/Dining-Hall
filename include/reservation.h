#ifndef RESERVATION_H_INCLUDED
#define RESERVATION_H_INCLUDED
#include <string.h>
#include <iostream>
#include "student.h"
#include "dininghall.h"
using namespace std;

enum RStatus{Success,Cancelled,Failed};

class Reservation
{
    int _reservation_id;
    DiningHall *_dHall;
    Meal *_meal;
    RStatus _rstatus;
    time_t _created_at;
    public:
    Reservation();
    void print()const;
    bool cancel();

    //setters()
    void setreserveid(int reservationid){_reservation_id=reservationid;}
    void setdininghall(DiningHall dhall){_dHall=&dhall;}
    void setmeal(Meal meal){_meal=&meal;}
    void setstatus(RStatus rstatus){_rstatus=rstatus;}
    void setcareatedat(time_t createdat)
    {
        _created_at=((createdat>=0)?createdat:0);
    }

    //getters()
    int getreserveid()const{return _reservation_id;}
    DiningHall getdininghall()const{return *_dHall;}
    Meal getmeal()const{return *_meal;}
    RStatus getrstatus()const{return _rstatus;}
    time_t getcreatedat()const{return _created_at;}
};
#endif