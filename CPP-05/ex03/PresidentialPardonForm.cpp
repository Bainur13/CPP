# include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &to_cpy) : AForm(to_cpy.get_name(), to_cpy.get_req_grade_s(), to_cpy.get_req_grade_x()), _target(to_cpy._target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &to_cpy)
{
    _target = to_cpy._target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!get_status())
        FormNotSignedException();
    if (executor.get_grade() > get_req_grade_x())
        GradeTooLowException();
    std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

void PresidentialPardonForm::set_target(std::string target)
{
    _target = target;
}