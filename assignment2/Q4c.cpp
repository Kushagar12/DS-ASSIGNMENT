#include <iostream>
#include <string>
using namespace std;

// Function to check if a character is a vowel
bool isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main() {
    string str, result = "";

    cout << "Enter a string: ";
    getline(cin, str);

    // Iterate over each character and append if not vowel
    for (char ch : str) {
        if (!isVowel(ch)) {
            result += ch;
        }
    }

    cout << "String after removing vowels: " << result << endl;

    return 0;
}
