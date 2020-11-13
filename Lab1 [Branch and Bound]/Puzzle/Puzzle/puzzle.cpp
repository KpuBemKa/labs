#include "puzzle.h";

int main()
{
    // valoarea inițială
    int initial[n][n] =
    {
        {1, 2, 3},
        {5, 6, 0},
        {7, 8, 4}
    };

    // valoarea finală
    int final[n][n] =
    {
        {1, 2, 3},
        {5, 8, 6},
        {0, 7, 4}
    };

    // coordonatele plăcii goale
    int x = 1, y = 2;

    solve(initial, x, y, final);

    system("pause");

    return 0;
}