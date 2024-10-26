#include <iostream>
#include <thread>

#include <format>
#include <semaphore> // C++20

using std::cout,std::format;

std::counting_semaphore<1> AC(0);
std::counting_semaphore<1> CE(0);

// 定义操作函数
void A() { cout<<format("A执行完成\n"); }
void B() { cout<<format("B执行完成\n"); }
void C() { cout<<format("C执行完成\n"); }
void D() { cout<<format("D执行完成\n"); }
void E() { cout<<format("E执行完成\n"); }
void F() { cout<<format("F执行完成\n"); }

// 线程T1的函数
void T1() {
    A();
    AC.release(); // signal(AC); 提示C可以运行
    CE.acquire(); // wait(CE); 等待C执行完成
    E();
    F();
}

// 线程T2的函数
void T2() {
    B();
    AC.acquire(); // wait(AC); 等待A执行完成
    C();
    CE.release(); // signal(CE); 提示C已经执行完成
    D();
}

int main() {

    std::thread thread1(T1);
    std::thread thread2(T2);

    thread1.join();
    thread2.join();

    return 0;
}

