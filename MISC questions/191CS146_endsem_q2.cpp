#include <stdio.h>
#include <stdlib.h>
struct process
{
    int size;
    int flagp;
    int partno;
};
struct block
{
    int size;
    int flag;
    int i_f;
    int pno;
    int partno;
};
int main()
{
    int l, nb, np;
    printf("\n enter the size of memory :  ");
    scanf("%d", &l);
    printf("\n enter the no of partition going to do:  ");
    scanf("%d", &nb);
    struct block *b = (struct block *)malloc(nb * sizeof(struct block));
    int rem_l = l;
    int nopart = 1;
    for (int i = 0; i < nb; i++)
    {
        printf("\n size of part %d  : ", i + 1);
        scanf("%d", &b[i].size);
        if (b[i].size <= rem_l)
        {
            b[i].partno = nopart++;
            b[i].flag = 1;
            rem_l = rem_l - b[i].size;
        }
        else
        {
            printf("\n cannot include part %d because available memory is %d ", i + 1, rem_l);
        }
    }
    printf("\n\n no of process :");
    scanf("%d", &np);
    struct process *p = (struct process *)malloc(np * sizeof(struct process));
    for (int i = 0; i < np; i++)
    {

        p[i].flagp = 0;
        p[i].partno = -1;
    }
    int ch = 1;
loop:
    while (ch != 3)
    {
        int x;
        printf("\n enter the choice 1)insertion 2)deletion 3)stop  ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("\n\n insertion");
            printf("\n enter process to insert :");
            scanf("%d", &x);
            if (p[x].flagp == 1)
            {
                printf("\n process%d is already present in partition %d", x, p[x].partno);
            }
            else
            {

                printf("\n enter the process size :");
                scanf("%d", &p[x].size);
                int min = 999;
                int index;
                int ifflag = 0, exflag = 0, fflag = 0;
                for (int i = 0; i < nb; i++)
                {
                    if (b[i].size >= p[x].size && b[i].size < min && b[i].flag == 1)
                    {
                        index = i;
                        fflag = 1;
                        //min = b[i].size;
                    }
                    else if (b[i].flag == 2)
                    {
                        if (b[i].i_f >= p[x].size)
                        {
                            ifflag = b[i].partno;
                        }
                        else
                        {
                            exflag = exflag + b[i].i_f;
                        }
                    }
                }
                if (fflag == 1)
                {
                    printf("process %d insert into partition %d", x, b[index].partno);
                    b[index].flag = 2;
                    b[index].pno = x;
                    b[index].i_f = b[index].size - p[x].size;
                    p[x].flagp == 1;
                    p[x].partno = b[index].partno;
                }
                else
                {
                    if (ifflag > 0)
                    {
                        printf("\n process%d is cannot insert because of internal fragmentation ", x);
                    }
                    else if (p[x].size <= exflag)
                    {
                        printf("\n process%d cannot insert because of external fragmentation", x);
                    }
                    else
                    {
                        printf("\n process%d cannot insert ", x);
                    }
                }
            }
        }

        if (ch == 2)
        {
            printf("process no for deletion :");
            scanf("%d", &x);
            if (p[x].partno == -1)
            {
                printf("\n page not in memmory");
            }
            else
            {
                printf("process %d is removed from %d", x, p[x].partno);
                p[x].partno = -1;
                p[x].flagp = -1;
                b[p[x].partno].flag = 1;
                b[p[x].partno].i_f = 0;
                b[p[x].partno].pno = -1;
            }
        }
        else if (ch == 3)
        {
            printf("%d amount of memory not used", rem_l);
            printf("\n printing memory");
            int totalif;
            for (int i = 0; i < nb; i++)
            {
                if (b[i].flag > 0)
                {
                    printf("\n process %d in %d partion", b[i].pno, b[i].partno);
                    totalif += b[i].i_f;
                }
            }

            printf("\n");
            printf("\n total internal fragmentation if %d", totalif);

            exit(0);
        }
        else
        {
            printf("\n please enter correct choice");
        }
    }

    return 0;
}