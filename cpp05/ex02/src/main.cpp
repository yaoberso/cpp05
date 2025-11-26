
#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    std::srand(std::time(nullptr)); // pour RobotomyRequestForm
    Bureaucrat alice("Alice", 1);   // Très haut grade
    Bureaucrat bob("Bob", 150);     // Très bas grade
    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robo("Bender");
    PresidentialPardonForm pardon("Marvin");

    std::cout << "\n--- Status des formulaires avant signature ---\n";
    std::cout << shrub << std::endl;
    std::cout << robo << std::endl;
    std::cout << pardon << std::endl;

    std::cout << "\n--- Tentatives de signature ---\n";
    alice.signForm(shrub);
    alice.signForm(robo);
    alice.signForm(pardon);

    bob.signForm(shrub);
    bob.signForm(robo);
    bob.signForm(pardon);

    std::cout << "\n--- Status des formulaires après signature ---\n";
    std::cout << shrub << std::endl;
    std::cout << robo << std::endl;
    std::cout << pardon << std::endl;

    std::cout << "\n--- Tentatives d'exécution ---\n";
    alice.executeForm(shrub);
    alice.executeForm(robo);
    alice.executeForm(pardon);

    bob.executeForm(shrub);
    bob.executeForm(robo);
    bob.executeForm(pardon);

    return 0;
}




