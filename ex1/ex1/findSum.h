#pragma once
#include <iostream>

using namespace std;

class FindSum
{

};

void findPairsIterative(const int i_Arr[], int i_ArrSize, int i_GoalSum);

void findPairsRecursiveHelper(const int i_Arr[], int i_ArrSize, int i_GoalSum, int i_Y);

void findPairsRecursive(const int i_Arr[], int i_ArrSize, int i_GoalSum);

void findPairsStackSimulated(const int i_Arr[], int i_ArrSize, int i_GoalSum);