#include "Form.hpp"

Form::Form() : _name("Basic"), _signed(false), _req_grade_s(150),
	_req_grade_x(150)
{
}

Form::Form(std::string name, int req_grade_s, int req_grade_x) : _name(name),
	_signed(false), _req_grade_s(req_grade_s), _req_grade_x(req_grade_x)
{
	if (_req_grade_s > 150 || _req_grade_x > 150)
        GradeTooLowException();
    if (_req_grade_s < 1 || _req_grade_x < 1)
        GradeTooHighException();
}
Form::Form(const Form &to_cpy) : _name(to_cpy._name), _signed(to_cpy._signed),
	_req_grade_s(to_cpy._req_grade_s), _req_grade_x(to_cpy._req_grade_x)
{
}

Form &Form::operator=(const Form &to_cpy)
{
    _signed = to_cpy.get_status();
    return (*this);
}

Form::~Form()
{
}

void Form::be_signed(Bureaucrat const &bur)
{
    GradeCheckThrow(bur.get_grade(), _req_grade_s);
	_signed = true;
}

std::string Form::get_name() const
{
	return (_name);
}

bool Form::get_status() const
{
    return (_signed);
}

int Form::get_req_grade_s() const
{
    return (_req_grade_s);
}

int Form::get_req_grade_x() const
{
    return (_req_grade_x);
}

void Form::GradeCheckThrow(int grade, int required)
{
    if (grade > required)
        throw Bureaucrat::GradeTooLowException();
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

std::ostream &operator<<(std::ostream &o, Form const &cur)
{
    o << "Form <" << cur.get_name() << "> is ";
    if (cur.get_status())
        o << "signed";
    else
        o << "not signed";
    o << ", it requires " << cur.get_req_grade_s() << " to be signed and ";
    o << cur.get_req_grade_x() << " to be executed." << std::endl;
    return (o);
}

