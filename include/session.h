#ifdef SESSION_H_INCLUDED
#define SESSION_H_INCLUDED
#include<iostream>
#include"student.h"
#include"shoppingcard.h"
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
    void setcreatedat(time_t time){_craetedat=time;}
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
    Shoppingcard *_shopping_card;
    int _studentID;
    sessionManager();
    SessionManager(const SessionManager&) = delete;
    SessionManager& operator=(const SessionManager&) = delete;
    
    public:
    void load_session() override;
    void save_session() override;
    void login(string, string) override;
    void logout()override;
    Student currentStudent();
    Shoppingcard shoppingCard();
    static SessionManager instance();

    //getters
    Student getcurrentstudent()const{return _currentStudent;}
    Shoppingcard getshoppingcard()const{return _shopping_card;}
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
    Admin currentAdmin();
    static SessionManager instance();
};
}
#endif