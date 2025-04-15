#include <iostream>

#include "findSum.h"

using namespace std;

int main()
{
    bool validArrayInput = false, validArraySizeInput = false, validSumInput = false;
    int i_ArrSize;
    cin >> i_ArrSize;

    int* i_Arr = new int[i_ArrSize];
    for (int i = 0; i < i_ArrSize; ++i)
    {
        cin >> i_Arr[i];
    }

    int i_GoalSum;
    cin >> i_GoalSum;

    // validArrayInput = ....  ;
    // validArraySizeInput = ....  ;
    // validSumInput = ....  ;

    bool validInput = validArrayInput && validArraySizeInput && validSumInput;
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