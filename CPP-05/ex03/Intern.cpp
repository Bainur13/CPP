#include "Intern.hpp"
#include <iostream>
#include <stdexcept>

typedef AForm* (*FormCreator)(const std::string &target);

Intern::Intern() {}

Intern::Intern(const Intern &to_cpy)
{
    *this = to_cpy;
}

Intern &Intern::operator=(const Intern &to_cpy)
{
    if (this != &to_cpy)
        return *this;
    return (*this);
}

Intern::~Intern() {}

AForm* createPresidentialPardonForm(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm* createRobotomyRequestForm(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm* createShrubberyCreationForm(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string type, std::string target)
{
    std::string types[3] = {"presidential pardon request", "robotomy request", "shrubbery form"};
    FormCreator creators[3] = {createPresidentialPardonForm, createRobotomyRequestForm, createShrubberyCreationForm};

    for (int i = 0; i < 3; i++) {
        if (type == types[i]) {
            std::cout << "Intern creates " << types[i] << std::endl;
            return creators[i](target);
        }
    }
    throw std::runtime_error("Invalid Form Name");
}
