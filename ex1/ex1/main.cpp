#include <iostream>

#include "findSum.h"

using namespace std;

int main()
{
    bool validArrayInput = true, validArraySizeInput = true, validGoalSumInput = true;
    int i_ArrSize, i_GoalSum;
    int* i_Arr = NULL;
    
    cin >> i_ArrSize;
    if (i_ArrSize <= 0)
    {
        validArraySizeInput = false;
    }

    i_Arr = new int[i_ArrSize];
    for (int i = 0; i < i_ArrSize; ++i)
    {
        cin >> i_Arr[i];
        if (i_Arr[i] < 0)
        {
            validArrayInput = false;
        }
    }

    cin >> i_GoalSum;
    if (i_GoalSum <= 0)
    {
        validGoalSumInput = false;
    }

    bool validInput = validArrayInput && validArraySizeInput && validGoalSumInput;
    if (validInput)
    {
        cout << "Iterative algorithm::" << endl;
        findPairsIterative(i_Arr, i_ArrSize, i_GoalSum);

        cout << endl << "Recursive algorithm (recursive version):" << endl;
        findPairsRecursive(i_Arr, i_ArrSize, i_GoalSum);

        cout << endl << "Recursive algorithm (iterative version):" << endl;
        findPairsStackSimulated(i_Arr, i_ArrSize, i_GoalSum);
    }
    else
    {
        cout << "wrong input" << endl;
    }
    
    delete[] i_Arr;
    
    return 0;
}