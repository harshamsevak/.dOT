#include<iomanip>
#include<math.h>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<cstdlib>
#include<windows.h>
#include<time.h>
using namespace std;
COORD coord={0,0}; // this is global variable center of axis is set to the top left corner of the screen
char file[50],NAME[30],CARMAN[30],CARMOD[30],PIN[30],RTO_NO[15],C_NO[15],CV[5],Cy[5],U_Id_Prem[10];long PRICE;
int Ins_flag=0,UID=0;
void load();

 void gotoxy(int x,int y)
 {
 coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

class NewUser
 {
public:
  char name[30];
  int pin;
  char carMan[20];
  char carMod[20];
  char rto_no[15];
  char c_no[15];
  char cv[5];
  char cy[5];
  char date;
  long price;
  int flag;
  }s;
void sucesslogin(int);
float valutation(char ch[],int present=2017)
{
int i=atoi(ch);
if(i!=present)
{
float y=pow(0.8,(present-i));
return PRICE*y;
}
else
return PRICE;
}
void home();
void design();
void reg ()
{
   //load();
   int i,l;
   char filename[100],choice;
   ifstream file("a1.txt",ios::in);
   file>>i;
   i+=1;
   file.close();
   fstream fout("a1.txt");
   fout<<i;
   fout.close();
   itoa(i,filename,10);
   l=strlen(filename);
   filename[l]='.';
   filename[l+1]='t';
   filename[l+2]='x';
   filename[l+3]='t';
   filename[l+4]='\0';
   label:
   system("cls");
   gotoxy(30,2);
   cout<<" R  E  G  I  S  T  R  A  T  I  O  N ";
   design();
   s.flag=0;
   gotoxy(35,3);
   cout<<"Your Unique Id is      :  "<<i;
   gotoxy(35,4);
   cout <<"Enter your pin         :  ";
   cin>>s.pin;
   gotoxy(35,5);
   cout <<"Enter your name        :  ";
   char ch=getchar();
   cin.getline(s.name, 100);
   gotoxy(35,6);
   cout << "Enter your contact No  :  ";
   cin.getline(s.c_no, 100);
   gotoxy(35,7);
   cout << "Enter Car Manufacturer :  ";
   cin.getline(s.carMan, 100);
   gotoxy(35,8);
   cout << "Enter Car Model        :  ";
   cin.getline(s.carMod, 100);
   gotoxy(35,9);
   cout << "Enter RTO No.          :  ";
   cin.getline(s.rto_no, 100);
   gotoxy(35,10);
   cout << "Enter Purchase Year    :  ";
   cin.getline(s.cy, 100);
   gotoxy(35,11);
   cout << "Enter Amt              :  ";
   cin>>s.price;
   int date_check=atoi(s.cy);
  if(date_check<=2017 && date_check >=1900 && s.price >= 50000)
  {
   gotoxy(35,12);
   cout<<"[1]Confirm";
   gotoxy(35,13);
   cout<<"[2]Enter Once Again";
   gotoxy(35,14);
   cin>>choice;
  }
  else
  {
      gotoxy(5,15);
      cout<<" Wrong Data Manufacturing year can't be less than 1900 or more than 2017 ";
      gotoxy(5,16);
      cout<<" Or Price Of Car can't be less than Rs.50,000";
      gotoxy(5,18);
      cout<<"Press Any Key To Add Detail Once again ";
      getch();
      goto label;
  }
switch(choice)
{
 case '1':
  {
    ofstream outfile;
    outfile.open(filename);
    outfile << s.pin << endl;
    outfile << s.name << endl;
    outfile << s.c_no << endl;
    outfile << s.carMan << endl;
    outfile << s.carMod << endl;
    outfile << s.rto_no << endl;
    outfile << s.cy << endl;
    outfile << s.price << endl;
    outfile << s.flag <<endl;
    outfile.close();
    outfile.open("admin.txt",ios::app);
    outfile <<i<<setw(10)<<s.name<<setw(12)<<s.c_no<<endl;
    outfile.close();
    home();
   }
break;
case '2':goto label;
break;
}
}
void delay(float);
void login();
void get_prem();
void about_us();
void exit();
void design()
{
  system("cls");
  int a=0;
  unsigned char ch,ch1=205,ch2=186,ch3=201,ch4=200,ch5=188,ch6=187;
  gotoxy(30,0);
  cout<<"  C  A  R  -  I  N  S  U  R  A  N  C  E ";
  for(int i=0;i<99;i++)
  {
  gotoxy(i+1,1);
  printf("%c",247);
  }
  for(int i=0;i<19;i++)
  {
  gotoxy(1,i+1);
  printf("%c",247);
  }
  for(int i=0;i<19;i++)
  {
  gotoxy(99,i+1);
  printf("%c",247);
  }
  for(int i=0;i<99;i++)
  {
  gotoxy(i+1,20);
  printf("%c",247);
  }
  gotoxy(4,2);
  printf("%c",ch3);
  for(int i=5;i<95;i++)
  {
  gotoxy(i,2);
  delay(0.03);
  printf("%c",ch1);
  }
  gotoxy(95,2);
  printf("%c",ch6);
  for(int i=2;i<18;i++)
  {
  gotoxy(4,i+1);
  delay(0.03);
  printf("%c",ch2);
  }
  gotoxy(4,19);
  printf("%c",ch4);
  for(int i=5;i<95;i++)
  {
  gotoxy(i,19);
  delay(0.03);
  printf("%c",ch1);
  }
  gotoxy(95,19);
  printf("%c",ch5);
  for(int i=2;i<18;i++)
  {
  gotoxy(95,i+1);
  delay(0.03);
  printf("%c",ch2);
  }
}
void loading(int);
void load()
{
    system("cls");
    gotoxy(20,6);
    cout<<"Loading";
    gotoxy(50,6);
    loading(6);
    gotoxy(40,3);
    system("cls");
    gotoxy(25,10);
    cout<<"Load Complete...Press Any key to continue";
    getch();
}
void home()
{
  char ch;
  //load();
  design();
  gotoxy(41,3);
  cout<<"M E N U";
  gotoxy(40,4);
  cout<<"~~~~~~~~~";
  gotoxy(35,6);
  cout<<"1.)R E G I S T E R";
  delay(0.9);
  gotoxy(35,8);
  cout<<"2.)L O G I N";
  delay(0.9);
  gotoxy(35,10);
  cout<<"3.)A B O U T  - U S";
  delay(0.9);
  gotoxy(35,12);
  cout<<"4.)E X I T";
  delay(0.9);
  gotoxy(35,14);
  cout<<"E N T E R  Y O U R  C H O I C E  : _____";
  delay(0.9);
  gotoxy(72,14);
  cin>>ch;
  gotoxy(10,18);
switch(ch)
    {
    case '1':reg(); break;
    case '2':login(); break;
    case '3':about_us(); break;
    case '4':exit();break;
    }
}
void sucesslogin(int);
void exita()
{
    system("cls");
    gotoxy(1,5);
    cout<<"You have exceeded maximum no. of login attempts...Securing Accounts...Force Exiting the Program!!!";
    delay(12);
    exit();
}
void login()
{
   int n,i,pin,l,j=0,j1=0;
   system("cls");
   design();
   gotoxy(30,4);
   cout<<" L  O  G  I  N ";
   gotoxy(30,6);
label1:
    if(j<3)
     {
      gotoxy(30,8);
      cout<<"Enter Your 3-digit U_Id : ";
      gotoxy(56+(j*4)+(j1*4),8);
      cin>>i;
      if(i!=100)
      {
       UID=i;
       itoa(i,file,10);
       l=strlen(file);
       file[l]='.';
       file[l+1]='t';
       file[l+2]='x';
       file[l+3]='t';
       file[l+4]='\0';
       ifstream infile;
       infile.open(file,ios::in);
        if(infile)
        {
         gotoxy(30,10+j);
         cout<<"Enter Your Pin : ";
         gotoxy(47+(j1*5),10+j);
         cin>>pin;
         infile >> s.pin;
         infile >> s.name;
         infile >> s.c_no;
         infile >> s.carMan;
         infile >> s.carMod;
         infile >> s.rto_no;
         infile >> s.cy;
         infile >> s.price;
         if(s.pin==pin)
          {
           strcat(NAME,s.name);
           strcat(C_NO,s.c_no);
           strcat(CARMAN,s.carMan);
           strcat(CARMOD,s.carMod);
           strcat(RTO_NO,s.rto_no);
           strcat(Cy,s.cy);
           PRICE=s.price;
           infile.close();
           time_t now = time(0);// current date/time based on current system
           tm *ltm = localtime(&now);// print various components of tm structure.
           int d1=1900 + ltm->tm_year;
           int d2=1 + ltm->tm_mon;
           int d3=ltm->tm_mday;
           int d4=ltm->tm_hour;
           int d5=ltm->tm_min;
           int d6=ltm->tm_sec;
           ofstream outfile;
           outfile.open("admin1.txt",ios::app);
           outfile <<UID<<setw(10)<<NAME<<setw(12)<<C_NO<<"   "<<d3<<"  "<<d2<<"  "<<d1<<"  "<<d4<<"  "<<d5<<"  "<<d6<<endl;
           outfile.close();
           sucesslogin(1);

          }
          else
          {
           static int j2=3;
           --j2;
           gotoxy(10,2+(j1+1));
           cout<<"Error! Incorrect Pin  - > Please Enter Detail Once Again"<<j2<<" Attempts Remaining ";
           j1++;
           goto label1;
           }
         }
     else
     {
      static int j2=3;
      --j2;
      gotoxy(2,9+(j+5));
      cout<<"Error! maybe the file or U_id doesn't exist -> Please Enter Once Again "<<j2<<" Attempts Remaining ";
      j++;
      goto label1;
     }
    }
 else
{ sucesslogin(2); }
}
else
   { exita(); }
  }

void exit();
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
void delay(float n=1.0)
{
 ShowConsoleCursor(false);
 for(int i2=0;i2<n*(110000000);i2++);
}


 void loading(int a=1)
 {
  ShowConsoleCursor(false);
   for(int j=0;j<a;j++)
    for(int i=0;i<a-j;i++)
     if(i%2!=0)
    {
     delay(0.2);
     {
     gotoxy(28+i,6);
     printf(" %c ",254);
     }
     }
     else
     {
     delay();
     {
     gotoxy(28+i,6);
     cout<<" ";
     }
    }
}
 void home();
 void loggedout()
 {
     system("cls");
     char ch;
     gotoxy(15,7);
     cout<<"You have Successfully Logged out";
     gotoxy(15,9);
     cout<<"Press [1] To Exit";
     gotoxy(15,11);
     cout<<"Press [2] to continue ";
     gotoxy(15,13);
     cin>>ch;
     if(ch==1) exit();
     else
     home();
}
 void logout()
 {
     system("cls");
     NAME[0]='\0';
     C_NO[0]='\0';
     CARMAN[0]='\0';
     CARMOD[0]='\0';
     RTO_NO[0]='\0';
     Cy[0]=0;
     design();
     gotoxy(15,6);
     cout<<"Logging out ";
     loading(7);
     loggedout();
 }
  void buy()
 {
 int i=0;
 i++;
 design();
 gotoxy(21,6);
 time_t now = time(0);// current date/time based on current system
 tm *ltm = localtime(&now);// print various components of tm structure.
 int d1=1900 + ltm->tm_year;
 int d2=1 + ltm->tm_mon;
 int d3=ltm->tm_mday;
 cout<<"Buying";
 loading(7);
 gotoxy(21,8);
 ofstream out;
 char file1[40];
 itoa(UID,file1,10);
 int  l=strlen(file1);
 file1[l]='a';
 file1[l+1]='.';
 file1[l+2]='t';
 file1[l+3]='x';
 file1[l+4]='t';
 file1[l+5]='\0';
 strcpy(U_Id_Prem,file1);
 out.open(file1);
 out <<d3<<"\\"<<d2<<"\\"<<d1;
 out.close();
 cout<<"Transaction...Complete ! ! !";
 gotoxy(21,7);
 cout<<"Press any key to continue";
 getch();
 sucesslogin(1);
 }
 void get_prem();
 float true_valutation=0.0;
 void sucesslogin(int n)
 {
  true_valutation=valutation(Cy);
  if(n==1)
  {
   //load();
   char ch,ch1;
   time_t now = time(0);// current date/time based on current system
   tm *ltm = localtime(&now);// print various components of tm structure.
   int d1=1900 + ltm->tm_year;
   int d2=1 + ltm->tm_mon;
   int d3=ltm->tm_mday;
   int d4=1 + ltm->tm_hour;
   int d5=ltm->tm_min;
   int d6=1 + ltm->tm_sec;
   system("cls");
   design();
   gotoxy(30,3);
   cout<<" L O G I N - S U C E S S F U L L ";
   gotoxy(30,4);
   cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
   gotoxy(10,2);
   cout<<" "<<d4<<":"<<d5<<":"<<d6<<" ";
   gotoxy(70,2);
   cout<<" Hi , "<<s.name<<" ";
   gotoxy(35,7);
   cout<<" 1 ) Display Details ";
   gotoxy(35,9);
   cout<<" 2 ) Get Premium ";
   gotoxy(35,11);
   cout<<" 3 ) Logout to Main-Menu ";
   gotoxy(35,13);
   cout<<" 4 ) Exit ";
   gotoxy(35,15);
   cout<<" Enter Your Choice : _____ ";
   gotoxy(58,15);
   cin>>ch;
   if(ch=='1')
    {
   //load();
   system("cls");
   design();
   gotoxy(30,6);
   cout <<"Name              :  "<< NAME << endl;
   gotoxy(30,7);
   cout <<"Contact No.       :  "<< C_NO << endl;
   gotoxy(30,8);
   cout <<"Manufacturer      :  "<< CARMAN << endl;
   gotoxy(30,9);
   cout <<"Model             :  "<< CARMOD << endl;
   gotoxy(30,10);
   cout <<"RTO No.           :  "<< RTO_NO << endl;
   gotoxy(30,11);
   cout <<"Purchase Year     :  "<< Cy << endl;
   gotoxy(30,12);
   cout <<"Amt               :  "<< PRICE << endl;
   gotoxy(30,13);
   cout <<"Present Valuation :  "<< true_valutation << endl;
   gotoxy(30,14);
   cout<<"Press [1] Go Back ";
   gotoxy(30,15);
   cout<<"Press [2] Logout to Main Menu ";
   gotoxy(30,16);
   cout<<"Press [3] Exit ";
   gotoxy(30,17);
   cin>>ch1;
    switch(ch1){
    case '1':sucesslogin(1);break;
    case '2':logout();break;
    case '3':exit();break;
    }
     }
   else if(ch=='2')
{ get_prem();}
  else if(ch=='3')
{ logout();}
  else if(ch=='4')
{ exit();}
  }
     else if(n==2)
     {
       char ch,ch1;
   time_t now = time(0);// current date/time based on current system
   tm *ltm = localtime(&now);// print various components of tm structure.
   int d1=1900 + ltm->tm_year;
   int d2=1 + ltm->tm_mon;
   int d3=ltm->tm_mday;
   int d4=1 + ltm->tm_hour;
   int d5=1 + ltm->tm_min;
   int d6=1 + ltm->tm_sec;
   system("cls");
   design();
   gotoxy(20,3);
   cout<<"  A D M I N  L O G I N - S U C E S S F U L L ";
   gotoxy(30,4);
   cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
   gotoxy(10,2);
   cout<<" "<<d4<<":"<<d5<<":"<<d6<<" ";
   gotoxy(70,2);
   cout<<" Hi , Admin  ";
   gotoxy(35,5);
   cout<<" 1 ) Display Details of All Account";
   gotoxy(35,7);
   cout<<" 2 ) Display last login Details ";
   gotoxy(35,9);
   cout<<" 3 ) Logout to Main-Menu ";
   gotoxy(35,11);
   cout<<" 4 ) Exit ";
   gotoxy(35,13);
   cout<<" Enter Your Choice : _____ ";
   gotoxy(58,13);
   cin>>ch;
   if(ch=='1')
   {
    int j=6;
    string content;
    system("cls");
    design();
    gotoxy(10,4);
    cout<<"U_Id   Name    Contact_no ";
    gotoxy(10,5);
    fstream fil;
    fil.open("admin.txt");
    if(fil.is_open())
    {
    while(getline(fil,content))
    {
        cout<<content<<endl;
        gotoxy(10,j++);
    }
    gotoxy(1,20);
    getch();
    sucesslogin(2);
    }
    else
        {
        cout<<"File Doesn't Exists";
        getch();
        sucesslogin(2);
         }
   }
  else if(ch=='2'){int j=6;
    string content;
    system("cls");
    design();
    gotoxy(10,4);
    cout<<"U_Id   Name    Contact_no    Last Login ";
    gotoxy(10,5);
    cout<<"                            mm-dd-yyyy-hr-min-secs";
    fstream fil;
    fil.open("admin1.txt");
    if(fil.is_open())
    {
    while(getline(fil,content))
    {
        cout<<content<<endl;
        gotoxy(10,j++);
    }
    gotoxy(1,20);
    getch();
    sucesslogin(2);
    }
}
  else if(ch=='3') logout();
  else if(ch=='4') exit();
  else exit();
   }
   }
   void get_prem()
{
   char ch;
   int date_1;
   system("cls");
   ifstream ifile;
   ifile.open(U_Id_Prem,ios::in);
   design();
   gotoxy(22,4);
   float prem_f_value=true_valutation*0.01;
   cout<<" P  R  E  M  I  U   M  -  C  A  L  C  U  L  A  T  O  R ";
   gotoxy(10,6);
   cout<<"Premium for 1 year of your car having true valuation  of "<<true_valutation<<" = Rs."<<prem_f_value;
   gotoxy(30,8);
   cout<<" [1] B U Y";
   gotoxy(30,10);
   cout<<" [2] G O  B A C K ";
   gotoxy(32,12);
   cout<<" Enter Your Choice : _____ ";
   gotoxy(55,12);
   cin>>ch;
   switch (ch)
   {
       case '1': if(ifile)
                           {
                            string content;
                            system("cls");design();
                            gotoxy(5,5);
                            cout<<"You already Purchased our policy on...";
                            gotoxy(5,15);
                            cout<<" Press Any key to go back";
                            int j=0;
                            while(getline(ifile, content))
                            {
                             gotoxy(52,5);
                             cout<<content;
                             }
                            getch();
                            sucesslogin(1);
                            }
                  else
                  buy();
                break;
       case '2':sucesslogin(1);break;
    }
   }
void about_us()
{
    system("cls");
    design();
    gotoxy(30,3);
    cout<<"A B O U T  -  U S ";
    gotoxy(29,4);
    cout<<"~~~~~~~~~~~~~~~~~~~";
    gotoxy(5,5);
    delay(0.9);
    cout<<"We Provide you following facility at best possible premium rate";
    gotoxy(5,6);
    delay(0.9);
    cout<<"Cashless settlement at over 4000 garages ";
    gotoxy(5,7);
    delay(0.9);
    cout<<"Hassle free claim settlement";
    gotoxy(5,8);
    delay(0.9);
    cout<<"Quick and easy online purchase process";
    gotoxy(5,9);
    delay(0.9);
    cout<<"24x7 Spot Assistance";
    gotoxy(5,10);
    delay(0.9);
    cout<<"24x7 telephonic service, even on holidays";
    gotoxy(5,11);
    delay(0.9);
    cout<<"Transfer up to 50% of your existing (NCB) from any car insurance provider";
    gotoxy(5,12);
    delay(0.9);
    cout<<"75% on account payment when cashless facility is not available";
    gotoxy(5,13);
    delay(0.9);
    cout<<"Towing Facility in an event of a vehicle breakdown/accident";
    gotoxy(5,14);
    delay(0.9);
    cout<<"Receive Instant Claims Assistance and SMS updates";
    gotoxy(5,15);
    delay(0.9);
    cout<<"Lock and key replacement cover";
    gotoxy(5,18);
    delay(0.9);
    cout<<"Press Any Key To Go Back";
    getch();
    home();
}
void exit()
{
system("cls");
cout<<"\n\n\n\t\tP R O G R A M  \n\n";
delay(0.9);
cout<<"\t\t\tD E V L O P E D \n\n";
delay(0.9);
cout<<"\t\t\t       B Y\n\n";
delay(0.9);
cout<<"\t\t\t\t\tD H A W N I L  G A N D H I\n\n";
delay(0.9);
cout<<"\t\t\t\t\tH A R S H A M  S E V A K\n\n";
cout<<"\n\t\tT   H   A   N   K   -   Y   O   U !  !  !\n";
delay(0.9);
cout<<"\t  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
exit(0);
}
int main()
{
home();
}
