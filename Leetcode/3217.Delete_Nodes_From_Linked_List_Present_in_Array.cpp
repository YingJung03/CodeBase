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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(0); 
        ListNode* prev = dummy;
        prev->next=head;
        ListNode* current = head;

        while(current!=nullptr){
            
            if (numSet.find(current->val) != numSet.end()){
                // 存在
                prev->next=current->next;
                current=current->next;
            
            }else{
                // 不存在
                prev=current;
                current=current->next;
            }
        }

        return dummy->next;


    }
};