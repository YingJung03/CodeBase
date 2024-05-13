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
    ListNode* middleNode(ListNode* head) {
        int n=0;
        ListNode* cur=head;  //cur宣告為指標變數，因此要加上「*」
        while(cur!=nullptr)  //當cur不等於空
        {
            n++;
            cur=cur->next;
        }

        n/=2;
        cur=head;
        while(n!=0)  //當cur不等於空
        {
            n--;
            cur=cur->next;  
        }
        return cur;

    }
};