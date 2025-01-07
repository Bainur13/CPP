#include "AForm.hpp"

AForm::AForm() : _name("Basic"), _signed(false), _req_grade_s(150),
	_req_grade_x(150)
{
}

AForm::AForm(std::string name, int req_grade_s, int req_grade_x) : _name(name),
	_signed(false), _req_grade_s(req_grade_s), _req_grade_x(req_grade_x)
{
	if (_req_grade_s > 150 || _req_grade_x > 150)
        GradeTooLowException();
    if (_req_grade_s < 1 || _req_grade_x < 1)
        GradeTooHighException();
}

AForm::AForm(const AForm &to_cpy) : _name(to_cpy._name), _signed(to_cpy._signed),
	_req_grade_s(to_cpy._req_grade_s), _req_grade_x(to_cpy._req_grade_x)
{
}

AForm &AForm::operator=(const AForm &to_cpy)
{
    _signed = to_cpy.get_status();
    return (*this);
}

AForm::~AForm()
{
}

void AForm::be_signed(Bureaucrat const &bur)
{
    GradeCheckThrow(bur.get_grade(), _req_grade_s);
	_signed = true;
}

std::string AForm::get_name() const
{
	return (_name);
}

bool AForm::get_status() const
{
    return (_signed);
}

int AForm::get_req_grade_s() const
{
    return (_req_grade_s);
}

int AForm::get_req_grade_x() const
{
    return (_req_grade_x);
}

void AForm::GradeCheckThrow(int grade, int required)
{
    if (grade > required)
        throw Bureaucrat::GradeTooLowException();
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}
const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("Not signed");
}

std::ostream &operator<<(std::ostream &o, AForm const &cur)
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

void AForm::execute(Bureaucrat const &executor) const
{
    this->executeForm(executor);
}

