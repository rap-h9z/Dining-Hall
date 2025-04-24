using namespace std;
#include <iostream>
#include "student.h"
#include "reservation.h"
#include "meal.h"
#include "dininghall.h"
//student

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

void Student::reserve_meal(Meal food)
{
    Reservation new_reserve;
    food.print();
    if (_balance>=food.getprice())
    {
        new_reserve.setstudent(*this);
        new_reserve.setmeal(food);
        //new_reserve.setdininghall();
        //new_reserve.setcareatedat();
        new_reserve.setstatus(Success);
        //new_reserve.getreserveid();

        _balance-=food.getprice();
        _reservations.push_back(new_reserve);
        cout<<"\nReservation was successful.";
    }
    else
        cout<<"\nNot enough inventory!";
    
}
bool Student:: cancel_reservation(Reservation reserve)
{
     char ans;
     if(reserve.getstatus()==Success){
     cout<<"\nAre you sure you want to cancel? Y/N";
     cin>>ans;
     if (ans=='y'||ans=='Y')
     {
        reserve.setstatus(Cancelled);
        _balance+=reserve.getmeal().getprice();
        return true;
     }
    }
    return false;
     
}

//reservation

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
bool Reservation::cancel()
{
    Status(Cancelled);
    cout<<"Reservation cancelled.";
    return true;
}

//meal

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

void Meal::update_price(float new_price)
{
    setprice(new_price);
    cout<<"Price Updated.";
}
void Meal::add_side_item(string item)
{   
    for (const string &sideitems:_side_items)
        if (sideitems==item)
           {cout<<"You already have it!";}
    
    _side_items.push_back(item);
}

//dininghall

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
