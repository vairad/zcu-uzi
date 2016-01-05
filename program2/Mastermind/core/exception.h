#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

/**
 * Výjimka, ktrá symbolizuje chybu špatné inicializace řešitele úlohy.
 * Konkrétně špatný počet hádaných míst.
 *
 * @author Radek VAIS - A13B0457P
 * 4.1.2016
 * @version verze 1.0.0
 */
class WrongCountException : public std::exception
{
  public:
  virtual const char* what() const throw()
  {
    return "Wrong number of guessed colors.";
  }
};



#endif // EXCEPTION_H

