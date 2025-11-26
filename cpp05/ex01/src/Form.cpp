#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form(): _name("Default"), _sign(false), _gradesign(100), _gradeexec(100)
{
	std::cout << "Default Form constructor called!" << std::endl;
}

Form::~Form()
{

}

Form::Form(std::string name, int gradesign, int gradeexec): _name(name), _sign(false), _gradesign(gradesign), _gradeexec(gradeexec)
{
	if (gradesign < 1 || gradeexec < 1)
		throw GradeTooHighException();
	if (gradesign > 150 || gradeexec > 150)
		throw GradeTooLowException();
	std::cout << "Form constructor called!" << std::endl;
}

Form::Form(Form &other): _name(other._name), _sign(other._sign), _gradesign(other._gradesign), _gradeexec(other._gradeexec)
{
	std::cout << "Form copy constructor called!" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->_sign = other._sign;
	std::cout << "Form copy assignement constructor called!" << std::endl;
	return (*this);
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->_gradesign)
		this->_sign = true;
	else
		throw GradeTooLowException();
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSign() const
{
	return (this->_sign);
}

int Form::getGradeSign() const
{
	return (this->_gradesign);
}

int Form::getGradeExec() const
{
	return (this->_gradeexec);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade Too High!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low!");
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << f.getName()
		<< ", form signed: " << (f.getSign() ? "yes" : "no")
		<< ", grade required to sign: " << f.getGradeSign()
		<< ", grade required to execute: " << f.getGradeExec();
	return (out);
}

