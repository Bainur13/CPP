#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <string>

class	AForm;

class RobotomyRequestForm : public AForm
{
  public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &to_cpy);

	RobotomyRequestForm &operator=(const RobotomyRequestForm &to_cpy);

	~RobotomyRequestForm();

	void executeForm(Bureaucrat const &executor) const;

	void set_target(std::string target);

  private:
	std::string _target;
};

#endif
