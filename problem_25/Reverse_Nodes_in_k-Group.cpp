// 25. Reverse Nodes in k-Group
/* 
 Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

*/
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
        // Base Case
        if (head == nullptr || k == 1) {
            return head;
        }
        // Dummy Node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        // Iterator Nodes
        ListNode* prev = dummy;
        ListNode* curr = head;
        // Looping The List
        while (curr != nullptr) {
            ListNode* tail = curr;
            int count = 0;

            // Selecting the Group Range
            while (tail != nullptr && count < k) {
                tail = tail->next;
                count++;
            }
            // IF last Group is less than k we dont change that
            if (count < k) {
                break;
            }
            // Pointers for altering the list
            ListNode* nextGroup = tail;
            ListNode* prevNode = nullptr;
            ListNode* currentNode = curr;

            // Reversing The List
            while (currentNode != nextGroup) {
                ListNode* nextNode = currentNode->next;
                currentNode->next = prevNode;
                prevNode = currentNode;
                currentNode = nextNode;
            }
            // Connecting To Main List
            prev->next = prevNode;
            curr->next = nextGroup;
            // Move Pointers Ahead
            prev = curr;
            curr = nextGroup;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};
