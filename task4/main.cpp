#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    const int K = 3;

    vector<int> V1 = {1, 2, 3, 4, 5};
    vector<int> V2 = {10, 20, 30, 40, 50};

    cout << "K = " << K << endl;

    cout << "V1: ";
    for_each(V1.begin(), V1.end(), [](int x){ cout << x << " "; });
    cout << endl;

    cout << "V2: ";
    for_each(V2.begin(), V2.end(), [](int x){ cout << x << " "; });
    cout << endl;

    transform(
        V1.begin(), V1.end(),
        V2.begin(),
        V1.begin(),
        bind(
            plus<int>(),
            bind(
                multiplies<int>(),
                placeholders::_1,
                K
            ),
            placeholders::_2
        )
    );

    cout << "V1 после преобразования (V1[i] * K + V2[i]):" << endl;
    cout << "V1: ";
    for_each(V1.begin(), V1.end(), [](int x){ cout << x << " "; });
    cout << endl;

    return 0;
}