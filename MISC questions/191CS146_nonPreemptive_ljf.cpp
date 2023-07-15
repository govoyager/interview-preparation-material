//Program for non-Pre-emptive LJF, Kindly use g++ to complie


#include<iostream>
#include<stdlib.h>

using namespace std;
struct ljfs
{
    int no,at,bt,ct,wt,tat,flag;

};
int main()
{
    int n; // number of process
    printf("enter the number of process: ");
    scanf("%d",&n);
    struct ljfs *p;
    p=(struct ljfs*)(malloc(n*sizeof(struct ljfs)));

    cout<<"\nEnter the arival times: ";
    for(int i=0;i<n;i++){
        cin>>(p+i)->at;
    }
    cout<<"\nEnter the burst times: ";
    for(int i=0;i<n;i++){
        cin>>(p+i)->bt;
    }
    int time=0,long_j,i=0;
    printf("%d",time);
    while(i==0)
    {
        if(p->at<=time)
        {
            printf("p%d",i+1);
            time=time+p->bt;
            p->ct=time;
            p->flag = 1;
            printf("%d",time);
            i++;
        }
        else
            time++;
            printf("%d",time);
    }
    for(i=0;i<n;i++)
    {
        (p+i)->flag = 0;
    }
    while(1)
    {
        long_j = -1 ;
        for(i=1;i<n;i++)
        {
            if((p+i)->at<=time)
            {
                if((p+i)->flag == 0)
                {
                    if(long_j == -1)
                        long_j = i;
                    else if((p+i)->bt > (p+long_j)->bt)
                        long_j = i;
                }
            }
        }
        if(long_j > 0)
        {
            printf("p%d",i+1);
            time = time + (p+long_j)->bt;
            (p+long_j)->ct = time;
            (p+long_j)->flag = 1;
        }
        else{
            for(i=1;i<n;i++)
            {
                if((p+i)->flag ==0)
                {
                    long_j = -2;
                    time++;
                    printf("%d ",time);
                    break;
                }
            }
        }
        if(long_j == -1)
         { break;
         }
    }
    for(i=0;i<n;i++)
    {
        (p+i)->tat = (p+i)->ct - (p+i)->at ;
        (p+i)->wt = (p+i)->tat - (p+i)->bt ;
    }
     float avg_tat=0,avg_wt=0;

    printf("\n  ID  AT  BT  CT  TAT  WT");
    for(i=0;i<n;i++)
    {
        printf("\n  %d   %d   %d   %d   %d   %d",(p+i)->no,(p+i)->at,(p+i)->bt,(p+i)->ct,(p+i)->tat,(p+i)->wt);
        avg_tat+=(p+i)->tat;
        avg_wt+=(p+i)->wt;
    }
    avg_tat=avg_tat/n;
    avg_wt=avg_wt/n;
    printf("\n\n  The average of  TATs is %f \n  The average of WTs is %f\n",avg_tat,avg_wt);
    free(p);
    for(i=0;i<n;i++)
    {
        printf("%d",(p+i)->at);
    }
    return 0;

}