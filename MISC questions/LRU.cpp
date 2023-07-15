//LRU page replacement algorithm
#include<stdio.h>
#include<stdlib.h>
int page_sequence[100],total_pages=0;//storing the sequence of pages

int faults=0,pointer=0,hit=0;
int LRU[20]; //declaring an array  to store the recent pages
void add_page(int *frame,int page,int n);
int main()
{
    int n=0;
    printf("Enter number of frames: ");
    scanf("%d",&n);
    int frame[n],i=0,j=0,page;
    for(i=0;i<n;i++)
    {
        frame[i] = -1;
        LRU[i] = i;
    }
    while(1)//loop for menu
    {
        int choice=0;
        printf("\nSelect Operation:\n\t1.Add a page\n\t2.Stop\n\nYour Selection: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Page number: ");
                scanf("%d",&page);
                add_page(frame,page,n);
                page_sequence[total_pages] = page;
                total_pages++;
                break;
            case 2:
                printf("No. of page faults = %d\n",faults);
                printf("Page fault ratio = %.2f",(float)faults/total_pages);
                exit(0);
            default:
                printf("Invalid operation! Try again\n");
        }
    }
}

//add_page
void add_page(int *frame,int page,int n)
{
    int i=0,flag,place=-1,j,k;
    for(i=0;i<n;i++)
    {
        if(frame[i] == page )
        {
            printf("P%d is already present in frame %d\n",page,i);
            hit++;
            //reordering LRU's contents
            for(j=0;j<n;j++)
            {
                if(LRU[j] == i)
                {
                    k=j;
                    //swappings
                    if(k>pointer)
                    {
                        while(k>pointer)
                        {
                            int t = LRU[k];
                            LRU[k] = LRU[k-1];
                            LRU[k-1] = t;
                            k--;
                        }
                        //updating pointer
                        pointer++;
                        pointer = pointer%n;
                    }
                    else if(k<pointer)
                    {
                        while(k+1<pointer)
                        {
                            int t = LRU[k];
                            LRU[k] = LRU[(k+1)%n];
                            LRU[(k+1)%n] = t;
                            k++;
                            k = k%n;
                        }
                    }

                    break;
                }
            }
            return;
        }
    }
    place = LRU[pointer];
    flag = frame[place];
    frame[place] = page;
    printf("P%d is accomodated in frame %d ",page,place);
    if(flag>0)
        printf("after removing P%d\n",flag);
    else
        printf("\n");
    faults++;
    pointer++;
    pointer = pointer%n;

}