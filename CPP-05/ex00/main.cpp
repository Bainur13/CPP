#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	bur_def;

	std::cout << "Basic Bureaucrat" << std::endl;
	std::cout << bur_def << std::endl;
	Bureaucrat bur_top("Patrick", 1);
	std::cout << bur_top << std::endl;
	try
	{
		std::cout << "Test increase Patrick rank" << std::endl;
		bur_top.inc_grade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << bur_top << std::endl;
	Bureaucrat bur_bot("Michael", 150);
	std::cout << bur_bot;
	try
	{
		std::cout << "Test decrease Michael rank" << std::endl;
		bur_bot.dec_grade();
	}
	catch (std::exception &e)
	{
		std::cout  << e.what() << std::endl;
	}
	std::cout << bur_bot << std::endl;
	try
	{
		std::cout << "Test decrease Patrick rank" << std::endl;
		bur_top.dec_grade();
	}
	catch (std::exception &e)
	{
		std::cout<< e.what() << std::endl;
	}
	std::cout << bur_top << std::endl;
	try
	{
		std::cout << "Test increase Michael rank" << std::endl;
		bur_bot.inc_grade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << bur_bot << std::endl;
}
