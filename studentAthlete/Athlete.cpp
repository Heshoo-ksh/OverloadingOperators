#include "Athlete.h"
#include "Student.h"
Athlete::Athlete(std::string firstName,std::string lastName,std::string sportPlayed)
{
	this-> firstName = firstName;
	this-> lastName = lastName;
	this-> sportPlayed = sportPlayed;
}

Athlete::~Athlete()
{
}

