/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return NULL;

        ListNode* curr = head;
        unordered_set<ListNode*> nodes;

        while(curr->next != NULL) {
            if(nodes.find(curr) != nodes.end())
                return curr;
            nodes.insert(curr);
            curr = curr ->next;
        }
        return NULL;
    }
};
