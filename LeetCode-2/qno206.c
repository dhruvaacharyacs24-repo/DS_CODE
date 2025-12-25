struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *temp=head,*temp2=NULL,*temp3=head;
    while(temp!=NULL){
        if(temp==head){
            temp2=temp->next;
            temp->next=NULL;
            temp3=temp;
            temp=temp2;
        }
        else{
            temp2=temp->next;
            temp->next=temp3;
            temp3=temp;
            temp=temp2;
            
        }
    }
    return temp3;
}

