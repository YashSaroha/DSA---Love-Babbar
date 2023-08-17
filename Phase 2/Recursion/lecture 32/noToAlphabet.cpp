// write  412 -> four one two,   332 -> three three two
#include<iostream>
using namespace std;

void letter(int n, string arr[])
{
    // base case
    if(n == 0)
    return ;

    // processing
    int digit = n%10 ;
    n = n/10;

    // R.C
    letter(n, arr);
    cout << arr[digit] << " ";

}

int main()
{
    string str[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int n;
    cin >> n;

    letter(n, str);

}