#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define size 26

struct dict
{
    char s[10];
    struct dict *next;
};

struct dict *hash[size] = {NULL};

int findHash(char c)
{
    int n;
    n = ((int)(tolower(c) - 'a'))%size;
    return n;
}

void insert(char a[])
{
    int hashValue = findHash(a[0]);
    struct dict *nn;
    nn = malloc(sizeof(struct dict));
    strcpy(nn->s,a);
    nn->next = NULL;
    if(hash[hashValue])
    {
        struct dict *temp = hash[hashValue];
        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }
    else
    {
        hash[hashValue] = nn;
    }
}

void print()
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%c\t - \t",toupper((char)i+'a'));
        if(hash[i])
        {
            struct dict *temp = hash[i];
            while(temp)
            {
                printf("%s -> ",temp->s);
                temp=temp->next;
            }
        }
        printf("NULL\n");
    }
}

void main()
{
    char *s;
    s = malloc(sizeof(char));
    
    
    /* char a[] = "Apple";
    char d[] = "Ball";
    char b[] = "Auto";
    char c[] = "Android";
    char e[] = "Basket";
    insert(a);
    insert(e);
    insert(c);
    insert(d);
    insert(b);
    print();*/
}