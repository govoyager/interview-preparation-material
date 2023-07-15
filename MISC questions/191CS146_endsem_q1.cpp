//program to implement paging in LRU
#include<stdio.h>
#include<stdlib.h>

void pages(int s, int n, int frame[], int page[], int time[], int p1, int track[]);//function to add pages
int min(int n,int time[]);

int max(int track[], int base, int n);
int minimum(int track[], int base, int n);
float count,count1;
int at=0,ti=0,t=0,tr,trak,page_track[1000];
int main()
{
    int i,n,ch,p,vm,pm,s,initial,seek;
    for(int i=0;i<1000;i++)
    page_track[i]=NULL;
    printf("Enter the size of Virtual memory(in kb):");
    scanf("%d",&vm);
    printf("Enter the size of Physical memory(in kb):");
    scanf("%d",&pm);
    printf("Enter the size of page(in kb):");
    scanf("%d",&s);
    n=pm/s;
    p=vm/s;
    printf("\nNumber of Pages in Virtual memory=%d\n",p);
    printf("Number of Frames in Physical memory=%d\n",n);
    printf("\nTotal no of tracks in secondary memory:");
    scanf("%d",&tr);
    printf("\n");
    int track[tr-1];
    for(int i=0;i<p;i++)
    {
        printf("Location of page%d is in track:",i);
        scanf("%d",&track[i]);
        if(track[i]>tr)
        {
            printf("\nEnter a valid track number\n");
            i--;
        }
    }
    printf("\nEnter the location of r/w head:");
    scanf("%d",&initial);
    int frame[n],page[p],time[n];
    for(int i=0;i<n;i++)
    {
        frame[i]=-1;
        }
    while(1)
    {
        printf("\n1.Enter the Virtual address in the format\nPage no\tWord offset\n2.Stop\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:pages(s,n,frame,page,time,p,track);
                   break;
            case 2:printf("\nNo of page faults:%0.0f\n",count);
                   printf("\nPage fault ratio is:%f\n",count/count1);
                   for(i=0;i<n;i++)
                   printf("%d\n",page_track[i]);
                       seek=initial-2*minimum(page_track,0,tr-1)+2*max(page_track,initial,tr-1)-minimum(page_track,initial,tr-1);
                   printf("\nSeek time is:%d",seek);
                   printf("\n");
                   for(i=0;i<p;i++)
                   page[i]=-1;
                   for(i=0;i<n;i++)
                   page[frame[i]]=i;
                   printf("\nFinal page table\n");
                   for(i=0;i<p;i++)
                   {
                       printf("Page%d %d\n",i,page[i]);
                       }
                   printf("\nFinal Physical memory\n");
                   for(i=0;i<n;i++)
                   {
                       printf("Frame%d Page%d\n",i,frame[i]);
                       }
                   exit(0);
            default:printf("Enter a valid choice\n");
                    break;
                    }
        }
    }
void pages(int s, int n, int frame[], int page[], int time[], int p1, int track[])
{
       int p,w;
       count1++;
       scanf("%d\t%d",&p,&w);
       if(p>=p1)
       {
           printf("No of pages can't be more than %d",p1);
           return;
       }
       if(w>=1024*s)
       {
           printf("Maximum possible byte is %d the word offset of page cannot exceed %d\n",1024*s,1024*s);
           return;
           }
       for(int i=0;i<n;i++)
       {
           if(frame[i]==p)
           {
               printf("Physical address for the above Virtual address is\n%d\t%d\n",i,w);
               t++;
               time[i]=t;
               return;
               }
           else if(frame[i]==-1)
           {
               frame[i]=p;
               printf("Page%d is not present in the Physical memory so page%d is accomodated in frame%d\n",p,p,i);
               page_track[trak]=track[p-1];
               trak++;
               t++;
               time[i]=t;
               count++;
               return;
               }
           }
       at=min(n,time);
       printf("Page%d is not present in the Physical memory so Page%d is accomodated in frame%d after removing page%d\n",p,p,at,frame[at]);
       page_track[trak]=track[p-1];
       trak++;
       frame[at]=p;
       t++;
       time[at]=t;
       count++;
       at++;
       if(at==n)
           at=0;
}
int min(int n,int time[])
{
    int min1,min=1000;
    for(int i=0;i<n;i++)
    {
        if(min>time[i])
        {
            min=time[i];
            min1=i;
        }
    }
    return min1;
}
int max(int track[], int base, int n)
{
    int max=base;
    for(int i=0;i<n;i++)
    if(max<track[i])
    max=track[i];
    return max;
}
int minimum(int track[], int base, int n)
{
    int min=base;
    for(int i=0;i<n;i++)
    if(min>track[i])
    min=track[i];
    return min;
}