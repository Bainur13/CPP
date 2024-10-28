#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Form	form;

	try
	{
		std::cout << "Basic Form" << std::endl;
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	try
	{
		std::cout << "Important Form" << std::endl;
		Form strong("Important", 1, 1);
		std::cout << form;
        Bureaucrat bur("John", 10);
        bur.signForm(strong);
        std::cout << strong << std::endl;
	}
    catch (std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
    try
	{
		std::cout << "Important Form" << std::endl;
		Form strong("Important", 1, 1);
		std::cout << form;
        Bureaucrat bur("Patrick", 1);
        bur.signForm(strong);
        std::cout << strong << std::endl;
	}
    catch (std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl; 
	}
    try
	{
		std::cout << "Important Form" << std::endl;
		Form strong("Important", 1, 1);
		std::cout << form;
        Bureaucrat bur("Patrick", 1);
        bur.signForm(strong);
        std::cout << strong;
        bur.signForm(strong);
        std::cout << strong << std::endl;
	}
    catch (std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
    try
    {
        std::cout << "Not so important Form" << std::endl;
        Form weak("Not so important", 150, 150);
        std::cout << form;
        Bureaucrat bur("John", 150);
        bur.signForm(weak);
        std::cout << weak << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl << std::endl;
    }

    try
    {
        std::cout << "Incorrect Form" << std::endl;
        Form incorrect("Incorrect", 0, 0);
        std::cout << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl << std::endl;
    }
    try
    {
        std::cout << "Incorrect Form" << std::endl;
        Form incorrect("Incorrect", 151, 151);
        std::cout << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl << std::endl;
    }
}

