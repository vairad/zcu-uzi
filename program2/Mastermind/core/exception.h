#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

class WrongCountException : public std::exception
{
  virtual const char* what() const throw()
  {
    return "Wrong number of guessed colors.";
  }
};



#endif // EXCEPTION_H

