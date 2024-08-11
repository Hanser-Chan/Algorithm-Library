#include <iostream>
#include <string>
#include <vector>
#include <format>

using std::string,std::vector;


string convert(string s, int numRows) {
    string result{};
    int t{numRows * 2 - 2};//一次z左边+中间部分
    int maxColumn = (s.length() + t - 1) / t * (numRows-1);

    vector<string> strMat(numRows,string(maxColumn, 0));

    for (int i{0},x{0},y{0}; i < s.length(); ++i) { //x为行量，y为列量
        strMat[x][y] = s[i];
        if (i % t < numRows - 1){
            ++x;    //x向下移动1行
        } else {
            --x;    //x向上移动一行
            ++y;    //y向右移动一列，整体往右上
        }
    }

    for (auto &row: strMat) {
        for (char ch: row) {
            if (ch){
                result += ch;
            }
        }
    }

    return result;
}

string convert1(string s, int numRows){
    if (numRows < 2){
        return s;
    }

    vector<string> row(numRows);
    int i{0},flag{-1};
    string result{};

    for (char ch : s) {
        row[i].push_back(ch);
        if (i == 0 || i == numRows - 1){
            flag = -flag;

        }
        i +=flag;
    }

    for (auto rows : row) {
        result += rows;
    }
    return result;
}

int main() {
    string s1{"PAYPALISHIRING"};
    //string s2{"PAYPALISHIRING"};

    std::cout << std::format("字符z型子串转换后为{}\n{}",
                             convert1(s1,3),
                             convert1(s1,4));
}
