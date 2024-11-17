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
// Merge sort解法
class Solution {
public:
    // 主函數，排序鏈表
    ListNode* sortList(ListNode* head) {
        // 基本情況：空鏈表或只有一個節點的鏈表已經有序
        if (head==nullptr || head->next==nullptr){
            return head;
        }
        // 使用快慢指針找到鏈表中點
        ListNode* slow = head;
        ListNode* fast = head->next; // 快指針比慢指針多一步，確保分割平衡
        while (fast!=nullptr && fast->next!=nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 將鏈表分割為兩部分
        ListNode* mid = slow->next; // 中點節點
        slow->next = nullptr;       // 斷開鏈表

        // 遞歸排序左右部分
        ListNode* left = sortList(head);  // 排序左部分
        ListNode* right = sortList(mid); // 排序右部分

        // 合併兩個有序鏈表
        return merge(left, right);
    }

private:
    // 合併兩個有序鏈表
    ListNode* merge(ListNode* l1, ListNode* l2) {
        // 建立一個虛擬頭節點，方便處理
        ListNode* dummy=new ListNode(0);
        ListNode* tail = dummy;

        // 合併過程
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1; // l1 的值較小，接入結果鏈表
                l1 = l1->next;  // 移動 l1
            } else {
                tail->next = l2; // l2 的值較小，接入結果鏈表
                l2 = l2->next;  // 移動 l2
            }
            tail = tail->next; // 移動 tail 指針
        }

        // 將剩餘節點接到結果鏈表
        tail->next = l1 ? l1 : l2;

        return dummy->next; // 返回合併後的鏈表頭
    }
};
