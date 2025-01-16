#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

string constructPalindrome(const string& s) {
    // Frequency map for characters
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    
    // Check feasibility and prepare half of the palindrome
    string half = "", middle = "";
    int oddCount = 0;
    
    for (const auto& p : freq) { // Iterate using pair
        char ch = p.first;
        int count = p.second;
        
        if (count % 2 == 1) {
            oddCount++;
            middle = ch; // Directly assign the character to the middle string
        }
        for (int i = 0; i < count / 2; i++) { // Append characters manually
            half += ch;
        }
    }
    
    // If more than one character has an odd frequency, no solution
    if (oddCount > 1) {
        return "NO SOLUTION";
    }
    
    // Construct the palindrome
    string leftHalf = half;
    string rightHalf = half;
    reverse(rightHalf.begin(), rightHalf.end());
    
    return leftHalf + middle + rightHalf;
}

int main() {
    // Input string
    string s;
    cin >> s;
    
    // Get the result and print
    cout << constructPalindrome(s) << endl;
    
    return 0;
}
