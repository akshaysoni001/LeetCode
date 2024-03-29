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
        
        if(head->next==NULL and n==1) return NULL;
        
        ListNode * ptr = head;
        ListNode * ptr2 = head;
        for(int i=0;i<n;i++) ptr2 = ptr2->next;
        // ListNode * prev = ptr;
        
        if(ptr2==NULL){
            head = head->next;
            return head;
        }
        
        while(ptr2->next){
            ptr2 = ptr2->next;
            // prev = ptr;
            ptr = ptr->next;
        }
        ptr->next = ptr->next->next;
        return head;       
        
        
    }
};

// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode *fast = head, *slow = head;
//         for (int i = 0; i < n; i++) fast = fast->next;
//         if (!fast) return head->next;
//         while (fast->next) fast = fast->next, slow = slow->next;
//         slow->next = slow->next->next;
//         return head;
//     }
// };