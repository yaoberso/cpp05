
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

    // ─────────────── Bureaucrats ───────────────
    Bureaucrat alice("Alice", 1);   // Très haut grade
    Bureaucrat bob("Bob", 150);     // Très bas grade

    // ─────────────── Forms ───────────────
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

    bob.signForm(shrub);   // doit échouer
    bob.signForm(robo);    // doit échouer
    bob.signForm(pardon);  // doit échouer

    std::cout << "\n--- Status des formulaires après signature ---\n";
    std::cout << shrub << std::endl;
    std::cout << robo << std::endl;
    std::cout << pardon << std::endl;

    std::cout << "\n--- Tentatives d'exécution ---\n";
    alice.executeForm(shrub);
    alice.executeForm(robo);
    alice.executeForm(pardon);

    bob.executeForm(shrub);   // doit échouer
    bob.executeForm(robo);    // doit échouer
    bob.executeForm(pardon);  // doit échouer

    return 0;
}




