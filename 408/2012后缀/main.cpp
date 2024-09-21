#include <iostream>
#include <algorithm>
using std::cout, std::cin, std::string;

class LLNode {
public:
    char data;
    LLNode* next;

    // 构造函数
    explicit LLNode(char d, LLNode* n = nullptr) : data(d), next(n) {}

    // 填充链表的函数
    void FillList(LLNode*& L) {
        char flag;
        LLNode* r = nullptr;
        cout << "请输入链表的节点（输入 '1' 结束）:" << std::endl;
        cin >> flag;
        if (flag != '1') {
            L = new LLNode(flag);  // 不再使用0作为头节点
            r = L;
        }

        while (flag != '1') {
            cin >> flag;
            if (flag == '1') break;  // 停止输入
            LLNode* s = new LLNode(flag);
            r->next = s;
            r = s;

        }
        if (r) {
            r->next = nullptr;
        }
        cout << "FillNodeOK\n";
    }

    // 计算链表长度的函数
    static int count(LLNode* L)  {
        int count = 0;
        LLNode* p = L;
        while (p != nullptr) {
            p = p->next;
            count++;
        }
        return count;
    }

    // 查找两个链表公共部分开始节点的静态函数
    static LLNode* FindNode(LLNode* L1, LLNode* L2) {
        if (L1 == nullptr || L2 == nullptr) {
            return nullptr;  // 如果任何一个链表为空，返回空
        }

        int s1 = LLNode::count(L1);  // 计算第一个链表的长度
        int s2 = LLNode::count(L2);  // 计算第二个链表的长度

        LLNode* p = L1;
        LLNode* q = L2;

        // 对齐两个链表的起点
        if (s1 > s2) {
            for (int i = 0; i < s1 - s2; i++) {
                p = p->next;
            }
        } else if (s2 > s1) {
            for (int i = 0; i < s2 - s1; i++) {
                q = q->next;
            }
        }

        // 同时遍历两个链表，寻找公共节点
        while (p != nullptr && q != nullptr) {
            if (p == q) {
                return p;  // 找到公共节点
            }
            p = p->next;
            q = q->next;
        }

        return nullptr;  // 没有找到公共节点
    }
};

int main() {
    LLNode* head1 = nullptr;
    LLNode* head2 = nullptr;
    LLNode node1(0);
    LLNode node2(0);

    cout << "填充第一个链表:" << std::endl;
    node1.FillList(head1);

    cout << "填充第二个链表:" << std::endl;
    node2.FillList(head2);

    LLNode* commonNode = LLNode::FindNode(head1, head2);
    if (commonNode) {
        cout << "两个链表的公共部分从节点: " << commonNode->data << " 开始。" << std::endl;
    } else {
        cout << "两个链表没有公共部分。" << std::endl;
    }

    return 0;
}
