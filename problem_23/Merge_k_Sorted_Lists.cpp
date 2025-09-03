// 23. Merge k Sorted Lists
/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                cur->next = new ListNode(list1->val);
                cur = cur->next;
                list1 = list1->next;
            } else {
                cur->next = new ListNode(list2->val);
                cur = cur->next;
                list2 = list2->next;
            }
        }

        // If one Becomes Nil add rest
        if (list1 != nullptr) cur->next = list1;
        if (list2 != nullptr) cur->next = list2;
        
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> mergedLists;
        ListNode* l1;
        ListNode* l2;
        if (lists.size() == 0) {
            return nullptr;
        }
        while (lists.size() > 1) {
            mergedLists = {};
            for (int i = 0; i < lists.size(); i += 2) {
                 l1 = lists[i];
                if ((i + 1) < lists.size()) {
                     l2 = lists[i + 1];
                } else {
                     l2 = nullptr;
                }
                mergedLists.push_back(mergeTwoLists(l1, l2));
            }
            lists = mergedLists;
        }
        return lists[0];
    }
};
