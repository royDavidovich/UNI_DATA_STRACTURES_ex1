#pragma once
#include <iostream>

using namespace std;

class FindSum
{
public:
	static void findPairsIterative(const int i_Arr[], int i_ArrSize, int i_GoalSum);

	static void findPairsRecursiveHelper(const int i_Arr[], int i_ArrSize, int i_GoalSum, int i_Y);

	static void findPairsRecursive(const int i_Arr[], int i_ArrSize, int i_GoalSum);

	static void findPairsStackSimulated(const int i_Arr[], int i_ArrSize, int i_GoalSum);
};
