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

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.empty()) return NULL;

        vector<int> v;
        for(int i=0; i<lists.size(); i++) {
            ListNode* temp = lists[i];
            while (temp) {
                v.push_back(temp->val);
                temp = temp->next;
            }
        }
        if(v.size()==0) return NULL;

        sort(v.begin(), v.end());

        ListNode* head = new ListNode();
        ListNode* curr = new ListNode();

        for(int i=0; i<v.size(); i++) {
            ListNode *temp = new ListNode(v[i]);
            
            if(i==0) {
                head = temp;
                curr = head;
            } else {
                curr->next = temp;
                curr = temp;
            }
        }
        return head;
    }
};
