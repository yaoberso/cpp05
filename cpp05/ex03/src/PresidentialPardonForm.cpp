#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Default", 25, 5, "Default target")
{
	std::cout << "Default PresidentialPardonForm constructor called!" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5, target)
{
	std::cout << "PresidentialPardonForm constructor called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other): AForm(other)
{
	std::cout << "PresidentialPardonForm copy constructor called!" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	std::cout << "PresidentialPardonForm copy assignement constructor called!" << std::endl;
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const 
{
    checkRequirements(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}


std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &f)
{
    out << f.getName()
        << ", signed: " << (f.getSign() ? "yes" : "no")
        << ", grade sign: " << f.getGradeSign()
        << ", grade exec: " << f.getGradeExec()
        << ", target: " << f.getTarget();
    return out;
}

