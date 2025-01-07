#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
  public:
	AForm();
	AForm(std::string name, int req_grade_s, int req_grade_x);
	AForm(const AForm &to_cpy);

	AForm &operator=(const AForm &to_cpy);

	virtual ~AForm();

    void be_signed(Bureaucrat const &bur);

	std::string get_name() const;
	virtual bool get_status() const;
	int get_req_grade_s() const;
	int get_req_grade_x() const;

   	void GradeCheckThrow(int grade, int required);
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	void execute(Bureaucrat const &executor) const;
	virtual void executeForm(Bureaucrat const &executor) const = 0;


  private:
	std::string const _name;
	bool _signed;
	const int _req_grade_s;
	const int _req_grade_x;
};

std::ostream &operator<<(std::ostream &o, AForm const &cur);

#endif
