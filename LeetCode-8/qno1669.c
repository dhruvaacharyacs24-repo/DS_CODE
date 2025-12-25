struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode* temp,*temp2,*temp3; int c=0;
    temp=list1;
    while(temp->next!=NULL && c<a){
        temp2=temp;
        temp=temp->next;
        c++;
    }
    temp2->next=list2;
    temp3=list2;
    while(c<b){
        temp=temp->next;
        c++;
    }
    while(temp3->next!=NULL){
        temp3=temp3->next;
    }
    temp3->next=temp->next;
    return list1;
    
}
