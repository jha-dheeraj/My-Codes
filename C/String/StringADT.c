#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <stdbool.h>

struct String
{
    int size;
    int length;
    char *string;
};

void populateString(struct String *string1)
{
    printf("\nEnter string:");
    /* The first call to printf leaves a newline character in 
    the input buffer. The next call gets() considers that newline 
    as end of input and hence doesn't wait for you to input.
    Consume the newline character using another getchar(). */
    getchar();
    gets(string1->string);
}

void DisplayString(struct String string)
{
    int i=0;
    printf("\nHere is your string:");
    puts(string.string);
    /* find out, why it is not working, without setvbuf?? 
    setvbuf (stdout, NULL, _IONBF, 0);
    printf("\n%s\n",string.string);*/
}

void vowelCount(struct String string)
{
    int i=0,flag=0;
    while(string.string[i]!='\0')
    {
        if(string.string[i]=='A' || string.string[i]=='E' || string.string[i]=='I' || 
        string.string[i]=='O' || string.string[i]=='U' || string.string[i]=='a' || 
        string.string[i]=='e' || string.string[i]=='i' || string.string[i]=='o' || 
        string.string[i]=='u' )
            flag++;
        i++;
    }
    printf("\n\nNumber of vowel in the given string=%d",flag);
}

void wordCount(struct String string)
{
    int i=0,count=0;
    while(string.string[i]!='\0')
    {
        if(string.string[i++]==' ')
            count++;
    }
    printf("Number of Words=%d",count);
}
void stringReverse(struct String *string)
{
    int i,j;
    char temp;
    i=0;
    j=strlen(string->string)-1;
    while(i!=j)
    {
        temp = string->string[i];
        string->string[i++]=string->string[j];
        string->string[j--]=temp;
    }
}
void stringCompare()
{
    struct String string1, string2;
    int i =0;
    printf("\nEnter size of string1 and string2:");
    scanf("%d%d",&string1.size, &string2.size);
    string1.string=(char *)malloc(string1.size*(sizeof(char)));
    string2.string=(char *)malloc(string2.size*(sizeof(char)));

    printf("\nEnter string1:");
    getchar();
    gets(string1.string);
    printf("\nEnter string2:");
    gets(string2.string);
    printf("\nStrings are:\n");
    puts(string1.string);
    puts(string2.string);

    while(string1.string[i]!='\0' && string2.string[i]!='\0')
    {
        if(string1.string[i] != string2.string[i])
            break;
        else
            i++;
    }
    if(string1.string[i] == string2.string[i])
        printf("\nStrings are Equal!!");
    else if(string1.string[i] > string2.string[i])
        printf("\nString1 is greater!");
    else
        printf("\nString2 is greater!");
    
}

void stringPelindrome(struct String string)
{
    int i=0,j;
    j=strlen(string.string)-1;
    while(i!=j)
    {
        if(string.string[i++]!=string.string[j--])
            break;
    }
    if(i==j)
        printf("\nStrings are pelindrome.\n");
    else
        printf("\nString are not pelindrome\n");
}

bool isDuplicate(char key, char string[])
{
    int i,flag;
    flag=1;
    for(i=0;string[i]!='\0';i++)
    {
        if(string[i]==key)
            flag++;
    }
    if(flag>1)
        return true;
    else 
        return false;
}

