#include <iostream>
#include <string>

using namespace std;

char ciao(char c) {
    string keyboard = "qwertyuiopasdfghjklzxcvbnm";
    size_t pos = keyboard.find(c);
    if (pos == string::npos) {
        return c; 
    }
    return keyboard[(pos + 1) % keyboard.size()];
}
int main() {
    int N;
    string S;
    cin >> N;
    cin >> S;
    for (char c : S) {
        cout << ciao(c);
    }
    
    return 0;
}
