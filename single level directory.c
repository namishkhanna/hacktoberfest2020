#include <stdio.h>
#include<string.h>
struct dir{
    char dir[20],file[20][10];
    int index;
}d;

void main()
{
    int ch,i,flag,c;
    char f[20];
    char m[40],s[20];
    printf("Enter the directory name \n");
    scanf("%s",d.dir);
    
    do{
        printf("Select choices \n 1:Create file \n 2:Delete a file \n 3:Search file \n 4:List file \n 0:Exit \n");
        printf("Enter your choice\n");
        scanf("%d",&ch);     
        switch (ch)
        {
        case 1:
            ///Create new file
            printf("Enter a new file name\n");
            scanf("%s",d.file[d.index]);
            
            d.index+=1;
            printf("File created.\n");

            break;
        case 2:
            //Delete a file
            printf("Enter the file to be deleted from directory\n");
            scanf("%s",f);
            flag=0;
            for(i=0;i<d.index;i++)
            {
                if(strcmp(d.file[i],f)==0)
                {
                    flag=1;
                    c=i;
                    break;
                }
            }
            if(flag==1)
            {
                printf("File removed\n");
                
                
                for(i=c;i<d.index-1;i++)
                {   
                    
                    strcpy(m,d.file[i+1]);
                    strcpy(d.file[i],m);


                }
                d.index-=1;

            }
            else
            {
                printf("No such file in the directory \n");
                break;
                
            }
            break;
        case 3:
          //search a file
            printf("enter the file to search\n");
            scanf("%s",m);
            printf("%s",m);
            flag=0;
            for(i=0;i<d.index;i++)
            {
                if (strcmp(d.file[i],m)==0)
                {
                    flag=1;
                    printf("File present at location %d \n",i+1);
                    break;
                }
            }
            if(flag==0)
            {
                printf("Search completed and no such file\n");
                
            }
            break;
        case 4:
        //list files in directory
            printf("\n The Files in directory \n");
            for(i=0;i<d.index;i++)
            {
                printf("%s \n",d.file[i]);
            }
            break;
        default:
            break;
        }
    }
    while(ch);
    {
        printf("\n");
    }
}
