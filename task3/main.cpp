#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::string> V = {
        "APPLE", "ORANGE", "GRAPE", "BANANA", "LIME",
        "PINE", "ROSE", "BLUE", "CRANE", "STONE",
        "FLAME", "DARK", "SPARK", "TRUNK", "BLANK"
    };

    std::cout << "Init vector V:" << std::endl;
    std::for_each(V.begin(), V.end(), [](const std::string& s) {
        std::cout << s << " ";
    });
    std::cout << std::endl << std::endl;

    std::multimap<char, std::string> M;

    std::for_each(V.rbegin(), V.rend(), [&M](const std::string& word) {
        char lastChar = word.back();
        M.insert({lastChar, word});
    });

    std::cout << "Multimap M (key -> word):" << std::endl;
    std::for_each(M.begin(), M.end(), [](const std::pair<char, std::string>& p) {
        std::cout << p.first << " -> " << p.second << std::endl;
    });

    return 0;
}