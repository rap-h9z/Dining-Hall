#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED
#include<iostream>
using namespace std;

enum TransactionType{Transfer,Payment};
enum TransactionStatus{Pending,Completed,Failed};

class Transaction
{
    int _tarnsactionID;
    string _trackingcode;
    float _amount;
    TransactionType _type;
    TransactionStatus _status;
    time_t _createdAT;

    public:
    Transaction(int tid=0,string trackcode=" ",float amount=0.00,TransactionType type,TransactionStatus status,time_t careatedat);
    //setters
    void settranid(int tranid){_tarnsactionID= tranid;}
    void settrackcode(string trackcode){_trackingcode= trackcode;}
    void setamout(float amount){_amount=amount>=0?amount:0.00;}
    void settrantype(TransactionType type){_type=type;}
    void settranstatus(TransactionStatus status){_status=status;}
    void setcreatedat(time_t time){_createdAT=time;}

    //getters
    int gettranid()const{return _tarnsactionID;}
    string gettarckcode()const{return _trackingcode;}
    float getamount()const{return _amount;}
    TransactionType gettype()const{return _type;}
    TransactionStatus getstatus()const{return _status;}
    time_t getcreatedat()const{return _createdAT;}
};
#endif