#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>

class Bureaucrat
{
  public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &to_cpy);

	Bureaucrat &operator=(const Bureaucrat &to_cpy);

	~Bureaucrat();

	std::string get_name() const;
    int get_grade() const;

	void inc_grade();
	void dec_grade();

	void GradeCheckThrow(int grade);
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

  private:
	std::string const _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &cur);

#endif
