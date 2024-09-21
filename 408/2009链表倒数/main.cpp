#include <iostream>
#include "ChainList.h"


int main() {
    LLNode<int> *head = nullptr;
    LLNode<int> node(0);
    node.FillList(head);
    try {
        int k = 3;  // 查找倒数第 3 个节点
        int result = node.FindK(head, k);
        cout << "倒数第 " << k << " 个节点的值为: " << result << std::endl;
    } catch (const std::out_of_range& e) {
        cout << e.what() << std::endl;
    }
}
