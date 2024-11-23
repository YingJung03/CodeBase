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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nodes;
        // 對 lists 中的每個鏈結串列頭節點 lst 進行遍歷
        // 多個鏈結串列的所有節點值取出並匯集成一個鏈結串列
        for (ListNode* lst : lists) {
            while (lst!=nullptr) {
                nodes.push_back(lst->val);
                lst = lst->next;
            }
        }
        sort(nodes.begin(), nodes.end());

        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        for (int node : nodes) {
            cur->next = new ListNode(node);
            cur = cur->next;
        }
        return res->next;
    }
};