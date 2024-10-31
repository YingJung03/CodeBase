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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: 建立虛擬節點，指向鏈表的頭部
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Step 2: 初始化快慢指針，指向 dummy 節點
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Step 3: 讓 fast 指針先向前移動 n+1 步
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Step 4: 同步移動快慢指針，直到 fast 到達鏈表末尾
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Step 5: 刪除 slow 的下一個節點
        // ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        // delete toDelete;  // 釋放記憶體

        // Step 6: 返回新鏈表的頭節點
        ListNode* newHead = dummy->next;
        delete dummy;  // 釋放 dummy 節點
        return newHead;
    }
};