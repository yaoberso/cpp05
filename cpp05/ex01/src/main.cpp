#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Alice", 50);
		Form f1("Contract", 75, 100);

		std::cout << f1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat b2("Bob", 120);
		Form f2("SecretDoc", 100, 50);

		std::cout << f2 << std::endl;
		b2.signForm(f2);
		std::cout << f2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}



