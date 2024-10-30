#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
    srand(time(0));
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    srand(time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &to_cpy) : AForm(to_cpy.get_name(), to_cpy.get_req_grade_s(), to_cpy.get_req_grade_x()), _target(to_cpy._target)
{
    srand(time(0));
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &to_cpy)
{
    _target = to_cpy._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    int random = rand();
    if (!get_status())
        FormNotSignedException();
    if (executor.get_grade() > get_req_grade_x())
        GradeTooLowException();
    std::cout << random << std::endl;
    if (random % 2 == 0)
    {
        std::cout << "DRRRRRRRRRRRRRRRRRRRRRRRRRRRR" << std::endl;
        std::cout << _target << " has been robotomized" << std::endl;
    }
    else
    {
        std::cout << "Robotomy FAILED" << std::endl;
    }
}

void RobotomyRequestForm::set_target(std::string target)
{
    _target = target;
}
