#include <iostream>
using namespace std;
int main()
{
    int arr[] = {3, 7, 8, 1, 17, 18, 9, 2};
    int f_max = 3, s_max = 3, t_max = 3;
    for (int i = 0; i < 8; i++)
    {
        if (arr[i] > f_max)
        {
            s_max = f_max;
            f_max = arr[i];
        }
        else if (arr[i] > s_max)
        {
            t_max = s_max;
            s_max = arr[i];
        }
        else if (arr[i] > t_max)
        {
            t_max = arr[i];
        }
    }
    cout << f_max << " " << s_max << " " << t_max;
    return 0;
}