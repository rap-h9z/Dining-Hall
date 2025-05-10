#ifndef STORAGE_H_INCLUDED
#define STORAGE_H_INCLUDED
#include <iostream>
#include "meal.h"
#include "dininghall.h"
using namespace std;
class Storage
{
   int _mealIDcounter;
   int _dininghallIDcounter;
   vector<Meal> allmeals;
   vector<DiningHall> alldininghalls;
   public:
   Storage();
   Storage(const Storage &);
   Storage operator=(const Storage &)
   static Storage& intance();
};
#endif