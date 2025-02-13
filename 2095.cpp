class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return nullptr; // If only one node, return nullptr

        ListNode* slow = head, *fast = head, *prev = nullptr;
        
        while (fast && fast->next) {
            prev = slow; 
            slow = slow->next; 
            fast = fast->next->next; 
        }

        prev->next = slow->next; // Remove middle node
        delete slow; // Free memory
        return head;
    }
};
