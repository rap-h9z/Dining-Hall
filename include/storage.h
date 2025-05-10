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
   Storage(): _mealIDcounter(0), _dininghallIDcounter(0) {}
   public:
   Storage(const Storage &)=delete;
   Storage &operator=(const Storage &)=delete;
   static Storage& instance();
};
#endif