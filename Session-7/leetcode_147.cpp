class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        vector<int>res;
        while(head!=NULL){
            res.push_back(head->val);
            head=head->next;
        }
        sort(res.begin(),res.end());
        ListNode * dummy= new ListNode(-1);
        ListNode *temp=dummy;
        for(int &i:res){
            temp->next=new ListNode(i);
            temp=temp->next;
        }
        return dummy->next;
    }
};


