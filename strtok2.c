#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

char buf[1024] = "";

typedef struct Token_list{
    char array[1024];
    int count;
    struct Token_list *next;
}Token_list;

int main(int argc,char *argv[])
{
    int flag = 0,loop=0;
    FILE *fp = fopen(argv[1],"r");
    if(fp == NULL) {
        printf("Cannot open file '%s' : %s\n", argv[1], strerror(errno));
        return;
    } 
    int c,i,num=0;
    Token_list *t;
    Token_list *head = (Token_list *)malloc(sizeof(Token_list));
    t = head;
    while((c=fgetc(fp))!=EOF){
        switch(c){
            case '+':
                if( flag!=0 ){
                    buf[num++] = c;
                    break;
                }
                else break;
            case '-':
                if( flag!=0 ){
                    buf[num++] = c;
                    break;
                }
                else break;
            case '<':
                if( flag!=0 ){
                    buf[num++] = c;
                    break;
                }
                else break;
            case '>':
                if( flag!=0 ){
                    buf[num++] = c;
                    break;
                }
                else break;
            case '.':
                if( flag!=0 ){
                    buf[num++] = c;
                    break;
                }
                else break;
            case ',':
                if( flag!=0 ){
                    buf[num++] = c;
                    break;
                }
                else break;
            case '[':
                loop++;
                flag = 1;
                buf[num++] = c;
                break;
            case ']':
                if( flag!=0 ){
                    loop--;
                    if(loop == 0){
                        flag = 0;
                        buf[num++] = c;
                        printf("buf:%s\n",buf);
                        t=head;
                        while((t->next)!=NULL){
                            if(strcmp(t->array,buf)==0){
                                t->count++;
                                for(i=0;i<num;i++) buf[i] = '\0';
                                num = 0;
                                while(t!=NULL) t=t->next;
                                break;
                            }
                            t=t->next;
                        }
                        if(t!=NULL){
                            if(strcmp(t->array,buf)==0){
                                t->count++;
                            }
                            else{
                                //buf[num] = c;
                                strncpy(t->array,buf,num);
                                t->count++;
                                t->next = (Token_list *)malloc(sizeof(Token_list));
                            }
                        }
                        for(i=0;i<num;i++) buf[i] = '\0';
                        num = 0;
                        break;
                    }
                    else{
                        buf[num++]=c;
                        break;
                    }
                }
                break;
            default:
                break;
        }
    }
    t=head;
    while(t!=NULL){ 
        printf("%s : %d\n",t->array,t->count);
        t=t->next; 
    }
    return 0;
}
