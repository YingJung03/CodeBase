/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 建立一個假節點 dummy，並讓 current 指向它。最後返回 dummy->next 就可以得到合併後的鏈結表。
        // new ListNode(0) 或 new ListNode(-1)都可以
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        // 使用兩個指標 list1point 和 list2point 來遍歷 list1 和 list2
        ListNode* list1point = list1;
        ListNode* list2point = list2;

        // 當兩個鏈結表都不為空時，進行合併，有一方為空就結束
        while (list1point != nullptr && list2point != nullptr) {
            // 比較兩個鏈結表的當前節點，將較小的節點鏈接到 current
            if (list1point->val < list2point->val) {
                current->next = list1point;
                list1point = list1point->next;
            } else {
                current->next = list2point;
                list2point = list2point->next;
            }
            // 將 current 移動到下個位置
            current = current->next;
        }

        // 如果 list1 還有剩餘的節點，直接鏈接到 current
        if (list1point != nullptr) {
            current->next = list1point;
        }

        // 如果 list2 還有剩餘的節點，直接鏈接到 current
        if (list2point != nullptr) {
            current->next = list2point;
        }

        // 返回合併後的鏈結表（去掉 dummy 節點）
        return dummy->next;
    }
};
