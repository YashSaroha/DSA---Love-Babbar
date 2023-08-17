#include<iostream>
using namespace std;

bool checkPalindrome( string str, int i, int j )
{
    if( i>j )
    return true;

    if(str[i] != str[j])
        return false;

    else
        return checkPalindrome(str, i+1, j-1);

}

int main()
{
    string s;
    cin >> s;
    bool ans = checkPalindrome(s, 0, s.size()-1);
    if(ans)
        cout << "palindrome" << endl;
    else
        cout << "not a palindrome" << endl;

}