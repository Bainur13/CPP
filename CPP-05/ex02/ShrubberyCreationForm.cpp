#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &to_cpy) : AForm(to_cpy.get_name(), to_cpy.get_req_grade_s(), to_cpy.get_req_grade_x()), _target(to_cpy._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &to_cpy)
{
    _target = to_cpy._target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!get_status())
        throw AForm::FormNotSignedException();
    if (executor.get_grade() > get_req_grade_x())
        throw Bureaucrat::GradeTooLowException();
    std::ofstream file;
    std::string filename = _target + "_shrubbery";
    file.open(filename.c_str());
    file << "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\n";
    file.close();
}

void ShrubberyCreationForm::set_target(std::string target)
{
    _target = target;
}
