#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form();
		Form(std::string name, int gradesign, int gradeexec);
		Form(Form &other);
		Form &operator=(const Form &other);
		~Form();

		void beSigned(const Bureaucrat &b);

		std::string getName() const;
		bool getSign() const;
		int getGradeSign() const;
		int getGradeExec() const;

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

	private:
		const std::string _name;
		bool _sign;
		const int _gradesign;
		const int _gradeexec;
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif

