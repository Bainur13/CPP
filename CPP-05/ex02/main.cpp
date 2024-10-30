
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
    try
    {
        Bureaucrat b1("b1", 1);
        Bureaucrat b2("b2", 150);
        ShrubberyCreationForm f1("f1");
        b1.signForm(f1);
        b1.executeForm(f1);
        b2.signForm(f1);
        b2.executeForm(f1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat b1("b1", 1);
        Bureaucrat b2("b2", 150);
        PresidentialPardonForm f2("f2");
        b1.signForm(f2);
        b1.executeForm(f2);
        b2.signForm(f2);
        b2.executeForm(f2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat b1("b1", 1);
        Bureaucrat b2("b2", 150);
        RobotomyRequestForm f3("f3");
        b1.signForm(f3);
        b1.executeForm(f3);
        b2.signForm(f3);
        b2.executeForm(f3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    return (0);


}

