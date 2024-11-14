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
    ListNode* deleteDuplicates(ListNode* head) {
        // 創建了一個值為 0 的新節點，並將其 next 指向 head
        ListNode *dummy=new ListNode(0,head);
        ListNode *prev=dummy;
        
        while(head!=nullptr){
            // 如果當前節點和下一個節點的值相同
            if(head->next!=nullptr && head->val==head->next->val){
                while(head->next!=nullptr && head->val==head->next->val){
                    head=head->next;
                }
                prev->next=head->next;
            }else{
                prev=prev->next;
            }
            head=head->next;
        }
        
        return dummy->next;
            
    }

        
};