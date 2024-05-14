/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr1=headA;
        ListNode* curr2=headB;
        int num1=0;
        int num2=0;
        //先計算A和B的節點數
        while(curr1->next!=NULL)
        {
            num1+=1;
            curr1=curr1->next;
        }
        while(curr2->next!=NULL)
        {
            num2+=1;
            curr2=curr2->next;
        }
        //當A和B平行時，才開始看他們是不是指到同一個點
        while(num2!=num1)
        {
            if(num2>num1)
            {
                headB=headB->next;
                num2-=1;
            }
            else
            {
                headA=headA->next;
                num1-=1;
            }
        }
        if(num2==num1)
        {
            while(headB!=headA)
            {
                headB=headB->next;
                headA=headA->next;
            }
        }
        return headA;  
    }
};