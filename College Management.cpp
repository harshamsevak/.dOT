#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<fstream>

struct marks_criteria
{
char sc_min[100],com_min[100],arts_min[100], seat_sc[100], seat_com[100], seat_arts[100];
} crit;

struct administrator
{
	char user_name[10];
	char password[10];
}admin;

struct  student
{
char name[20];
int regno,m_sc,m_sst;
char m_eng[100],m_math[100],m_lang[10];
int pref_code, stream;



	public:
		void new_file();
		void input_data();
		void allot_stream();
		int get_stream();
		void display();


};
void welcome();
void menu();
int verify_password();
void assign_user();
void clear();
void input_criteria();
void read_criteria();
void read_student();
void create_eligible_sc();
void create_eligible_com();
void create_eligible_arts();
void read_eligible_sc();
void read_eligible_com();
void read_eligible_arts();
char * stream_name(int strm);
void select_list( char *in_file, char *out_file);
void thanks();
void student1();
void student2();
student s;
int x,y,h,m,g;
char username[100],password1[100];
char username1[100],password2[100];
int main()
{



     welcome();


    fstream fin, fout;
fstream fsc, fcom, farts;

int opt=1, ch;

while(opt!=8)
{



 clear();
	cout<<"\n\t======================  MAIN   MENU  =======================\n";
	cout<<"\n\t[1] CREATE / MODIFY  STUDENT AND STAFF DETAILS(Administrator only)";
	cout<<"\n\n\t[2] ENTER STUDENT'S DATA (Administrator only)";
	cout<<"\n\n\t[3] STUDENT LOGIN";
	cout<<"\n\n\t[4] EMPLOYEE LOGIN";
	cout<<"\n\n\t[5] DISPLAY ATTENDANCE OF STUDENTS";
	cout<<"\n\n\t[6] DISPLAY EXAM TIMETABLE";
	cout<<"\n\n\t[7] ACADEMIC CALENDAR(Administrator only)";
	cout<<"\n\n\t[8] QUIT";
	cout<<"\n\t=============================================================\n";
	cout<<"\n\n\t\tEnter your  choice : ";
	cin>>opt;
	switch(opt)
	{
	case 1:
			int p;
			assign_user();
			p=verify_password();
			if(p==0)
			{

				input_criteria();
			}
			else
			{
				cout<<"\n\tU R Not a Valid User.";
				cout<<"\n\tU Dont have the Authority to Create Question Bank. Bye\n\n";
			}
			break;

	case 2:
	       int option;

	       cout<<"\nWhat do u want --\n\n\n\n\n\tCreate  a new student information  file or Append to the existing file?\n\n\t(press 1 for new creation and 2 for appending)";
	       cin>>option;
	       if(option==1)
	       {
		  s.new_file();
		  }
		  else
		  {
		s.input_data();
		}
		break;

	case 3:

		cout<<"enter username for student login:";
		cin>>username;
		cout<<"enter password";
		cin>>password1;
		student1();
		break;



	case 4:
	    cout<<"enter username for employee login:";
		cin>>username1;
		cout<<"enter password";
		cin>>password2;
		student2();

break;

	case 5:
	    char name3[100],branch3[5];
	    int number3;

		cout<<"enter your name";
		cin>>name3;
		cout<<"enter branch";
		cin>>branch3;
		cout<<"enter your no.";
		cin>>number3;
		cout<<"your overall attendance is 78%";


		break;
	case 6:
			read_student();
			break;
	case 7:
		{
			char c;
			int k=1;
			cout<<"\n****************************************";
			cout<<"\n****************************************";
			cout<<"\n    ACADEMIC CALENDAR";
			cout<<"\n    ==================";
			cout<<"\n****************************************";
			cout<<"\n****************************************"<<endl;
			cout<<"DATE"<<setw(20)<<"REASON"<<endl;
			cout<<"14-1-17"<<setw(20)<<"UTTARAYAN"<<endl;
			cout<<"26-1-17"<<setw(20)<<"REPUBLIC DAY"<<endl;
			cout<<"20-2-17"<<setw(20)<<"SPORTS DAY"<<endl;
			cout<<"10-3-17"<<setw(20)<<"HOLI"<<endl;
			cout<<"11-3-17"<<setw(20)<<"DHULETI"<<endl;
			cout<<"17-3-17"<<setw(20)<<"EDUCATION TRIP"<<endl;
			cout<<"17-4-17"<<setw(20)<<"2nd INTERNAL EXAM"<<endl;
			cout<<"24-4-17"<<setw(20)<<"PRACTICAL EXAMS"<<endl;
			cout<<"11-5-17"<<setw(20)<<"UNIVERSITY  EXAM"<<endl;
			cout<<"24-5-17"<<setw(20)<<"END OF SEM"<<endl;
			cout<<"15-8-17"<<setw(20)<<"REPUBLIC DAY"<<endl;
			cout<<"18-8-17"<<setw(20)<<"RAKSHABANDHAN"<<endl;
			cout<<"20-10-17"<<setw(20)<<"DIWALI VACATION"<<endl;


		break;
		}
	case 8:
	   thanks();

		break;
	}

		}

 }




