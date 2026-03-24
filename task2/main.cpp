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

void printList(const list<int>& L)
{
    cout << "List: ";
    for (int x : L) cout << x << " ";
}

void printVector(const vector<int>& V)
{
    cout << "Vector: ";
    for (int x : V) cout << x << " ";
}

int main(void){
    list<int> L = {1, 2, 3, 9, 10};
    vector<int> V = {1, 2, 3, 4};

    cout << "Init vector and list" << endl;
    printVector(V);
    printList(L);

    middleToList(L, V);
    cout << "\nVector and list after moving middle element to end of vector:" << endl;
    
    printVector(V);
    printList(L);

    return 0;
}