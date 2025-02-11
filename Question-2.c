#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
    char name[100];
    struct node* next;
}Node;
Node* insertElement(Node* head, char*temp){
    Node* ptr = (Node*)malloc(sizeof(Node));
    if(ptr == NULL){
        printf("Overflow\n");
    }else{
        strcpy(ptr->name, temp);
        ptr->next = NULL;
        if(head == NULL){
            head = ptr;
        }else{
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = ptr;
        }
    }
    return head;
}

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%s ->", temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}
Node* stringconvertintolinklist(Node* head, char* input){
    int tempIndex = 0;
    char temp[100];
    int inputIndex = 0;

    while(inputIndex < strlen(input)){
        if((input[inputIndex] == ',' || input[inputIndex] == ']') && (tempIndex > 0)){
            temp[tempIndex] = '\0';
            head = insertElement(head, temp);
            strcpy(temp, "");
            tempIndex = 0;
        }else if(input[inputIndex] != '[' && input[inputIndex] != '"'){
            temp[tempIndex++] = input[inputIndex];
        }
        inputIndex++;
    }
    return head;
}
bool twostringhavedifferentcharcter(Node*temp1, Node*temp2){
    for(int i = 0; i < strlen(temp1->name); i++){
        for(int j = 0; j < strlen(temp2->name); j++){
            if(temp1->name[i] == temp2->name[j]){
                return false;
            }
        }
    }
    return true;
}

int maximumlength(Node*head, int maximum){
    
    for(Node* temp1 = head; temp1 != NULL; temp1 = temp1->next){
        
        for(Node* temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next){
            
            if(twostringhavedifferentcharcter(temp1, temp2)){
               int m = strlen(temp1->name);
            int n = strlen(temp2->name);
            
            if(m*n > maximum){
                maximum = m*n;
            }  
            }
           
        }
    }
    return maximum;
}

int main(){
    Node* head = NULL;
    char input[1000];
    scanf("%[^\n]%*c", input);
    head = stringconvertintolinklist(head, input);
    int maximum = 0;
     maximum = maximumlength(head, maximum);
     printf("%d", maximum);
    return 0;
}