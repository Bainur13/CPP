#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern &to_cpy);

    Intern &operator=(const Intern &to_cpy);
    
    ~Intern();

    AForm *makeForm(std::string type, std::string target);
};

#endif