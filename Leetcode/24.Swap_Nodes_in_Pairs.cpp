class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        
        ListNode* prev = nullptr;
        ListNode* current = head;
        head = head->next; 

        while (current != nullptr && current->next != nullptr) {
            ListNode* nextPair = current->next->next; 
            ListNode* second = current->next;          

            
            second->next = current;
            current->next = nextPair;

            
            if (prev != nullptr) {
                prev->next = second;
            }

            
            prev = current;
            current = nextPair;
        }

        return head;
    }
};
