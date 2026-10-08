# You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

void reorderList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return;


    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

  
    struct ListNode *second = slow->next;
    slow->next = NULL;

    struct ListNode *prev = NULL;
    struct ListNode *next = NULL;

    while (second != NULL) {
        next = second->next;
        second->next = prev;
        prev = second;
        second = next;
    }


    struct ListNode *first = head;
    second = prev;

    while (second != NULL) {
        struct ListNode *temp1 = first->next;
        struct ListNode *temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}
