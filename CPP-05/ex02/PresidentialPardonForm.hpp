#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <string>


class	AForm;

class PresidentialPardonForm : public AForm
{
  public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &to_cpy);

    PresidentialPardonForm &operator=(const PresidentialPardonForm &to_cpy);

    ~PresidentialPardonForm();

    void execute(Bureaucrat const &executor) const;

    void set_target(std::string target);

  private:
    std::string _target;
};

#endif