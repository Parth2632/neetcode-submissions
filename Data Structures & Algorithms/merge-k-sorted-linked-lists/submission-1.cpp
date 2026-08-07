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
        if(lists.size()==0){
            return NULL;
        }
        return mergeHelper(lists,0,lists.size()-1);
    }
    ListNode *mergeHelper(vector<ListNode*>&lists, int start, int end){
        int mid = start + (end-start)/2;
        if(start==end){
            return lists[start];
        }
        if(end==start+1){
            return mergetwo(lists[start],lists[end]);
        }
        ListNode *left = mergeHelper(lists,start,mid);
        ListNode *right = mergeHelper(lists,mid+1,end);
        return mergetwo(left,right);
    }
    ListNode *mergetwo(ListNode *l1, ListNode *l2){
        ListNode *dummy = new ListNode(-1);
        ListNode *current = dummy;
        while(l1 && l2){
            if(l1->val<l2->val){
                current->next = l1;
                l1 = l1->next;
            }
            else{
                current ->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        if(!l2){
            current->next = l1;
        }
        else{
            current->next = l2;
        }
        return dummy->next;
    }
};
