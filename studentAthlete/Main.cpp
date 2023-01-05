/*
Name: Hisham Odeh
Programm: Student Athlete
Date: 4/13/2022
*/
#include "Student.h"
#include "Athlete.h"
#include <vector>
#include <limits>

//-----Student operator overloading functions---------
std::ostream& operator << (std::ostream& o,const Student & aStudent)
{
  o<<"\nStudent full name:\t"<<aStudent.firstName<<" "<<aStudent.lastName<<std::endl;
  o<<"\nStudent grade:\t"<<aStudent.grade<<std::endl;
  o<<"\nStudent total fee:\t"<<aStudent.fee<<std::endl;

  return o;
}

bool operator==(std::string lastName, Student aStudent)
{
	return(lastName == aStudent.lastName);
}

bool operator==(int grade, Student aStudent)
{
	return(grade == aStudent.grade);
}

//----Athlete operator overloading functions----------
std::ostream& operator << (std::ostream& o,const Athlete & anAthlete)
{
  o<<"\nPlayer full name:\t"<<anAthlete.firstName<<" "<<anAthlete.lastName<<std::endl;
  o<<"\nSport name:\t"<<anAthlete.sportPlayed<<std::endl;

  return o;
}

bool operator==(std::string sport, Athlete anAthlete)
{
	return (sport == anAthlete.sportPlayed);
}

//--------------------ProtoTypes---------------------
int displayMenu();
void addStudent(std::vector <Student> & students, std::vector <Athlete> &athletes);
void displayStudents(std::vector <Student> & students);
void displayOneStudent(std::vector <Student> & students);
void displayAthletes(std::vector <Athlete> &athletes);
void displayStudentsByGrade(std::vector <Student> & students);
void displayStudentsBySport(std::vector <Athlete> &athletes);
void displaySportByGrade(std::vector <Student> & students, std::vector <Athlete> &athletes);
void validateNumaricData(int &choice, int min, int max);

//--------------------------------------------------
int main(){

	std::vector <Student> students;
	std::vector <Athlete> athletes;
	
	while (true ){
		
	int choice = displayMenu();
	
	if (choice == 1)
		addStudent(students,athletes);
	
	else if (choice == 2)
		displayStudents(students);
	
	else if (choice == 3)
		displayOneStudent(students);
	
	else if (choice == 4)
		displayAthletes(athletes);
		
	else if (choice == 5)
		displayStudentsByGrade(students);
	else if (choice == 6)
		displayStudentsBySport(athletes);
	else if (choice == 7)
		displaySportByGrade(students,athletes);
	else if (choice == 0)
		break;
	
	}
}
//---------------Non-Member functions---------------
int displayMenu()
{
	int choice;
	
	std::cout<<"\nPlease choose from the following menu \n1: Add student\n2: Print a list of enrolled students\n3: Print a list of students by last name\n4: Print a list of students who play sports\n5: Print a list of students by grade\n6: Print a list of students by sport\n7: Display student by sport\n0: Exit program \nChoice:\t";
	std::cin>>choice;
	validateNumaricData(choice, 0,7);


	   		
	return choice;
} 

void addStudent(std::vector <Student> & students, std::vector <Athlete> &athletes)
{

	std::string firstName, lastName, sportPlayed;
	int grade;
	double fee =0;
	std::string playsSports;
	std::cin.ignore();
	std::cout<<"\nEnter student first name:\t";
	getline(std::cin, firstName);
	
	std::cout<<"\nEnter student last name:\t";
	getline(std::cin, lastName);
	
	std::cout<<"\nEnter student grade:\t";
	std::cin>>grade;
	validateNumaricData(grade, 9,12);


	std::cout<<"\nDoes "<<firstName<<" "<<lastName<<" play sports? (y/n)";
	std::cin.ignore();

	getline(std::cin, playsSports);
	
	
	while ((playsSports == "y") ||( playsSports == "Y"))
	{
		std::cout<<"\nEnter sport name:\t";
		getline(std::cin, sportPlayed );
		
		Athlete anAthlete(firstName,lastName,sportPlayed);
		athletes.push_back(anAthlete);
		fee +=  athleticFee;
		std::cout<<"\nDoes "<<firstName<<" "<<lastName<<" play any other sport? (y/n)";
		getline(std::cin, playsSports);
	}
	
	Student aStudent(firstName,lastName,grade,fee);
	students.push_back(aStudent);
}

void displayStudents(std::vector <Student> & students)
{
	for (Student aStudent : students)
		std::cout<<aStudent;
}

void displayOneStudent(std::vector <Student> & students)
{
	std::string lastName;
	std::cout<<"\nEnter student last name:\t";
	std::cin.ignore();
	getline(std::cin, lastName );
	
	for (Student aStudent : students)
	{
		if (lastName == aStudent)
			std::cout<<aStudent;
	}
}

void displayAthletes(std::vector <Athlete> &athletes)
{
	for (Athlete anAthlete : athletes)
		std::cout<<anAthlete;
}
void displayStudentsByGrade(std::vector <Student> & students)
{
	int grade;
	std::cout<<"\nWhat grade will you like to see displayed?\t";
	std::cin.ignore();
	std::cin>>grade;
	validateNumaricData(grade, 9,12);
	

	for (Student aStudent : students)
	{
		if (grade == aStudent)
			std::cout<<aStudent;
	}
}
void displayStudentsBySport(std::vector <Athlete> &athletes)
{
	std::string sport;
	std::cout<<"\nWhat sport will you like to see displayed?\t";
	std::cin.ignore();
	getline(std::cin,sport);
	
	for (Athlete anAthlete : athletes)
	{
		if (sport == anAthlete)
			std::cout<<anAthlete;
	}
}
void displaySportByGrade(std::vector <Student> & students, std::vector <Athlete> &athletes)
{
	int grade;
	std::cout<<"\nWhat grade will you like to see displayed?\t";
	std::cin.ignore();
	std::cin>>grade;
	validateNumaricData(grade, 9,12);
	
	std::string sport;
	std::cout<<"\nWhat sport will you like to see displayed?\t";
	std::cin.ignore();
	getline(std::cin,sport);
	
	
	for (Athlete anAthlete : athletes)
	{
		if (sport == anAthlete)
		{
			for (Student aStudent : students)
			{
				if (grade == aStudent && sport == anAthlete)
					std::cout<<aStudent;	
			}
		}	
	}
}

void validateNumaricData(int &choice, int min, int max)
{
	while(std::cin.fail()){
		
			std::cout<<"\nERROR:\tInvalid input Due to the wrong Data type, try again \nChoice:\t";
	  		std::cin.clear();
	   		std::cin.ignore( std::numeric_limits<std::streamsize>::max(),'\n'); 
	   		std::cin>>choice;
	}
	while ( choice > max || choice < min)
	{
		std::cout<<"\nERROR:\tOption selected is not valid, try again.\nChoice:\t";
		std::cin>>choice;
		validateNumaricData( choice,  min,  max);
	}
}

