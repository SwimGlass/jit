#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h> 
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>
#include <fcntl.h>

typedef struct Token_list{
    char array[100];
    int count;
    struct Token_list *next;
}Token_list;

void match_pattern(char *argv[])
{
    FILE *fp;
    int fd,r,j=0,count=0;
    char temp,line[100];
    Token_list *head = (Token_list *)malloc(sizeof(Token_list));
    Token_list *t = head;
    fp=fopen("tokenList.txt","r");
    while(fgets(t->array,100,fp)!=NULL){
        t->array[strlen(t->array)-1]='\0';
        t->count = 0;
        t->next = (Token_list *)malloc(sizeof(Token_list));
        t=t->next;
    }
    t=head;
    while((t->next)!=NULL) 
        if(t->next->array[0]=='\0')
        { 
            t->next=NULL;
        }
        else t=t->next;
    t=head;
    while(t!=NULL)
    {
        if((fd=open(argv[1],O_RDONLY)) != -1)
        {
            while((r=read(fd,&temp,sizeof(char)))!= 0)
            {
                if(temp!='\n')
                {
                    line[j]=temp;
                    j++;
                }
                else
                {
                    if(strstr(line,t->array)!=NULL) t->count++;
                    //printf("%s\n",line);
                    memset(line,0,sizeof(line));
                    j=0;
                }
            }
            printf("%s\t%d\n",t->array,t->count);
            t=t->next;
        }
    }   
}

int main(int argc,char *argv[])
{
    struct stat stt;
    if(argc==2)
    {
        if(stat(argv[1],&stt)==0)
        {
            match_pattern(argv);
        }
        else 
        {
            perror("stat()");
            exit(1);
        }
    }
    return 0;
}
