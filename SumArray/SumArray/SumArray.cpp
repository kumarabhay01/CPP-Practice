#include <string>
#include <iostream>
using namespace std;

string reverseString(string str)
{
    string reverseStr{};
    int len = str.length();
    for (int i = len-1; i >= 0; i--) {
        reverseStr += str[i];
    }
    return reverseStr;
}

int main() {
    string s = reverseString("Hello");
    cout << s;
    return 0;
}