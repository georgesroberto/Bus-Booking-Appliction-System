#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char name[50];
	int bus_num;
	int num_of_seats;
}pd;
void booking(void);
void viewdetails(void);
void printticket(char name[],int,int,float);
void specificbus(int);
float charge(int,int);
void login();
int main()

{
	system("cls");
	system("COLOR 0A");
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|       ----------------------------------      |\n");
	printf("\t\t|                IMANI BUS BOOKING              |\n");
	printf("\t\t|                   SYSTEM                      |\n");
	printf("\t\t|       ----------------------------------      |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n");
	printf(" \n Press any key to continue:");
	getch();
    system("cls");
	login();
	int menu_choice,choice_return;
	start:
	system("cls");
	printf("\n=================================\n");
	printf("     BUS BOOKING SYSTEM");
	printf("\n=================================");
	printf("\n1>> Reserve A Ticket");
	printf("\n2>> View Available Bus");
	printf("\n3>> Exit");
	printf("\n-->");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1:
			booking();
			break;
		case 2:
			viewdetails();
			printf("\nPress any key to go to Main Menu..");
			getch();
			break;
		case 3:
			return(0);
		default:
			printf("\nInvalid choice");
	}
	goto start;
	return(0);
}

void viewdetails(void)
{
	system("cls");
	printf("---------------------------------------------------------");
	printf("\nBus.No\tName\tDestinations  \t\tCharges  \tTime\n");
	printf("---------------------------------------------------------");
	printf("\n1001\tBus 1\tMombasa to Nairobi\tKsh.1500\t8:00 AM");
	printf("\n1002\tBus 2\tNairobi To Kisumu \tKsh.1500\t2:00 PM");
	printf("\n1003\tBus 2\tKisumu To  Nairobi\tKsh.1450\t2:00 PM");
	printf("\n1004\tBus 1\tNairobi To Mombasa\tKsh.2000\t8:00 AM");
	printf("\n1005\tBus 3\tMombasa To Kisumu \tKsh.2500\t3:30 PM");
	printf("\n1006\tBus 3\tKisumu  To Mombasa\tKsh.2500\t3:30 PM");
}

void booking(void)
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	system("cls");

	printf("\nEnter Your Name:> ");
	fflush(stdin);
	gets(passdetails.name);
	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View Available Bus<< ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter bus number:> ");
	start1:
	scanf("%d",&passdetails.bus_num);
	if(passdetails.bus_num>=1001 && passdetails.bus_num<=1010)
	{
		charges=charge(passdetails.bus_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.bus_num,charges);
	}
	else
	{
		printf("\nInvalid bus Number! Enter again--> ");
		goto start1;
	}

	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.bus_num,charges);
		printf("=============================");
		printf("\n Seat Reserved Successfully\n");
		printf("=============================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\nBus Not Booked!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}

float charge(int bus_num,int num_of_seats)
{

	if (bus_num==1001)
	
	{
		return(1500*num_of_seats);
	}
	if (bus_num==1002)
	{
		return(1500*num_of_seats);
	}
	if (bus_num==1003)
	{
		return(1450*num_of_seats);
	}
	if (bus_num==1004)
	{
		return(2000*num_of_seats);
	}
	if (bus_num==1005)
	{
		return(2500*num_of_seats);
	}
	if (bus_num==1006)
	{
		return(2500*num_of_seats);
	}
}

void printticket(char name[],int num_of_seats,int bus_num,float charges)
{
	system("cls");
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nbus Number:\t\t%d",bus_num);
	specificbus(bus_num);
	printf("\nCharges:\t\t%.2f",charges);
}

void specificbus(int bus_num)
{
	if (bus_num==1001)
	{
		printf("\nBus:\t\t\tBus 1");
		printf("\nRoute:\t\t\tMombasa to Nairobi");
		printf("\nDeparture:\t\t8:00 AM");
	}
	if (bus_num==1002)
	{
		printf("\nBus:\t\t\tBus 2");
		printf("\nRoute:\t\t\tNairobi To Kisumu");
		printf("\nDeparture:\t\t2:00 PM");
	}
	if (bus_num==1003)
	{
		printf("\nBus:\t\t\tBus 2");
		printf("\nRoute:\t\t\tKisumu To  Nairobi");
		printf("\nDeparture:\t\t2:00 PM");
	}
	if (bus_num==1004)
	{
		printf("\nBus:\t\t\tBus 1");
		printf("\nRoute:\t\t\tNairobi To Mombasa");
		printf("\nDeparture:\t\t8:00 AM");
	}
	if (bus_num==1005)
	{
		printf("\nBus:\t\t\tBus 3");
		printf("\nRoute:\t\t\tMombasa To Kisumu");
		printf("\nDeparture:\t\t3:30 PM");
	}
	if (bus_num==1006)
	{
		printf("\nBus:\t\t\tBus 3");
		printf("\nRoute:\t\t\tKisumu To Mombasa");
		printf("\nDeparture:\t\t3:30 PM");
	}
}

void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10];
    char pass[10];
    do
{
    printf("\n\n");
    printf("\n  =======================  LOGIN FORM  =======================\n  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	i=0;
		if(strcmp(uname,"admin")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n       WELCOME !!\n YOUR LOGIN TO IMANI BUS BOOKING IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();
		system("cls");
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
}