#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    int data;
     struct node* next;
} Node;
void display(Node* head){
    Node*temp = head;
    while(temp != NULL){
      printf("%d ", temp->data);
      temp = temp->next;
    }
 }
Node* insertElement(Node* head, int value){
    Node* ptr = (Node*)malloc(sizeof(Node));
    if(ptr == NULL){
      printf("OverFlow");
    }
    else{
        ptr->data = value;
        if(head == NULL){
            ptr->next = NULL;
            head  = ptr;
        }else{
            Node*temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            ptr->next = NULL;
            temp->next = ptr;
            }
    }
    return head;
}
Node* bubbleSort(Node* head, int size){
    int itr = 0;
    int swapped;
   while(itr < size){
        Node *traverseNode = head;
        Node *prevNode = head;
        swapped = 0;
   while(traverseNode->next != NULL){
                Node* ptr = traverseNode->next;
                if(traverseNode->data > ptr->data){
                    swapped = 1;
                    if(traverseNode == head){
                        traverseNode->next = ptr->next;
                        ptr->next = traverseNode;
                        prevNode = ptr;
                        head = prevNode;
                    }else{
                        traverseNode->next = ptr->next;
                        ptr->next = traverseNode;
                        prevNode->next = ptr;
                        prevNode = ptr;
                    }
                    continue;
                }
                prevNode = traverseNode;
                traverseNode = traverseNode->next;
        }
        itr++;
    }
    return head;
}
 int main(){
   char input[100];
   fgets(input, 100, stdin);
   input[strcspn(input, "\n")] = '\0';
   int indexInput = 0;
   int temp = 0;
   int is_negative = 0;
  Node* head = NULL;
   while(indexInput <= strlen(input)){
    if(input[indexInput] == ' ' || input[indexInput] == '\0'){
        if(is_negative == 1){
            temp = temp*-1;
       head = insertElement(head, temp);
        // display(head);
        is_negative = 0;
        }else{
          head =  insertElement(head, temp);
       }
        temp = 0;
      }
      else if(input[indexInput] == '-'){
        is_negative = 1;
      }
      else{
        temp = temp*10 + (input[indexInput] - '0');
      }
      indexInput++;
   }
   int count = 0;
   Node* temp1 = head;
   while(temp1 != NULL){
     count++;
    temp1 = temp1 -> next;
   }
bubbleSort(head, count);
display(head);
 return 0;
}