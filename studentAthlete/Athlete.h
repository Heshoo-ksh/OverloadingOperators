#ifndef ATHLETE_H
#define ATHLETE_H
#include <iostream>
#include "Student.h"

class Athlete
{
	friend std::ostream& operator << (std::ostream& o,const Athlete & anAthlete);
	friend bool operator==(std::string sport, Athlete anAthlete);
	//friend bool operator==(Student aStudent, Athlete anAthlete);

	private:
		std::string firstName;
		std::string lastName;
		std::string sportPlayed;
		static double athleticFee;
	public:
		Athlete(std::string firstName,std::string lastName,std::string sportPlayed);
		~Athlete();
		
};
static double athleticFee = 125.50;

#endif
