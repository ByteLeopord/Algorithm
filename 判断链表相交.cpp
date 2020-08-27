/*
1)先判断链表有无环，如果一个有环，一个没有环，则说明两个链表肯定不会相交。
2)如果两个链表都没有环，则如果两个链表相交，两个链表的最后一个结点肯定是同一个结点。
3)如果两个链表h1,h2都有环，则可以找到两个链表上并且在环上的任何一个结点p1和p2。如果从结点p1开始遍历链表h1，能够遍历到p2，说明两个链表相交；否则从p1开始遍历h1，遍历一圈后又回到p1，而未遍历到p2，说明两个链表不相交。
*/
typedef int ElemType;

//定义链表的存储结构
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;

typedef struct Node *LinkList;
typedef struct Node *pNode;

//判断单链表有无环，如果有环，返回环上的任意结点，否则返回NULL
pNode testCycle(LinkList L) {
    pNode p1 = L;
    pNode p2 = L;
    while (p2 != NULL && p2->next != NULL) {
        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2) {
            return p1;
        }
    }
    return NULL;
}

//假设两个单链表都没有环
int isJoinedSimple(pNode h1, pNode h2) {
    while (h1->next) {
        h1 = h1->next;
    }
    while (h2->next) {
        h2 = h2->next;
    }
    if (h1 == h2) {
        return 1;
    }
    return 0;
}

//判断两个链表是否相交
int isListJoined(pNode p1, pNode p2) {
    
    pNode cycle1 = testCycle(p1);
    pNode cycle2 = testCycle(p2);
    
    if ((cycle1 != NULL && cycle2 == NULL) || (cycle1 == NULL && cycle2 != NULL)) {
        //1.如果一个有环，一个没有环
        return 0;
    }
    if (cycle1 == NULL && cycle2 == NULL) {
        //2.两个都没有环，判断单链表是否相交
        return isJoinedSimple(p1, p2);
    }
    
    //3.两个都有环
    pNode p = cycle1;
    while (1) {
        if (p == cycle2 || p->next == cycle2) {
            return 1;
        }
        p = p->next->next;
        cycle1 = cycle1->next;
        if (p == cycle1) {
            return 0;
        }
    }
}
