#include <cstdio>
#include <vector>
#include <cassert>

int N;
std::vector<std::vector<int>> FT;

int lsb(int x)
{
    return (x & (-x));
}

void prepare(int n)
{
    /*
        Prepares a Fenwick tree of size n
    */
    N = n;
    FT.resize(n + 1);
    for (int i = 1; i <= N; i++)
    {
        FT[i].resize(n + 1);
        for (int j = 1; j <= N; j++)
        {
            FT[i][j] = 0;
        }
    }
}

void update(int y, int x, int v)
{
    assert(1 <= y);
    assert(y <= N);
    assert(1 <= x);
    assert(x <= N);
    /*
        Aggiorna V[x], settando V[x] += v
    */

    for (int i = y; i <= N; i += lsb(i))
        for (int j = x; j <= N; j += lsb(j))
            FT[i][j] += v;
}

int prefix_sum(int by, int bx)
{
    assert(0 <= by);
    assert(by <= N);
    assert(0 <= bx);
    assert(bx <= N);

    int sum = 0;
    for (int i = by; i > 0; i -= lsb(i))
        for (int j = bx; j > 0; j -= lsb(j))
            sum += FT[i][j];
    return sum;
}

int rectangle_sum(int ay, int by, int ax, int bx)
{
    assert(1 <= ay);
    assert(ay <= by);
    assert(by <= N);
    assert(1 <= ax);
    assert(ax <= bx);
    assert(bx <= N);

    return (
        + prefix_sum(by, bx)
        - prefix_sum(by, ax-1)
        - prefix_sum(ay-1, bx)
        + prefix_sum(ay-1, ax-1)
    );
}