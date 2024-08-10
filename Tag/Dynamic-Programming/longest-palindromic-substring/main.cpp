#include <iostream>
#include <string>
#include <vector>
#include <format>

using std::string,std::vector;

string longestPalindrome(string s) {
    size_t n{s.size()};
    int maxLength{1},begin{0};

    vector<vector<int>> dp(n, vector<int> (n));

    for (int i = n - 1; i >= 0; i--) {

        for (int j = i; j < n; j++) {

            if (s[i] == s[j] && (j - i <= 1 || dp[i+1][j-1]) ){
                dp[i][j] = true;

                if (j - i + 1 >= maxLength){
                    begin = i;
                    maxLength = j - i + 1;
                }
            }
        }
    }
    return s.substr(begin,maxLength);
}

int main() {
    string s1{"abbbbac"};
    string s2{"ababac"};
    string s3{"acbacbcabcc"};

    std::cout << std::format("最长回文子串分别为：\n {} \n {} \n {}",
                             longestPalindrome(s1),
                             longestPalindrome(s2),
                             longestPalindrome(s3));
}
