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
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        if(list1 == NULL && list2 == NULL)
            return NULL;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        ListNode* main = NULL;

        if(temp1->val <= temp2->val){
            main = temp1;
            temp1 = temp1->next;
        } else {
            main = temp2;
            temp2 = temp2->next;
        }

        ListNode* ans = main;

        while(temp1 != NULL && temp2 != NULL){
            if(temp1->val <= temp2->val){
                main->next = temp1;
                temp1 = temp1->next;
            } else {
                main->next = temp2;
                temp2 = temp2->next;
            }
            main = main->next;
        }

        if(temp1 != NULL){
            main->next = temp1;
        } else if(temp2 != NULL) {
            main->next = temp2;
        }

        return ans;
    }
};