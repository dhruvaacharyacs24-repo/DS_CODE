struct ListNode* create(int val){
    struct ListNode* temp=malloc(sizeof(struct ListNode));
    temp->val=val;
    temp->next=NULL;
    return temp;
}
struct ListNode* insertion(struct ListNode *blahh,int val){
    struct ListNode* newnode=create(val);
    struct ListNode* head=blahh;
    if(head==NULL){
        head=newnode;
    }
    else{
        struct ListNode*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }temp->next=newnode;
    }
    return head;
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    struct ListNode *temp1=list1,*temp2=list2,*head=NULL;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->val<=temp2->val){
            head=insertion(head,temp1->val);
            temp1=temp1->next;
        }
        else{
            head=insertion(head,temp2->val);
            temp2=temp2->next;
        }
    }
    if(temp1==NULL){
        while(temp2!=NULL){
            head=insertion(head,temp2->val);
            temp2=temp2->next;
        }
    }
    if(temp2==NULL){
        while(temp1!=NULL){
            head=insertion(head,temp1->val);
            temp1=temp1->next;
        }
    }
    return head;
}
