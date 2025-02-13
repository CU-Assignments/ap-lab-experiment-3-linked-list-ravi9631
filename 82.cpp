class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head); // Dummy node pointing to head
        ListNode* prev = &dummy; // Pointer to last distinct node

        while (head) {
            // Check if the current node is a duplicate
            if (head->next && head->val == head->next->val) {
                // Skip all nodes with the same value
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                prev->next = head->next; // Remove duplicates
            } else {
                prev = prev->next; // Move forward if no duplicate
            }
            head = head->next; // Move to the next node
        }

        return dummy.next; // Return new head
    }
};
