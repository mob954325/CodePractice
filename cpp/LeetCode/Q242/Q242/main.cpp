#include <iostream>
#include <queue>
#include <unordered_map>

std::unordered_map<int, char> qt;
std::queue<char> qs;
std::string original = "anagram";
std::string anagramed = "nagaram";

bool isAnagram(std::string s, std::string t);

int main()
{
	std::cout << isAnagram(original, anagramed);
}

bool isAnagram(std::string s, std::string t) {
    std::unordered_map<char, int> count;

    // Count the frequency of characters in string s
    for (auto x : s) {
        count[x]++;
    }

    // Decrement the frequency of characters in string t
    for (auto x : t) {
        count[x]--;
    }

    // Check if any character has non-zero frequency
    for (auto x : count) {
        if (x.second != 0) {
            return false;
        }
    }

    return true;
}