#include<iostream>
using namespace std;

void reverse(string &str, int i, int j)
{
    if( i>j )
    return ;    

    swap(str[i] , str[j]);
    i++ ;
    j-- ;

    reverse(str, i, j);

}

int main()
{
    string s;
    cin >> s;
    reverse(s, 0, s.size()-1);
    cout << s;
}