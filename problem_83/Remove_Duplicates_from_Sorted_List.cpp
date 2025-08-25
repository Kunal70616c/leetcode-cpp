// 83. Remove Duplicates from Sorted List
/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
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
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> isSeen;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while (head != nullptr) {
            auto itr = isSeen.find(head->val);
            if (itr == isSeen.end()) {
                isSeen.insert(head->val);
                curr->next = new ListNode(head->val);
                curr = curr->next;
                head = head->next;
            } else {
                head = head->next;
            }
        }
        return dummy->next;
    }
};
