using namespace std;
#include <iostream>
#include "include/student.h"
#include "include/reservation.h"
#include "include/meal.h"
#include "include/dininghall.h"
#include "include/admin.h"
#include "include/panel.h"
#include "include/storage.h"
#include"include/user.h"
//student

Student::Student()
{
   _user_id=000000000;
   _student_id="0000000000";
   _name="Unknown";
   _email="Unknown@gmail.com";
   _balance=0.00;
   _is_active=false;
   _phone="0900000000000";
}
void Student::print()const
{
    cout<<"\n---Student info---"<<"\nUser ID: "<<getuserid()<<"\tUsername: "<<getname()<<"\nPhone: "<<getphone()<<"\nEmail: "<<getemail()<<"\nBalance: "<<getbalance()<<"\tStatus: ";
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
     if(reserve.getrstatus()==Success){
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
      _dHall(),
      _meal(),
      _rstatus(Success),
      _created_at(time(nullptr))
{}
void Reservation::print()const
{
    cout<<"\n---Reaservation info---"<<"\nReservation ID: "<<getreserveid()
    <<"\nMeal: "<<getmeal().getname()<<"\tDining Hall: "<<getdininghall().getname()<<getdininghall().gethallid()<<"\nTime:"<<getcreatedat();
}
bool Reservation::cancel()
{
    RStatus(Cancelled);
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

//admin
void Admin::print()const
{}
void Admin::getType(){}

//panel
void Panel::action(int act){}
void Panel::showmenu()
{
    cout<<"\n---User Panel---"
        <<"\n1.Meal reservation 🍽️"
        <<"\n2.All reservations✅"
        <<"\n3.Add credit💰"
        <<"\n4.Transaction history📁"
        <<"\n5.Setting⚙️";
}
void Panel::showStudentInfo(){}
void Panel::checkBalance(){}
void Panel::viewReservations(){}
void Panel::addReservation(Reservation){}
void Panel::addToShoppingCart(){}
void Panel::confirmShoppingCart(){}
void Panel::removeShoppingCartItem(){}
void Panel::increaseBalance(){}
void Panel::viewRecentTransactions(){}
void Panel::cancelReservation(int){}
void Panel::exit(){exit;}

//storage

//user
User::User(int userid,string name,string lastname,string hashedpass)
{
    setuserid(userid);
    setname(name);
    setlastname(lastname);
    sethashedpass(hashedpass);
}
void User::print()const
{
 cout<<"\nUser ID:"<<User::getuserid()<<"\nFull Name:"<<User::getname()<<" "<<getlastname()
 <<"\nHashed password: "<<gethashedpass();
}
void User::getType()
{}