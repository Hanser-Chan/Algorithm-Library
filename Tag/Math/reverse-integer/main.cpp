#include <iostream>
#include <format>

int reverse(int x) {
    int ret = 0;
    while (x != 0) {
        if (abs(ret) > 214748364) return 0;
        ret = ret * 10 + x % 10;
        x /= 10;
    }
    return ret;
}

int main() {
    int num1{-120};
    int num2{123};
    int num3{1534236469};
    std::cout << INT_MAX << "\n";
    std::cout << std::format("{},{},{}转换后分别为\n{},\n{},\n{}",
                             num1,num2,num3,
                             reverse(num1),
                             reverse(num2),
                             reverse(num3));
}
