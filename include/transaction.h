#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED
#include<iostream>
using namespace std;
namespace TransactionE{
enum TransactionType{Transfer,Payment};
enum TransactionStatus{Pending,Completed,Failed};
}

class Transaction
{
    int _tarnsactionID;
    string _trackingcode;
    float _amount;
    TransactionE::TransactionType _type;
    TransactionE::TransactionStatus _status;
    time_t _createdAT;

    public:
    Transaction(int tid=0,string trackcode=" ",float amount=0.00,TransactionE::TransactionType type=TransactionE::Transfer,TransactionE::TransactionStatus status=TransactionE::Pending,time_t careatedat=time(nullptr));
    //setters
    void settranid(int tranid){_tarnsactionID= tranid;}
    void settrackcode(string trackcode){_trackingcode= trackcode;}
    void setamout(float amount){_amount=amount>=0?amount:0.00;}
    void settrantype(TransactionE::TransactionType type){_type=type;}
    void settranstatus(TransactionE::TransactionStatus status){_status=status;}
    void setcreatedat(time_t time){_createdAT=time;}

    //getters
    int gettranid()const{return _tarnsactionID;}
    string gettarckcode()const{return _trackingcode;}
    float getamount()const{return _amount;}
    TransactionE::TransactionType gettype()const{return _type;}
    TransactionE::TransactionStatus getstatus()const{return _status;}
    time_t getcreatedat()const{return _createdAT;}
};
#endif