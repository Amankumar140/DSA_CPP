#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int data1)
    {
        data = data1;
        next = NULL;
    }
};
int main()
{
    node *n;
    n =new node(3);
    cout << n->data << " " << n->next;

    return 0;
}