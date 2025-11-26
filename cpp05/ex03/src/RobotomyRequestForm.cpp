#include "../include/AForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Default", 72, 45, "Default target")
{
	std::cout << "Default RobotomyRequestForm constructor called!" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45, target)
{
	std::cout << "RobotomyRequestForm constructor called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other): AForm(other)
{
	std::cout << "RobotomyRequestForm copy constructor called!" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	std::cout << "RobotomyRequestForm copy assignement constructor called!" << std::endl;
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const 
{
    checkRequirements(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &f)
{
    out << f.getName()
        << ", signed: " << (f.getSign() ? "yes" : "no")
        << ", grade sign: " << f.getGradeSign()
        << ", grade exec: " << f.getGradeExec()
        << ", target: " << f.getTarget();
    return out;
}