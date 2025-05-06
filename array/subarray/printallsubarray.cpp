#include <iostream>
using namespace std;
int main()
{
    int a[5] = {1, 2, 6, 7, 8};
    // print all sub array
    for (int i = 0; i < 5; i++)
    {
        for (int j = i; j < 5; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << a[k] << " ";
            }
            cout << "   ";
        }
        cout << endl;
    }
    return 0;
}