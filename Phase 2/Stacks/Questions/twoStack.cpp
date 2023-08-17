#include <bits/stdc++.h> 
using namespace std;
class TwoStack {

public:
    int *arr;
    int top1;
    int top2;
    int size;

    // Initialize TwoStack.
    TwoStack(int s) {
        this -> size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
        // atleast 1 empty space present
        if(top2 - top1 > 1){
            top1++;
            arr[top1] = num;
            cout << "element pushed is " << num << endl;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = num;
            cout << "element pushed is " << num << endl;
        }
    }

    // Pop from stack 1 and return popped element.
    void pop1() {
        if(top1 >= 0){
            int ans = arr[top1];
            top1--;
            cout << "element popped is " << ans << endl;
            // or directly write return arr[top1--]
        }
        else{
            cout << "empty stack" << endl;
        }
    }

    // Pop from stack 2 and return popped element.
    void pop2() {
        if(top2 < size){
            int ans = arr[top2];
            top2++;
            cout << "element popped is " << ans << endl;
            // or directly write return arr[top2++]
        }
        else{
            cout << "empty stack" << endl;
        }
    }
};

int main()
{
    // Initialising the size of the array to 3
    TwoStack s(3);

    s.push1(3); // pushing 3 in stack1.
    s.push2(4); // pushing 4 in stack2.
    s.push1(5); // pushing 5 in stack1.
    
    s.pop1(); // popping out from stack2, it returns 5.
    s.pop2(); // popping out from stack2, it returns 4.
}