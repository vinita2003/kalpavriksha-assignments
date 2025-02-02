#include<stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 10
typedef struct node{
    int key, value;
    struct node* next;
}Node;

Node* hashTable[TABLE_SIZE] = {NULL};

int hashFunction(int key){
    return key%TABLE_SIZE;
}

void insert(int key, int value){
    int index = hashFunction(key);
    Node* temp = hashTable[index];

    while(temp){
        if(temp->key == key){
            temp->value = value;
            return;
        }
        temp = temp->next;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

void search(int key){
    int index = hashFunction(key);

    Node* temp = hashTable[index];
    while(temp){
        if(temp->key == key){
            printf("Value: %d\n", temp->value);
            return;
        }
        temp = temp->next;
    }
    printf("Key are not found\n");
}

void delete(int key){
    int index = hashFunction(key);
    Node* temp = hashTable[index];
    Node* prev = NULL;
    while(temp){
        if(temp->key == key){
            if(prev){
                prev->next = temp->next;
                temp->next = NULL;
            }else{
                hashTable[index] = temp->next;
            }
            free(temp);
            printf("key %d deleted. \n", key);
            return;
        }

        prev = temp;
        temp = temp->next;
    }
    printf("key are not found");
}

void display(){
    printf("Hash Table:\n");
    for(int index = 0; index < TABLE_SIZE; index++){
        printf("Index %d:", index);
        Node* temp = hashTable[index];
        while(temp){
            printf(" (%d, %d) ->", temp->key, temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
 
 int validkey(int key){
    int valid;
    do{
        valid = 1;
      printf("Enter key: Key should be non-negative integer");
       scanf("%d", &key);
       if(key < 0){
        valid = 0;
       }

    }while(!valid);
 }


int validValue(int value){
    int valid;
    do{
        valid = 1;
     printf("Enter value: Value should be non-negative integer");
       scanf("%d", &value);
       if( value < 0){
        valid = 0;
       }

    }while(!valid);
 }

int main(){
    int choice;

    while(1){
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:{
            int key;
            key = validkey(key);
            int value;
            value = validValue(value);
            insert(key, value);
            break;
            }

            case 2:{
               int key;
            key = validkey(key);
            search(key);
            break;
            }
           

            case 3:{
             int key;
            key = validkey(key);
            delete(key);
            break;
            }
            

            case 4:
            display();
            break;

            case 5:
            printf("Exiting program.\n");
            return 0;

            default:
            printf("Invalid choice! try again.\n");
        }
    }
    return 0;
}