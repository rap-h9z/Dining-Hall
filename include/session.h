#ifndef SESSION_H
#define SESSION_H
#include<iostream>
#include"student.h"
#include"shoppingcart.h"
using namespace std;
enum SessionStatus{Authenticated,Anonymous};
class SessionBase
{
    protected:
    time_t _createdat;
    time_t _lasttimeLogin;
    SessionStatus _status;
    virtual void load_session()=0;
    virtual void save_session()=0;

    public:
    virtual void login(string,string)=0;
    virtual void logout()=0;

    //setters
    void setcreatedat(time_t time){_createdat=time;}
    void setlasttimelogin(time_t lasttime){_lasttimeLogin=lasttime;}
    void setSstatus(SessionStatus status){_status=status;}
    
    //gettes
    time_t getcraetedat()const{return _createdat;}
    time_t getlasttimelogin()const{return _lasttimeLogin;}
    SessionStatus getsstatus()const{return _status;}
};
namespace StudentSession{

class SessionManager:protected SessionBase
{
    Student *_currentStudent;
    Shoppingcart *_shopping_cart;
    int _studentID;
    SessionManager();
    SessionManager(const SessionManager&) = delete;
    SessionManager& operator=(const SessionManager&) = delete;
    
    public:
    void load_session() override;
    void save_session() override;
    void login(string, string) override;
    void logout()override;
    Student currentStudent();
    Shoppingcart shoppingCart();
    static SessionManager& instance();

    //getters
    Student getcurrentstudent()const{return *_currentStudent;}
    Shoppingcart getshoppingcart()const{return *_shopping_cart;}
    int getstudentid()const{return _studentID;}

};
}
namespace AdminSession{

class SessionManager:protected SessionBase
{
    Admin *_currentAdmin;
    int _adminID;
    SessionManager();
    SessionManager(const SessionManager&) = delete;
    SessionManager& operator=(const SessionManager&) = delete;

    public:
    void load_session()override;
    void save_session()override;
    void login(string, string)override;
    void logout()override;
    int getadminid()const{return _adminID;}
    Admin currentAdmin();
    static SessionManager& instance();
};
}
#endif