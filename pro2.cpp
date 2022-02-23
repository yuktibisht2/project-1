#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<iomanip>
#define max 50
using namespace std;
int num=0;
void gotoXY(int,int);
void Cdelay(int);
void border(int, int,int, int);
void editstock(int,char);
void bill(int[][2],int,int);
void purchase();
void update();
void intro();
void menu();
void insert();
void getrecords();
bool isFilePresent();
class Medicine
{
public:
	char name[100];
	int code;
	char Company[100];
	char exp[100];
	int dose;
	int stock;
	int cost;	
};
Medicine msm[max],tempmsm[max];
void setWindowSize(int width=670,int height=445)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void Cdelay(int msec)
{
    long goal = msec + (clock());
    while (goal > (clock()));
}
void menu()
{
	system("cls");
	gotoXY(16,4);
	printf("Medical Store Management System");
	gotoXY(12,6);
	cout<<"Press  1 ----> Add Stock.";
	gotoXY(12,8);
	cout<<"Press  2 ----> Purchase Medicine.";
	gotoXY(12,10);
	cout<<"Press  3 ----> Delete/Update Stock.";
	gotoXY(12,12);
	cout<<"Press  4 ----> Search a medicine.";
	gotoXY(12,14);
	cout<<"Press  5 ----> List the stock.";
	gotoXY(12,16);
	cout<<"Press  6 ----> Quit Program.";
	gotoXY(16,22);
	cout<<"Select Your Option ====> ";
}
bool isFilePresent()
{
	FILE *fp;
	fp = fopen("Records.txt","r");
	if(fp==NULL)
		return false;
	else
		return true;
}
void getrecords()
{
	FILE *fp;
	fp = fopen("Records.txt","r");
	int c=0;
	if(fp!=NULL)
	{
		while(feof(fp)==0)
		{
			fscanf(fp,"%s\t%d\t%s\t%s\t%d\t%d\t%d\n",&msm[c].name,&msm[c].code,&msm[c].Company,&msm[c].exp,&msm[c].dose,&msm[c].stock,&msm[c].cost);
			c++;
		}
		num=c;
	}
	fclose(fp);
}
void saverecords()
{
	system("cls");
	cout<<"QUITING...!!!!!";
	if(num==0)
	{
		system("del Records.txt");
	}
	else
	{
		FILE *fp;
		fp = fopen("Records.txt","w");
		for(int c=0;c<num;c++)
		{
			fprintf(fp,"%s\t%d\t%s\t%s\t%d\t%d\t%d\n",msm[c].name,msm[c].code,msm[c].Company,msm[c].exp,msm[c].dose,msm[c].stock,msm[c].cost);
		}
		fclose(fp);
	}
}
void gotoXY(int X, int Y)
{
    COORD coordinates;
    coordinates.X = X;
    coordinates.Y = Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void border(int xLenS = 2, int yLenS = 2,int xLenE = 76, int yLenE = 22 )
{
	system("cls");
	gotoXY(xLenS,yLenS);printf("%c",201);
	
	gotoXY(xLenS,yLenE);printf("%c",200);
	
    for(int i=xLenS+1;i<=xLenE-1;i++)         
    {
        gotoXY(i,yLenS);
        printf("%c",205);
        gotoXY(i,yLenE);
        printf("%c",205);
    }
    gotoXY(xLenE,yLenS);printf("%c",187);
    gotoXY(xLenE,yLenE);printf("%c",188);
    for(int i=yLenS+1;i<=yLenE-1;i++)       
    {
        gotoXY(xLenS, i);
        printf("%c",186);
        gotoXY(xLenE, i);
        printf("%c",186);
    }
    printf("\n\n");
}
void insert()
{
    system("cls");
	int i=num;
	num++;
	gotoXY(28,4);
	printf("Insert New Record");
	gotoXY(10,6);
	cout<<"Medicine Name : ";
	cin>>msm[i].name;
	gotoXY(10,8);
	cout<<"Medicine Code : ";
	cin>>msm[i].code;
	gotoXY(10,10);
	cout<<"Company : ";
	cin>>msm[i].Company;
	gotoXY(10,12);
	cout<<"Expire Date: ";
	cin>>msm[i].exp;
	gotoXY(10,14);
	cout<<"Dose : ";
	cin>>msm[i].dose;
	gotoXY(10,16);
	cout<<"Cost: ";	
	cin>>msm[i].cost;
	gotoXY(10,18);
	cout<<"Total Stock: ";	
	cin>>msm[i].stock;
	gotoXY(14,22);
	cout<<"Recorded Succesfully...!!!";
	Cdelay(1000);
}
void intro()
{
	gotoXY(25,4); printf("MEDICAL STORE MANAGEMENT SYSTEM");
    gotoXY(25,5); for(int i=0;i<29;i++) printf("%c",196);
    gotoXY(20,8); printf("Designed and Programmed by:");
    gotoXY(20,9);for(int i=0;i<29;i++) printf("%c",196);
	gotoXY(20,11); printf("YUKTI BISHT");
	gotoXY(20,13); printf("https://github.com/yuktibisht2");
	gotoXY(20,15); printf("https://www.linkedin.com/in/yukti-bisht-ab2025217/");
    gotoXY(24,20);printf("Press Any key to continue...");
    getch();    
}
void search()
{	system("cls");
	;
	int mcode;
	bool found = false;
	gotoXY(10,4);
	cout<<"You can Search only through the Medicine code of a medicine";
	gotoXY(10,6);
	cout<<"Enter Code Of the medicine: ";
	cin>>mcode;
	for(int i=0;i<=num-1;i++)
	{
		if(msm[i].code==mcode)
		{
			gotoXY(6,9);
			cout<<"------------------------------------------------------------------"<<endl;
			gotoXY(6,11);
			cout<<"Medicine Name: "<<msm[i].name;
			gotoXY(6,13);
			cout<<"Code: "<<msm[i].code;
			gotoXY(6,15);
			cout<<"Company: "<<msm[i].Company;
			gotoXY(6,17);
			cout<<"Expiry Date: "<<msm[i].exp;
			gotoXY(6,19);
			cout<<"Cost: "<<msm[i].cost;
			gotoXY(6,21);
			cout<<"Dose(mg): "<<msm[i].dose;
			gotoXY(6,23);
			cout<<"Total Stock: "<<msm[i].stock;
			found = true;
		}
	}
	if(!found)
	{
		gotoXY(26,11);
		cout<<"No records Found...!!!\a";
	}
	getch();
}
void display()
{
	system("cls");
	gotoXY(26,4);
	printf("*List of the Stock Available*");
	gotoXY(26,6);
	cout<<"---------------------------------"<<endl;
	for(int i=0,j=8;i<=num-1;i++,j++)
	{
		gotoXY(6,j);
		cout<<"Name: "<<msm[i].name<<"  Code: "<<msm[i].code<<"  Available Stock: "<<msm[i].stock;
	}
	if(num==0)
	{
		gotoXY(26,11);
		cout<<"No Stock Available...!!!\a";
	}
	getch();
}
void update()
{
	system("cls");
	int a;
	gotoXY(28,4);
	printf("Add or delete Stock: ");
	int option;
	gotoXY(10,6);
	cout<<"Enter the Medicine code to Edit : ";
	cin>>a;
	for(int i=0;i<=num-1;i++)
	{
		if(msm[i].code==a)
		{ 
			gotoXY(6,8);
			cout<<"Medicine Name: "<<msm[i].name;
			gotoXY(6,10);
			cout<<"Enter 1: Add Stock\t2: Remove Stock  ";
			cin>>option;
			switch(option)
				{
					case 1:
						editstock(i,'A');
						break;
					case 2:
						editstock(i,'R');
						break;
				}
		}
	}
}
void editstock(int i,char a)
{
	int S;
	if(a=='A'){
	gotoXY(10,12);
	cout<<"Available Stock: "<<msm[i].stock;
	gotoXY(10,14);
	cout<<"How many Stock you wanna add: ";
	cin>>S;
	msm[i].stock=msm[i].stock+S;
	gotoXY(10,16);
	cout<<"Successfully Added";
	gotoXY(10,18);
	cout<<"Available Stock: "<<msm[i].stock;
	getch();
	}
	else{
	gotoXY(10,12);
	cout<<"Available Stock: "<<msm[i].stock;
	gotoXY(10,14);
	cout<<"How many Stock you wanna remove: ";
	cin>>S;
	msm[i].stock=msm[i].stock-S;
	gotoXY(10,16);
	cout<<"Successfully Removed";
	gotoXY(10,18);
	cout<<"Available Stock: "<<msm[i].stock;
	getch();
	}
}
void purchase()
{
	
	string a;
    int k,j=0,total=0;
	char o;
	int arr[30][2];
	bool found = false;
	while(1){
	system("cls");
	gotoXY(10,4);	
	cout<<"Enter Medicine name ";
	cin>>a;
	for(int i=0;i<num;i++)
	{
    if(msm[i].name==a)
	{
	   found=true;
	   gotoXY(10,6);
	   cout<<"Enter amount ";
	   cin>>k;
	   if(k<=msm[i].stock){
		  total=total+(k*msm[i].cost); 
	      msm[i].stock=msm[i].stock-k;
	      arr[j][0]=i;
		  arr[j][1]=k;
	      j=j+1;
	    } 
		else
		{
			gotoXY(10,8);
			cout<<"SORRY THERE IS NOT ENOUGH STOCK\tAVAILBLE STOCK:- "<<msm[i].stock;
		}
	}
	}
	if(!found)
	{
		gotoXY(26,8);
		cout<<"No Stock Available...!!!\a";
	}
	gotoXY(10,11);
	cout<<"Press 1 to CHECKOUT or other to continue PURCHASE";
	cout<<"Press 1 to CHECKOUT or other to continue PURCHASE  ";
    cin>>o;
	if(o=='1')
	break;
	}
	bill(arr,j,total);
}
void bill(int arr[][2],int j,int total)
{
  system("cls");

  gotoXY(26,4);
  printf("*PURCHASE BILL*");
  printf("*CHECKOUT BILL*");
  gotoXY(26,6);
  cout<<"-------------------"<<endl;
  cout<<"--------------------"<<endl;
  gotoXY(10,8);
  cout<<"NAME\t\tCOST\t\tAMOUNT";
  int k=10;
  for(int i=0;i<j;i++)
  {
	  gotoXY(10,k);
	  k=k+2;
	  cout<<msm[arr[i][0]].name<<"\t\t"<<msm[arr[i][0]].cost<<"\t\t"<<arr[i][1];
  }
  gotoXY(27,k);
  cout<<"TOTAL BILL "<<total;
  cout<<"TOTAL BILL  "<<total;
  getch();
}
int main()
{
	setWindowSize();	
	border();   
	intro();    
    menu();
    getrecords();
    char option;
    if(msm[0].code==0 && isFilePresent())
    	num--;
	while(1)
	{
		option=getch();
		switch(option)
		{
			case '1':
				insert();
				break;
			case '2':
				purchase();
				break;
			case '3':
				update();
				break;
			case '4':
				search();
				break;
			case '5':
				display();
				break;
			case '6':
				saverecords();
				exit(0);
		}
		menu();
	}
	
	
	return 0;
}