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
 } return head;
}
bool twostringhavedifferentcharcter(Node*temp1, Node*temp2, bool value){
    int flag = 0;
    for(int index1 = 0; index1 < strlen(temp1->name); index1++){
        for(int index2 = 0; index2 < strlen(temp2->name); index2++){
            if(temp1->name[index1] == temp2->name[index2]){
                value = false;
                break;
            }
        }
        if(value == false){
            break;
        }
    } return value;
}
int maximumlength(Node*head, int maximum){
    for(Node* temp1 = head; temp1 != NULL; temp1 = temp1->next){
        for(Node* temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next){
            bool value = true;
            if(twostringhavedifferentcharcter(temp1, temp2, value)){
               int length1 = strlen(temp1->name);
            int length2 = strlen(temp2->name);
            if(length1*length2 > maximum){
                maximum = length1*length2;
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
    int flag = 0;
    if(strlen(input) > 2){
        flag = 1;
    }
    if(flag == 1){
        head = stringconvertintolinklist(head, input);
    int maximum = 0;
     maximum = maximumlength(head, maximum);
     printf("%d", maximum);
    }
return 0;
}
