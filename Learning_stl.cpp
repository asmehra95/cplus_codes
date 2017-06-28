#include<bits/stdc++.h>
using namespace std;
int main()
{
    // use of vectors
    map<int, vector<int> > m;
    vector<int> a;
    a.push_back(10);
    a.push_back(12);
    m[1]=a;
    cout<<*(m[1].begin());
    queue <string> q;
    q.push("avtar");
    q.push("singh");
    q.push("amit");
    cout<<q.front()<<" "<<q.back();

    stack<int> s;
    s.push(5);
    s.push(7);
    s.push(9);
    /*

        doesn't work this way

    stack<int> :: iterator it;
    while(it!=s.end())
    {
        cout<<" "<<*it;
        it++;
    }*/
    return 0;
}
