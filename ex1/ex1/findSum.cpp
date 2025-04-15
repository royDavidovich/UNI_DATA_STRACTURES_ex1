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

struct StackFrame
{
    int m_remainingElements;   // Number of remaining array elements to consider.
    int m_auxiliaryValue;      // Auxiliary value chosen for pairing (0 if not chosen).
};

// Node in our linked-list-based stack.
struct StackNode
{
    StackFrame m_frame;
    StackNode* m_next;
};

// Custom stack class (linked list implementation) for simulating recursion.
class Stack
{
private:
    StackNode* m_top;   // Pointer to the top node of the stack.

public:
    Stack() : m_top(nullptr) {}
    ~Stack()
    {
        while (!IsEmpty())
        {
            Pop();
        }
    }

    // Returns true if the stack is empty.
    bool IsEmpty() const
    {
        return (m_top == nullptr);
    }

    // Pushes a new frame onto the stack.
    void Push(const StackFrame& i_frame)
    {
        StackNode* newNode = new StackNode;
        newNode->m_frame = i_frame;
        newNode->m_next = m_top;
        m_top = newNode;
    }

    // Pops the top frame from the stack.
    StackFrame Pop()
    {
        if (IsEmpty())
        {
            return StackFrame();
        }
        StackFrame frame = m_top->m_frame;
        StackNode* temp = m_top;
        m_top = m_top->m_next;
        delete temp;
        return frame;
    }
};

void findPairsStackSimulated(const int i_Arr[], int i_ArrSize, int i_GoalSum)
{
    Stack simulationStack;

    // Initial frame: process the entire array with no auxiliary value chosen (auxiliaryValue = 0).
    StackFrame initialFrame{};
    initialFrame.m_remainingElements = i_ArrSize;
    initialFrame.m_auxiliaryValue = 0;
    simulationStack.Push(initialFrame);

    // Process simulated recursive calls using the stack.
    while (!simulationStack.IsEmpty())
    {
        StackFrame currentFrame = simulationStack.Pop();

        // If there are no elements left, skip this frame.
        if (currentFrame.m_remainingElements <= 0)
        {
            continue;
        }

        // Base case: when exactly one element remains.
        if (currentFrame.m_remainingElements == 1)
        {
            if (currentFrame.m_auxiliaryValue != 0 && (i_Arr[0] + currentFrame.m_auxiliaryValue == i_GoalSum))
            {
                // Print the pair, with the auxiliary value first, to match the required output order.
                cout << currentFrame.m_auxiliaryValue << " " << i_Arr[0] << endl;
            }

            continue;
        }

        // General case: process the element at index (remainingElements - 1).
        if (currentFrame.m_auxiliaryValue != 0)
        {
            // If an auxiliary value has already been chosen, check if the current element forms a valid pair.
            if (i_Arr[currentFrame.m_remainingElements - 1] + currentFrame.m_auxiliaryValue == i_GoalSum)
            {
                // Print the pair in the correct order.
                cout << currentFrame.m_auxiliaryValue << " " << i_Arr[currentFrame.m_remainingElements - 1] << endl;
            }
                
            // Simulate the recursive call by reducing the remainingElements count, without changing auxiliaryValue.
            StackFrame nextFrame;
            nextFrame.m_remainingElements = currentFrame.m_remainingElements - 1;
            nextFrame.m_auxiliaryValue = currentFrame.m_auxiliaryValue;
            simulationStack.Push(nextFrame);
        }
        else
        {
            // If no auxiliary value has been chosen (auxiliaryValue == 0), simulate two recursive calls.
            // To ensure correct ordering (so that pairs with a chosen value are printed before others),
            // we push the branch that skips the current element first, then push the branch that chooses it.

            // Branch 1: Skip the current element (keep auxiliaryValue = 0).
            StackFrame frameWithoutChoice;
            frameWithoutChoice.m_remainingElements = currentFrame.m_remainingElements - 1;
            frameWithoutChoice.m_auxiliaryValue = 0;
            simulationStack.Push(frameWithoutChoice);

            // Branch 2: Choose the current element as the auxiliary value.
            StackFrame frameWithChoice;
            frameWithChoice.m_remainingElements = currentFrame.m_remainingElements - 1;
            frameWithChoice.m_auxiliaryValue = i_Arr[currentFrame.m_remainingElements - 1];
            simulationStack.Push(frameWithChoice);
        }
    }
}