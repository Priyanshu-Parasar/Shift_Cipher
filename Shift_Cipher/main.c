#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dispOptions()
{
    int ch;
    printf("\t\tWhat do you want to do\n\n");
    printf("\t\t1) Encode a plain text \n");
    printf("\t\t2) Decode a cipher text \n");
    printf("\t\t3) Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: system("cls");
                encode();
                break;

        case 2: system("cls");
                decode();
                break;

        case 3: exit(0);
                break;

        default : printf("Choose a valid option !");
                getch();
                system("cls");
                dispOptions();
                break;
    }
}

void encode()
{
    char text[30];
    int i,j,k;

    printf("Enter text : ");
    scanf(" %[^\n]s",&text);

    printf("Enter the shift key : ");
    scanf("%d",&k);

    int len_text=strlen(text);
    char c_text[len_text];

    for(i=0;i<len_text;i++)
    {
        if(text[i] >= 65 && text[i] <=90 || text[i] >=97 && text[i] <=122 )
        {
            c_text[i]=text[i]+k;

            if((c_text[i]>90 && c_text[i]<97) || c_text[i]>122 || c_text[i]< -110)
            {
                c_text[i]-=26;
            }

        }
        else
        {
            c_text[i]=text[i];
        }

    }

    system("cls");
    printf("\t\tThe cipher text generated : \n");
    printf("\t\t\n%s",c_text);

}

void decode()
{
    char cipher[30];
    int i,j,k;

    printf("Enter cipher text : ");
    scanf("%[^\n]s",&cipher);


    printf("Enter the shift key : ");
    scanf("%d",&k);

    int len_text=strlen(cipher);
    char text[len_text];

    for(i=0;i<len_text;i++)
    {
        if(cipher[i] >= 65 && cipher[i] <=90 || cipher[i] >=97 && cipher[i] <=122 )
        {
            text[i]=cipher[i]-k;

            if(text[i]<65 || (text[i]>90 && text[i]< 97))
            {
                text[i]+=26;
            }


           /* printf("\t%d\t%c\t%d\t%c\t%d\t%c\n",encode[i],encode[i],text[i],text[i],c[j],c[j]);
        */
        }

        else
        {
            text[i]=cipher[i];
        }

    }
    system("cls");
    printf("\t\tThe plain test obtained : \n");
    printf("\t\t\n%s",text);

}

int main()
{
    printf("\tThis is to generate a cipher test from the user input plain text using shift cipher... \n");
    printf("\n\n\tPress any key to continue...");
    getch();
    system("cls");
    dispOptions();

    return 0;
}
