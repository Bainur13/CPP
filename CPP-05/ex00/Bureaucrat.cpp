#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	// try
	// {
		if (grade >= 1 && grade <= 150)
			_grade = grade;
		else
		{
			if (grade < 1)
				_grade = 1;
			else
				_grade = 150;
			GradeCheckThrow(grade);
		}
	//}
	// catch (std::exception &e)
	// {
	// 	std::cerr << "Caught an exception: " << e.what() << std::endl;
	// }
}

Bureaucrat::Bureaucrat(const Bureaucrat &to_cpy) : _name(to_cpy.get_name())
{
	_grade = to_cpy.get_grade();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &to_cpy)
{
	_grade = to_cpy.get_grade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

void Bureaucrat::inc_grade()
{
	// try
	// {
		GradeCheckThrow(_grade - 1);
		_grade--;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cerr << "Caught an exception: " << e.what() << std::endl;
	// }
}

void Bureaucrat::dec_grade()
{
    // try
    // {
		GradeCheckThrow(_grade + 1);
        _grade++;
    // }
    // catch (std::exception &e)
    // {
	// 	std::cerr << "Caught an exception: " << e.what() << std::endl;
    // }
}

void Bureaucrat::GradeCheckThrow(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

std::string Bureaucrat::get_name() const
{
	return (_name);
}

int Bureaucrat::get_grade() const
{
	return (_grade);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &cur)
{
    o << cur.get_name() <<  ", bureaucrat grade " << cur.get_grade() << "." << std::endl;
    return (o);
}
