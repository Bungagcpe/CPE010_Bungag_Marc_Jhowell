#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }

int memo[1001]; // we will initialize the elements to -1 ( -1 means, not solved it yet )

int getMinSteps ( int n )
{
    if ( n == 1 ) return 0; // base case
    if( memo[n] != -1 ) return memo[n]; // we have solved it already :)
    int r = 1 + getMinSteps( n - 1 ); // '-1' step . 'r' will contain the optimal answer finally
    if( n%2 == 0 ) r = min( r , 1 + getMinSteps( n / 2 ) ) ; // '/2' step
    if( n%3 == 0 ) r = min( r , 1 + getMinSteps( n / 3 ) ) ; // '/3' step
    memo[n] = r ; // save the result. If you forget this step, then its same as plain recursion.
    return r;
}

int main()
{
    int n, i;
    for ( i = 0; i <= 1000; i++ ) memo[i] = -1;

    printf("Enter n: ");
    scanf("%d", &n);
    printf("Minimum steps to reduce %d to 1 = %d\n", n, getMinSteps(n));
    return 0;
}