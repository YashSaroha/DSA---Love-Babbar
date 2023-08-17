#include<iostream>
using namespace std;

void print(int n)
{
    // base case
    if(n==0)
        return ;
    
    // processing
    cout << n << " ";

    // recursive relation
    print(n-1);
}
// this is tail recursion...agr R.R ko upr le gye and processing ko niche then head recursion

int main()
{
    int n;
    cin >> n;
    print(n);

}