#include<iostream>
#include<stack>
using namespace std;

// not a good approach...normal 2 pointer approach is better
// because that takes space complexity O(1) and stack take O(n) 

int main()
{
    string str;
    cin >> str;
    stack<char> s;
    
    for(int i=0 ; i<str.length() ; i++) 
    {
        char ch = str[i];
        s.push(ch);
    }

    string ans = "";
    // jbtk stack empty nhi hota tbtk pop krte rhenge
    while(s.empty() == false)
    {
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
    }

    cout << ans ;

    
}