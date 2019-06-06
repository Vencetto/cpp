//
// Created by Volodymyr ZOMBER on 2019-01-21.
//

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

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

					Form();
					Form(std::string name, int gradeToSign, int gradeToExec);
					Form(Form const & src);
					~Form();
	Form			&operator=(Form const & src);

	const int		getGradeToSign() const;
	const int		getGradeToExec() const ;
	const std::string	getName() const;

	void			beSigned(Bureaucrat const &src);


private:

	const std::string	_name;
	bool				_sign;
	const int			_gradeToSign;
	const int			_gradeToExec;

};

std::ostream & operator<<( std::ostream & o, Form const & src );

#endif //FORM_HPP
