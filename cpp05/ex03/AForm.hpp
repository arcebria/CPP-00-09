#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class   Bureaucrat;

class AForm {
	private:
		std::string const _name;
		bool    _isSigned;
		int const _signGrade;
		int const _executeGrade;
	public:

		AForm();
		AForm(std::string const& name, int const signGrade, int const executeGrade);
		AForm(const AForm& other);
		virtual ~AForm();
		AForm& operator=(const AForm& other);

		std::string const& getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void    beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class	FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};

		virtual void execute(const Bureaucrat& executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif