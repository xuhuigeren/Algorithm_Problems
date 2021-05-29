/*
反转链表 I
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
*/


//迭代 依次反转
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

//递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //递归退出条件
        if (!head || !head->next) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
