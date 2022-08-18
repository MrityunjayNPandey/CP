#include <stdio.h>
#include <stdlib.h>

//time complexity O(log(log(n)), Sieve of Eratosthenes

void sieve_createarray(int** primes, int* m, int* n) // function to create an array of size n+1
{
    printf("Enter the value of m and n respectively : ");
    scanf("%d %d", &(*m), &(*n));
    *primes = (int*)malloc((*n + 1) * sizeof(int));
}

int sieve(int* pointer, int m, int n)
{
    //     NOTE: In sieve of Eratosthenes, we start from 2 and go to n.
    //     We mark each number as prime or not prime.
    //     If a number is marked as prime, then we mark all its multiples as not prime.
    //     At the end, we are left with an array of numbers upto n, which are marked as prime or not prime.
    //     If we find a 1, we know that it's prime.
    int i, j, count = 0, sum = 0;
    for(i = 2; i <= n; i++)
    {
        *(pointer + i) = 1;
    }
    for(i = 2; i <= n; i++)
    {
        if(*(pointer + i) == 1)
        {
            for(j = i * i; j <= n; j += i)
            {
                *(pointer + j) = 0;
            }
        }
    }
    for(i = m; i <= n; i++)
    {
        if(*(pointer + i) == 1)
        {
            sum += i;
        }
    }
    return sum;
}

int main()
{
    int* primes, sum, n, m;
    sieve_createarray(&primes, &m, &n);
    sum = sieve(primes, m, n);
    printf("%d\n", sum);
    return 0;
}