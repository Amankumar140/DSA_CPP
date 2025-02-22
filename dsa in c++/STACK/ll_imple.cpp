// #include <iostream>
// using namespace std;
// class stack
// {
// private:
//     stack *top;

// public:
//     int val;
//     stack *next;
//     stack(int data)
//     {
//         val = data;
//         next = NULL;
//     }

//     void push(int x)
//     {
//         stack *temp = new stack(x);
//         temp->next = top;
//         top = temp;
//     }

//     void pop(stack)
//     {
//         if (top == NULL)
//         {
//             cout << "stack is empty" << endl;
//         }
//         stack *temp = top;
//         top = top->next;
//         free(temp);
//     }

//     void print()
//     {
//         stack *temp = top;
//         while (temp != NULL)
//         {
//             cout << temp->next << " ";
//             temp = temp->next;
//         }
//     }
// };
// int main()
// {

//     stack aman;
//     aman.push(6);
//     aman.print();
//     aman.push(7);
//     aman.print();
//     aman.push(8);
//     aman.print();
//     aman.push(19);
//     aman.print();
//     aman.push(24);
//     aman.print();

//     return 0;
// }


#include <iostream>
using namespace std;

class stack {
private:
    stack *top;

public:
    int val;
    stack *next;

    // Constructor to initialize top and create an empty stack
    stack() : top(nullptr) {}

    // Constructor to create a node with data
    stack(int data) {
        val = data;
        next = nullptr;
    }

    void push(int x) {
        stack *temp = new stack(x);
        temp->next = top;
        top = temp;
    }

    void pop() {  // Removed parameter
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return; // Added return to avoid dereferencing null pointer
        }
        stack *temp = top;
        top = top->next;
        delete temp; // Use delete for C++ objects
    }

    void print() {
        stack *temp = top;
        while (temp != nullptr) {
            cout << temp->val << " ";  // Print the value
            temp = temp->next;
        }
        cout << endl; // Added endl for better output formatting
    }
};

int main() {
    stack aman;  // Changed to use default constructor
    aman.push(6);
    aman.print();
    aman.push(7);
    aman.print();
    aman.push(8);
    aman.print();
    aman.push(19);
    aman.print();
    aman.push(24);
    aman.print();

    return 0;
}
