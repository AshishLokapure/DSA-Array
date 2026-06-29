#include<iostream>
#include<vector>
#include<list>
#include<deque>
using namespace std;

int main(){
    int val, idx = 1;
    vector<int> vec;
    vec = {1, 2, 3, 4, 5};

    cout<<vec.at(0)<<endl;
    cout<<vec.at(1)<<endl;
    cout<<vec.at(2)<<endl;
    cout<<vec.at(3)<<endl;
    cout<<vec.at(4)<<endl;

    cout<<"\nusing foreach() : "<<endl;

    for(int val: vec){
        cout<<val<<endl;
    }

    cout<<"\nfront : " << vec.front() << endl;
    cout<<"\nback : " << vec.back() << endl;
    cout<<"\nsize : " << vec.size() << endl;
    cout<<"\nInsert 10 : ";
    vec.push_back(10);
    cout<<"\nsize after insert : " << vec.size() << endl;
    cout<<"\nDelete 10 : ";
    vec.pop_back();
    cout<<"\nsize after delete : " << vec.size() << endl;

    cout<<"\nEnter elements to search : ";
    cin>>val;

    for(int value: vec){
        if(value == val){
            cout<<"\nElement fount at "<<idx<<" position";
            break;
        }
        else{
            idx++;
        }
    }

    cout<<"\n\nIterators\n";

    vector<int> v = {1, 2, 3, 4, 5};

    cout << "\nvector.begin() : " << *(v.begin());
    cout << "\nLast element : " << *(v.end());
    cout << endl;

    vector<int>::iterator i;
    for(i = v.begin(); i != v.end(); i++){
        cout << *i << " ";
    }
    cout << endl;

    for(auto k = v.begin(); k != v.end(); k++){
        cout << *k << " ";
    }
    cout << endl;

    vector<int>::reverse_iterator j;
    for(j = v.rbegin(); j != v.rend(); j++){
        cout << *j << " ";
    }
    cout << endl;

    for(auto l = v.rbegin(); l != v.rend(); l++){
        cout << *l << " ";
    }



    cout<<"\n\nList\n";

    list<int> l;

    l.push_front(10);
    l.push_front(100);
    l.push_back(200);
    l.push_back(500);

    l.emplace_front(1000);
    l.emplace_back(2000);

    l.pop_front();
    l.pop_back();

    for(int i : l){
        cout<<i<<" ";
    }

    // cout<<"l[1] : "<<l[1];


    cout<<"\n\nDeque\n";
    
    deque<int> d;
    d.push_front(10);
    d.push_front(100);
    d.push_back(200);
    d.push_back(500);

    d.emplace_front(1000);
    d.emplace_back(2000);

    d.pop_front();
    d.pop_back();

    for(int i : d){
        cout<<i<<" ";
    }
    cout<<"\nd[1] : "<<d[1];


    cout<<"\n\nPair\n";

    pair<int, int> p = {1, 2};
    pair<int, char> p1 = {10, 'a'};

    cout<<"first Value of p : "<<p.first<<" second value of p : "<<p.second<<endl;
    cout<<"first Value of p1 : "<<p1.first<<" second value of p1 : "<<p1.second<<endl;

    pair<int, pair<char, string>> p2 = {10, {'m', "Ashish"}};

    cout<<p2.first<<endl;
    cout<<p2.second.first<<" "<<p2.second.second;
    cout<<endl;

    vector<pair<int, int>> vector = {{1,2}, {3, 4}, {5, 6}, {7, 8}};

    vector.push_back({100, 200});
    vector.emplace_back(1000, 2000);

    for(pair<int, int> p : vector){
        cout<<p.first<<" "<<p.second;
        cout<<endl;
    }

    

}

