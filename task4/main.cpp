#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void printVector(const std::vector<int>& vec) {
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void inputVector(vector<int>& vec, const string& name) {
    cout << "Enter vector elements " << name << " (" << vec.size() << " ):" << endl;
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << "  " << name << "[" << i << "] = ";
        cin >> vec[i];
    }
}

using namespace std;

int main() {
    int K = 0;
    size_t n = 0;

    cout << "Enter vector size (N): ";
    cin >> n;

    cout << "Enter K value: ";
    cin >> K;

    vector<int> V1(n);
    vector<int> V2(n);

    inputVector(V1, "V1");
    inputVector(V2, "V2");
    
    cout << "K = " << K << endl;

    cout << "V1: ";
    printVector(V1);
    cout << "V2: ";
    printVector(V2);

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
    printVector(V1);
    cout << endl;

    return 0;
}
