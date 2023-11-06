#include <iostream>
#include <queue>

class StackUsingQueues {
public:
    // Initialize your data structure.
    StackUsingQueues() {}

    // Push element x onto the stack.
    void push(int x) {
        // Push the new element into an empty queue (q1).
        q1.push(x);

        // Move all elements from the first queue (q1) to the second queue (q2).
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
    }

    // Removes the element on top of the stack and returns it.
    int pop() {
        int top_element = q1.front();
        q1.pop();
        return top_element;
    }

    // Get the top element.
    int top() {
        return q1.front();
    }

    // Return true if the stack is empty.
    bool empty() {
        return q1.empty();
    }

private:
    std::queue<int> q1, q2;
};

int main() {
    StackUsingQueues stack;
    int x,option;
    while(true)
    {
        std::cout <<"(1). Push, (2). POP, (3). exit\n";
        std::cin >> option;
    switch(option)
    {
        case 1:
        {
            std::cout << "Enter element to be pushed: ";
        std::cin >> x;
        stack.push(x);
        break;
        }
        case 2:
        {
            stack.pop();
            break;
        }
        case 3: return 0;
    }
    }

    return 0;
}
