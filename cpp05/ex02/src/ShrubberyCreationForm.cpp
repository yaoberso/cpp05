#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Default", 145, 137, "Default target")
{
	std::cout << "Default ShrubberyCreationForm constructor called!" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137, target)
{
	std::cout << "ShrubberyCreationForm constructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other): AForm(other)
{
	std::cout << "ShrubberyCreationForm copy constructor called!" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	std::cout << "ShrubberyCreationForm copy assignement constructor called!" << std::endl;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	checkRequirements(executor);
	std::ofstream file(getTarget() + "_shrubbery");
	if (!file.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
    	return;
	}
    file << "           ___\n";
	file << "        __/    \\__\n";
	file << "       /~  ~       \\___\n";
	file << "    __|   ~      ~    ~\\\n";
	file << "   /   ~  ~  ~  ~      |\n";
	file << "  |  ~  ~      ___~___/\n";
	file << "  \\______  || |//\n";
	file << "      \\\\| || //\n";
	file << "        \\|    |\n";
	file << "          |    |\n";
	file << "          |  @ |\n";
	file << "          |    |\n";
	file << "_________/______\\_______\n";
	file.close();
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &f)
{
    out << f.getName()
        << ", signed: " << (f.getSign() ? "yes" : "no")
        << ", grade sign: " << f.getGradeSign()
        << ", grade exec: " << f.getGradeExec()
        << ", target: " << f.getTarget();
    return out;
}