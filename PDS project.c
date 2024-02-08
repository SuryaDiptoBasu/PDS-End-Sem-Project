#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void add();  //FUNCTIONS
void list();
void edit();  //GLOBALLY DECLARED FUNCTIONS N VARIABLE
void delete1();
void search();
void mini_casino();
void GuessGame();
void rateus();
void aboutus();
void sound1();
void sound2();
void sound3();
void sound4();

void sound1()
{
    for (int i=900;i<=1500;i+=200)
    Beep(i,300);
}
void sound2()
{
  Beep(1000,300);
}
void sound3()
{
    Beep(523,400);
}
void sound4()
{
   Beep(3500,400);
}

void setcolor(int ForgC)
{ WORD wColor;
HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbi;

if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
{
	wColor=(csbi.wAttributes & 0xB0)+(ForgC & 0x0B);
//	SetConsoleTextAttributes(hStdOut,wColor);
	SetConsoleTextAttribute(hStdOut,wColor);

}
}

void login()
{

	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
	system("cls");

    printf("\n  **************************  LOGIN FORM  **************************  ");
    printf(" \n\n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n\n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else 
        {
            printf("*");
            sound2();
        }
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
		if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
	{
	printf("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL");
    sound4();

	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
        sound3();
		a++;

		getch();

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

struct CustomerDetails   
{
	char roomnumber[10];
	char name[20];
	char address[25];
	char phonenumber[15];
	char nationality[15];
	char email[20];
	char period[10];
	char arrivaldate[10];
}s;

int main(){     
	int i=0;

	time_t t;
	time(&t);
	char customername;
	char choice;
    login();
    system("cls");
	while (1)      
	{
		system("cls");
		setcolor(10);
		 for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("\n ______________________ HOTEL RUSHIKULYA WELCOMES YOU !!!______________________\n");
		printf("   ******************************  |MAIN MENU|  ***************************** \n");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		setcolor(10);
        sound1();
		printf("\t\t *Please enter your choice for menu*:");
		printf("\n\n");
		printf(" \n Enter 1 -> Book a room");
		printf("\n------------------------");
		printf(" \n Enter 2 -> View Customer Record");
		printf("\n----------------------------------");
		printf(" \n Enter 3 -> Delete Customer Record");
		printf("\n-----------------------------------");
		printf(" \n Enter 4 -> Search Customer Record");
		printf("\n-----------------------------------");
		printf(" \n Enter 5 -> Edit Record");
		printf("\n-----------------------");
        printf(" \n Enter 6 -> Mini Casino");
		printf("\n-----------------------");
		printf(" \n Enter 7 -> Check out");
		printf("\n-----------------");
		printf("\n Enter 8 -> About us");
		printf("\n---------------------");
		printf("\n");
		for(i=0;i<80;i++)
		printf("-");
	    printf("\nCurrent date and time : %s",ctime(&t));
	    for(i=0;i<80;i++)
		printf("-");

		choice=getche();
		choice=toupper(choice);
		switch(choice)           
		{
			case '1':
                sound4();
				add();break;
			case '2':
                sound4(); 
				list();break;
			case '3':
                sound4();
				delete1();break;
			case '4':
                sound4();
				search();break;
			case '5':
                sound4();
				edit();break;
            case '6':
                sound4();
                mini_casino();break;
			case '7':
                sound4();
				system("cls");
				rateus();
				sound4();
				printf("\n\n\t *****THANK YOU*****");
				printf("\n\t FOR TRUSTING OUR SERVICE");
				exit(0);
				break;
			case '8':
			    sound4();
				aboutus();
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\n Press any key to continue");
				getch();
		}
	}
}
void aboutus()
{
	system("cls");
	char key;
	printf("HOTEL RUSHIKULYA:\n");
    printf("The site near Jatni Railway Station on the East Coast Railway is 35 kilometres from Biju Patnaik Airport Bhubaneswar. The land is picturesque with Barunai Hill on one side and a reserve forest nearby. A total of 936 acres (3.79 km2) of land has been allocated towards the self-contained campus for nearly 10,000 students and 1,100 faculty. A science park is being set up as a part of this institution to support industry oriented research activities. The institute has started operating in its new campus at Arugul from academic year 2015/16. The campus construction began on 14 August 2011, Chief minister Naveen Patnaik laid the foundation stone of the IIT campus at Aragul village near Jatni. The campus master plan has been prepared by Vastunidhi Architects, Noida.");
	printf("\n\n\n                          -------------OUR DETAILS------------");
	printf("\n\n");
	printf("\nPHONE NO : 8567367480 , 7986630764");
	printf("\nE Mail : hor.rushikulya@iitbbs.ac.in ");
	printf("\n\n");
	printf("Enter any key to continue\n");
	scanf("\n%c",&key);
	getch();
}
void add()
{
	FILE *f;
	char test;
	f=fopen("add.txt","a+");
	if(f==0)
	{   f=fopen("add.txt","w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	while(1)
	{
		system("cls");
		printf("\n Enter Customer Details:");
		printf("\n**************************");
		printf("\n Enter Room number:\n");
		scanf("\n%s",s.roomnumber);
		fflush(stdin);
		printf("Enter Name:\n");
		scanf("%s",s.name);
		printf("Enter Address:\n");
		scanf("%s",s.address);
		printf("Enter Phone Number:\n");
		scanf("%s",s.phonenumber);
		printf("Enter Nationality:\n");
		scanf("%s",s.nationality);
		printf("Enter Email:\n");
		scanf(" %s",s.email);
		printf("Enter Period(\'x\'days):\n");
		scanf("%s",&s.period);
		printf("Enter Arrival date(dd\\mm\\yyyy):\n");
		scanf("%s",&s.arrivaldate);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		printf("\n\n1 Room is successfully booked!!");
        sound2();
		printf("\n Press esc key to exit,  any other key to add another customer detail:");
		test=getche();
		if(test==27)
			break;

	}
	fclose(f);
}

void list()
{
	FILE *f;
	int i;
	if((f=fopen("add.txt","r"))==NULL)
		exit(0);
	system("cls");
	printf("ROOM    ");
	printf("NAME\t ");
	printf("\tADDRESS ");
	printf("\tPHONENUMBER ");
	printf("\tNATIONALITY ");
	printf("\tEMAIL ");
	printf("\t\t  PERIOD ");
	printf("\t ARRIVAL DATE \n");

	for(i=0;i<118;i++)
		printf("-");
	while(fread(&s,sizeof(s),1,f)==1)
	{
		printf("\n%s \t%s \t\t%s \t\t%s \t%s  \t%s  \t     %s  \t  %s",s.roomnumber, s.name , s.address , s.phonenumber ,s.nationality ,s.email,s.period,  s.arrivaldate);
	}
	printf("\n");
	for(i=0;i<118;i++)
		printf("-");

	fclose(f);
	getch();
}

void delete1()
{
	FILE *f,*t;
	int i=1;
	char roomnumber[20];
	if((t=fopen("temp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("add.txt","r"))==NULL)
	exit(0);
	system("cls");
	printf("Enter the Room Number of the hotel to be deleted from the database: \n");
	fflush(stdin);
	scanf("%s",roomnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0)
		{       i=0;
			continue;
		}
		else
			fwrite(&s,sizeof(s),1,t);
	}
	if(i==1)
	{
		printf("\n\n Records of Customer in this  Room number is not found!!");
        sound3();
		//remove("E:/file.txt");
	   //rename("E:/temp.txt","E:/file.txt");
		getch();
		fclose(f);
		fclose(t);
		main();
	}
	fclose(f);
	fclose(t);
	remove("add.txt");
	rename("temp.txt","add.txt");
	printf("\n\nThe Customer is successfully removed....");
    sound2();
	fclose(f);
	fclose(t);
	getch();
}

void search()
{
system("cls");
	FILE *f;
	char roomnumber[20];
	int flag=1;
	f=fopen("add.txt","r+");
	if(f==0)
		exit(0);
	fflush(stdin);
	printf("Enter Room number of the customer to search its details: \n");
	scanf("%s", roomnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0){
			flag=0;
			printf("\n\tRecord Found\n ");
			printf("\nRoom Number:\t%s",s.roomnumber);
			printf("\nName:\t%s",s.name);
			printf("\nAddress:\t%s",s.address);
			printf("\nPhone number:\t%s",s.phonenumber);
			printf("\nNationality:\t%s",s.nationality);
			printf("\nEmail:\t%s",s.email);
			printf("\nPeriod:\t%s",s.period);
			printf("\nArrival date:\t%s",s.arrivaldate);
			flag=0;
			break;
		}
	}
	if(flag==1){
		printf("\n\tRequested Customer could not be found!");
        sound3();
	}
	getch();
	fclose(f);
}

void edit()
{
	FILE *f;
	int k=1;
	char roomnumber[20];
	long int size=sizeof(s);
	if((f=fopen("add.txt","r+"))==NULL)
		exit(0);
	system("cls");
	printf("Enter Room number of the customer to edit:\n\n");
	scanf("%[^\n]",roomnumber);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0)
		{
			k=0;
			printf("\nEnter Room Number     :");
			gets(s.roomnumber);
			printf("\nEnter Name    :");
			fflush(stdin);
			scanf("%s",&s.name);
			printf("\nEnter Address        :");
			scanf("%s",&s.address);
			printf("\nEnter Phone number :");
			scanf("%f",&s.phonenumber);
			printf("\nEnter Nationality :");
			scanf("%s",&s.nationality);
			printf("\nEnter Email :");
			scanf("%s",&s.email);
			printf("\nEnter Period :");
			scanf("%s",&s.period);
			printf("\nEnter Arrival date :");
			scanf("%s",&s.arrivaldate);
			fseek(f,size,SEEK_CUR);  //to go to desired position infile
			fwrite(&s,sizeof(s),1,f);
			break;
		}
	}
	if(k==1){
		printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
        sound3();
		fclose(f);
		getch();
	}else{
	fclose(f);
	printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
    sound4();
	getch();
}
}
void GuessGame(int amount_bet, int *inhand_cash)
{
    char num[3] = { 'N', 'R', 'N' };
    printf("\nWait !! number is shuffling its position...\n");
    srand((time(NULL)));
    int i, x, y, temp;
    for (i = 0; i < 10; i++) 
    {
        x = rand() % 4;
        y = rand() % 4;
        temp = num[x];
        num[x] = num[y];
        num[y] = temp;
    }
    int PlayerGuess;
    printf("\nYou may now guess the number in which R is present: ");
    scanf("%d", &PlayerGuess);
    if (num[PlayerGuess - 1] == 'R') 
    {
        (*inhand_cash) += 2 * amount_bet;
        sound2();
        printf("You WIN !     ------ YOU GOT LADY LUCK ON YOUR SIDE ------ The numbers are as follows: ");
        printf("\"%c %c %c\" ", num[0], num[1], num[2]);
        printf("\nYour inhand_cash is now = %d \n", *inhand_cash);
    }
    else 
    {
        (*inhand_cash) -= amount_bet;
        sound2();
        printf("You LOOSE !    ------ IT HAPPENS ------ The numbers are as follows: ");
        printf("\"%c %c %c\" ", num[0], num[1], num[2]);
        printf("better luck next time");
        printf("\nYour inhand_cash is now = %d \n", *inhand_cash);
    }
}
void mini_casino()
{
	system("cls");
    int amount_bet, inhand_cash,a,count=0;
printf("\n       ////////----WELCOME TO MINI CASINO----\\\\\\\\\\\\ \n");
sound4();
printf("          HEYYY.....\n     This game is all about luck play at your own risk!!!!");
printf("-----RULES :");
printf(" \n1 --> Enter the amount you want to start the game with.");
printf(" \n2 --> There are 3 letters 'R ,'N','N' they will we arranged randomly in three positions namely 1, 2, 3." );
printf(" \n3 --> You have to guess the coreect position of 'R' in 1,2,3 then enter the value of gussed position. ");
printf(" \n4 --> now it's time to leave your money to lady luckk!");
printf("            \n------LET'S PUT YOUR LUCK TO TEST------");
printf("\n----Enter the inhand_cash you have right now---- :\n ");
scanf("%d", &inhand_cash);
while (inhand_cash > 0) 
{
    printf("\nEnter the amount_bet you want to play for : \n");
    scanf("%d", &amount_bet);
    if (inhand_cash == 0 || amount_bet > inhand_cash)
    {
		count++;
		break;
	}
    else
    GuessGame(amount_bet, &inhand_cash);
    printf("press 1 to continue game ----- press 0 to return to home page\n");
    scanf("%d",&a);
    if(a==1) 
    mini_casino();
    if(a==0)
    {
    sound3();
    printf("\nDo come next time\n\n");
	break;
    }
}
if (count!=0) 
{
sound3();
printf("\n\""" \nSorry you don't have enough cash to play more,\n ");
getch();
}
}
void rateus()
{
    char x;
    float food,room,service,rating;
    char sugg[500];
    printf("\nWould you like to rate us?(y/n)\n");
    scanf("\n%c",&x);
    if(x=='y' || x=='Y')
    {  
        printf("\nRate our food out of five : ");
        scanf("%f",&food);
        printf("\nRate our rooms out of five : ");
        scanf("%f",&room);
        printf("\nRate our service out of five : ");
        scanf("%f",&service);
        rating=(food+service+room)/3;
        if(rating<=3)
		{
        sound2();
		printf("\nYour review is invaluable to us.\nSorry for the inconvenience and hope we can improve your experience next time.");
		}
		else if ((rating>3 )&& (rating<=4))
	    {
		sound2();
        printf("\nYour review is invaluable to us.\nWe are commited to make your next stay even better.");
		}
        else if ((rating>4 )&& (rating<=5))
		{
		sound2();
        printf("\nYour review is invaluable to us.\nWe are delighted to have known that we met your expectations,hope you will visit us again.");
		}
		printf("\nWe will be delighted if you could write a suggestion or two for us.\n");
		printf("\n");
        scanf("\n%s",sugg);
		sound2();
		printf("\nWe take every suggestion seriously !!");
		printf("\nThank You for your suggestions.");
    }
}

