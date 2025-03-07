#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int num;
    struct Node* next;
    struct Node* prev;
};
typedef struct Node node;

node* push_back(node* head, int num);
void print_linked_list(node* head);
void print_help();
node* insert(node* head, int num, int pos);
node* delete(node* head, int pos);
node* flush(node* head);
node* look_up(node* head, int pos);


int main(){
    node* head=NULL;
    print_help();
    while(1){
        int command;
        printf("Please enter a command: ");
        scanf("%d",&command);
        if(command==0){
            break;
        }
        else if(command==1){
            int num;
            printf("Please enter a number: ");
            scanf("%d", &num);
            head=push_back(head, num);
        }
        else if(command==2){
            int num, pos;
            printf("Please enter a number and a position: ");
            scanf("%d %d",&num,&pos);
            head=insert(head, num, pos);
        }
        else if(command==3){
            int pos;
            printf("Please enter a position: ");
            scanf("%d",&pos);            
            head=delete(head, pos);
        }
        else if(command==4){
            int pos;
            printf("Please enter a position: ");
            scanf("%d",&pos);              
            node* target=look_up(head, pos);
        }
        else if(command==5){
            print_linked_list(head);
        }
        else if(command==6){
            head=flush(head);
        }
        else if(command==7){
            print_help();
        }
        else{
            printf("Invalid command\n");
        }
    }
    return 0;
}


node* push_back(node* head, int num){
    node* new_node_ptr=(node*)malloc(sizeof(node));
    new_node_ptr->num=num;
    new_node_ptr->next=NULL;
    new_node_ptr->prev=NULL;
    if(head==NULL){
        head=new_node_ptr;
        new_node_ptr->next=head;
        new_node_ptr->prev=head;        
    }
    else{
        node* tail= head->prev;
        tail->next=new_node_ptr;
        new_node_ptr->prev=tail;
        head->prev=new_node_ptr;
        new_node_ptr->next=head;
    }
    return head;
}

void print_linked_list(node* head){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    printf("Current node's num is %d\n",head->num);
    node* current_ptr=head->next;
    while(current_ptr!=head){
        // printf("Current node's memory address is %d\n",current_ptr);
        printf("Current node's num is %d\n",current_ptr->num);
        current_ptr=current_ptr->next;
    }
    printf("\n");
}    

void print_help(){
    printf("0: quit\n");
    printf("1: push back\n");
    printf("2: insert\n");
    printf("3: delete\n");
    printf("4: look up\n");
    printf("5: print linked list\n");
    printf("6: flush\n");
    printf("7: help\n");   
}

node* insert(node* head, int num, int pos){
    node* new_node_ptr=(node*)malloc(sizeof(node));
    new_node_ptr->num=num;
    new_node_ptr->next=NULL;
    new_node_ptr->prev=NULL;
    int length=1;
    if(head==NULL){
        if(pos==0){
            head=new_node_ptr;
            new_node_ptr->next=head;
            new_node_ptr->prev=head;
        }
        else{
            printf("Position invalid\n");
        }
    }    
    else{
        if(pos==0){
            node* tail= head->prev;
            tail->next=new_node_ptr;
            new_node_ptr->prev=tail;
            head->prev=new_node_ptr;
            new_node_ptr->next=head;
            head=new_node_ptr;
        }
        else if(pos==1){
            new_node_ptr->next=head->next;
            new_node_ptr->prev=head;
            head->next->prev=new_node_ptr;
            head->next=new_node_ptr;
        }
        else{
            node* current_ptr=head->next;
            while(current_ptr!=head){
                if(length==pos-1){
                    new_node_ptr->next=current_ptr->next;
                    new_node_ptr->prev=current_ptr;
                    current_ptr->next->prev=new_node_ptr;
                    current_ptr->next=new_node_ptr;
                    return head;
                }
                current_ptr=current_ptr->next;
                length++;
            }
            printf("Position invalid\n");
        }
    }
    return head;
}

node* delete(node* head, int pos){
    int length=1;
    if(head==NULL){
        printf("List is empty, return NULL\n");
        return head;
    }
    else if(head->next==head&&pos>0){
        printf("Position invalid, return head to Target\n");
        return head;
    }
    else if(pos==0){
        if(head->next==head){
            head->next=NULL;
            head->prev=NULL;
            free(head);
            return NULL;
        }
        else{
            node* new_head=head->next;
            head->prev->next=head->next;
            head->next->prev=head->prev;
            head->next=NULL;
            head->prev=NULL;
            free(head);
            return new_head;
        }
    }
    else if(pos==1){
        node* temp=head->next;
        head->next=temp->next;
        temp->next->prev=head;
        temp->next=NULL;
        temp->prev=NULL;
        free(temp);
        return head;
    }
    else{
        node* current= head->next;
        while(current!=head){
            if(length==pos){
                current->next->prev=current->prev;
                current->prev->next=current->next;
                current->next=NULL;
                current->prev=NULL;
                free(current);
                return head;
            }
            current=current->next;
            length++;
        }
        printf("Position invalid, return head to Target\n");
        return head;
    }
}

node* flush(node* head){
    if(head==NULL){
        return NULL;
    }
    node* tail=head->prev;
    while(head!=tail){
        node* temp=tail;
        tail=tail->prev;
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        temp->next=NULL;
        temp->prev=NULL;
        free(temp);
    }
    head->next=NULL;
    head->prev=NULL;
    free(head);
    return NULL;
}

node* look_up(node* head, int pos){
    int length=1;
    if(head==NULL){
        printf("List is empty\n");
        return NULL;
    }
    if(pos==0){
        printf("Target is %d\n",head->num);
        return head;
    }
    else{
        if(head->next==head){
            printf("Position invalid\n");
            return head;
        }
        node* current=head->next;
        while(current!=head){
            if(length==pos){
                printf("Target is %d\n",current->num);
                return current;
            }
            current=current->next;
            length++;
        }
        printf("Position invalid\n");
        return head;
    }

}