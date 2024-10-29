#include "ShrubberyCreationForm.hpp"

ShruberryCreationForm::ShruberryCreationForm() : AForm("ShruberryCreationForm", 145, 137), _target("default")
{
}
ShruberryCreationForm::ShruberryCreationForm(std::string target) : AForm("ShruberryCreationForm", 145, 137), _target(target)
{
}

ShruberryCreationForm::ShruberryCreationForm(const ShruberryCreationForm &to_cpy) : AForm(to_cpy.get_name(), to_cpy.get_req_grade_s(), to_cpy.get_req_grade_x()), _target(to_cpy._target)
{
}

ShruberryCreationForm &ShruberryCreationForm::operator=(const ShruberryCreationForm &to_cpy)
{
    _target = to_cpy._target;
    return (*this);
}

ShruberryCreationForm::~ShruberryCreationForm()
{
}

void ShruberryCreationForm::execute(Bureaucrat const &executor) const
{
    if (!get_status())
        FormNotSignedException();
    if (executor.get_grade() > get_req_grade_x())
        GradeTooLowException();
    std::ofstream file;
    std::string filename = _target + "_shrubbery";
    file.open(filename.c_str());
    file << "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\n";
    file.close();
}

void ShruberryCreationForm::set_target(std::string target)
{
    _target = target;
}