void	assign_user()
{

	strcpy(admin.user_name, "harsham");
	strcpy(admin.password, "harsham22");


}
void student1()
{
    cout<<"select any one from the following:";
    cout<<"[1] for exam timetable"<<endl;
    cout<<"[2] for attendance"<<endl;
    cout<<"[3] for academic calendar"<<endl;
    cout<<"[4] for courses"<<endl;
    cin>>x;
    switch(x)
    {


case 1:
    read_student();
    break;
case 2:
    cout<<"your attendance is 75%";
    break;
case 3:
    cout<<"\n****************************************";
			cout<<"\n****************************************";
			cout<<"\n    ACADEMIC CALENDAR";
			cout<<"\n    ==================";
			cout<<"\n****************************************";
			cout<<"\n****************************************"<<endl;
			cout<<"DATE"<<setw(20)<<"REASON"<<endl;
			cout<<"14-1-17"<<setw(20)<<"UTTARAYAN"<<endl;
			cout<<"26-1-17"<<setw(20)<<"REPUBLIC DAY"<<endl;
			cout<<"20-2-17"<<setw(20)<<"SPORTS DAY"<<endl;
			cout<<"10-3-17"<<setw(20)<<"HOLI"<<endl;
			cout<<"11-3-17"<<setw(20)<<"DHULETI"<<endl;
			cout<<"17-3-17"<<setw(20)<<"EDUCATION TRIP"<<endl;
			cout<<"17-4-17"<<setw(20)<<"2nd INTERNAL EXAM"<<endl;
			cout<<"24-4-17"<<setw(20)<<"PRACTICAL EXAMS"<<endl;
			cout<<"11-5-17"<<setw(20)<<"UNIVERSITY  EXAM"<<endl;
			cout<<"24-5-17"<<setw(20)<<"END OF SEM"<<endl;
			cout<<"15-8-17"<<setw(20)<<"REPUBLIC DAY"<<endl;
			cout<<"18-8-17"<<setw(20)<<"RAKSHABANDHAN"<<endl;
			cout<<"20-10-17"<<setw(20)<<"DIWALI VACATION"<<endl;
         break;
case 4:
    cout<<"ENTER SEM";
    cin>>h;
    if(h==2)
    {
        cout<<"1.LINEAR ALGEBRA"<<endl;
        cout<<"2.ESFP"<<endl;
        cout<<"3.BCS"<<endl;
        cout<<"4.CO"<<endl;
        cout<<"5.ASB"<<endl;

    }
    else{
        cout<<"1 MATHS"<<endl;
        cout<<"2 JAVA"<<endl;
        cout<<"3 BOSS"<<endl;
    }


}
}
void student2()
{
    cout<<"select any one from the following:";
    cout<<"[1] for course ";
    cout<<"[2] for academic calendar";
    cin>>y;
    switch(y)
    {
        case 1:

        cout<<"ENTER SEM";
    cin>>g;
    if(g==2)
    {
        cout<<"1.POINTERS"<<endl;
        cout<<"2.CLASSES AND OBJECTS"<<endl;
        cout<<"3.FILE HANDLING"<<endl;
        cout<<"4.STRINGS"<<endl;
        cout<<"5.FRIEND FUNCTION"<<endl;
        cout<<"6.INHERITANCE"<<endl;

    }
    else{
        cout<<"1 MATHS"<<endl;
        cout<<"2 JAVA"<<endl;
        cout<<"3 BOSS"<<endl;
    }
     break;
        case 2:
             cout<<"\n****************************************";
			cout<<"\n****************************************";
			cout<<"\n    ACADEMIC CALENDAR";
			cout<<"\n    ==================";
			cout<<"\n****************************************";
			cout<<"\n****************************************"<<endl;
			cout<<"DATE"<<setw(20)<<"REASON"<<endl;
			cout<<"14-1-17"<<setw(20)<<"UTTARAYAN"<<endl;
			cout<<"26-1-17"<<setw(20)<<"REPUBLIC DAY"<<endl;
			cout<<"20-2-17"<<setw(20)<<"SPORTS DAY"<<endl;
			cout<<"10-3-17"<<setw(20)<<"HOLI"<<endl;
			cout<<"11-3-17"<<setw(20)<<"DHULETI"<<endl;
			cout<<"17-3-17"<<setw(20)<<"EDUCATION TRIP"<<endl;
			cout<<"17-4-17"<<setw(20)<<"2nd INTERNAL EXAM"<<endl;
			cout<<"24-4-17"<<setw(20)<<"PRACTICAL EXAMS"<<endl;
			cout<<"11-5-17"<<setw(20)<<"UNIVERSITY  EXAM"<<endl;
			cout<<"24-5-17"<<setw(20)<<"END OF SEM"<<endl;
			cout<<"15-8-17"<<setw(20)<<"REPUBLIC DAY"<<endl;
			cout<<"18-8-17"<<setw(20)<<"RAKSHABANDHAN"<<endl;
			cout<<"20-10-17"<<setw(20)<<"DIWALI VACATION"<<endl;
         break;

    }

}
int verify_password()
{
	char u_name[10];
	char u_pwd[10],temp[2];
	int x=1;
	cout<<"\n\n   Enter user name : ";
	cin>>u_name;
	cout<<"\n\n   Enter Password : ";
	cin>>u_pwd;
	x=strcmp(admin.user_name,u_name);
	if (x==0)
	{
		x=strcmp(admin.password,u_pwd);

	}
	cin.getline(temp,2);
	return(x);

}
int password;
void student::allot_stream()
{

	read_criteria();


}

