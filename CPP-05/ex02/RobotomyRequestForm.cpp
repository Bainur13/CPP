#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &to_cpy) : AForm(to_cpy.get_name(), to_cpy.get_req_grade_s(), to_cpy.get_req_grade_x()), _target(to_cpy._target)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &to_cpy)
{
    _target = to_cpy._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const{
    int random = rand();
    if (!get_status())
        FormNotSignedException();
    if (executor.get_grade() > get_req_grade_x())
        GradeTooLowException();
    if (random % 2 == 0 )
    {
    std::cout << "DRRRRRRRRRRRRRRRRRRRRRRRRRRRR" << std::endl;
    std::cout << _target << " has been robotomized" << std::endl;
    }
    else 
    {
        std::cout << "Robotomized FAILED" << std::cout;
    }
}
