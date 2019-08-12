#include<stdio.h>
#include<conio.h>
#include<string.h>
void admin_panel();
void customer_panel();
void admin_access();
void admin_display();
void admin_update();
typedef struct
{
    char mobile_name[30];
    long long int imei_number;
    char issue[156];
    int token;
}COMPLAIN;
//STRUCTURE
COMPLAIN input(void);
void display(COMPLAIN user_input);

void main()
{
int choice;
top:
clrscr();
printf("THIS SOFTWARE IS DEVELOPED BY ANKUSH SONI");
printf("\n WELCOME \n");
printf("\nPRESS [1].FOR ADMIN_PANEL \n");
printf("\nPRESS [2].FOR CUSTOMER_PANEL\n");
printf("\nPRESS [3].FOR EXIT\n");
scanf("%d",&choice);

switch (choice)
     {
        case 1:
              admin_panel();
              break;
        case 2:
              customer_panel();
              break;
        case 3:
              exit(0);
              break;
        default:
               printf("\n WRONG CHOICE  TRY AGAIN");
               getch();
               goto top;
    }
    goto top;
}
void customer_panel()
{
int input_cust;
system("cls");
printf("\n WELCOME TO SMARTPHONE SERVICES CENTER \n");
printf("\nCHOOSE BELOW \n");
printf("\n [1].APPLE \n");
printf("\n [2].SAMSUNG \n");
printf("\n [3].MI \n");
printf("\n [4].NOKIA \n");
printf("\n [5].ONE PLUS \n");
printf("\n [6].FOR MAIN MANU \n");
scanf("%d",&input_cust);

switch (input_cust)
   {
      case 1:
        clrscr();
        select("Apple");
        break;
      case 2:
        clrscr();
        select("Samsung");
        break;
      case 3:
        clrscr();
        select("Mi");
        break;
      case 4:
        clrscr();
        select("Nokia");
        break;
      case 5:
        clrscr();
        select("one plus");
        break;
      case 6:
        clrscr();
        main();
        break;
      default :
       printf("WRONG CHOICE");
       getch();
       clrscr();
       customer_panel();
   }
}
void select(char name[20])
{
    alter:
    printf("\n Welcome To %s Service Center \n",name);
    COMPLAIN user_input;
    user_input=input();
    display(user_input);
    wrong://label
    printf("\n TO CONFORM  ENTER. [YES] \t TO ALTER ENTER.[NO]");
    char check[7];
    fflush(stdin);
    printf("\n");
    gets(check);
    strlwr(check);
    if(strcmp(check,"yes")==0)
    {
        write(user_input);
        read(user_input);
    }
    else if(strcmp(check,"no")==0)
    {
        clrscr();
        goto alter;
    }
    else
    {
        printf("Wrong Choice");
        clrscr();
        goto wrong;
    }

}
COMPLAIN input(void)
{
    COMPLAIN use_input_1;
    printf("\nEnter your Mobile Name \n");
    fflush(stdin);
    gets(use_input_1.mobile_name);
    printf("\nEnter IMEI Number \n");
    scanf("%llu",&use_input_1.imei_number);
    printf("\nIssue With Your Phone\n");
    fflush(stdin);
    gets(use_input_1.issue);
    printf("\n");
    return use_input_1;
}
void display(COMPLAIN user_input)
{
    clrscr();
    printf(" \n Your phone Detail \n");
    printf("\n NAME: %s \n",user_input.mobile_name);
    printf("\n IMEI: %llu \n",user_input.imei_number);
    printf("\n ISSUE: %s \n",user_input.issue);
}
void clrscr()
{
    system("cls");
}
void write(COMPLAIN user_input)
{
    FILE *data_file;
    COMPLAIN copy_file;
    data_file=fopen("token_data.dat","ab+");
    int s_token=0;
    nullfile(data_file);
    while(fread(&copy_file,sizeof(copy_file),1,data_file)>0)
    {
     s_token++;
    }
    s_token++;
    user_input.token=s_token;
    fwrite(&user_input,sizeof(user_input),1,data_file);
    fclose(data_file);
    printf("\n Your Token Number:%d",s_token);
}
void read(COMPLAIN user_input)
{
    FILE *read_data_file;
    read_data_file=fopen("token_data.dat","rb");
    while(fread(&user_input,sizeof(user_input),1,read_data_file)>0)
    {
        printf("\n Token:%d \n Name:%s \n IMEI:%llu \n ISSUE:%s",user_input.token,user_input.mobile_name,user_input.imei_number,user_input.issue);
    }
    fclose(read_data_file);
    getch();
    clrscr();
    main();

}
void nullfile(write)
{
    if(write==NULL)
    {
        printf("data file doesn't exist");
    }
}
////// admin panel start here
void admin_panel()
{
    clrscr();
    printf("\nADMIN PASSWORD: 2580");
    printf("\nThis Section is only for Admin \n");
    printf("\n [1].For Main Menu\n");
    printf("\n To Access Enter  Password \n");
    char user_pass[20];
    fflush(stdin);
    gets(user_pass);
    if(strcmp(user_pass,"2580")==0)
      {
          clrscr();
          printf("\n Welcome Ankush");
          admin_access();
      }
    else if (strcmp(user_pass,"1")==0)
        {
        clrscr();
        main();
        }
    else
       {
        printf("Invalid Password");
        getch();
        clrscr();
        admin_panel();
       }

}
admin_access()
{
    int choice;
    printf("\n 1.display all token \n");
    printf("\n 2.update in any token\n");
    printf("\n 3.For Previous Menu\n");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1 :
        clrscr();
        admin_display();
        break;
        case 2 :
        clrscr();
        admin_update();
        break;
        case 3:
        clrscr();
        admin_panel();
        break;
        default:
            printf("\n Wrong Choice \n");
            getch();
            clrscr();
            admin_access();

    }
}
admin_display()
{
    COMPLAIN read;
    FILE *admin_read;
    admin_read=fopen("token_data.dat","rb");
    nullfile(admin_read);
    while(fread(&read,sizeof(read),1,admin_read)>0)
    {
        printf("\nToken number : %d\tMobile name : %s\tIMEI : %llu\t Issue :%s\n",read.token,read.mobile_name,read.imei_number,read.issue);
    }
    fclose(admin_read);
    getch();
    clrscr();
    admin_access();
}
admin_update()
{
    int admin_input;
    printf("\n[1].Change Name:");
    printf("\n[2].IMEI Number");
    printf("\n[3].Problem");
    printf("\n[4].Change Everything");
    printf("\n[5].Previous Manu");
    printf("\n");
    scanf("%d",&admin_input);

    switch (admin_input)
     {
         case 1 :
          change_name();
          break;
         case 2:
          imei_num();
          break;
        case 3:
          issue();
          break;
        case 4:
          change_every();
          break;
        case 5:
            clrscr();
            admin_access();
        default:
            printf("wrong choice");
            getch();
            clrscr();
            admin_update();

     }
}

