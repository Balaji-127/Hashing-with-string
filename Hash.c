#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define size 26

struct dict
{
    char s[100];
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

void printLetter(char c)
{
    int i = findHash(c);
    printf("\n%c\t - \t",toupper((char)i+'a'));
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

void printAll()
{
    int i;
    for(i=0;i<size;i++)
    {
        if(hash[i])
        {
            printf("\n%c\t - \t",toupper((char)i+'a'));
            struct dict *temp = hash[i];
            while(temp)
            {
                printf("%s -> ",temp->s);
                temp=temp->next;
            }
            printf("NULL\n");
        }
    }
    printf("All other letters do not contain any word\n");
}

void main()
{
    char s[100];
    int choice,flag = 1;
    char letter;
    while (flag)
    {    
        printf("\n1.Insert\n2.Display words of specific character\n3.Display all\n4.Exit\n\nEnter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter a string : ");
            scanf("%s",s);
            insert(s);
            break;
        case 2:
            printf("\nEnter a letter to display the words : " );
            scanf(" %c",&letter);
            printLetter(letter);
            break;
        case 3:
            printAll();
            break;  
        case 4:
            flag=0;
            break;
        default:
            printf("\nEnter a valid choice\n");
        }
    }
    printf("\nDo you want to See the Hash Table ? (y/Y) : ");
    scanf(" %c",&letter);
    if(letter == 'y' || letter == 'Y')
    {
        printf("\nDo you want to see for specific letter ? (y/Y) : ");
        scanf(" %c",&letter);
        if(letter == 'y' || letter == 'Y')
        {
            printf("\nEnter a letter to display the words : " );
            scanf(" %c",&letter);
            printLetter(letter);
        }
        else
        {
            printAll();
        }
    }

}