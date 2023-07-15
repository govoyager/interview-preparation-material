#include <stdio.h>
#include <stdlib.h>

int *frame, count, n_frames, top, page_fault, p_count;

void addPage()
{
    int val, i, flag=0, temp;
    printf("\nEnter the page number to be added to the frame: ");
    scanf("%d", &val);
    p_count++;
    if(count){
        for(i=0;i<count;i++){
            if(frame[i]==val){
                printf("\nPage%d is already present in Frame%d.", val, i);
                flag=1;
                break;
            }
        }
    }
    if(flag==0){
        page_fault=page_fault+1;
        if(count<n_frames){
            frame[count]=val;
            printf("\nPage%d is accommodated in frame%d.", val, count);
            count++;
        }else{
            temp=frame[top];
            frame[top]=val;
            printf("\nPage%d is accommodated in Frame%d after removing Page%d.", val, top, temp);
            top = (top+1)%n_frames;
        }
    }
}


int main()
{
    int n, c;
    printf("\nEnter the number of frames: ");
    scanf("%d", &n_frames);
    frame = (int*)malloc(n_frames*sizeof(int));
    c=1;
    while(c){
        printf("\n\nThe operations available are - ");
        printf("\n1. Add page");
        printf("\n2. Exit");
        printf("\nEnter the appropriate operation to be performed: ");
        scanf("%d", &n);
        switch(n)
        {
        case 1:
            {
                addPage();
                break;
            }
        case 2:
            {
                c=0;
                break;
            }
        default:
            {
                printf("\nEnter a valid number.");
            }
        }
    }
    printf("\nThe number of Page Faults are %d.\n", page_fault);
    printf("\nThe Page Fault ratio is %f.\n", (page_fault*1.0)/p_count);
}
