/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         ListNode* slow=head;
//         ListNode* fast=head->next->next;

//         while(fast!=nullptr){
//             if(slow==fast){
                
//             }else{
//                 slow=slow->next;
//                 fast=fast->next->next;
//             }
//         }
//     }
    
// };


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next){
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        
        while (fast && fast->next) {  
            slow = slow->next;        
            fast = fast->next->next;  

            // 快慢指針相遇，說明存在循環
            if (slow == fast) {       
                // 找到循環的起點
                ListNode* entry = head;  // 從頭開始
                while (entry != slow) {  // 當 entry 和 slow 相遇時，即為循環起點
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;  // 返回循環的起始節點
            }
        }

        // 如果 fast 或 fast->next 為空，說明沒有循環
        return nullptr;
    }
};
