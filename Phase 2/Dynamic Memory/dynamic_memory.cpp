/*
    2 types ki memory hoti hai, stack and heap
    stack choti hoti h or heap bdi
    stack wali heap se required memory le aati h or allot kr deti h..this is static allocation
    But if we want to allot memory from heap then it is called dynamic memory allocation
    e.g cin >> n , int arr[n] this is bad practice as n is not known during compilation
    agr n bda hua or static ki memory kam pad gyi to program crash ho skta hai to hm chahenge ki
    array ko heap me se memory dede jo bdi hoti h or kbi km nhi pdegi

    'new' keyword use krke dynamic memory allot kr skte hai but block ka naam nhi rkh skte
    e.g int char ch;  ->  static memory allocation
        new char;     ->  dynamic memory allocation

    new char ch   is invalid syntax
    new char statement returns a address so to access this memory we need to use pointers
        
        char *ch = new char;

    new char will take 1 byte size and pointer will always take 4/8 byte size to total memory alloted
    will be either 1+4=5 or 1+8=9 bytes

        int *p = new int;           (4+4=8 or 4+8=12 bytes)

        int *ptr = new int[5];      (20+4=24 or 20+8=28 bytes)

    jo 20 bytes variable array ki heap me allot ho rhi it is called dynamic allocation and jo 4/8 bytes pointer ke liye
    use hori that is static memory allocation

            
*/

#include<iostream>
using namespace std;

int getSum(int *arr , int n)
{
    int sum = 0;
    for(int i=0 ; i<n ; i++)
        sum = sum + arr[i];
    return sum;
}

int main()
{
    int n; 
    cout << "Enter n : " ;
    cin >> n;
    cout << "Enter values : " ;
    // variable size array
    int *arr = new int[n];
    // taking input in array
    for(int i=0 ; i<n ; i++)
    {
        cin >> arr[i];
    }
    int ans = getSum(arr,n);
    cout << "ans is " << ans << endl;


    // case 1
    while(true){
        int i = 5;
    }

    // case 2
    while(true){
        int *p = new int;
    }

    /*  case 1 me static memory me variable create hua and braces aane pr wo memory block dlt hogya
        same chlta rhega for infinite...it means kisi bhi instant pe hmare paas bs 1 hi integer ki
        memory store ho rhi h i.e 4 bytes jo automatically ud jati h function pura hone pe
        case 2 me dynamic memory me variable bna and static memory me pointer..similarly as above static
        ki memory udti rhegi but heap ki nhi...wo variables heap me bnte jayenge and ek time pr heap puri
        bhr jaegi tb program crash ho jaega

    DELETING MEMORY FROM HEAP
    
        to remove that memory alloted in heap we use 'delete' keyword
        int *i = new int;
        delete i;

        int *arr = new int[50];
        delete []arr;
    */

}