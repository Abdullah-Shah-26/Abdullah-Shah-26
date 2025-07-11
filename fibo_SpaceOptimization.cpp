int fib(int n)
{
    if(n <= 1)
        return n;
// TC = O(N)
// SC = O(1)
    // space optimization
    int curr, prev1 = 1, prev2 = 0;

    for(int i = 2; i <= n ; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}