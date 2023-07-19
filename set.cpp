#include <iostream>
#include <set>

using namespace std;

// O(log n)
// size
// insert

int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(1);
    cout<<s.size()<<endl;

    return 0;
}