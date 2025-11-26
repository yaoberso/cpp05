#ifndef INTERN_CPP
#define INTERN_CPP
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

class PresidentialPardonForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;

class AForm;
class Intern{
	public :
		Intern();
		Intern(const Intern &obj);
		Intern &operator=(const Intern &obj);
		~Intern();
		AForm *makeForm(const std::string &name, const std::string &target);
		class BadName : public std::exception {
		public:
			const char* what() const throw();
		};
};

#endif