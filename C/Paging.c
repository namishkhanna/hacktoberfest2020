//Paging Technique in memory management

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct process
{
    int pid;
    int size;
};

void main()
{
    int n,ch,c,flag,nop,rpage,reqpage,mem,page,id,i=0;
    struct process p[100];
    printf("Enter memory size\n");
    scanf("%d",&mem);
    printf("Enter page size\n");
    scanf("%d",&page);
    nop=mem/page;
    rpage=nop;
    printf("No of pages available is:%d\n",nop);

    do
    {
        printf("MENU 1.ADD\n2.DELETE\nEnter choice\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            
            printf("Enter process id and size\n");
            scanf("%d%d",&p[i].pid,&p[i].size);
            reqpage=(p[i].size+page-1)/page;
            if(reqpage<=rpage)
            {
                rpage-=reqpage;
                printf("Memory allocated successfully\n");
                printf("No of pages available is %d\n",rpage);
            }
            else
            {
                printf("Memory full:unable to allocate\n");
            }
            n=i;
            i++;
        }
        else if(ch==2)
        {
            printf("Enter id of process to be deleted\n");
            scanf("%d",&id);
            for(i=0;i<=n;i++)
            {
                flag=0;
                if(p[i].pid==id)
                {
                    rpage+=(p[i].size+page-1)/page;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                printf("Process with given id not available\n");
            }
            else
            {
                printf("Process deleted.\n");
                printf("No of pages available is %d\n",rpage);
            }
        }
        printf("Do you want to continue\n");
        printf("YES-1\t NO-0\n");
        scanf("%d",&c);
    }while(c==1);
}
