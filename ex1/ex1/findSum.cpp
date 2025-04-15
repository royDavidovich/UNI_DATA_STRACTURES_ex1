#include "findSum.h"

struct ItemType
{
    int m_numLeft;  // number of array items left
    int m_aux;      // currently chosen number (0 if none)
};

struct StackNode
{
    ItemType m_data;
    StackNode* m_next;
};

class Stack
{
private:
    StackNode* m_top;  // the top item in my stack

public:
    Stack() : m_top(nullptr) {}

    bool IsEmpty() const
    {
        return (m_top == nullptr);
    }

    void Push(const ItemType& i_ItemType)
    {
        StackNode* newNode = new StackNode;
        newNode->m_data = i_ItemType;
        newNode->m_next = m_top;
        m_top = newNode;
    }

    ItemType Pop()
    {
        if (IsEmpty())
        {
            return ItemType();
        }
        ItemType frame = m_top->m_data;
        StackNode* temp = m_top;
        m_top = m_top->m_next;
        delete temp;
        return frame;
    }

    void MakeEmpty()
    {
        while (!IsEmpty())
        {
            Pop();
        }
    }

    ~Stack()
    {
        while (!IsEmpty())
        {
            Pop();
        }
    }
};

//------------------------

void FindSum::findPairsIterative(const int i_Arr[], int i_ArrSize, int i_GoalSum)
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

void FindSum::findPairsRecursiveHelper(const int i_Arr[], int i_ArrSize, int i_GoalSum, int i_Y)
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

void FindSum::findPairsRecursive(const int i_Arr[], int i_ArrSize, int i_GoalSum)
{
    findPairsRecursiveHelper(i_Arr, i_ArrSize, i_GoalSum, 0);
}

void FindSum::findPairsStackSimulated(const int i_Arr[], int i_ArrSize, int i_GoalSum)
{
    Stack simStack;

    ItemType startFrame{};
    startFrame.m_numLeft = i_ArrSize;
    startFrame.m_aux = 0;
    simStack.Push(startFrame);

    while (!simStack.IsEmpty()) {
        ItemType curFrame = simStack.Pop();
        if (curFrame.m_numLeft <= 0)
            continue;

        if (curFrame.m_numLeft == 1) {
            if (curFrame.m_aux != 0 && (i_Arr[0] + curFrame.m_aux == i_GoalSum))
                cout << curFrame.m_aux << " " << i_Arr[0] << endl;
            continue;
        }

        if (curFrame.m_aux != 0) {
            if (i_Arr[curFrame.m_numLeft - 1] + curFrame.m_aux == i_GoalSum)
                cout << curFrame.m_aux << " " << i_Arr[curFrame.m_numLeft - 1] << endl;
            ItemType nextFrame{};
            nextFrame.m_numLeft = curFrame.m_numLeft - 1;
            nextFrame.m_aux = curFrame.m_aux;
            simStack.Push(nextFrame);
        }
        else {
            // Push the branch that skips current element first...
            ItemType skipFrame{};
            skipFrame.m_numLeft = curFrame.m_numLeft - 1;
            skipFrame.m_aux = 0;
            simStack.Push(skipFrame);
            // ...then push the branch that takes the current element.
            ItemType takeFrame{};
            takeFrame.m_numLeft = curFrame.m_numLeft - 1;
            takeFrame.m_aux = i_Arr[curFrame.m_numLeft - 1];
            simStack.Push(takeFrame);
        }
    }
}
