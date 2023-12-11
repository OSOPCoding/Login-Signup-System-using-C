#include<stdio.h>
#include<string.h>
#include<windows.h>
#define path "C:\\Login & Signup system\\database.txt"

char useremail[50];
char userpass[8];
void signup();
void login();
int emailcheck();
int passcheck();
int main()
{

    int choice;
    do
    {

    printf("**********MENU********\n");
    printf("Press 1 : Signup\n");
    printf("Press 2 : Login\n");
    printf("Press 3 : Exit\n");
    printf("**********MENU********\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1 : signup();break;
        case 2 : login();break;
        case 3 : printf("exit\n"); break;
        default : printf("Invalid choice\n");break;
    }
    } while(choice != 3);
    return 0;
}

void login()
{
    while(getchar()!='\n')
    ;
    printf("Enter your email\n");
    gets(useremail);
    printf("Enter your password\n");
    gets(userpass);

    FILE *fptr=NULL;
    fptr = fopen(path,"r");
    if(fptr==NULL)
    {
        system("cls");
        printf("some went wrong try again\n");

    }
    else
    {
        char tempstr[50];
        char temppass[8];
           while(fscanf(fptr,"%s",tempstr)==1)
           {
                 if(strcmp(useremail,tempstr)==0)
                 {
                      fscanf(fptr,"%s",temppass);

                      if(strcmp(userpass,temppass)==0)
                      {
                          system("cls");
                          printf("Login Success Full\n");
                          exit(0);
                      }
                 }

           }

           system("cls");
           printf("Invalid email and password try again or signup\n");
           
    }
    
}
void signup()
{
    while(getchar()!='\n')
    ;
    check1:
   printf("Enter an email\n");
   gets(useremail);

   if(emailcheck()==0)
   {
      goto check1;
   }
   else
   {  
         check2: 
         printf("Enter password\n");

         gets(userpass);
         if(passcheck() == 0)
         {
            goto check2;
         }
         else
         {
              FILE *fptr = NULL;
              fptr = fopen(path,"a");
              if(fptr == NULL)
              {
                 system("cls");
                 printf("Something Went wrong Try again\n");
              }
              else
              {
                   fprintf(fptr,"%s %s\n",useremail,userpass);
                   printf("Signup Success Full");
                   fclose(fptr);
                   exit(0);
              }
         }

    }
   
   
}
int passcheck()
{
    
         int len = strlen(userpass);
         if(len<8)
         {
            system("cls");
            printf("Invalid password min len = 8\n");
             return 0;
         }

         int i =0;
         while(userpass[i]!='\0')
         {
             if(userpass[i] == ' ')
             {
                 system("cls");
                 printf("Invalid password don't use space\n");
                return 0;
             }
             i++;
         }
         return 1;
}
int emailcheck()
{
    int len;
   len =strlen(useremail);
   if(len<12)
   {
      system("cls");
      printf("Invalid email min len 12 \n");
      return 0;
   }
   int i =0;
   while(useremail[i] != '\0')
   {
      if(useremail[i]==' ')
      {
         system("cls");
         printf("Invalid Email don't use space\n");
         return 0;
      }
      i++;
   }
   char tempstr[]= "moc.liamg@";

   i = 0;
   while(tempstr[i]!='\0')
   {
      if(tempstr[i] !=useremail[len-i-1])
      {
          system("cls");
          printf("Invalid email write @gmail.com perfectly\n");
          return 0;
      }
       i++;
   }

    FILE *fptr = NULL;
              fptr = fopen(path,"r");
              if(fptr == NULL)
              {
                 system("cls");
                 printf("Something Went wrong Try again\n");
              }
              else
              {
                 char tempstr[50];
                  while(fscanf(fptr,"%s",tempstr)==1)
                  {
                      if(strcmp(tempstr,useremail)==0)
                      {
                          system("cls");
                          printf("Email already available\n");
                          return 0;
                      }
                  }
              }
   return 1;

}