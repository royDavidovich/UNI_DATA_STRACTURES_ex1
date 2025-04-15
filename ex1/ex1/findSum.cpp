#include "findSum.h"

void findPairsIterative(const int i_Arr[], int i_ArrSize, int i_GoalSum)
{
    for (int i = i_ArrSize - 1; i >= 0; --i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (i_Arr[i] + i_Arr[j] == i_GoalSum)
            {
                cout << i_Arr[i] << " " << i_Arr[j] << endl;
            }
        }
    }
}

void findPairsRecursiveHelper(const int i_Arr[], int i_ArrSize, int i_GoalSum, int i_Y)
{
    if (i_ArrSize == 1)
    {
        if (i_Y != 0 && i_Arr[i_ArrSize - 1] + i_Y == i_GoalSum)
        {
            cout << i_Y << " " << i_Arr[0] << endl;
        }
        return;
    }

    if (i_Y != 0)
    {
        if (i_Arr[i_ArrSize - 1] + i_Y == i_GoalSum)
        {
            cout << i_Y << " " << i_Arr[i_ArrSize - 1] << endl;
        }

        findPairsRecursiveHelper(i_Arr, i_ArrSize - 1, i_GoalSum, i_Y);
    }
    else
    {
        findPairsRecursiveHelper(i_Arr, i_ArrSize - 1, i_GoalSum, i_Arr[i_ArrSize - 1]);
        findPairsRecursiveHelper(i_Arr, i_ArrSize - 1, i_GoalSum, 0);
    }
}

void findPairsRecursive(const int i_Arr[], int i_ArrSize, int i_GoalSum)
{
    findPairsRecursiveHelper(i_Arr, i_ArrSize, i_GoalSum, 0);
}

//------------------------

