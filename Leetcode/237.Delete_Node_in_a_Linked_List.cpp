/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// node 是指需要刪除的節點，但並未給出整個鏈表的頭節點。因此，我們不能使用常規方法（從頭節點遍歷）。
// 解法是將目標節點的值替換為下一個節點的值，並刪除下一個節點
class Solution {
public:
    void deleteNode(ListNode* node) {
        // 將下一個節點的值複製到當前節點
        node->val = node->next->val;
        // 將下一個節點刪除
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp; // 釋放記憶體
    }
};
