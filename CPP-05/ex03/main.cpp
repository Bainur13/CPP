#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int	main(void)
{
    try
    {
    Intern someRandomIntern;
    AForm* rrf;
    Bureaucrat n1("Albert", 41);
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    rrf->be_signed(n1);
    
    rrf->execute(n1);
    delete(rrf);
    
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

