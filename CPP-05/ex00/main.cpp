#include "Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat();
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << *a;

		try // in my opinion would make more sense if the try-catch blocks would have been inside the class itself already
		{
		a->inc_grade();
		}
		catch(Bureaucrat::GradeTooHighException &e) // the try-catch blocks inside the class are commented out but fully functional
		{
			std::cerr << "\033[33mIncrementing grade of " << a->get_name() <<
			" failed: " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << *a;

		try
		{
		a->dec_grade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33mDecrementing grade of " << a->get_name() <<
			" failed: " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << *a;

		try
		{
		a->dec_grade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33mDecrementing grade of " << a->get_name() <<
			" failed: " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << *a;
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Michael", 1);
		std::cout << std::endl;
		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << *a;

		try
		{
		a->dec_grade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33mDecrementing grade of " << a->get_name() <<
			" failed: " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << *a;

		try
		{
		a->inc_grade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "\033[33mIncrementing grade of " << a->get_name() <<
			" failed: " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << *a;

		try
		{
		a->inc_grade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "\033[33mIncrementing grade of " << a->get_name() <<
			" failed: " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << *a;
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = NULL;

		try
		{
			a = new Bureaucrat("John", 0);
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " <<
			e.what() << "\033[0m" << std::endl;
		}

		if (a != NULL)
		{
			std::cout << std::endl;

			std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
			delete a;
		}

		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = NULL;

		try
		{
			a = new Bureaucrat("Patrick" ,160);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " <<
			e.what() << "\033[0m" << std::endl;
		}

		if (a != NULL)
		{
			std::cout << std::endl;
			std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
			delete a;
		}
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Peter", 120);
		std::cout << std::endl;

		std::cout << "\033[34mTesting a\033[0m" << std::endl;
		std::cout << *a;

		a->dec_grade();

		std::cout << *a;
		std::cout << std::endl;

		std::cout << "\033[34mConstructing b\033[0m" << std::endl;
		Bureaucrat *b = new Bureaucrat(*a);
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing a\033[0m" << std::endl;
		delete a;
		std::cout << std::endl;

		std::cout << "\033[34mTesting b\033[0m" << std::endl;
		std::cout << *b;
		b->dec_grade();
		std::cout << *b;
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
		delete b;

		std::cout << std::endl;
	}
}
