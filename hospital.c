#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int id;
    char name[50];
    struct node* next;
}Node;

Node* insertElement(Node * head, int id, char * name){
    Node* ptr = (Node*)malloc(sizeof(Node));
    if(ptr == NULL){
        printf("Overflow");
    }else{
        ptr->id = id;
       strcpy(ptr->name , name);
       ptr->next = NULL;
       if(head == NULL){
        head = ptr;
       }else{
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next =ptr;
       }}
    return head;
}
void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%d -> %s", temp->id, temp->name);
        temp = temp ->next;
    }
}
void critical(Node* head, char * name1){
    Node* temp = head;
    
    while(temp != NULL){
        if(strcmp(temp->name, name1) == 0){
            printf("%d -> %s\n",temp->id, temp->name);
        }
        temp = temp->next;
    }
}

int uniqueId(Node* head, int id){
    int valid;
    
    do{
        valid = 1;
        printf("Enter the id\n");
        scanf("%d", &id);

        Node*temp = head;
        while(temp !=NULL){
            if(temp->id ==id){
                valid =0;
                printf("invalid input\n");
                break;
            }
            temp = temp->next;
        }
    }while(!valid);
    return id;
}

char* validString(Node* head , char* name){
    int valid;
    do{
        valid = 1;
        printf("Enter the string\n");
        scanf("%s", name);

        
            if((strcmp("critical", name) != 0) && (strcmp("serious", name) != 0) && strcmp("stable", name) != 0){
                valid = 0;
                printf("invalid string\n");
                
            }
        }while(!valid);
    return name;
    }


int main(){
    int n;
    scanf("%d", &n);
    Node* head = NULL;
    
    
 while(n > 0){
    int id;
    char name[50];
     id = uniqueId(head, id);
     strcpy(name , validString(head, name));
  
    head = insertElement(head, id, name);
    n--;
 }
    critical(head, "critical");
    critical(head, "serious");
    critical(head, "stable");
    return 0;
}