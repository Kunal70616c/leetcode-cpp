// 24. Swap Nodes in Pairs
/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr = head;
        ListNode* temp;
        ListNode* prev = nullptr;
        if (head == nullptr) {
            return head;
        } else if (head->next == nullptr) {
            return head;
        }
        while (curr != nullptr && curr->next != nullptr) {
            temp = curr->next;
            if (curr == head) {
                head = temp;
            }
            curr->next = temp->next;
            temp->next = curr;

            if (prev != nullptr) {
                prev->next = temp;
            }

            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};
