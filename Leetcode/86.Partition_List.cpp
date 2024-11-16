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
    ListNode* partition(ListNode* head, int x) {
        // 建立兩個虛擬頭節點，用於構造分割後的兩個鏈表
        ListNode* lessDummy = new ListNode(0); 
        ListNode* greaterDummy = new ListNode(0); 
        
        ListNode* less = lessDummy; 
        ListNode* greater = greaterDummy; 
        ListNode* current = head; 
        
        // 遍歷原始鏈表
        while (current != nullptr) {
            if (current->val < x) {
                less->next = current; 
                less = less->next; 
            } else {
                greater->next = current; 
                greater = greater->next; 
            }
            current = current->next; 
        }
        
        // 將大於等於 x 的鏈表接到小於 x 的鏈表後
        greater->next = nullptr; // 確保大於等於 x 的鏈表結尾為 nullptr
        less->next = greaterDummy->next; // 連接兩個鏈表
        
        // 返回小於 x 鏈表的頭節點
        ListNode* partitionedHead = lessDummy->next;
        
        
        delete lessDummy;
        delete greaterDummy;
        
        return partitionedHead;
    }
};
