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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1,num2,sum,remainder;
        int quotient=0;
        ListNode* dummyHead = new ListNode(0); // 初始化虛擬頭節點
        ListNode* current = dummyHead; // 用於遍歷結果鏈結串列
        
        while(l1!=nullptr || l2!=nullptr){
            int num1 = (l1 != nullptr) ? l1->val : 0; // 取得 l1 的值，若 l1 已空則取 0
            int num2 = (l2 != nullptr) ? l2->val : 0; // 取得 l2 的值，若 l2 已空則取 0
            sum=num1+num2+quotient;
            // 商，要加到下一組sum
            quotient=sum/10;
            // 餘數
            remainder=sum%10;

            // 創建新節點，並將它連接到結果鏈結串列
            current->next = new ListNode(remainder);
            current = current->next; // 移動 current 指標到新節點

            // 移動 l1 和 l2 指標到下一節點（若還有的話）
            if (l1 != nullptr){
                l1 = l1->next;
            }
            if (l2 != nullptr){
                l2 = l2->next;
            }
        }
        // 檢查是否還有剩餘進位
        if (quotient > 0) {
            current->next = new ListNode(quotient);
        }

        return dummyHead->next; // 返回結果鏈結串列的頭（跳過虛擬頭節點）
        

    }
};