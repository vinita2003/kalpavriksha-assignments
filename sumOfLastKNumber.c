#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} Node;
Node* head;
void addtostream(int value){
    Node* ptr = (Node*)malloc(sizeof(Node*));
    if(ptr == NULL){
        printf("Overflow");
    }else{
        if(head == NULL){
          ptr->data = value;
            ptr->next = NULL;
            head = ptr;
        }else{
            ptr->data = value;
            ptr->next = head;
            head = ptr;
        }
        }}
int sumoflastknumber(int k){
    Node *temp = head;
    int count = 0;
    int sum = 0;
   while(temp != NULL){
        count++;
        temp = temp->next;
    }
if(count < k){
        temp = head;
        while(temp != NULL){
            sum += temp->data;
            temp = temp->next; }
        }else{
        temp = head;
        while(k > 0){
            sum += temp->data;
            temp = temp->next;
            k--;
        }}
 return sum;
 }
int main(){
    int numberOfOperation;
    scanf("%d", &numberOfOperation);
    getchar();
    int arraySum[numberOfOperation];
    int index = 0;
    int lastKNumber;
    scanf("%d", &lastKNumber);
    getchar();
    while(numberOfOperation > 0){
         char choiceCharacter;
        scanf("%c", &choiceCharacter);
        getchar();
        switch(choiceCharacter){
            case 'A':
            printf("Enter the value");
            int value;
            scanf("%d", &value);
            getchar();
            addtostream(value);
            break;
            case 'S':
            // printf("SUM");
            arraySum[index++] = sumoflastknumber(lastKNumber);
            break;
            default:
            break;}
            numberOfOperation--;}
            printf("Output\n");
            for(int index1 = 0; index1 < index; index1++){
                printf("%d\n", arraySum[index1]);
            }
        return 0;}
