struct ListNode* sortList(struct ListNode* head) {
    struct ListNode* temp1=head,*temp2=head;
    int blah;
    if(head==NULL){
        return head;
    }
    for(temp1=head;temp1!=NULL;temp1=temp1->next){
        for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next){
            if(temp1->val>=temp2->val){
                blah=temp1->val;
                temp1->val=temp2->val;
                temp2->val=blah;
            }
        }
    }
    return head;
}
