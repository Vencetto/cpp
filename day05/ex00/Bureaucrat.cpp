
# include "Bureaucrat.hpp"
# include <stdexcept>

/*________Coplien's form_________*/

Bureaucrat::Bureaucrat() : _grade(150), _name("Casual") {}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name) {
	*this = src;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &src) {
	if (this != &src)
	{
		this->_grade = src.getGrade();
	}
	return *this;
}

/*______getters______*/

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

/*__________methods_________*/

Bureaucrat::Bureaucrat(int grade, std::string name) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

void Bureaucrat::incGrade() {
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade += 1;
}

void Bureaucrat::decGrade() {
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade -= 1;
}

/*_______Overload________*/

std::ostream & operator<< (std::ostream & o, Bureaucrat const & src) {
	o << '<' + src.getName() + ">, bureaucrat grade " << src.getGrade();
	return o;
}

/*_________________GradeTooHighException___________________*/

Bureaucrat::GradeTooHighException::GradeTooHighException() {}

Bureaucrat::GradeTooHighException::GradeTooHighException(const Bureaucrat::GradeTooHighException &src) {
	*this = src;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

Bureaucrat::GradeTooHighException& Bureaucrat::GradeTooHighException::operator=(const Bureaucrat::GradeTooHighException &src) {
	(void)src;
	return *this;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high.";
}

/*_________________GradeTooLowException___________________*/

Bureaucrat::GradeTooLowException::GradeTooLowException() {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const Bureaucrat::GradeTooLowException &src) {
	*this = src;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

Bureaucrat::GradeTooLowException& Bureaucrat::GradeTooLowException::operator=(const Bureaucrat::GradeTooLowException &src) {
	(void)src;
	return *this;
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low.";
}