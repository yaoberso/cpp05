#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(99)
{
	std::cout << "Default Bureaucrat constructor called!" << std::endl;
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat constructor called!" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &other): _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat copy constructor called!" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->_grade = other._grade;
	std::cout << "Bureaucrat copy assignement constructor called!" << std::endl;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::decrGrade()
{
	if ((this->_grade + 1) > 150)
		throw GradeTooLowException();
	this->_grade += 1;
}

void Bureaucrat::incrGrade()
{
	if ((this->_grade - 1) < 1)
		throw GradeTooHighException();
	this->_grade -= 1;
}

void Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm &f)
{
	try
	{
		f.execute(*this);
		std::cout << this->_name << " execute " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " couldn't execute " << f.getName() << " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low!");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (out);
}
