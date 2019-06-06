
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat {

public:
	class GradeTooHighException : public std::exception {
	public:
		GradeTooHighException();
		GradeTooHighException(GradeTooHighException const & src);
		~GradeTooHighException() throw();
		GradeTooHighException & operator=(GradeTooHighException const & src);
		virtual const char	*  what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		GradeTooLowException();
		GradeTooLowException(GradeTooLowException const & src);
		~GradeTooLowException() throw();
		GradeTooLowException & operator=(GradeTooLowException const & src);
		virtual const char	*  what() const throw();
	};

	Bureaucrat();
	Bureaucrat(int grade, std::string name);
	Bureaucrat(Bureaucrat const & src);
	~Bureaucrat();
	Bureaucrat & operator=(Bureaucrat const & src);

	std::string		getName() const;
	int				getGrade() const ;
	void			incGrade();
	void			decGrade();

	void			signForm(Form & form) const;

private:

	const std::string	_name;
	int					_grade;

};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & src );

#endif
