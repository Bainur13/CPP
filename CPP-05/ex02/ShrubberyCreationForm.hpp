#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <exception>
# include <iostream>
# include <string>
# include <fstream>
# include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{
  public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &to_cpy);

    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &to_cpy);

    ~ShrubberyCreationForm();

    void executeForm(Bureaucrat const &executor) const;

    void set_target(std::string target);

  private:
    std::string _target;
};

#endif
