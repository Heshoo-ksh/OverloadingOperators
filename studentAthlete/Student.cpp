#include "Student.h"

Student::Student(std::string firstName,std::string lastName,int grade,double fee)
	{
		this->firstName = firstName;
		this->lastName = lastName;
		this->grade = grade;
		this->fee = fee;
	}

Student::~Student()
{
}
Student Student::operator+=(double num)
	{
		this->fee = this->fee + num;
		return *this;
	}



