#include<iostream>
#define N 3
using std::cout;

bool check(int* river, int* bank, bool watch)
{
    for (int i = 0; i < 2; i++)
    {
        if (((river[i] && river[i + 1]) || (bank[i] && bank[i + 1])) && !watch)
        {
            return true;
        }
    }
    return false;
}

bool solve(int* river, int* bank, int D)
{
    if (D == N)
    {
        return true;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            if (river[i] != 0)
            {
                bank[i] = river[i];
                river[i] = 0;
                int Di = D + 1;
                bool x;
                if (Di > 1)
                {
                    x = check(river, bank, 1);
                }
                else
                {
                    x = check(river, bank, 0);
                }
                if (x)
                {
                    river[i] = bank[i];
                    bank[i] = 0;
                }
                else
                {
                    if (solve(river, bank, Di))
                    {
                        cout << bank[i] << "\n";
                        return true;
                    }
                    else
                    {
                        river[i] = bank[i];
                        bank[i] = 0;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    int river[N] = { 1, 2, 3 };
    int bank[N] = { 0, 0, 0 };
    solve(river, bank, 0);
}