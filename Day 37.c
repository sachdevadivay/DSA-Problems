# Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *prev = &dummy;

    while (prev->next != NULL && prev->next->next != NULL) {

        struct ListNode *first = prev->next;
        struct ListNode *second = first->next;

        first->next = second->next;
        second->next = first;
        prev->next = second;

        prev = first;
    }

    return dummy.next;
}
