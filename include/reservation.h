#ifndef RESERVATION_H_INCLUDED
#define RESERVATION_H_INCLUDED
#include <string.h>
#include <iostream>
#include "student.h"
#include "dininghall.h"
using namespace std;
class Reservation
{
    int _reservation_id;
    Student _student;
    DiningHall _dHall;
    Meal _meal;
    Enum _status;
    time_t _created_at;
    public:
    Reservation();
    void print()const;
    bool cancel();

    //setters()
    void setreserveid(int reservationid);
    void setstudent(Student student);
    void setdininghall(DiningHall dhall);
    void setmeal(Meal meal);
    void setenum(Enum status);
    void setcareatedat(time_t createdat);

    //getters()
    int getreserveid(){return _reservation_id;}
    Student getstudent(){return _student;}
    DiningHall getdininghall(){return _dHall;}
    Meal getmeal(){return _meal;}
    Enum hetstatus(){return _status;}
    time_t getcreatedat(){return _created_at;}
};
#endif