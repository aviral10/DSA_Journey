#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void printNodes(Node* x){
  printf("Nodes:  \n");
  while(x != NULL){
    printf("%d ", x->data);
    x = x->next;
  }
  printf("\n");
}

Node* merge(Node* l1, Node* l2){
    Node* a = l1;
    Node* b = l2;
    Node *fake,*temp;
    fake = (Node*)malloc(sizeof(Node));
    fake->data = -1;fake->next = NULL;
    temp = fake; 
    while(a!=NULL && b!=NULL){
        if(a->data <= b->data){
            temp->next = a;
            temp = a;
            a = a->next;
        }else{
            temp->next = b;
            temp = b;
            b = b->next;
        }
    }
    if(a!=NULL) temp->next = a;
    if(b!=NULL) temp->next = b;
    return fake->next;
}

Node* mergeSort(Node* begin, Node* end){
    if(begin == end){
        return begin;
    }
    Node *first,*mid,*last,*first_mid;
    first=mid=first_mid=last=begin;
    while(last!=end && last->next != end){
        mid = mid->next;
        last = last->next->next;
    }
    // printf("Mid: %d \n", mid->data);
    first_mid = mid->next;
    mid->next = NULL;

    Node* t1 = mergeSort(first, mid);
    Node* t2 = mergeSort(first_mid, end);
    return merge(t1, t2);
}

Node* createll(int *arr, int n){
    Node* head=NULL, *tail = NULL;
    for(int i=0;i<n;i++){
        Node *n = (Node*)malloc(sizeof(Node));
        n->data = arr[i];
        n->next = NULL;
        if(head == NULL){
            head = n;
            tail = n;
        }else{
            tail->next = n;
            tail = n;
        }
    }
    return head;
}



int main(){
    int arr[] = {1,39,10,12,20,-7,6,25,12,15,16,17, 0, 99, -99};
    int arr1[] = {5,20, -1, 0};
    Node* a = createll(arr, 15);
    Node* b = createll(arr1, 4);
    Node*t = b;
    while(t->next!=NULL){
        t = t->next;
    }
    a = mergeSort(b, t);
    printNodes(a);
    // printNodes(b);

    return 0;
}
