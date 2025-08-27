// 19. Remove Nth Node From End of List
//Given the head of a linked list, remove the nth node from the end of the list and return its head.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        ListNode* prev;
        int size = 0, count = 0;
        // base case
        if (head->next == nullptr && n == 1) {
            return nullptr;
        }
        // find size of the list
        while (curr != nullptr) {
            size++;
            curr = curr->next;
        }
        // if n == size that means remove first element
        if (size == n) {
            return head->next;
        }
        curr = head->next;
        prev = head;
        while (count != (size - n - 1)) {
            curr = curr->next;
            prev = prev->next;
            count += 1;
        }
        prev->next = curr->next;
        return head;
    }
};
