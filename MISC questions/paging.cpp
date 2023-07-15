#include <stdio.h>
#include<stdlib.h>

int page_table[250], frame[250], total_pages = 0, pointer = 0;
int page_in_virt, page_in_phy, fault = 0;

void paging(int page,int offset);

int main()
{
    int i, virt_mem_size, phy_mem_size, page_size, choice, pageno, offset;
    printf("Enter Size of Virtual Memory: ");
    scanf("%d", &virt_mem_size);
    printf("Enter Size of physical memory: ");
    scanf("%d", &phy_mem_size);
    printf("Enter Size of page: ");
    scanf("%d", &page_size);
    page_in_virt = virt_mem_size / page_size;
    page_in_phy = phy_mem_size / page_size;
    printf("number of pages in Virtual memory: %d\n", page_in_virt);
    printf("number of pages in physical memory: %d\n", page_in_phy);
    for (i = 0; i < page_in_virt; i++)
        page_table[i] = -1;
    for (i = 0; i < page_in_phy; i++)
        frame[i] = -1;

    while (1)
    {
        printf("\nSelect Option:\t1.Enter the virtual address\t2.Stop\n: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        printf("page no|word offset\n");
            scanf("%d %d", &pageno, &offset);
            paging(pageno, offset);
            total_pages++;
            break;
        case 2:
            printf("No of page fault= %d\n",fault);
            printf("page fault ratio= %.2f",(float)fault/total_pages);
            printf("\nFinal page table\n");
            for(i=0;i<page_in_virt;i++)
            printf("P%d | %2d \n",i,page_table[i]);
            printf("\nFinal frame\n");
            for(i=0;i<page_in_phy;i++)
            printf("F%d | P%d\n",i,frame[i]);
            exit(0);
        default:
            printf("Invalid choice try again\n");
        }
    }

}

void paging(int page, int offset)
{
    int i, flag;
    for (i = 0; i < page_in_phy; i++)
    {
        if (frame[i] == page)
           { printf("The physical address for the above Virtual Address is :  %d | %d \n", i, offset);
            return;
           }
    }
    flag = frame[pointer];
    frame[pointer] = page;
    printf("Page %d is not present in physical memory\nso page %d is accomodated in frame %d", page, page, pointer);
    if (flag >=0)
    {
        printf("after removing P%d according to the FIFO\n",flag);
        page_table[flag] = -1;
    }
    else
        printf("\n");

    fault++;
    page_table[page] = pointer;
    pointer++;
    pointer = pointer % page_in_phy;

}