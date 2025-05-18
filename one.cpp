using namespace std;
using namespace StudentSession;
using namespace AdminSession;
#include <iostream>
#include "include/student.h"
#include "include/reservation.h"
#include "include/meal.h"
#include "include/dininghall.h"
#include "include/admin.h"
#include "include/panel.h"
#include "include/storage.h"
#include "include/user.h"
#include "include/shoppingcart.h"
#include "include/transaction.h"
#include "include/session.h"

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
//student

Student:: Student(int userid,string name,string lastname,string hashedpass,string studentid,string email,string phone,float balance,bool active)
:User(userid,name,lastname,hashedpass)
{
   _student_id="0000000000";
   _email="Unknown@gmail.com";
   _balance=0.00;
   _is_active=false;
   _phone="0900000000000";
}
void Student::print()const
{
    cout<<"\n---Student info---";
    User::print();
    cout<<"\nPhone: "<<getphone()<<"\nEmail: "<<getemail()<<"\nBalance: "<<getbalance()<<"\tStatus: ";
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
        //new_reserve.setreserveid();
        new_reserve.setrstatus(Success);

        _balance-=food.getprice();
        _reserves.push_back(new_reserve);
        cout<<"\nReservation was successful."<<"\nYour reservation ID: "<<new_reserve.getreserveid();
        
    }
    else
        cout<<"\nNot enough credit!";
    
}
bool Student:: cancel_reservation(Reservation reserve)
{
     char ans;
     if(reserve.getrstatus()==Success){
     cout<<"\nAre you sure you want to cancel? Y/N";
     cin>>ans;
     if (ans=='y'||ans=='Y')
     {
        reserve.setrstatus(Cancelled);
        _balance+=reserve.getmeal().getprice();
        return true;
     }
    }
    return false;
     
}

//admin
void Admin::print()const
{
    cout<<"\n---Admin Info---";
    User::print();
}
void Admin::getType(){}


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
    _meal->print();
    cout<<"\nTime:"<<getcreatedat();
    cout<<"\nReservation ID: "<<getreserveid()<<"\tReservation status: "<<getrstatus()
    <<"\nDining Hall: ";
    _dHall->print();
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
     _side_items(),
     _reserveday(Saturday)
{}     

void Meal::print()const
{
    cout<<"\n▶︎Day: "<<getreserveday()<<"\tMeal type: "<<getmealtype()<<"\tMeal name: "<<getname()<<"\nSide items: ";
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
    cout<<"Dining Hall name: "<<getname()<<gethallid()<<"\tCapacity: "<<getcapacity()<<"\nAddress: "<<getadd();
}

//panel
void Panel::action(int act)
{
    switch (act)
    {
    case 1:
        showStudentInfo();
        break;
    case 2:
        
        break;
    case 3:
        viewReservations();
        break;
    case 4:
        checkBalance();
        break;
    case 5:
        increaseBalance();
        break;
    case 6:
        
        break;
    case 7:
        exit();    
    default:
        break;
    }
}
void Panel::showmenu()
{
    cout<<"\n---User Panel---"
        <<"\n1.My info"
        <<"\n2.Meal reservation 🍽️"
        <<"\n3.My reservations✅"
        <<"\n4.My balance💶"
        <<"\n5.Add credit💰"
        <<"\n6.Transaction history📁"
        <<"\n7.exit👋🏻";
}
void Panel::showStudentInfo()
{
   _student->print();
}
void Panel::checkBalance()
{
    cout<<"\nYour Balance: "<<_student->getbalance();
}
void Panel::viewReservations()
{
    vector<Reservation> reservations = _student->getreserves();
    cout<<"\n---Reservations---";

    if(_student->getreserves().empty()){
       cout<<"\nNo reservations.";}

    for (int i = 0; i < reservations.size(); ++i) {
        reservations[i].print();}

}
//void Panel::addToShoppingCart(){}
//void Panel::confirmShoppingCart(){}
//void Panel::removeShoppingCartItem(){}
void Panel::increaseBalance()
{float amount;
    cout<<"Enter the deposit amount: ";
    cin>>amount;
    _student->setbalance(_student->getbalance()+amount);
}
//void Panel::viewRecentTransactions(){}
//void Panel::cancelReservation(int){}
void Panel::exit(){exit();}

//storage
Storage& Storage::instance()
{
    static Storage _storage;
    return _storage;
}
//shoppintcart
void Shoppingcart::addreservation(Reservation reservation)
{
    _reservations.push_back(reservation);
    reservation.setrstatus(Not_Paid);
    cout<<"Added to Shppingcart";
}
void Shoppingcart::removereservation(int ID)
{
    for (int i=0; i < _reservations.size(); i++)
        if (_reservations[i].getreserveid()==ID){
            _reservations.erase(_reservations.begin()+i);
            cout<<"Successfully Removed";
            break;
        }
}
void Shoppingcart::viewshoppingcartitems()
{
    cout<<"\n---Shoppingcart 🛒---";
    for (int i=0; i <_reservations.size(); i++)
    {
        _reservations[i].print();
    }
    
}
void Shoppingcart::clear()
{
    _reservations.clear();
}
//Trnsaction
Transaction::Transaction(int tid,string trackcode,float amount,TransactionType type,TransactionStatus status,time_t careatedat)
{
    settranid(tid);
    settrackcode(trackcode);
    setamout(amount);
    settrantype(type);
    settranstatus(status);
    setcreatedat(careatedat);
}

//Studentsession
StudentSession::SessionManager::SessionManager()
{_currentStudent = nullptr;
    _shopping_cart = nullptr;
    _studentID = 0;
}

StudentSession::SessionManager& StudentSession::SessionManager::instance() {
    static SessionManager _studentmanager;
    return _studentmanager;
}
//void StudentSession::SessionManager::load_session(){}
//void StudentSession::SessionManager::save_session(){}
//void StudentSession::SessionManager::login(string, string){}
//void StudentSession::SessionManager::logout(){}
Student StudentSession::SessionManager::currentStudent()
{
    return *_currentStudent;
}
Shoppingcart StudentSession::SessionManager::shoppingCart()
{
    return *_shopping_cart;
}

//AdminSession
AdminSession::SessionManager::SessionManager()
{
    _currentAdmin=nullptr;
    _adminID=0;
}
//void AdminSession::SessionManager::load_session(){}
//void AdminSession::SessionManager::save_session(){}
//void AdminSession::SessionManager::login(string, string){}
//void AdminSession::SessionManager::logout(){}
Admin AdminSession::SessionManager::currentAdmin()
{
    return *_currentAdmin;
}
AdminSession::SessionManager& AdminSession::SessionManager::instance() {
    static SessionManager _adminmanager;
    return _adminmanager;
}


