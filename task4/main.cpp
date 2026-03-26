#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <sstream>
#include <stdexcept>

void printVector(const std::vector<int>& vec) {
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

std::vector<int> readVector(const std::string& prompt) {
    std::cout << prompt;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream stream(line);
    return std::vector<int>(
        std::istream_iterator<int>(stream),
        std::istream_iterator<int>()
    );
}

int main() {
    int K;
    std::cout << "Введите K: ";
    std::cin >> K;
    std::cin.ignore();

    std::vector<int> V1 = readVector("Введите элементы V1: ");
    std::vector<int> V2 = readVector("Введите элементы V2: ");

    if (V1.size() != V2.size()) {
        throw std::logic_error("Размеры V1 и V2 должны совпадать!");
    }

    std::cout << "\nK = " << K << std::endl;

    std::cout << "V1: ";
    std::copy(V1.begin(), V1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "V2: ";
    std::copy(V2.begin(), V2.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::transform(
        V1.begin(), V1.end(),
        V2.begin(),
        V1.begin(),
        std::bind(
            std::plus<int>(),
            std::bind(
                std::multiplies<int>(),
                std::placeholders::_1,
                K
            ),
            std::placeholders::_2
        )
    );

    std::cout << "\nV1 после преобразования (V1[i] * K + V2[i]):" << std::endl;
    std::cout << "V1: ";
    std::copy(V1.begin(), V1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}