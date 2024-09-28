
#include "func.h"

int main() {
    LNode *L = nullptr;
    FillList(L);
    PrintList(L);

    LNode *LL = nullptr;
    FindMiddle(L,LL);
    PrintList(L);
    PrintList(LL);

    Reverse(LL);
    PrintList(LL);

    MergeList(L,LL);
    PrintList(L);
}
