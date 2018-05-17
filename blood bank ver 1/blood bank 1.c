#include <stdio.h>                // to perform print and scan
#include <stdlib.h>               // to do work with file
#include <string.h>              // to compare string
#include <windows.h>              // to use gotoxy/ coordinator

int a=0,b=0;                   // global variable for file
void blooddonar();
void adminwork();                       // declaring functions
void bloodread();
void bloodsave();
void deletedonar();
void readyblood();
void donarsave();
void viewblood();
void viewdonar();
void donarread();

void gotoxy(short x,short y)     // a function to handle cursor
{
    COORD pos= {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void ascii_line(int k){                // a function to print ascii value line
	int j;
	for(j=0;j<30;j++)
	printf("%c",k);
}
struct donar                     // structure of blood donor
{
    char name[30];
    int age;
    char address[50];
    char bg[3];
    char number[14];
    int code;
}bld[60];

struct admin                 // structure of administrator
{
    char blood[3];
    int amount;
    int day,month,year;
    int eday,emonth,eyear;
}ad[60];


void adminwork()                            //  function for admin to classify his works
{
    system("color 0A");
    gotoxy(50,9);
    char ch[]="PASSWORD PROTECTED";
    unsigned int i,pass=12345,p,m;
    for(i=0; i<ch[i]; i++)
    {
        Sleep(50);                            /// to view the password protected string in slow motion
        printf("%c", ch[i]);
    }
    printf("\n");gotoxy(50,10);
      for(i=0; i<ch[i]; i++)
    {
        Sleep(50);
        printf("%c", 254);
    }
    gotoxy(35,15);printf("Enter password: ");
    scanf("%d", & p);
    if (pass==p)
    {
        system("cls");
B:      gotoxy(50,2);
        ascii_line(219);
        gotoxy(58,4);
        printf("ADMIN PANEL");
        gotoxy(50,6);
        ascii_line(219);                  // admin working options //
        system("color 5f");gotoxy(40,8);printf("Press--");gotoxy(49,10);printf("1. Input available blood group");gotoxy(49,11);printf("2. View blood group");gotoxy(49,12);printf("3. View registered donar");
        gotoxy(49,13);printf("4. Delete all data about blood");gotoxy(49,14);printf("5. Exit");gotoxy(36,15);printf("Enter choice: ");gotoxy(50,15);scanf("%d", &m);
        if (m==1)
        {
            system("cls");
            readyblood();
            goto B;                // goto function to go back to B line (69) after readyblood function
        }
        else if (m==2)
        {
            system("cls");
            viewblood();
            goto B;
        }
        else if (m==3)
        {
            system("cls");
            viewdonar();
            system("cls");
            goto B;
        }
        else if (m==4)
        {
            gotoxy(40,2);
            ascii_line(178);
            gotoxy(50,4);printf("RESET DATA");
            gotoxy(40,6);ascii_line(178);
            char n;
            printf("\n\n\nAre you sure you want to delete?? Press 'y' for yes and 'n' for no: ");
            scanf("%c", &n);
            if (n=='y'|| 'Y')
            {
                remove("test.txt");remove("test2.txt");printf("\n\n\n");
                for(i=10; i>=0; i--)
                {
                    printf("\r\t\t\tYour program will be closed after %d seconds",i);
                    Sleep(1000);
                }
                 exit(0);
            }
            else if (n=='n'||n=='N')
            {
                system("cls");
                goto B;
            }
        }
        else if (m==5)
        {
            exit(0);
        }
        else{
            printf("\aWrong choice");
            getch();
            system("cls");
            goto B;
        }
    }
    else
    {
        printf("\n\n\t\t\t\t\a Sorry!! wrong password.\n\n");
        system("pause"); system("cls");main();
    }
}

void readyblood()
{
    system("color 71");
    gotoxy(40,2);
    ascii_line(178);
    gotoxy(50,4);printf("ADD BLOOD");
    gotoxy(40,6);ascii_line(178);
    unsigned int m;
    do{
        printf("\n\nEnter date (dd) :");
        scanf("%d", & ad[b].day);
        printf("\nEnter month (mm) : ");                 // assuming all months are in 30 days
        scanf("%d", & ad[b].month);
        printf("\nEnter year (yy) : ");
        scanf("%d", & ad[b].year);
        printf("\n\nEnter blood type: ");
        scanf("%s", ad[b].blood);
        printf("\nEnter amount of blood: ");
        scanf("%d", &ad[b].amount);
        ad[b].eday= ad[b].day+28;           // in eday define inputted date sum 28 days
    if (ad[b].eday>30)                      // if the sum is more than 30 days then month will increased by 1. after 30 the rest of the days will be printed.
    {
        ad[b].emonth= ad[b].month+1;
        ad[b].eday=30-ad[b].eday;
        ad[b].eday=abs(ad[b].eday);           // abs() function is used to show the days in positive form
    }
    else { ad[b].emonth=ad[b].month; }             // if the sum does not exceed 30 days then month number will be printed as inputted
                    // blood lasts only 28 days.
    if (ad[b].emonth>12)                             // if the month number exceeds more than 12 then year will be increased by 1.
    {
        ad[b].eyear= ad[b].year+1;
        ad[b].emonth=1;                             // and month will be 1 as first month of the new year
    }
    else { ad[b].eyear=ad[b].year;}                   // else the year number will be printed as inputted

        bloodsave();                       // save function is called to save the data
        b++;                            // global variable b will be increased for looping and to get another input
        bloodsave();                      // after increasing global variable save function again will be called to save data so that if the program is closed data will not be gone
        printf("\nPress 1 to continue or 0 to exit: ");
        scanf("%d", &m);
        ascii_line(45);                       // print ascii line
    }while(m!=0);                                 // continue to get information until 0 is pressed
    printf("\n\n\t\tAvailable blood updated\n\n");
    system("pause");
    system("cls");
}


void bloodsave()                         // blood data save function used for file
{
    FILE * fp;
    fp= fopen("test.txt", "w");
    fwrite(&ad, sizeof (ad), 1, fp);
    fclose(fp);
    FILE *fp1;
    fp1= fopen("test2.txt", "w");
    fwrite(&b, sizeof (b), 1, fp1);
    fclose(fp1);
}
void bloodread()                    // blood data read function used for file
{
    FILE * fp;
    fp= fopen("test.txt", "r");
    fread(&ad, sizeof (ad), 1, fp);
    fclose(fp);
    FILE *fp1;
    fp1= fopen("test2.txt", "r");
    fread(&b, sizeof (b), 1, fp1);
    fclose(fp1);
}
void blooddonar()                           // function for blood donor
{
    system("color 71");
    gotoxy(40,2);
    ascii_line(178);
    gotoxy(45,4);
    printf("Welcome to blood bank");
    gotoxy(40,6);
    ascii_line(178);
    unsigned int i,m;
    time_t t;
    gotoxy(9,9);printf("Full name: ");
    fflush(stdin);
    gotoxy(20,9);scanf("%[^\n]s", bld[a].name);       // to get more than one string with space
    gotoxy(40,9);printf("Age: ");
    gotoxy(45,9);scanf("%d", & bld[a].age);
    gotoxy(9,11);
    printf("Address: ");
    fflush(stdin);
    gotoxy(18,11);scanf("%[^\n]s", bld[a].address);
    gotoxy(9,13);printf("Blood group: ");
    gotoxy(22,13);scanf("%s", bld[a].bg);
    gotoxy(40,13);printf("Contact number: ");
    gotoxy(56,13);scanf("%s", bld[a].number);
    gotoxy(9,15);printf("Pin number: ");
    srand(time(NULL)); bld[a].code=rand()% 1000;              // produce random number
    gotoxy(21,15);printf("%d", bld[a].code);
    gotoxy(26,15);printf("(Make sure to remember your pin number. Without pin number you won't able to delete your information later.)");
    donarsave();         // save information of donor in file
    a++;                // increasing global variable by 1
    donarsave();           // again call save function
    gotoxy(44,18);
    printf("Information uploaded");
    gotoxy(40,20);ascii_line(254);
    gotoxy(2,23);
    system("pause");
    system("cls");
}
void viewblood()                   // function to view available blood
{
    system("color 71");
    gotoxy(40,2);
    ascii_line(178);
    gotoxy(45,4);
    printf("VIEW AVAIALABLE BLOOD");
    gotoxy(40,6);
    ascii_line(178);
    gotoxy(20,9);printf("Blood group");gotoxy(20,10);printf("___________");gotoxy(35,9);printf("Blood (bag)");gotoxy(35,10);printf("__________");gotoxy(50,9);printf("Donated date");gotoxy(50,10);printf("___________"); gotoxy(68,9);printf("Expire date");gotoxy(68,10);printf("____________");
    int i;
    for(i=0; i<b; i++)
    {
        gotoxy(20,i+12);printf("%s", ad[i].blood);gotoxy(35,i+12);printf("%d", ad[i].amount);gotoxy(50,i+12);printf("%d/",ad[i].day);gotoxy(53,i+12);printf("%d/", ad[i].month);gotoxy(56,i+12);printf("%d", ad[i].year);gotoxy(68,i+12);printf("%d/", ad[i].eday);gotoxy(71,i+12);printf("%d/", ad[i].emonth);gotoxy(74,i+12);printf("%d", ad[i].eyear);
    }
    printf("\n\n\n\n     For blood please contact with the admin-- \t");printf("%c Mail: abc123@gmail.com\n\t\t\t\t\t\t",248);printf("%c Contact number: +8801234567890\n\n",248);
    system("pause");system("cls");
}

void viewdonar()                     // function to view available donor who are eager to donate blood
{

    gotoxy(40,2);
    ascii_line(178);
    gotoxy(45,4);
    printf("VIEW AVAIALABLE DONAR");
    gotoxy(40,6);
    ascii_line(178);
    int j,count=0;gotoxy(2,9);
    char blood[3];
    printf("Enter blood group to search available donor (Ex: A+) : ");               // get blood group name to search from the file
    scanf("%s", blood);
    for(j=0; j< a; j++)
    {
        if (strcmp(bld[j].bg, blood)==0)                     // compare string with the file blood group name and searching blood group name. if the blood group match then show result
        {
            printf("\n\n\tName           : %s", bld[j].name);
            printf("\n\tAge            : %d", bld[j].age);
            printf("\n\tAddress        : %s", bld[j].address);
            printf("\n\tBlood group    : %s", bld[j].bg);
            printf("\n\tContact number : %s\n\t", bld[j].number);
            ascii_line(45);
            count++;                         // count variable count number of donor available from respective blood group
        }
    }
    printf("\n\nTotal member found %d\n\n", count);system("pause");system("cls");
}
void deletedonar()           // function to delete all information of donor from the file
{
    int i,pin,flag=0,in=0;
    char name[30],mbl[14];
    gotoxy(40,2); ascii_line(178);gotoxy(43,4);printf("DELETE DONOR INFORMATION");gotoxy(40,6);ascii_line(178);
    gotoxy(5,8);printf("Contact number: ");gotoxy(21,8);scanf("%s", mbl);gotoxy(36,8);printf("Pin number: ");gotoxy(48,8);scanf("%d", &pin);
    for(i=0; i<a; i++)
    {
        if (strcmp(mbl, bld[i].number)==0)                       // contact number will be compared with the file information.. if matches then pin number will be compared.
        {
            if (pin==bld[i].code)
            {
                flag=1;
                in=i;
                break;
            }
        }
    }
    for(i=in; i<a; i++)
    {
        bld[i]=bld[i+1];                                        // if contact number and pin number matches then the information of respective donor will be erased
    }a--;
    if (flag==0)
    {
        gotoxy(10,10);printf("\aOooops! Info do not match");gotoxy(2,13);system("pause");           // this block of code works if the informations do not match
        system("cls");
        main();
    }
    donarsave();             // call save function to save updated file after erasing one donor information
    gotoxy(10,10);printf("Your information successfully deleted");gotoxy(2,13);system("pause");
}
void donarsave()                  // function to save donor information
{
    FILE *ft;
    ft= fopen("ab.txt", "w");
    fwrite(&bld, sizeof (bld), 1, ft);
    fclose(ft);
    FILE *ft1;
    ft1= fopen("ab1.txt", "w");
    fwrite(&a, sizeof (a),1, ft1);
    fclose(ft1);
}
void donarread()             // function to read donor information
{
    FILE *ft;
    ft= fopen("ab.txt", "r");
    fread(&bld, sizeof (bld), 1, ft);
    fclose(ft);
    FILE *ft1;
    ft1= fopen("ab1.txt", "r");
    fread(&a, sizeof (a),1, ft1);
    fclose(ft1);
}

int main()                              // main function
{
    bloodread();                // call read function to show available blood from the file
    donarread();                    // call read function  to show available blood donor from the file
    unsigned int i,m;
    char ch[]="WELCOME TO BLOOD BANK";
    gotoxy(10,2);
    system("color 3F");              // to change window color
    system("mode 200");             // to set window
    gotoxy(35,2);
    for(i=0; i<15; i++)
    {
         Sleep(50);
        printf("*");
    }
    for(i=0; i<ch[i]; i++)
    {
         Sleep(50);
        printf(" %c", ch[i]);
    }
    printf(" ");
     for(i=0; i<15; i++)
    {
        Sleep(50);
        printf("*");
    }
    gotoxy(40,5);printf("Press--");gotoxy(49,6);printf("1. Admin");gotoxy(49,7);printf("2. Donar registration");gotoxy(49,8);printf("3. Delete donor info");
    gotoxy(49,9);printf("4. View available donor");gotoxy(49,10);printf("5. View available blood");gotoxy(49,11);printf("6. Exit");gotoxy(36,13);printf("Enter choice: ");gotoxy(50,13);scanf("%d", &m);
    if (m==1)
    {
        system("cls");
        adminwork();
        main();
    }
    else if (m==2)
    {
        system("cls");
        blooddonar();
        main();
    }
    else if (m==3)
    {
        system("cls");
        deletedonar();
        main();
    }
    else if (m==4)
    {
        system("cls");
        viewdonar();
        main();
    }
    else if (m==5)
    {
        system("cls");
        viewblood();
        main();
    }
    else if (m==6)
    {
        printf("\n\n\n\t\t\tTHANX FOR USING THE SYSTEM\n\n");
        exit(0);
    }
    else
    {
        printf("\aWrong key");
        system("cls");
        main();
    }
}
