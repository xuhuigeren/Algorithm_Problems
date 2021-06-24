/*
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

 

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
 

限制：

0 <= 节点个数 <= 5000

*/

//简洁的递归

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(!head || !head->next) return head;
        ListNode* newhead=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;

        return newhead;   
    }
};


// 双指针 就地反转
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre=nullptr, *cur=head;

        
        while(cur!=nullptr){
            ListNode *tmp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=tmp;
        }
        return pre;

    }
};