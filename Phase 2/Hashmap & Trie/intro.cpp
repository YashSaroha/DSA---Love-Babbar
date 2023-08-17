#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{
    // creation
    unordered_map <string , int> m;


    // insertion
    // 1
    pair<string,int> pair1 = make_pair("name",1);
    m.insert(pair1);

    // 2
    pair<string,int> pair2 ("my",3);
    m.insert(pair2);

    // 3
    m["yash"] = 1;
    m["yash"] = 2;



    // SEARCHING
    // 1
    cout << m["name"] << endl;
    // 2
    cout << m.at("my") << endl;

    // lets say we search for a unknown key which is not in map
    // cout << m.at("saroha") << endl;

    // this will give error but if we search unknown key using 1st searching method , it will give 0
    cout << m["saroha"] << endl;
    // now if we use at() function for this unknown key, it will also give 0
    cout << m.at("saroha") << endl;

    // it means if any key is not present, m["unknown"] this will first create the unknown key and return value 0



    // SIZE
    cout << "size is " << m.size() << endl;
    // my , name , yash , saroha    4 keys are present at present in the map



    // TO CHECK PRESENCE
    cout << "is bro key present " << m.count("bro") << endl;
    cout << "is my key present " << m.count("my") << endl;


    // ERASE
    m.erase("name") ;
    cout << "size after erasing name " << m.size() << endl;


    // TRAVERSING THE MAP WITHOUT ITERATOR
    for(auto i:m){
        cout << i.first << " " << i.second << endl;
    }

    // TRAVERSING THE MAP USING ITERATOR
    unordered_map <string,int> :: iterator it = m.begin();
    while(it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        it++ ;
    }

    // random order me key print hongi
    // if ordered map is taken, jo key pehli dali thi whi phle print hogi..order is preserved


}