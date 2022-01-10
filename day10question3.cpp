class Solution
{
    public:
    void linkdelete(struct Node  *head, int m, int n)
    {
        struct Node *temp = head;
        int x = m, y = n;
        m--;
        while(temp!=NULL && m--){
            temp = temp->next;
        }
        
        if(temp == NULL) return;
        
        struct Node *temp2 = temp->next;
        while(temp2 != NULL && n--){
            struct Node *del = temp2;
            temp2 = temp2->next;
        }
        
        temp->next = temp2;
        linkdelete(temp2, x, y);
    }
};