>[2022] 408操作系统pv操作题目

## 描述

有两个线程`T1`，`T2`并发执行A,B,C,D,E,F六个操作，其中`T1`执行A,E和F，`T2`执行B,C和D。这些操作受以下约束：A,B同时开始，C在A,B完成后执行，D和E在C完成后执行，F在E完成后执行，F完成后整体结束。

## 题解

```
semaphore AC = 0; \\ AC操作间的信号量
semaphore CE = 0; \\ CE操作间的信号量
T1{
A();
signal(AC); \\提示C可以运行
wait(CE); \\等待C执行完成
E();
F();
}

T2{
B();
wait(AC); \\等待C执行完成
C();
signal(CE);\\提示C已经执行完成
D();
}
```