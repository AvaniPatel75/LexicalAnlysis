#include<stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    FILE *fp1;
    char ch, prev;
    fp1 = fopen("E:/Sem-6/ATCC_Lab/Output.txt","r");
    if(fp1 == NULL){
        printf("File not found\n");
        return 1;
    }

    const char *keywords[] = {
        "auto","break","case","char","const","continue","default","do","double",
        "else","enum","extern","float","for","goto","if","inline","int","long",
        "register","restrict","return","short","signed","sizeof","static","struct",
        "switch","typedef","union","unsigned","void","volatile","while", NULL
    };

    while((ch = fgetc(fp1)) != EOF){

        /* Skip string literals */
        if(ch == '"'){
            while((ch = fgetc(fp1)) != EOF && ch != '"'){
                if(ch == '\\') fgetc(fp1); // skip escaped character
            }
            continue; // skip the closing quote
        }

        /* Double-character operators */
        if (ch=='+' || ch=='-' || ch=='=' || ch=='!' || ch=='<' || ch=='>') {
            char next = fgetc(fp1);
            if ((ch=='+' && next=='+') || (ch=='-' && next=='-') ||
                (ch=='=' && next=='=') || (ch=='!' && next=='=') ||
                (ch=='<' && next=='=') || (ch=='>' && next=='=')) {
                printf("Operator : %c%c\n", ch, next);
                continue;
            } else {
                if(next != EOF) ungetc(next, fp1);
                printf("Operator : %c\n", ch);
                continue;
            }
        }

        /* Other single-character operators */
        if(ch=='*' || ch=='/' ){
            printf("Operator : %c\n", ch);
            continue;
        }

        /* Identifiers / Keywords */
        if(isalpha(ch) || ch=='_'){
            char str[100];
            int i = 0;
            str[i++] = ch;

            char c;
            while((c = fgetc(fp1)) != EOF && (isalnum(c) || c=='_')){
                if (i < (int)sizeof(str) - 1) {
                    str[i++] = c;
                }
            }
            str[i] = '\0';
            if(c != EOF) ungetc(c, fp1);

            /* Check if identifier is a keyword */
            int is_kw = 0;
            for(int k=0; keywords[k] != NULL; k++){
                if(strcmp(str, keywords[k]) == 0){
                    is_kw = 1;
                    break;
                }
            }
            if(is_kw)
                printf("Keyword : %s\n", str);
            else
                printf("Identifier : %s\n", str);
            continue;
        }

        /* Numbers */
        if(isdigit(ch)){
            char num[50];
            int i = 0;
            num[i++] = ch;
            char c;
            while((c=fgetc(fp1))!=EOF && isdigit(c)){
                if(i < (int)sizeof(num)-1) num[i++] = c;
            }
            num[i] = '\0';
            if(c != EOF) ungetc(c, fp1);
            printf("Number : %s\n", num);
            continue;
        }

        /* Symbols */
        if(strchr("(){};,:", ch)){
            printf("Symbol : %c\n", ch);
            continue;
        }

        /* Ignore spaces and other chars */
        if(!isspace(ch)){
            printf("Other char: %c\n", ch);
        }
    }

    fclose(fp1);
    return 0;
}
