#include "../include/Intern.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern &obj)
{
	(void)obj;
}

Intern &Intern::operator=(const Intern &obj)
{
    (void)obj;
    return *this;
}
Intern::~Intern()
{
	
}

AForm *createPresidential(const std::string &t)
{
    return new PresidentialPardonForm(t);
}

AForm *createRobotomy(const std::string &t)
{
    return new RobotomyRequestForm(t);
}

AForm *createShrubbery(const std::string &t)
{
    return new ShrubberyCreationForm(t);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
    const std::string formNames[3] =
    {
        "PresidentialPardonForm",
        "RobotomyRequestForm",
        "ShrubberyCreationForm"
    };
    typedef AForm *(*CreateFunc)(const std::string &);

    CreateFunc creators[3] =
    {
        &createPresidential,
        &createRobotomy,
        &createShrubbery
    };

    for (int i = 0; i < 3; i++)
    {
        if (name == formNames[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return creators[i](target);
        }
    }
    std::cerr << "Error: form \"" << name << "\" not found." << std::endl;
    return 0;
}
