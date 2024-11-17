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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddDummy=new ListNode(0);
        ListNode* evenDummy=new ListNode(0);
        ListNode* current=head;
        ListNode* odd=oddDummy;
        ListNode* even=evenDummy;
        
        int num=1;
        while(current!=nullptr){
            // odd
            if(num%2!=0){
                odd->next=current;
                odd=current;
                current=current->next;
                num++;
            }else{
                // even
                even->next=current;
                even=current;
                current=current->next;
                num++;
            }
        }
        even->next = nullptr; 
        odd->next = evenDummy->next; 

        return oddDummy->next;
        
        
    }
};