int student::get_stream()
{
	return(stream);
}


void input_criteria()
{

    fstream fout;
	fout.open("criteria" ,ios::in|ios::out);
	 cout<<"\nEnter  the name of faculty";
	cin>>crit.sc_min;

	cout<<"\nEnter  No. of subject the faculty teaches";
	cin>>crit.seat_sc;
	cout<<"\nEnter  the  name of subject the faculty teaches";
	cin>>crit.com_min;
	cout<<"\nEnter  qualification of the faculty";
	cin>>crit.seat_com;

	cout<<"\nEnter  the  name of student)";
	cin>>crit.arts_min;
	cout<<"\nEnter  the course of student";
	cin>>crit.seat_arts;
    fout.write((char*)& crit,sizeof(crit));
	fout.close();
}

void read_criteria()
{
	fstream fin;
	fin.open("criteria" ,ios::in);
	fin.read((char*)& crit,sizeof(crit));
	fin.close();

}

void student::input_data()
{
	fstream fin;
	fin.open("student",ios::app|ios::out);
	char t[2], ans;
	while(1)
	{
	cout<<"\nEnter  the  name of the  student  :  ";
	gets(name);
	cout<<"\n\nEnter  the roll of the  student  :  ";
	cin>>regno;
	cout<<"\n\nEnter Branch of student :  ";
	cin>>m_eng;
	cout<<"\n\nEnter  city of student:  ";
	cin>>m_math;
	cout<<"\n\nEnter  phone no of student  :  ";
	cin>>m_sc;
	cout<<"\n\nEnter  student's attendance :  ";
	cin>>m_sst;
	cout<<"\n\nEnter  student's overall grade :  ";
	cin>>m_lang;

	cout<<"\n\tEnter More Student ? (y/n)";
		cin>>ans;
	if (ans=='n')
		break;
	}
	fin.close();
}
void student::new_file()
{
	fstream fin;
	fin.open("student",ios::out);
	char t[2], ans;
	while(1)
	{
	cout<<"\nEnter  the  name of the  student  :  ";
	cin>>name;
	cout<<"\n\nEnter  the roll of the  student  :  ";
	cin>>regno;
	cout<<"\n\nEnter Branch of student :  ";
	cin>>m_eng;
	cout<<"\n\nEnter  city of student:  ";
	cin>>m_math;
	cout<<"\n\nEnter  phone no of student  :  ";
	cin>>m_sc;
	cout<<"\n\nEnter  student's attendance :  ";
	cin>>m_sst;
	cout<<"\n\nEnter  student's overall grade :  ";
	cin>>m_lang;


	cout<<"\n\tEnter More Student ? (y/n)";
		cin>>ans;
	if (ans=='n')
		break;
	}
	fin.close();
}
void student::display()
{

	cout<<"\n============================================\n";
	cout<<"\n\tNAME		: "<<name;
	cout<<"\n\tREGISTRATION NO. : "<<regno;
	cout<<"\n\tSTREAM APPLIED FOR :  "<<stream_name(pref_code);
	cout<<"\n============================================\n";

}

