#include<iostream>
#include<string.h>

using namespace std;

class Student
{
	protected: 
		char name[15];
		int roll;
		char gender[15];
		char dept[15];
	
	public:
		void get_stu_details()
		{
			cout<<"Enter name: ";
			cin>>name;
			cout<<"Enter reg no: ";
			cin>>roll;
			cout<<"Your Gender: ";
			cin>>gender;
			cout<<"Enter your dept: ";
			cin>>dept;
		
		}
		
};

class Marks: public Student
{
	protected:
		
		int marksinmath, marksinenglish, marksinscience, marksincse, marksingeo;
		int total=0, average=0;
	
	public:
		void getMarks()
		{
			cout<<"\nEnter Math score: ";
			cin>>marksinmath;
			cout<<"Enter English score: ";
			cin>>marksinenglish;
			cout<<"Enter Science score: ";
			cin>>marksinscience;
			cout<<"Enter CSE score: ";
			cin>>marksincse;
			cout<<"Enter Geography score: ";
			cin>>marksingeo;
		}
		
		void calculateTotalAverage()
		{

				total= marksinmath+ marksinenglish+ marksinscience+ marksincse+ marksingeo;
				average=total/5;
		}
		
};

class Sports: public Marks 
{
	char grade;
	int marksinsports;
	
	public:
	void addExtraMarks(){
		cout<<"Enter marks in sports: ";
		cin>>marksinsports;
		if(marksinsports>8)
		{
			average=average+5;
		}
		else if(marksinsports>=6 && marksinsports<=8 )
		{
			average=average+3;
		}
		else if(marksinsports>=3 && marksinsports<=5)
		{
			average=average+1;
		}
	}
	void gradecalc(){
		if(average>=95)
		{
			grade='A';
		}
		else if(average>=90)
		{
			grade='A';
		}
		else if(average>=85)
		{
			grade='B';
		}
		else if(average>=80)
		{
			grade='B';
		}
		else if(average>=70)
		{
			grade='C';
		}
			else if(average>=60)
		{
			grade='D';
		}
		else if(average>=50)
		{
			grade='E';
		}
		else
		{
			grade='F';
		}
	}
	
	void report(){
		cout<<"\n\nName: "<<name<<"\n";
		cout<<"reg no: "<<roll<<"\n";
		cout<<"Department: "<<dept<<"\n";
		cout<<"Your total score is: "<<total<<"\n";
		cout<<"Your average score is: "<<average<<"\n";
		cout<<"Grade is: "<<grade;
	}

};

int main(){
	
	Sports e;
	e.get_stu_details();
	e.getMarks();
	e.calculateTotalAverage();
	e.addExtraMarks();
	e.gradecalc();
	e.report();
	
	return 0;
}
