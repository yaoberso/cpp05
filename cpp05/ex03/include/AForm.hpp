#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm();
		AForm(std::string name, int gradesign, int gradeexec, std::string target);
		AForm(AForm &other);
		AForm &operator=(const AForm &other);
		~AForm();

		void beSigned(const Bureaucrat &b);

		std::string getName() const;
		bool getSign() const;
		int getGradeSign() const;
		int getGradeExec() const;
		std::string getTarget() const;
		void checkRequirements(const Bureaucrat &executor) const;
		virtual void execute(Bureaucrat const &executor) const;

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};
	protected:
		const std::string _name;
		bool _sign;
		const int _gradesign;
		const int _gradeexec;
		std::string _target;
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif

