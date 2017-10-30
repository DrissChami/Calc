#include "boucle.h"

Pour::Pour(Expression *init, Expression *cond, Expression *inc, Expression *calc) :
    Expression("for"), _init(init), _condition(cond), _incremente(inc), _calcul(calc)
{
    // Reste des méthodes définies dans le .h
}
