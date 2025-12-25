struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head==NULL){
        return head;
    }
    label1:if(head->val==val){
        head=head->next;
        if(head==NULL){
            return head;
        }
        goto label1;
    }
    struct ListNode* temp=head,*temp2=head;
    while(temp!=NULL){
        if(temp->val==val){
            temp2->next=temp->next;
            temp=temp->next;
            continue;
        }
        temp2=temp;
        temp=temp->next;
        
    }
    return head;
}
