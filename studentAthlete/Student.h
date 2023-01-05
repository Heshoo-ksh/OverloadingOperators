#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
class Student
{
	friend std::ostream& operator << (std::ostream& o,const Student & aStudent);
	friend bool operator==(std::string lastName, Student aStudent);
	friend bool operator==(int grade, Student aStudent);

	private:
		std::string firstName;
		std::string lastName;
		int grade;
		double fee;
		
	public:
		Student(std::string firstName,std::string lastName,int grade,double fee = 0);
		
		~Student();
		
	Student operator+=(double num);
		
};

#endif