void findDuplicate(struct String string)
{
    int i,j,choice,k;
    char temp[26]="";
    int temp1[26]={0};
    i=0;
    k=0;
    printf("\nEnter 1 to find duplicate using Brute Force method.");
    printf("\nEnter 2 to find duplicate using Hash table method.");
    printf("\nEnter 3 to find duplicate using Bitwise operation method.");
    scanf("%d",&choice);

    if(choice==1)
    {
        while(string.string[i]!='\0')
        {
            for(j=0;string.string[j]!='\0';j++)
            {
                if(j!=i && string.string[i]==string.string[j])
                {
                    if(!isDuplicate(string.string[i],temp))
                    {
                        temp[k++]=string.string[i];
                    }
                }
            }
            i++;
        }
        printf("\nDuplicate characters are:\n");
        for(i=0;temp[i]!='\0';i++)
            printf("%c, ",temp[i]);
    }
    else if(choice==2)
    {
        for(i=0;string.string[i]!= '\0';i++)
        {
            temp1[string.string[i]-97]+=1;
        }
        printf("\nDuplicate letters are:\n");
        for(i=0;i<26;i++)
        {
            if(temp1[i]>1)
                printf("%c, ",i+97);
        }

    }
    else if(choice==3)
    {
        /* In above hashing method, we have used an array of length 26
        i.e. completely waste of space(about 26*4 Byte). But we just need to store
        26 value, that can be stored in 26 bit, or maximum of 1 BYTE.
        So, here we will use that method only. */
        int H = 0; /* Hash Byte, Int is used as, Int is of 4 Byte(32 BITS) */
        int X,i;
        for(i=0; string.string[i]!='\0';i++)
        {
            X=1; /*To make LSB 1 i.e 00000001 */
            X=X<<(string.string[i]-97); /* It will move 1 to the index according to aphabet */
            if(H&X) /* This is called Masking, to check if required bit is on or not */
                printf("\n' %c ' character appeared multiple times in this string.",string.string[i]);
            else
                H=H | X; /* This is called Merging, i.e. making some bit ON */
        }

    }
    else
    {
        printf("\nInvalid Choice!!!");
    }
}

void checkAnagram()
{
    char str1[20];
    char str2[20];
    int  hash[26]={0};
    int i,flag=0;
    printf("\nEnter string1: ");
    scanf("%s",str1);
    printf("\nEnter string2: ");
    scanf("%s",str2);
    puts(str1);
    puts(str2);
    for(i=0;str1[i]!='\0';i++)
    {
        hash[str1[i]-97]+=1;
    }
    for(i=0;str2[i]!='\0';i++)
    {
        hash[str2[i]-97]-=1;
    }

    for(i=0;i<26;i++)
    {
        if(hash[i]!=0)
            flag=1;
    }
    if(flag==0)
        printf("\nStrings are Anagram.\n");
    else
        printf("\nStrings are not Anagram.\n");

}
int main()
{
    struct String string1;
    int choice=1;
    printf("\nEnter Size of string you want to create:");
    scanf("%d",&string1.size);
    string1.string=(char *)malloc(string1.size*sizeof(char));
    while(choice>0)
    {
        printf("\n\nEnter Choice:");
        printf("\nEnter 1 to populate string.");
        printf("\nEnter 2 to display string.");
        printf("\nEnter 3 to to count vowels in string.");
        printf("\nEnter 4 to do word count in string.");
        printf("\nEnter 5 to reverse the string.");
        printf("\nEnter 6 to compare two string.");
        printf("\nEnter 7 to check is string is pelindrome or not.");
        printf("\nEnter 8 to find duplicate in given string.");
        printf("\nEnter 9 to check string Anagram.");
        printf("\nEnter 10 to check string permutation.");
        printf("\nEnter -1 to exit.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case -1:
                printf("\nUser Asked for Termination!!!");
                break;
            case 1:
                populateString(&string1);
                break;
            case 2:
                DisplayString(string1);
                break;
            case 3:
                vowelCount(string1);
                break;
            case 4:
                wordCount(string1);
                break;
            case 5:
                stringReverse(&string1);
                break;
            case 6:
                stringCompare();
                break;
            case 7:
                stringPelindrome(string1);
                break;
            case 8:
                findDuplicate(string1);
                break;
            case 9:
                checkAnagram();
                break;
            default :
                printf("\nInvalid Choice...");
                break;
            
        }
    }
    printf("\nDone with use of String ADT, Releasing Memory...!\n");
    free(string1.string);

    return 0;

}