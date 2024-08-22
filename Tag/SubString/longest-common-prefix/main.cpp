#include <iostream>
#include <format>
#include <string>
#include <vector>
#include <algorithm>

using std::string,std::vector;

string longestCommonPrefix(vector<string>& strs) {

    string temp {strs[0]};

    for (int i = 1; i < strs.size() ; i++) {
        size_t index{0};
        size_t length { std::min( temp.size(), strs[i].size() ) };
        while (index < length && strs[i][index] == temp[index]){
            index++;
        }
        temp = temp.substr(0,index);
    }

    return temp;
}


int main() {
    vector<string> strs1 {"flower","flow","flight"};
    vector<string> strs2 {"ab", "a"};

    std::cout << std::format("最长前缀为：{};{}"
                             ,longestCommonPrefix(strs1)
                             , longestCommonPrefix(strs2));
}
