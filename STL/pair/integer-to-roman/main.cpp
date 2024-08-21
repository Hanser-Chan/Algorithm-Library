#include <iostream>
#include <string>
#include <utility> // std::pair
#include <format>

using std::string;

const std::pair<int, string> ValueLetter[] = {
        {1000, "M"},
        {900,  "CM"},
        {500,  "D"},
        {400,  "CD"},
        {100,  "C"},
        {90,   "XC"},
        {50,   "L"},
        {40,   "XL"},
        {10,   "X"},
        {9,    "IX"},
        {5,    "V"},
        {4,    "IV"},
        {1,    "I"},
};


string intToRoman(int num) {
    string rom{};

    for (auto [value,letter]: ValueLetter) {
        while (num >= value){
            num -= value;
            rom += letter;
        }
        if (num == 0){
            break;
        }
    }

    return rom;
}



int main() {
    int num1{3749};
    int num2{58};
    int num3{1994};

    std::cout << std::format("{},{},{}转换为罗马数字：{},{},{}",
                             num1,num2,num3,
                             intToRoman(num1),
                             intToRoman(num2),
                             intToRoman(num3));
}
