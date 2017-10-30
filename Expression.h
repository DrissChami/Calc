#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "binaire.h"

#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include "binaire.h"

using namespace std;

/* retourne une valeur reelle (val) sous forme de chaine de caracteres */
string string_from_double(double val)
{
    ostringstream os;
    os << val;
    return os.str();
}


class Expression
{
protected:
    string _nom;
private:
    static set<Expression*> _pool;
public:
    /* applique itérativement l'operateur delete au premier element
    du pool tant que le pool n’est pas vide */
    static void toutLiberer()
    {
        set<Expression*>::iterator it;
        while ( (it = _pool.begin()) != _pool.end() )
            delete (*it);
    }
public:
    Expression(const string& nom) : _nom(nom);

        virtual ~Expression();

        virtual double eval() const = 0;
        virtual string str() const
    {
        return _nom;
    }
    friend ostream& operator<<(ostream& os, const Expression& exp)
    {
        return os << exp.str();
    }
};


class Constante : public Expression
{
    double _value;
public:
    Constante(double val) : Expression(string_from_double(val)), _value(val) {}
    virtual double eval() const
    {
        return _value;
    }
};

class Unaire : public Expression
{
protected:
    Expression *_op;
public:
    Unaire(const string& nom, Expression* op) : Expression(nom), _op(op) {}
    virtual double eval() const = 0;
    virtual string str() const
    {
        return _nom + "(" + _op->str() + ")";
    }
};


class Cos : public Unaire
{
public:
    Cos(Expression* op) : Unaire("cos", op) {}
    double eval() const
    {
        return cos(_op->eval());
    }
};


class Sin : public Unaire
{
public:
    Sin(Expression* op) : Unaire("sin", op) {}
    double eval() const
    {
        return sin(_op->eval());
    }
};



#endif // EXPRESSION_H
