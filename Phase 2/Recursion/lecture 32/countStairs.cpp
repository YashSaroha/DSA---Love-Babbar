// Find the no of ways to reach to nth stair
// initially you are standing on 0th stair and can climb only 1 or 2 stairs at a time
// DONE IN DAIRY

#include<iostream>
using namespace std;

int climb(int n)
{
    // Base case
    if(n < 0)
        return 0;
    if( n == 0)
        return 1;
    
    // R.C
    int ans = climb(n-1) + climb(n-2);
    return ans;

}

int main()
{
    int n;
    cin >> n;
    int ans = climb(n);
    cout << ans;
}