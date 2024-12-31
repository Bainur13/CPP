#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
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
	GradeCheckThrow(_grade - 1);
	_grade--;
}

void Bureaucrat::dec_grade()
{
	GradeCheckThrow(_grade + 1);
	_grade++;
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

void Bureaucrat::signForm(Form &to_sign)
{
	if (to_sign.get_status() == 1)
	{
		std::cout << _name << " couldn't sign " << to_sign.get_name() << ", the form is already signed." << std::endl;
		return ;
	}
	if (_grade <= to_sign.get_req_grade_s())
	{
		to_sign.be_signed(*this);
		std::cout << _name << " signed " << to_sign.get_name() << "." << std::endl;
	}
	else
		std::cout << _name << " couldn't sign " << to_sign.get_name() << " because rank to low." << std::endl;
}

void Bureaucrat::execForm(Form &to_exec)
{
	if (_grade > to_exec.get_req_grade_x())
		std::cout << _name << " execute " << to_exec.get_name() << "." << std::endl;
	else
		std::cout << _name << " couldn't execute " << to_exec.get_name() << " because rank to low." << std::endl;
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
	o << cur.get_name() << ", bureaucrat grade " << cur.get_grade() << "." << std::endl;
	return (o);
}
