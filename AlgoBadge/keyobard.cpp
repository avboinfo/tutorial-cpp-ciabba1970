#include <iostream>
#include <string>

using namespace std;

char getShiftedChar(char c) {
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
        cout << getShiftedChar(c);
    }
    
    return 0;
}



