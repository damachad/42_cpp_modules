# Bureaucrats and forms
In this module, the classes **Bureaucrat** and **Form** are implemented, simulating some behaviours one would expect from this entities, such as having a grade, a name, member funtions to sign/execute forms or to be signed/executed, etc.
Three derived classes are implemented, that inherit from the **AForm** class: **ShrubberyCreationForm**, **RobotomyRequestForm** and **PresidentialPardonForm**.
Each has their ```execute()``` function, with a different behavior.   
Finally, an **Intern** class is implemented, that has the capacity to return an instance of the requested form, with its given target.   
Throughout the implementation of these classes, exceptions are used to handle the cases which are considered invalid. For example, attempting to execute a Form without it being previously signed.   

General use of try, catch and throw to handle exceptions:
```
try {
  // Block of code to try
  throw exception; // Throw an exception when a problem arise
}
catch () {
  // Block of code to handle errors
}
```
You can learn more about C++ exceptions [here](https://www.w3schools.com/cpp/cpp_exceptions.asp).
