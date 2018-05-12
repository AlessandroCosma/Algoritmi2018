#include <cstdio>
#include <vector>
#include <cassert>

int N;
std::vector<int> FT;

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
        FT[i] = 0;
    }
}

void update(int x, int v)
{
    assert(1 <= x);
    assert(x <= N);
    /*
        Aggiorna V[x], settando V[x] += v
    */
    
    for (int i = x; i <= N; i += lsb(i))
        FT[i] += v;
}

int prefix_sum(int b)
{
    assert(0 <= b);
    assert(b <= N);
    /*
        Calcola la somma dei primi b valori
        (V[1], ..., V[b])
    */
    int sum = 0;
    for (int i = b; i > 0; i -= lsb(i))
        sum += FT[i];
    return sum;
}

int prefix_sum_ricorviso(int b)
{
    assert(0 <= b);
    assert(b <= N);
    /*
        Calcola la somma dei primi b valori 
        (V[1],....,V[b])
    */
    if(b == 0) return 0;
    return FT[b] + prefix_sum(b - lsb(b));
}

int interval_sum(int a, int b)
{
    assert(1 <= a);
    assert(a <= b);
    assert(b <= N);

    /*
        Calcola la somma dei valori V[a], ..., V[b]
    */
    return prefix_sum(b) - prefix_sum(a - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    prepare(n);

    for (;;)
    {
        char command = 'e';
        scanf(" %c", &command);
        if (command == 'u')
        {
            int x, v;
            scanf("%d%d", &x, &v);
            update(x, v);
        }
        else if (command == 'q')
        {
            int a, b;
            scanf("%d%d", &a, &b);
            printf("%d\n", interval_sum(a, b));
        }
        else if (command == 'p')
        {
            int b;
            scanf("%d", &b);
            printf("%d\n", prefix_sum(b));
        }
        else
        {
            fprintf(stderr, "Unrecognized command '%c'\n", command);
            break;
        }
    }
}