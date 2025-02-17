#include <stdio.h>
#include <stdlib.h>
struct heap{
    int total_size;
    int size;
    int* arr;
    int maxheap;
};
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void display(struct heap* h,int n){
    for(int i=0;i<n;i++){
        printf(" %d",h->arr[i]);
    }
    printf("\n");
}

void insert(struct heap* h,int value){
    if(h->size==h->total_size){
        printf("overflow");
        return;
    }
    if(h->maxheap){
        h->arr[h->size]=value;
        int index =h->size;
        h->size++;
        while(index>0 && h->arr[(index-1)/2]<h->arr[index]){
            swap(& h->arr[(index-1)/2],&h->arr[index]);
            index=(index-1)/2;
        }
    }if(!h->maxheap){
        h->arr[h->size]=value;
        int index =h->size;
        h->size++;
        while(index>0 && h->arr[(index-1)/2]>h->arr[index]){
            swap(& h->arr[(index-1)/2],&h->arr[index]);
            index=(index-1)/2;
        }
    }
}
void heapify(struct heap* h,int index){
    int root=index;
    int left=2*index+1;
    int right=2*index+2;
    if(h->maxheap){
        if(h->size > left && h->arr[root] < h->arr[left]){
            root=left;
        }
        if(h->size > right && h->arr[root] < h->arr[right]){
            root=right;
        }
    }else{
        if(h->size > left && h->arr[root] > h->arr[left]){
            root=left;
        }
        if(h->size > right && h->arr[root] > h->arr[right]){
            root=right;
        }
    }
    if(root!=index){
        swap(&h->arr[root],&h->arr[index]);
        heapify(h,root);
    }
}
void sort(struct heap* h){
    int original_size=h->size;

    for(int i=h->size-1;i>0;i--){
        swap(&h->arr[0],&h->arr[i]);
        printf("Deleted node :%d\n",h->arr[i]);
        h->size--;
        heapify(h,0);
        printf("heap tree status:");
        display(h,h->size);
        printf("Array status:");
        display(h,h->total_size);
        printf("\n");
    }
    h->size=original_size;
}

int main(){
    struct heap* h= (struct heap*)malloc(sizeof(struct heap));
    printf("Enter the total size of heap :");
    int total_size;
    scanf("%d",&total_size);
    h->total_size=total_size;
    h->size=0;
    h->arr=(int*)malloc(sizeof(int)*total_size);
    printf("Enter the number algorithm of sorting \n 0.minheap  1.maxheap\n");
    scanf("%d",&h->maxheap);
    for(int i=1;i<=total_size;i++){
        int data;
        printf("Enter number %d. ",i);
        scanf("%d",&data);
        insert(h,data);
    }
    printf("before sorting\n");
    display(h,total_size);
    sort(h);
    printf("after sorting\n");

    display(h,total_size);
}