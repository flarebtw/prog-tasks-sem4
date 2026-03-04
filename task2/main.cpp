#include <iostream>
#include <list>
#include <vector>
#include <iterator>

using namespace std;

void middleToList(list<int>& L, vector<int>& V)
{
    size_t size = L.size();

    size_t midIndex = size / 2;

    auto it = L.begin();

    advance(it, midIndex);

    V.push_back(*it);
    L.erase(it);
}

int main(void){
    list<int> L = {1, 2, 3, 9, 10};
    vector<int> V = {1, 2, 3, 4};

    cout << "Init vector and list" << endl;

    cout << "L: ";
    for (int x : L) cout << x << " ";
    cout << "\nV: ";
    for (int x : V) cout << x << " ";

    middleToList(L, V);
    cout << "\nVector and list after moving middle element to end of vector:" << endl;
    
    cout << "L: ";
    for (int x : L) cout << x << " ";
    cout << "\nV: ";
    for (int x : V) cout << x << " ";

    return 0;
}