void read_student()
{
	fstream fin;
	char c;
	fin.open("student" ,ios::in);
			cout<<"FOR FIRST YEAR"<<endl;
			cout<<"DATE"<<setw(20)<<"SUBJECT"<<setw(20)<<"TIME"<<endl;
			cout<<"17-4-17"<<setw(20)<<"LA"<<setw(20)<<"9:00-12:00"<<endl;
			cout<<"18-4-17"<<setw(20)<<"ESFP"<<setw(20)<<"9:00-12:00"<<endl;
			cout<<"19-4-17"<<setw(20)<<"CO"<<setw(20)<<"9:00-12:00"<<endl;
			cout<<"20-4-17"<<setw(20)<<"ASB"<<setw(20)<<"9:00-12:00"<<endl;
			cout<<"21-4-17"<<setw(20)<<"BOSS"<<setw(20)<<"9:00-12:00"<<endl;
			cout<<endl;
			cout<<"FOR SECOND YEAR"<<endl;
			cout<<"DATE"<<setw(20)<<"SUBJECT"<<setw(20)<<"TIME"<<endl;
			cout<<"17-4-17"<<setw(20)<<"COMPUTER"<<setw(20)<<"9:00-12:00"<<endl;
			cout<<"18-4-17"<<setw(20)<<"ESFP"<<setw(20)<<"9:00-12:00"<<endl;
			cout<<"19-4-17"<<setw(20)<<"JAVA"<<setw(20)<<"9:00-12:00"<<endl;
			cout<<"20-4-17"<<setw(20)<<"ENGLISH"<<setw(20)<<"9:00-12:00"<<endl;
			cout<<"21-4-17"<<setw(20)<<"MATHS"<<setw(20)<<"9:00-12:00"<<endl;
			cout<<endl;

fin.close();

}





void clear()
{

}
char * stream_name(int strm)
{
	switch(strm)
	{
	case -1:
		return("Not assigned");

	case 0:
		return("Nill");

	case 1:
		return("Science");

	case 2:
		return("Commerce");

	case 3:
		return("Arts");

	    default:
		return("None");
	}
}




void welcome()
   {

     int z;
	 cout<<"\t%%      %%      ";
       cout<<"\n\t%%      %% %%%%%%% %%      %%%%%%  %%%%%% %%%%  %%%% %%%%%%%";
       cout<<"\n\t%%      %% %%      %%      %%      %%  %% %%  %%% %% %%       ";
       cout<<"\n\t%%  %%  %% %%%%%   %%      %%      %%  %% %%  %%% %% %%%%%      ";
       cout<<"\n\t%%  %%  %% %%      %%      %%      %%  %% %%      %% %%           ";
       cout<<"\n\t%%%%%%%%%% %%%%%%% %%%%%%% %%%%%%% %%%%%% %%      %% %%%%%%%     ";
       cout<<"\n\n\t\t\t        $$$$$$$$  $$$$$        ";
       cout<<"\n\t\t\t           $$     $   $      ";
       cout<<"\n\t\t\t           $$     $$$$$    ";

       cout<<"\n\n\n\t UNIVERSITY   MANAGEMENT PROJECT " ;
       cout<<"\n\n\t\t\t\t       BY  :-";
       cout<<"\n\n\t\t\t*  HARSHAM"<<"\t CBA ";
       cout<<"\n\n\t\t\t*  DHWANIL "<<"\t  CBA ";

	 cout<<" \n\n\n\t\t     press any number and 'ENTER' to continue: ";
	 cin>>z;


    }
    void thanks()
	{     int w;

		cout<<"\n\n\n\n\n\n\n\n\n\n\t**********   T H A N K   Y O U   F O R   W O R K I N G   *******";
		cout<<"\n\n\n\n\n\n\n\t\t\tpress any number and then 'ENTER' to exit";
		cin>>w;
	}


