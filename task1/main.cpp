#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <cstddef>

using namespace std;

bool checkLength(const string& word)
{
    return word.length() == 6;
}

int main(void)
{
    cout << "Enter filename:" << endl;
    string filename = "";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) return 1;
    
    ptrdiff_t count = count_if(istream_iterator<string>(file), istream_iterator<string>{}, checkLength);

    cout << "Words with length 6: " << count << endl;
    return 0;
}