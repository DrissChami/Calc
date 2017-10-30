#ifndef VARIABLE_H
#define VARIABLE_H



#include "binaire.h"

class Variable : public Expression
{
public:
    Variable(const string& nom);
    Variable(const string& nom, double init);
    /* retourne la valeur de la variable dont le nom est dans _nom
    si _nom n'est pas trouve dans _memoire alors une nouvelle variable
    est cree avec la valeur 0.0 qui est retournee */
    double eval() const
    {
        return _memoire[_nom];
    }
    double set(double val)
    {
        _memoire[_nom] = val;
        return val;
    }
private:
    /*ensemble des variable sous la forme d'un tableau
    associatif : la cle est le nom de la variable stockee */
    static map<string,double> _memoire;
public:
    /* vide completement le tableau associatif _memoire */
    static void effacerMemoire()
    {
        _memoire.clear();
    }
};
class Affectation : public Binaire
{
public:
    Affectation(Variable* var, Expression* exp) : Binaire("<-", var, exp) {}
    double eval() const
    {
        return ((Variable*)_opleft)->set(_opright->eval());
    }
};





/*
class variable
{
    public:
        variable();
        virtual ~variable();
    protected:
    private:
};
*/
#endif // VARIABLE_H
