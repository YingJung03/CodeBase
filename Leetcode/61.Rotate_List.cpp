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
    ListNode* rotateRight(ListNode* head, int k) {
        // 處理特殊情況
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        ListNode *now=head;
        int len=1;
        while(now->next!=nullptr){
            len++;
            now = now->next;
        }

        // 變成循環串列
        now->next = head;
        
    
        int stop_num = len - (k % len);  // 計算要移動位置
        ListNode* newTail = head;
        
        // 找到新的尾節點
        for (int i = 1; i < stop_num; i++) {
            newTail = newTail->next;
        }
        
        // 設定新的頭跟斷開尾節點
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        
        return newHead;  

    }
};