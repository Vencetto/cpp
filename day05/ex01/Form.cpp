//
// Created by Volodymyr ZOMBER on 2019-01-21.
//

#include <curses.h>
#include "Form.hpp"

Form::Form() : _sign(FALSE), _name("FormDefault"), _gradeToSign(0), _gradeToExec(1) {}

Form::Form(std::string name, int gradeToSign, int gradeToExec) :
_name(name), _sign(FALSE), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
}

Form::Form(Form const &src) :
_name(src._name), _sign(src._sign), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {
	*this = src;
}

Form::~Form() {}

Form& Form::operator=(Form const &src) {
	if (this != &src)
	{
		this->_sign = src._sign;
	}
	return *this;
}

/*_________________GradeTooHighException___________________*/

Form::GradeTooHighException::GradeTooHighException() {}

Form::GradeTooHighException::GradeTooHighException(const Form::GradeTooHighException &src) {
	*this = src;
}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooHighException& Form::GradeTooHighException::operator=(const Form::GradeTooHighException &src) {
	(void)src;
	return *this;
}

const char	*Form::GradeTooHighException::what() const throw() {
	return "Grade too high.";
}

/*_________________GradeTooLowException___________________*/

Form::GradeTooLowException::GradeTooLowException() {}

Form::GradeTooLowException::GradeTooLowException(const Form::GradeTooLowException &src) {
	*this = src;
}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

Form::GradeTooLowException& Form::GradeTooLowException::operator=(const Form::GradeTooLowException &src) {
	(void)src;
	return *this;
}

const char	*Form::GradeTooLowException::what() const throw() {
	return "Grade too low.";
}

/*_____________________GETTERS______________________________*/

const int Form::getGradeToExec() const {
	return _gradeToExec;
}

const int Form::getGradeToSign() const {
	return _gradeToSign;
}
const std::string Form::getName() const {
	return _name;
}

/*________________________Overload______________________________*/

std::ostream & operator<< (std::ostream & o, Form const & src) {
	o << '<' + src.getName() + "> form, grade to sign:" << src.getGradeToSign();
	o << " , grade to execute:" << src.getGradeToExec();
	return o;
}

void Form::beSigned(Bureaucrat const &src) {
	if (src.getGrade() <= getGradeToSign())
		this->_sign = true;
	else
		throw Form::GradeTooLowException();
}