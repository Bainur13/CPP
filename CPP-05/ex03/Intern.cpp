#include "Intern.hpp"

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

AForm *Intern::makeForm(std::string type, std::string target)
{
    int i;
    std::string types[3] = {"presidential pardon request", "robotomy request", "shrubbery form"};
    AForm
    for (i = 0; i <= 3; i++)
    {
        if (i == 3 || type == types[i])
            break;
    }
    switch (i)
    {
    case 0:
        std::cout << "Intern creates " << types[i] << std::endl;
        return (new PresidentialPardonForm(target));
    case 1:
        std::cout << "Intern creates " << types[i] << std::endl;
        return (new RobotomyRequestForm(target));
    case 2:
        std::cout << "Intern creates " << types[i] << std::endl;
        return (new ShrubberyCreationForm(target));
    case 3:
        throw std::runtime_error("Invalid Form Name");
    default:
        throw std::runtime_error("Invalid Form Name");
    }
}