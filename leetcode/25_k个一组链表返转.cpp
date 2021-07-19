/*
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

进阶：

你可以设计一个只使用常数额外空间的算法来解决此问题吗？
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 

示例

1->2->3->4->5

For  k  = 2,  return: 2->1->4->3->5

For  k  = 3,  return: 3->2->1->4->5

提示：

列表中节点的数量在范围 sz 内
1 <= sz <= 5000
0 <= Node.val <= 1000
1 <= k <= sz
*/

/*
递归
处理逻辑：

判断当前“车箱”是否是 满载。如果不是直接返回当前车箱头。
如果是满载，翻转当前车箱里面的元素。
跳到下节车箱，递归处理车箱里面的元素。
返回当前处理完车箱的车头位置
递归处理，直到最后一节车箱处理完
这里面需要注意，在递归函数里面，最开始的 “车头” head，经过翻转变成当前车箱的 “车尾”。
刚好用于下节车箱的 连接头尾。所以会有 head->next = reverseKGroup(node, k)
再来就是递归函数要返回 “车头” ，给上个递归函数做“连接”。所有会有 return res
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto node = head;
        for (int i=0; i < k; ++i) { // 判断“满载”
            if (!node) return head;
            node = node->next;
        }
        auto res = reverse(head, node); // 翻转“满载”车箱
        head->next = reverseKGroup(node, k); // 递归处理下节车箱
        return res; // 返回当前翻转完车箱的车头位置
    }

private:
    // 翻转车箱元素
    ListNode* reverse(ListNode* left, ListNode* right) {
        auto pre = right;
        while (left != right) {
            auto node = left->next;
            left->next = pre;
            pre = left, left = node;
        }
        return pre;
    }
};



/*
代码2 递归2
代码逻辑同上面代码，只不过把翻转函数合到的递归函数里面，看起来更精简，更舒服。

（注意，与代码1对比，还是有一些细微的差别）
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto isOk = head;
        for (int i = 0; i < k; ++i) {
            if (!isOk) return head;
            isOk = isOk->next;
        }
        ListNode *cur = head, *pre = nullptr, *next = nullptr;
        for (int i = 0; i < k; ++i) {
            next = cur->next;
            cur->next = pre;
            pre = cur, cur = next;
        }
        head->next = reverseKGroup(cur, k);
        return pre;
    }
};

