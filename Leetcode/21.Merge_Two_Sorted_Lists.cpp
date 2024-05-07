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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr){
            return list2;
        }

        if(list2==nullptr){
            return list1;
        }

        ListNode *lst = new ListNode();
        ListNode *temp = lst;
        while(list1!=nullptr && list2!=nullptr)
        {
            ListNode *newNode = new ListNode();
            if(list1->val<list2->val)
            {
                newNode->val = list1->val;
                list1=list1->next;
            }
            else
            {
                newNode->val = list2->val;
                list2=list2->next;
            }
            temp->next=newNode;
            temp=newNode;         //temp=temp.next
        }
        while(list1!=nullptr)
        {
            ListNode *newNode = new ListNode(list1->val);
            list1=list1->next;
            temp->next=newNode;
            temp=newNode;
        }
        while(list2!=nullptr)
        {
            ListNode *newNode = new ListNode(list2->val);
            list2=list2->next;
            temp->next=newNode;
            temp=newNode;
        }
        return lst->next;  
    }
};