#ifndef BINAIRE_H
#define BINAIRE_H


#include "Expression.h"

class Binaire : public Expression
{
protected:
    Expression *_opleft, *_opright;
public:
    Binaire(const string& nom, Expression* left, Expression* right);
    virtual double eval() const = 0;
    virtual string str() const
    {
        return "(" + _opleft->str() + " " + _nom + " " + _opright->str() + ")";
    }
};



class Somme : public Binaire
{
public:
    Somme(Expression* left, Expression* right) : Binaire("+", left, right) {}
    double eval() const
    {
        return _opleft->eval() + _opright->eval();
    }
};

class Superieur : public Binaire
{
public:
    Superieur(Expression* left, Expression* right) : Binaire(">", left, right) {}
    double eval() const
    {
        return (double)(_opleft->eval() > _opright->eval());
    }
};

class Produit : public Binaire
{
public :
    Produit(Expression* left, Expression* right) : Binaire("*", left, right) {}

    double eval() const
    {

        return _opleft->eval() *  _opright->eval();
    }
};

class InferieurEgal : public Binaire
{
public :
    InferieurEgal(Expression* left, Expression* right) : Binaire ("<=", left, right) {}
    double eval() const
    {
        return (double)(_opleft->eval() <= _opright->eval());
    }
};




/*
class binaire
{
    public:
        binaire();
        virtual ~binaire();
    protected:
    private:
};
*/
#endif // BINAIRE_H
