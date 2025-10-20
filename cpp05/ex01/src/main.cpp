#include "../include/Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat alice("Alice", 0);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught (Alice): " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat bob("Bob", 151);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught (Bob): " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat charlie("Charlie", 2);
        std::cout << charlie.getName() << ", grade: " << charlie.getGrade() << std::endl;
        charlie.incrGrade();
        std::cout << "After increment: " << charlie.getGrade() << std::endl;
        charlie.incrGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught (Charlie): " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat dave("Dave", 149);
        std::cout << dave.getName() << ", grade: " << dave.getGrade() << std::endl;
        dave.decrGrade();
        std::cout << "After decrement: " << dave.getGrade() << std::endl;
        dave.decrGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught (Dave): " << e.what() << std::endl;
    }

    return 0;
}

