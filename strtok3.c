#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main(int argc,char *argv[])
{
    int flag = 0,loop=0;
    FILE *fp = fopen(argv[1],"r");
    if(fp == NULL) {
        printf("Cannot open file '%s' : %s\n", argv[1], strerror(errno));
        return;
    }
    char temp[20];
    char new[]="_new.b";
    strncpy(temp,argv[1],(strlen(argv[1])-2));
    FILE *fpw = fopen(temp,"w"); 
    if(fp == NULL) {
        printf("Cannot open file '%s' : %s\n", argv[1], strerror(errno));
        return;
    }
    int c,i,num=0;
    loop=0;
    while((c=fgetc(fp))!=EOF){
        switch(c){
            case '+':
                fputc(c,fpw);
                break;
            case '-':
                fputc(c,fpw);
                break;
            case '<':
                fputc(c,fpw);
                break;
            case '>':
                fputc(c,fpw);
                break;
            case '.':
                fputc(c,fpw);
                break;
            case ',':
                fputc(c,fpw);
                break;
            case '[':
                fputc(c,fpw);
                loop+=1;
                break;
            case ']':
                fputc(c,fpw);
                loop--;
                if(loop < 1) fputc('\n',fpw);
                break;
            default:
                break;
        }
    }
    fputc(EOF,fpw);
    return 0;
}
