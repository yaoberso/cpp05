#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <iomanip>

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat &other);
		Bureaucrat &operator=(Bureaucrat &other);
		std::string getName();
		int getGrade();
		~Bureaucrat();

	private:
		const std::string _name;
		int _grade;
};
#endif