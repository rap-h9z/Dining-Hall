using namespace std;
#include <iostream>
#include "student.h"
#include "reservation.h"
#include "meal.h"
#include "dininghall.h"
Student::Student()
{
   _user_id=000000000;
   _student_id="0000000000";
   _name="Unknown";
   _email="Unknown@gmail.com";
   _balance=0.00;
   _is_active=false;
}
void Student::print()const
{
    cout<<"\n---Student info---"<<"\nUser ID: "<<getuserid()<<"\tUsername: "<<getname()<<"\nEmail: "<<getemail()<<"\nBalance: "<<getbalance()<<"\tStatus: ";
    if(getactive())
       cout<<"Active";
    else
        cout<<"Inactive";   

}

//void Student::reserve_meal(Meal food)
//void Student:: cancel_reservation(Reservation reserve)

Reservation::Reservation()
    : _reservation_id(0),
      _student(),
      _dHall(),
      _meal(),
      _status(Success),
      _created_at(time(nullptr))
{}
void Reservation::print()const
{
    cout<<"\n---Reaservation info---"<<"\nReservation ID: "<<getreserveid()<<"\nStudent name: "<<getstudent().getname()<<"\tStudent ID: "<<getstudent().getstudentid()
    <<"\nMeal: "<<getmeal().getname()<<"\tDining Hall: "<<getdininghall().getname()<<getdininghall().gethallid()<<"\nTime:"<<getcreatedat();
}
//void Reservation::cancel()

Meal::Meal()
    :_meal_id(0),
     _name(" "),
     _price(0.00),
     _meal_type(Breakfast),
     _side_items()
{}     

void Meal::print()const
{
    cout<<"\n---Meal info---"<<"\nMeal type: "<<getmealtype()<<"\tMeal name: "<<getname()<<"\tSide items: ";
    for (const string& item : _side_items) {
        cout << item << ",";
    }
     
    cout<<"\nPrice: "<<getprice()<<"\tMeal ID: "<<getmealid();
}

//void Meal::update_price(float new_price){}
//void Meal::add_side_item(string item){}

DiningHall::DiningHall()
     :_hall_id(0),
     _name(" "),
     _address(" "),
     _capacity(0)
{}
void DiningHall::print()const
{
    cout<<"\n---Dining Hall info---"<<"\nDining Hall name: "<<getname()<<gethallid()<<"\tCapacity: "<<getcapacity()<<"\nAddress: "<<getadd();
}
