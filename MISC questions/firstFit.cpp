#include <stdio.h>
#include <stdlib.h>

void firstFit();
void Remove();
void Display();

struct process{
    int size;
    int id;
};
struct process *proc;

struct node{
    int size;
    int flag;
    struct process p;
    struct node *prev;
    struct node *next;
};
struct node *head;

int t_size, id;

int main()
{
    int n1;
    proc=(struct process*)malloc(100*sizeof(struct process));
    printf("\nEnter the total memory block size: ");
    scanf("%d", &t_size);
    head=(struct node*)malloc(sizeof(struct node));
    head->size=t_size;
    head->flag=0;
    head->prev=head->next=NULL;

    printf("\nThe operations available are:");
    printf("\n1. Insert");
    printf("\n2. Remove");
    printf("\n3. Display");
    printf("\n4. Exit");
    
    while(true){
        printf("\n--> ");    
        scanf("%d", &n1);
        switch(n1)
        {
        case 1:
            {
                firstFit();
                break;
            }
        case 2:
            {
                Remove();
                break;
            }
        case 3:
            {
                Display();
                break;
            }
        default:
            printf("\nEnter the valid input!!");
        }
    }
}

void firstFit()
{
    int flag=0;
    struct node *newnode, *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    (proc+id)->id=id;
    printf("\nEnter the Process size: ");
    scanf("%d", &(proc+id)->size);
    temp=head;
    do{
        if(temp->flag==0 && temp->size>(proc+id)->size){
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->size=(proc+id)->size;
            newnode->flag=1;
            newnode->p=*(proc+id);
            temp->size=temp->size-(proc+id)->size;
            if(temp->prev){
                temp->prev->next=newnode;
                newnode->prev=temp->prev;
                newnode->next=temp;
                temp->prev=newnode;
            }else{
                newnode->prev=NULL;
                head=newnode;
                head->next=temp;
                temp->prev=head;
            }
            flag=1;
            break;
        }
        else if(temp->flag==0 && temp->size==(proc+id)->size){
            temp->flag=1;
            temp->p=*(proc+id);
            flag=1;
            break;
        }
    }while((temp=temp->next));
    if(flag==1){
        printf("\nThe process is allocated");
    }else{
        printf("\nThe process couldn't be allocated");
    }
    id++;
}

void Remove()
{
    int v, flag=0;
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the Process ID of the process to be removed: ");
    scanf("%d", &v);
    temp=head;
    do{
        if(temp->flag==1 && temp->p.id==v){
            temp->flag=0;
            flag=1;
            if((temp->prev) && (temp->next)){
                if(temp->prev->flag==0 && temp->next->flag==0){
                    temp->size=temp->size+temp->prev->size+temp->next->size;
                    temp->prev=temp->prev->prev;
                    temp->next=temp->next->next;
                    if(temp->prev){
                        temp->prev->next=temp;
                    }else{
                        head=temp;
                    }
                    if(temp->next){
                        temp->next->prev=temp;
                    }
                    break;
                }else if(temp->prev->flag==0){
                    temp->size=temp->size+temp->prev->size;
                    temp->prev=temp->prev->prev;
                    if(temp->prev){
                        temp->prev->next=temp;
                    }else{
                        head=temp;
                    }
                    break;
                }else if(temp->next->flag==0){
                    temp->size=temp->size+temp->next->size;
                    temp->next=temp->next->next;
                    if(temp->next){
                        temp->next->prev=temp;
                    }
                    break;
                }
            }else if((temp->prev)){
                if(temp->prev->flag==0){
                    temp->size=temp->size+temp->prev->size;
                    temp->prev=temp->prev->prev;
                    if(temp->prev){
                        temp->prev->next=temp;
                    }else{
                        head=temp;
                    }
                    break;
                }
            }else if((temp->next)){
                if(temp->next->flag==0){
                    temp->size=temp->size+temp->next->size;
                    temp->next=temp->next->next;
                    if(temp->next){
                        temp->next->prev=temp;
                    }
                    head=temp;
                    break;
                }
            }
        }
    }while((temp=temp->next));
    if(flag==1){
        printf("\nThe process is removed");
    }else{
        printf("\nThe process couldn't be removed");
    }
}

void Display()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    printf("\nAbout Memory Partitions");
    do{
        printf("\n\nPartition size = %d", temp->size);
        if(temp->flag==1){
            printf("\nProcess is allocated");
            printf("\nProcess ID: %d", temp->p.id);
        }else{
            printf("\nNo process is allocated");
        }

    }while((temp=temp->next));
}