#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat {
    private:
        std::string const _name;
        int _grade;

    public:
        Bureaucrat(void);
        Bureaucrat(std::string const& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        virtual ~Bureaucrat(void);

        std::string const& getName() const;
        int getGrade() const;

        void    incrementGrade();
        void    decrementGrade();

        
        class GradeTooHighException : public std::exception {
            public:
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
    };
    
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);


#endif