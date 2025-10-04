#include <iostream>
using namespace std;
#include <vector>
int cnt = 0;

bool isValid(vector<vector<int>> &board, int r, int c)
{
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        if (board[r][i] == 1)
        {
            return false;
        }
        if (board[i][c] == 1)
        {
            return false;
        }
    }

    for (int i = r, k = c; i >= 0 && k >= 0; k--, i--)
    {
        if (board[i][k] == 1)
            return false;
    }
    for (int i = r, k = c; i >= 0 && k < n; k++, i--)
    {
        if (board[i][k] == 1)
            return false;
    }
    return true;
}
void queen(vector<vector<int>> &board, int r, int n)
{

    if (r == n)
    {
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isValid(board, r, i))
        {
            board[r][i] = 1;
            queen(board, r + 1, n);
            board[r][i] = 0;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the n : ";
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    queen(board, 0, n);
    cout << cnt << endl;
    return 0;
}