#include <iostream>
#include <stack>

class QueueUsingStacks {
private:
    std::stack<int> stack1;
    std::stack<int> stack2;
public:
    void enqueue(int item) {
        stack1.push(item);
    }
    
    int dequeue() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        
        if (!stack2.empty()) {
            int item = stack2.top();
            stack2.pop();
            return item;
        } else {
            return -1;  // or any other value to indicate empty queue
        }
    }
};

int main() {
    QueueUsingStacks queue;
    int x,option;
    while(true)
    {
        std::cout <<"(1). enqueue, (2). dequeue, (3). exit\n";
        std::cin >> option;
    switch(option)
    {
        case 1:
        {
            std::cout << "Enter element to be enqueued: ";
        std::cin >> x;
        queue.enqueue(x);
        break;
        }
        case 2:
        {
            queue.dequeue();
            break;
        }
        case 3: return 0;
    }
    }

    
    return 0;
}

