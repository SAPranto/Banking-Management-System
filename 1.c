
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CODE "MFS115"


int main_exit;

struct date
{
    int month,day,year;

};
struct bank
{

    char name[60];
    int acc_no;
    char address[60];
    char NID[15];
    char phone[12];
    float amt;
    struct date dob;
    struct date deposit;

} add,upd,check;

float interest(float t,float amount,int rate)
{

    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);

}
void fordelay(int j)
{
    int i,k;
    for(i=0; i<j; i++)
        k=i;
}

void new_acc()
{

    int choice;
    int x = 0, y = 0;
    FILE *ptr;
    ptr=fopen("record.txt","a+");
account_no:
    system("cls");
    printf("\t\t\t\xB2\xB2\xB2 ADD RECORD  \xB2\xB2\xB2\xB2");

    printf("\nEnter the account number:");
    scanf("%d",&check.acc_no);
    fflush(stdin);
    while(fscanf(ptr,"%d %s %d/%d/%d %s %s %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,add.address,add.NID,&add.phone,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
        {
            printf("Account no. already in use!");
            fordelay(1000000000);
            goto account_no;

        }
    }
    add.acc_no=check.acc_no;
    printf("\nEnter the name:");
    gets(add.name);
    fflush(stdin);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    do
    {
        scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
        fflush(stdin);

        x = d_valid(add.dob.day, add.dob.month, add.dob.year);

        if (x == 1)
        {

            printf("\nEnter the address:");
            gets(add.address);
            fflush(stdin);
            printf("\nEnter the NID number:");
            gets(add.NID);
            fflush(stdin);
            printf("\nEnter the phone number: ");
            scanf("%s",&add.phone);
            fflush(stdin);
            printf("\nEnter the amount to deposit:BDT");
            scanf("%f",&add.amt);
            fflush(stdin);
            printf("\n\n\nEnter today's date(mm/dd/yyyy):");
            do
            {
                scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
                fflush(stdin);

                y = d_valid(add.deposit.day,add.deposit.month, add.deposit.year);

                if(y == 1)
                {

                    printf("\n\n\t\tFORM SUBMITTED");
                    printf("\n\n  CONGRATULATIONS! YOUR NEW ACCOUNT HAS BEEN CREATED!");
                }
                else
                {
                    printf("\n\n\t\aWRONG INPUT OF DATE!!");
                    printf("\n\tRE-ENTER THE DATE: ");
                }

            }
            while(y == 0);
        }
        else
        {
            printf("\n\n\t\aWRONG INPUT OF DATE!!");
            printf("\n\tRE-ENTER THE DATE: ");
        }
    }
    while (x == 0);

    fprintf(ptr,"%d %s %d/%d/%d %s %s %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.address,add.NID,add.phone,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);


    fclose(ptr);

add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
        exit(0);
    else
    {
        printf("\nInvalid!\a");
        goto add_invalid;
    }
}



int d_valid(int d, int m, int y)
{

    int leap;
    int legit = 0;
    int count = year_valid(y);
    if(count == 4)
    {

        if(y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
            leap=1;

        switch(m)
        {

        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(d>0 && d<32)
            {
                legit = 1;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(d>0 && d<31)
            {
                legit = 1;
            }
            break;
        case 2:
            if(leap == 1)
            {
                if(d>0 && d<30)
                {
                    legit = 1;
                }
            }
            else
            {
                if(d>0 && d<29)
                {
                    legit = 1;
                }
            }
            break;

        }
    }

    else
    {
        printf("\n\nYear should be in full form");

    }
    return legit;
}

int year_valid(int n)
{
    int c;
    if(n == 0)
        return 0;
    else
    {
        c = 1 + year_valid(n/10);
    }

    return (c);
}

void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %s %s %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,add.address,add.NID,&add.phone,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {
            test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
            {
                printf("Enter the new address:");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %d/%d/%d %s %s %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,upd.address,add.NID,add.phone,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
            }
            else if(choice==2)
            {
                printf("Enter the new phone number:");
                scanf("%s",&upd.phone);
                fprintf(newrec,"%d %s %d/%d/%d %s %s %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.address,add.NID,upd.phone,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
            }

        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %s %s %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.address,add.NID,add.phone,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.txt");
    rename("new.txt","record.txt");


        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)

            menu();
        else if (main_exit==2)
            exit(0);
        else if(main_exit==0)
            edit();
        else
        {
            printf("\nInvalid!\a");
            goto edit_invalid;
        }

    if(test!=1)
    {
        system("cls");
        printf("\nRecord not found!!\a\a\a");
edit_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)

            menu();
        else if (main_exit==2)
            exit(0);
        else if(main_exit==0)
            edit();
        else
        {
            printf("\nInvalid!\a");
            goto edit_invalid;
        }
    }
    else
    {
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            exit(0);
    }
}
void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.txt","r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {
        printf("Enter the account number:");
        scanf("%d",&check.acc_no);

        while (fscanf(ptr,"%d %s %d/%d/%d %s %s %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,add.address,add.NID,&add.phone,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {
                system("cls");
                test=1;

                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAddress:%s \nNID No:%s \nPhone number:%s \nAmount deposited:BDT %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.address,add.NID,add.phone,
                       add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

            }
        }
    }
    else if (choice==2)
    {
        printf("Enter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %s %s %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,add.address,add.NID,&add.phone,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {
                system("cls");
                test=1;
                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAddress:%s \nNID No:%s \nPhone number:%s \nAmount deposited:$%.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.address,add.NID,add.phone,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

            }
        }
    }


    fclose(ptr);
    if(test!=1)
    {
        system("cls");
        printf("\nRecord not found!!\a\a\a");
see_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            exit(0);
        else if(main_exit==0)
            see();
        else
        {
            system("cls");
            printf("\nInvalid!\a");
            goto see_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
    }
    if (main_exit==1)
    {
        system("cls");
        menu();
    }

    else
    {

        system("cls");
        exit(0);
    }

}


void menu()
{
    int choice;
    system("cls");

    printf("\n\n\t\t\t\tCSE BANK LTD.");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create new account\n\t\t2.Update information of existing account\n\t\t3.Check the details of existing account\n\t\t4.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
    case 1:
        new_acc();
        break;
    case 2:
        edit();
        break;
    case 3:
        see();
        break;
    case 4:
        exit(0);
        break;
    }
}

int password()
{

    char pass[20], c;
    int i;

    do
    {
        system("cls");
        printf("\n\n Enter password: \n\n\t");

        for (i=0; ; ++i)
        {
            c = getch();

            if (c == '\r')
            {
                pass[i] = '\0';
                break;
            }
            else
            {
                pass[i] = c;
                printf("*");
            }
        }



        printf("\n\n\n\n LOADING");
        for(i=0; i<=4; i++)
        {
            fordelay(100000000);
            printf(".");
        }


        if (!strcmp(pass, CODE))
        {

            printf("\n\n ACCESS GRANTED. \n\n");
            break;
        }

        else
        {
            printf("\n\n\n\n\a ACCESS DENIED. ");

        }
        printf("Press any key to continue...");

        getch();

    }
    while (1);

}

int main()
{

  system("color f5");
    int grant = 1;
    password();
    if(grant == 1)
    {
        printf("Press any key to continue...");
        getch();
        system("cls");
        menu();
    }
    else
    {
        exit(0);
    }
    return 0;
}


