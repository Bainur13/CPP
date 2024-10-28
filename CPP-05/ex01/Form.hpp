#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
  public:
	Form();
	Form(std::string name, int req_grade_s, int req_grade_x);
	Form(const Form &to_cpy);

	Form &operator=(const Form &to_cpy);

	~Form();

    void be_signed(Bureaucrat const &bur);

	std::string get_name() const;
	bool get_status() const;
	int get_req_grade_s() const;
	int get_req_grade_x() const;

    void GradeCheckThrow(int grade, int required);
	void GradeTooHighException();
	void GradeTooLowException();

  private:
	std::string const _name;
	bool _signed;
	const int _req_grade_s;
	const int _req_grade_x;
};

std::ostream &operator<<(std::ostream &o, Form const &cur);

#endif
