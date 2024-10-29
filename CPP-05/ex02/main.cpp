#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
    Bureaucrat bob("Bob", 1);
    Bureaucrat jim("Jim", 150);
    ShruberryCreationForm form("home");

    std::cout << bob << std::endl;
    std::cout << jim << std::endl;

    bob.signForm(form);

    bob.executeForm(form);

    return (0);
}

