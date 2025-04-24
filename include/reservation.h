#ifndef RESERVATION_H_INCLUDED
#define RESERVATION_H_INCLUDED
#include <string.h>
#include <iostream>
#include "student.h"
#include "dininghall.h"
using namespace std;

enum Status{Success,Cancelled,Failed};

class Reservation
{
    int _reservation_id;
    Student _student;
    DiningHall _dHall;
    Meal _meal;
    Status _status;
    time_t _created_at;
    public:
    Reservation();
    void print()const;
    bool cancel();

    //setters()
    void setreserveid(int reservationid){_reservation_id=reservationid;}
    void setstudent(Student student){_student=student;}
    void setdininghall(DiningHall dhall){_dHall=dhall;}
    void setmeal(Meal meal){_meal=meal;}
    void setstatus(Status status){_status=status;}
    void setcareatedat(time_t createdat)
    {
        _created_at=((createdat>=0)?createdat:0);
    }

    //getters()
    int getreserveid()const{return _reservation_id;}
    Student getstudent()const{return _student;}
    DiningHall getdininghall()const{return _dHall;}
    Meal getmeal()const{return _meal;}
    Status getstatus()const{return _status;}
    time_t getcreatedat()const{return _created_at;}
};
#endif