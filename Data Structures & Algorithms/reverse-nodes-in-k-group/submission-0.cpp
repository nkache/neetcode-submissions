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
    ListNode* reverse(ListNode* a, ListNode* b)
    {
        ListNode* prev = b->next;
        while (a != b)
        {
            ListNode* tmp = a->next;
            a->next = prev;
            prev = a;
            a = tmp;
        }

        a->next = prev;
        return a;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode *s = dummy, *e = dummy;

        while (e) {
            for (int i = 0; i < k; ++i) {
                e = e->next;
                if (!e) return dummy->next;
            }
            ListNode* start = s->next;
            s->next = reverse(start, e);
            s = start;
            e = start;
        }

        return dummy->next;
    }
};