change_name()
{
    COMPLAIN name;
    FILE *f1 ;
    FILE *f2 ;
    int user_token;
    printf("\n Enter a token number which you want to change");
    if(name.token!=user_token)
    {
        printf("INVALID TOKEN:");
        getch();
        clrscr();
        admin_update();
    }
    scanf("%d",&user_token);
    char new_name[20];
    fflush(stdin);
    gets(new_name);
    f1=fopen("token_data.dat","rb");
    f2=fopen("token_data1.dat","wb");

    while(fread(&name,sizeof(name),1,f1)>0)
    {
        if(name.token==user_token)
        {
            strcpy(name.mobile_name,new_name);
            printf("name changed!");
        }
        fwrite(&name,sizeof(name),1,f2);
    }
    fclose(f1);
    fclose(f2);
    remove("token_data.dat");
    rename("token_data1.dat","token_data.dat");
    getch();
    clrscr();
    admin_access();
}
void imei_num()
{
    COMPLAIN name;
    FILE *f1 ;
    FILE *f2 ;
    int user_token;
    printf("\n Enter a token number which you want to change");
    scanf("%d",&user_token);
    if(name.token!=user_token)
    {
        printf("INVALID TOKEN:");
        getch();
        clrscr();
        admin_update();
    }
    long long int imei;
    fflush(stdin);
    scanf("%llu",&imei);
    f1=fopen("token_data.dat","rb");
    f2=fopen("token_data1.dat","wb");

    while(fread(&name,sizeof(name),1,f1)>0)
    {
        if(name.token==user_token)
        {
            name.imei_number=imei;
            printf("IMEI changed!");
        }
        fwrite(&name,sizeof(name),1,f2);
    }
    fclose(f1);
    fclose(f2);
    remove("token_data.dat");
    rename("token_data1.dat","token_data.dat");
    getch();
    clrscr();
    admin_access();
}
issue()
{
    COMPLAIN name;
    FILE *f1 ;
    FILE *f2 ;
    int user_token;
    printf("\n Enter a token number which you want to change");
    scanf("%d",&user_token);
    if(name.token!=user_token)
    {
        printf("INVALID TOKEN:");
        getch();
        clrscr();
        admin_update();
    }
    char problme[20];
    fflush(stdin);
    gets(problme);
    f1=fopen("token_data.dat","rb");
    f2=fopen("token_data1.dat","wb");

    while(fread(&name,sizeof(name),1,f1)>0)
    {
        if(name.token==user_token)
        {
            strcpy(name.issue,problme);
            printf("issue update!");
        }
        fwrite(&name,sizeof(name),1,f2);
    }
    fclose(f1);
    fclose(f2);
    remove("token_data.dat");
    rename("token_data1.dat","token_data.dat");
    getch();
    clrscr();
    admin_access();
}
change_every()
{
    COMPLAIN name;
    FILE *f1 ;
    FILE *f2 ;
    int user_token;
    printf("\n Enter a token number which you want to change");
    scanf("%d",&user_token);
    if(name.token!=user_token)
    {
        printf("INVALID TOKEN:");
        getch();
        clrscr();
        admin_update();
    }
    char new_name[20];
    long long int imei;
    char problme[20];
    fflush(stdin);
    printf("\n Enter mobile name ");
    gets(new_name);
    printf("\n Enter new IMEI number");
    scanf("%llu",&imei);
    fflush(stdin);
    printf("\n Enter Issue");
    gets(problme);
    f1=fopen("token_data.dat","rb");
    f2=fopen("token_data1.dat","wb");

    while(fread(&name,sizeof(name),1,f1)>0)
    {
        if(name.token==user_token)
        {
            strcpy(name.mobile_name,new_name);
            name.imei_number=imei;
            strcpy(name.issue,problme);
            printf("changed..");
        }
        fwrite(&name,sizeof(name),1,f2);
    }
    fclose(f1);
    fclose(f2);
    remove("token_data.dat");
    rename("token_data1.dat","token_data.dat");
    getch();
    clrscr();
    admin_access();
}






