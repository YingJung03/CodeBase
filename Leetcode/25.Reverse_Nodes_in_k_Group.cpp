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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* groupPrev = dummy;

        while (true) {
            ListNode* kth = getKth(groupPrev, k);
            // 如果不到 K 個節點，則返回 nullptr，退出迴圈。
            if (kth==nullptr) {
                break;
            }
            // 記錄下一組的起點
            ListNode* groupNext = kth->next;
            
            // 反轉當前分組
            ListNode* prev = kth->next;
            ListNode* curr = groupPrev->next;
            while (curr != groupNext) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            // 更新前一組的指標並接回反轉結果
            ListNode* tmp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = tmp;
        }
        return dummy->next;
    }

// 找到第 𝑘 個節點，並返回該節點指標。

private:
    ListNode* getKth(ListNode* curr, int k) {
        while (curr!=nullptr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};
