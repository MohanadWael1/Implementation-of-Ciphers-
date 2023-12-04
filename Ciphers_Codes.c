#include "stdio.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
char Native_Alpha[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char Alpha[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','1','2','3','4','5','6','7','8','9','0','?','!','.',',',';',':','+','-','/','='};
char Morse_Table[][6] = {".-" /*a*/
                        ,"-..."/*b*/
                        ,"-.-."/*c*/
                        ,"-.."/*d*/
                        ,"."/*e*/
                        ,"..-."/*f*/
                        ,"--."/*g*/
                        ,"...."/*h*/
                        ,".."/*I*/
                        ,".---" /*j*/
                        ,"-.-" /*k*/
                        ,".-.." /*l*/
                        ,"--"  /*m*/
                        ,"-."  /*n*/
                        ,"---" /*o*/
                        ,".--." /*p*/
                        ,"--.-" /*q*/
                        ,".-."  /*r*/
                        ,"..."  /*s*/
                        ,"..._" /*t*/
                        ,".--"  /*u*/
                        ,"-..-" /*v*/
                        ,"-.--" /*w*/
                        ,"--.." /*x*/
                        ,".----"/*y*/
                        ,"..---"/*z*/
                        ,"...--"
                        ,"....-"
                        ,"....."
                        ,"-...."
                        ,"--..."
                        ,"---.."
                        ,"----."
                        ,"-----"
                        ,"..--.."
                        ,"-.-.--"
                        ,".-.-.-"
                        ,"--..--"
                        ,"-.-.-."
                        ,"---..."
                        ,".-.-."
                        ,"-....-"
                        ,"-..-."
                        ,"-...-"
                        };
void Cesar_Cipher_Encrypt(void);
void Cesar_Cipher_Decrypt(void);
void Morse_Code_Encrypt(void);
void Morse_Code_Decrypt(void);
int Morse_char_search(char ch);
void Affine_Cipher_Encrypt(void);
void Affine_Cipher_Decrypt(void);
int Morse_Code_search(char code[]);
int str_len(char word[]);
int char_search(char character);
int mod_inv(int a);










int main()
{
    int choice ;
    printf("Welcome to Ciphers and Codes Repo \n");
    printf("**********************************\n");
    while(choice !=0)
    {
    printf(" 1- Cesar Cipher Encryption \n ");
    printf(" 2- Cesar Cipher Decryption \n ");
    printf(" 3- Morse Code Encryption \n ");
    printf(" 4- Morse Code Decryption \n ");
    printf(" 5- Affine Cipher Encryption \n");
    printf(" 6- Affine Cipher Decryption \n");
    printf(" 7- Rail Fence Cipher Encryption \n");
    printf(" 0-Exit \n");
    printf(" **********************************\n");
    scanf("%i" , &choice);

    switch (choice)
        {
            case 1:
                Cesar_Cipher_Encrypt();
            break;

            case 2:
                Cesar_Cipher_Decrypt();
            break;

            case 0:
                printf("Thanks");
                break;
            break;

            case 3:
                Morse_Code_Encrypt();
            break;

            case 4:
            Morse_Code_Decrypt();
            break;
            case 5:
                Affine_Cipher_Encrypt();
            break;
            case 6:
                Affine_Cipher_Decrypt();
            break ;
            case 7:
                Rail_Fence_Cipher_Encrypt();
            break;
        }
    }



    return 0 ;
}


int str_len(char word[])
{
    int i = 0 ;
    for(i = 0 ; word[i]!= '\0' ; i++);
    return i ;
}


 Cesar_Cipher_Encrypt(void)
{   char word[100];
    int key = 0 ;
    printf("Enter the Plain Text : \n");
    scanf("%s",word);
    fflush(stdin);
    printf("Enter Key : \n");
    scanf("%i",&key);
    int index = str_len(word);
    int i = 0 ;
    int j = 0 ;
    int new_key = 0 ;
    for(i = 0 ; i <index ; i++)
    {       word[i] = tolower(word[i]);
            j = char_search(word[i]);
            new_key = key + j ;
            if (new_key > 25)
            {
                new_key -= 26 ;
            }
            word[i] = Native_Alpha[new_key];
    }
            printf("%s \n",word);
}


int char_search(char character)
{
   int index = (int)character - 97 ;
    return index ;
}


void Cesar_Cipher_Decrypt(void)
{
    char word[100];
    int key = 0 ;
    printf("Enter the Cipher Text : \n");
    scanf("%s",word);
    fflush(stdin);
    printf("Enter Key : \n");
    scanf("%i",&key);
    int index = str_len(word);
    int i = 0 ;
    int j = 0 ;
    int new_key = 0 ;
    for(i=0 ; i<index ; i++)
    {
        word[i] = tolower(word[i]);
        j = char_search(word[i]);
        new_key = j - key ;
        if(new_key < 0)
        {
            new_key+= 26 ;
        }
        word[i] = Native_Alpha[new_key];
    }
    printf("%s \n",word);
}
void Morse_Code_Encrypt(void)
{
    char word[100];
    printf("Enter the Plain Text : \n");
    scanf("%s",word);
    fflush(stdin);
    printf("the word u entered is  %s \n",word);
    int index = str_len(word);
    int i = 0 ;
    int j = 0 ;
    for(i = 0 ; i < index ; i ++)
    {
        word[i]=tolower(word[i]);
        j=Morse_char_search(word[i]);
        printf("%s  " , Morse_Table[j]);
    }
    printf(" \n");
}

void Morse_Code_Decrypt(void)
{
    char word[6];
    int index = 0;
     printf("Enter character");
     scanf("%s",word);
     fflush(stdin);
     printf("The character u Entered is %s \n",word);
     index = Morse_Code_search(word);
     printf("The index is %i \n",index);
     printf("The character is %c \n",Alpha[index]);
}

int Morse_char_search(char ch)
{
    int i = 0 ;
    for(i = 0 ; i < strlen(Alpha) ; i++)
    {
        if(ch == Alpha[i])
        {
            return i ;
        }
    }
    return -1 ;
}
int Morse_Code_search(char *code)
{
       int i ;
   for(i = 0 ; i < 46 ; i++)
   {
       if (strcmp(code , Morse_Table[i]) == 0)
       {
           return i ;
       }
   }
   return -1 ;
}


void Affine_Cipher_Encrypt(void)
{
    char word[100];
     printf("Enter the Plain Text : \n");
    scanf("%s",word);
    fflush(stdin);
    printf("the word u entered is  %s \n",word);
    int a , b = 0 ;
    printf("Enter the First Key for the format ax+b \n");
    scanf("%i",&a);
    printf("Enter the second Key for the format ax+b \n");
    scanf("%i",&b);
    int index = str_len(word);
    int i = 0 ;
    int j = 0 ;
    int temp = 0 ;
    int new_key = 0 ;
    for(i = 0 ; i < index ; i++)
    {
        word[i] = tolower(word[i]);
        j = char_search(word[i]);
        temp = (a*j)+b ;
         if (temp < 26)
         {
             new_key = temp;
         }
         else
         {
             new_key = temp % 26 ;
         }
            word[i] = Native_Alpha[new_key];
    }
        printf("%s \n",word);
}
void Affine_Cipher_Decrypt(void)
{
    char word[100];
     printf("Enter the Cipher Text : \n");
    scanf("%s",word);
    fflush(stdin);
    printf("the word u entered is  %s \n",word);
    int a , b = 0 ;
    printf("Enter the First Key for the format ax+b \n");
    scanf("%i",&a);
    printf("Enter the second Key for the format ax+b \n");
    scanf("%i",&b);
    int index = str_len(word);
    int i = 0 ;
    int j = 0 ;
    int temp = 0 ;
    int new_key = 0 ;
     for(i = 0 ; i < index ; i++)
     {
         word[i] = tolower(word[i]);
         j = char_search(word[i]);
          temp = ((j-b) * mod_inv(a))%26;
          if(temp < 0)
          {
              temp += 26;
          }
          new_key = temp ;
        word[i] = Native_Alpha[new_key];
     }
     printf("%s \n" , word);
}

int mod_inv(int a)
{
     a = a%26;
    int i = 0 ;
    for(i = 1 ; i < 26 ; i++)
    {
        if((a*i)%26 ==1)
        {
            return i ;
        }
    }
    return -1 ;
}













