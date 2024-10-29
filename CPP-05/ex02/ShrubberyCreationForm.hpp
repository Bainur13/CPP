#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

# include <exception>
# include <iostream>
# include <string>
# include <fstream>
# include "AForm.hpp"

class AForm;

class ShruberryCreationForm : public AForm
{
  public:
    ShruberryCreationForm();
    ShruberryCreationForm(std::string target);
    ShruberryCreationForm(const ShruberryCreationForm &to_cpy);

    ShruberryCreationForm &operator=(const ShruberryCreationForm &to_cpy);

    ~ShruberryCreationForm();

    void execute(Bureaucrat const &executor) const;

    void set_target(std::string target);

  private:
    std::string _target;
};

#endif
