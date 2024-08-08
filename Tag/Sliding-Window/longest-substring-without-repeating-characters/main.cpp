#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>


int lengthOfLongestSubstring(std::string s) {
    std::unordered_set<char> set;
    int maxLength{0},left{0},right{0};

    while (right < s.length()){
        if (set.find(s[right]) == set.end()){
            set.insert(s[right]);
            maxLength = std::max(maxLength, right - left + 1);
            ++right;
        } else {
            set.erase(s[left]);
            ++left;
        }
    }
    return maxLength;
}

int main() {
    std::string s1{"abcab"};
    std::string s2{"bbbbb"};
    std::string s3{"pwwkew"};
    std::cout << lengthOfLongestSubstring(s1) <<"\n";
    std::cout << lengthOfLongestSubstring(s2) <<"\n";
    std::cout << lengthOfLongestSubstring(s3) <<"\n";
}
