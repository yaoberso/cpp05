#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm(): _name("Default"), _sign(false), _gradesign(100), _gradeexec(100), _target("Default target")
{
	std::cout << "Default AForm constructor called!" << std::endl;
}

AForm::~AForm()
{

}

AForm::AForm(std::string name, int gradesign, int gradeexec, std::string target): _name(name), _sign(false), _gradesign(gradesign), _gradeexec(gradeexec), _target(target)
{
	if (gradesign < 1 || gradeexec < 1)
		throw GradeTooHighException();
	if (gradesign > 150 || gradeexec > 150)
		throw GradeTooLowException();
	std::cout << "AForm constructor called!" << std::endl;
}

AForm::AForm(AForm &other): _name(other._name), _sign(other._sign), _gradesign(other._gradesign), _gradeexec(other._gradeexec), _target(other._target)
{
	std::cout << "AForm copy constructor called!" << std::endl;
}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) 
	{
        this->_sign = other._sign;
        this->_target = other._target;
    }
    std::cout << "AForm copy assignment operator called!" << std::endl;
    return *this;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->_gradesign)
		this->_sign = true;
	else
		throw GradeTooLowException();
}

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSign() const
{
	return (this->_sign);
}

int AForm::getGradeSign() const
{
	return (this->_gradesign);
}

int AForm::getGradeExec() const
{
	return (this->_gradeexec);
}

std::string AForm::getTarget() const
{
	return (this->_target);
}

void AForm::checkRequirements(const Bureaucrat &executor) const
{
	if (!getSign())
	{
		throw FormNotSignedException();
	}
	if (executor.getGrade() < _gradeexec)
	{
		throw GradeTooLowException();
	}
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade Too High!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low!");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed!");
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << f.getName()
		<< ", form signed: " << (f.getSign() ? "yes" : "no")
		<< ", grade required to sign: " << f.getGradeSign()
		<< ", grade required to execute: " << f.getGradeExec();
	return (out);
}

