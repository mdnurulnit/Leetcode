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
    ListNode* merge(ListNode* L,ListNode* R){
        if(L==NULL and R==NULL)return NULL;
        if(L==NULL)return R;
        if(R==NULL)return L;
        ListNode* root;
        ListNode* r1=L;
        ListNode* r2=R;
        ListNode* temp=new ListNode(0);
        // if(r1->val<r2->val){
        //         temp->val=r1->val;
        //         r1=r1->next;
        //     }else{
        //         temp->val=r2->val;
        //         r2=r2->next;
        //     }
        root=temp;
        //temp=temp->next;
        while(r1!=NULL and r2!=NULL){
            //ListNode* node=new ListNode();
            if(r1->val<r2->val){
                // node->val=r1->val;
                // node->next=NULL;
                temp->next=r1;
                r1=r1->next;
            }else{
                // node->val=r2->val;
                temp->next=r2;
                r2=r2->next;
                // node->next=NULL;
            }
            temp=temp->next;
        }
        if(r1==NULL)
            temp->next=r2;
        if(r2==NULL)
            temp->next=r1;
        // while(r1){
        //     ListNode* node=new ListNode(r1->val);
        //     temp->next=node;
        //     temp=temp->next;
        //     r1=r1->next;
        // }
        // while(r2){
        //     ListNode* node=new ListNode(r2->val);
        //     temp->next=node;
        //     temp=temp->next;
        //     r2=r2->next;
        // }
        return root->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0)
            return NULL;
        if(n==1)
            return lists[0];
        ListNode* root=merge(lists[0],lists[1]);
        for(int i=2;i<lists.size();i++){
            root=merge(root,lists[i]);
        }
        return root;
    }
};