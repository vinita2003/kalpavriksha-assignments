#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int id;
    char name[50];
    int grade;
    struct node* next;
} Node;
Node* insertElement(Node*head, int id, char name[50], int grade){
     Node* ptr = (Node*)malloc(sizeof(Node));
     if(ptr == NULL){
        printf("NULL");
     }else{
        ptr->id = id;
        strcpy(ptr->name ,name);
        ptr->grade = grade;
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
void display(Node *head){
    Node* temp = head;
    while(temp != NULL){
        printf("%d, %s, %d\n", temp->id, temp->name, temp->grade);
        temp = temp->next;
    }
 }
Node* sortedInsert(Node* createNode, Node* sorted){
    if(sorted == NULL  || sorted->id >= createNode->id ){
        createNode->next = sorted;
        sorted = createNode;  
    }
    else{
        Node* curr = sorted;
        while(curr->next != NULL && curr->next->id < createNode->id){
            curr = curr->next;
        }
        createNode->next = curr->next;
        curr->next = createNode;
        }
    return sorted;
     }
Node* insertionSort(Node* head){
    Node* sorted = NULL;
    Node* curr = head;
   while(curr != NULL){
        Node* next = curr->next;
        sorted = sortedInsert(curr, sorted);
        curr = next;
    }
    return sorted;
    }
 void binarySearch(Node* head, int start, int end, int target){
    if(start > end){
        printf("-1");
        return;
    }
    int mid = (end+start)/2;
    int traverse = mid;
    Node* temp = head;
    while(traverse > 0){
        temp = temp->next;
        traverse--;
    }
    if(temp->id == target){
        mid = mid+1;
        printf("%d, %s, %d", temp->id, temp->name, temp->grade);
        return;
    }else if(temp->id < target){
          binarySearch(head, mid+1, end, target);
    }else{
        binarySearch(head, start, mid-1, target);
    }
}
int main(){
    int n;
printf("enter the size of linklist: ");
  scanf("%d", &n);
  getchar();
  int id, grade;
  char str[50];
  Node* head = NULL;
 int flag = 0;
  if(n == 0){
    flag = 1;
    printf("Empty linklist");
 }
 if(flag != 1){
   while(n > 0){
    printf("Enter the id: ");
    scanf("%d", &id);
    printf("Enter the name: ");
    scanf("%s", str);
    getchar();
    printf("Enter the grade: ");
    scanf("%d", &grade);
    getchar();
    head = insertElement(head, id, str, grade);
    n--;
}
  printf("Enter the searching id: ");
  int target;
  scanf("%d", &target);
     head = insertionSort(head);
     printf("After sorting\n");
     display(head);
     int count = 0;
    Node* temp1 = head;
    while(temp1 != NULL){
        count++;
        temp1 = temp1->next;
    }
   printf("After searching: ");
   binarySearch(head, 0 ,count-1, target);
 }
 return 0;
 }