#include "Action.h"
#include "Litteral.h"
#include<iostream>
#include<math.h>

map<tuple<string, LitType, LitType>, Action*> Action::getActions()
{
    map <tuple<string, LitType, LitType>, Action*> actions;
    pair<tuple<string, LitType, LitType>, Action*> entry;
    tuple<string, LitType, LitType> t;

    //Action Addition
    t = make_tuple("+", INTLIT, INTLIT);
    entry.first = t;
    entry.second = new PlusSimpleAction();
    actions.insert(entry);

    t = make_tuple("+", REALLIT, INTLIT);
    entry.first = t;
    entry.second = new PlusSimpleAction();
    actions.insert(entry);

    t = make_tuple("+", REALLIT, REALLIT);
    entry.first = t;
    entry.second = new PlusSimpleAction();
    actions.insert(entry);

    t = make_tuple("+", RATIONALLIT, REALLIT);
    entry.first = t;
    entry.second = new PlusSimpleAction();
    actions.insert(entry);

    t = make_tuple("+", RATIONALLIT, RATIONALLIT);
    entry.first = t;
    entry.second = new PlusRatRatAction();
    actions.insert(entry);

    t = make_tuple("+", RATIONALLIT, INTLIT);
    entry.first = t;
    entry.second = new PlusRatIntAction();
    actions.insert(entry);

    //Action Mutliplication
     t = make_tuple("*", INTLIT, INTLIT);
    entry.first = t;
    entry.second = new MulSimpleAction();
    actions.insert(entry);

    t = make_tuple("*", REALLIT, INTLIT);
    entry.first = t;
    entry.second = new MulSimpleAction();
    actions.insert(entry);

    t = make_tuple("*", REALLIT, REALLIT);
    entry.first = t;
    entry.second = new MulSimpleAction();
    actions.insert(entry);

    t = make_tuple("*", RATIONALLIT, REALLIT);
    entry.first = t;
    entry.second = new MulSimpleAction();
    actions.insert(entry);

    t = make_tuple("*", RATIONALLIT, RATIONALLIT);
    entry.first = t;
    entry.second = new MulRatRatAction();
    actions.insert(entry);

    t = make_tuple("*", RATIONALLIT, INTLIT);
    entry.first = t;
    entry.second = new MulRatIntAction();
    actions.insert(entry);


    //Actions Soustraction
    t = make_tuple("-", INTLIT, INTLIT);
    entry.first = t;
    entry.second = new MoinsSimpleAction();
    actions.insert(entry);

    t = make_tuple("-", REALLIT, INTLIT);
    entry.first = t;
    entry.second = new MoinsSimpleAction();
    actions.insert(entry);

    t = make_tuple("-", INTLIT, REALLIT);
    entry.first = t;
    entry.second = new MoinsSimpleAction();
    actions.insert(entry);

    t = make_tuple("-", REALLIT, REALLIT);
    entry.first = t;
    entry.second = new MoinsSimpleAction();
    actions.insert(entry);

    t = make_tuple("-", RATIONALLIT, REALLIT);
    entry.first = t;
    entry.second = new MoinsSimpleAction();
    actions.insert(entry);

    t = make_tuple("-", REALLIT, RATIONALLIT);
    entry.first = t;
    entry.second = new MoinsSimpleAction();
    actions.insert(entry);

    t = make_tuple("-", RATIONALLIT, RATIONALLIT);
    entry.first = t;
    entry.second = new MoinsRatRatAction();
    actions.insert(entry);

    t = make_tuple("-", RATIONALLIT, INTLIT);
    entry.first = t;
    entry.second = new MoinsRatIntAction();
    actions.insert(entry);

    t = make_tuple("-", INTLIT, RATIONALLIT);
    entry.first = t;
    entry.second = new MoinsIntRatAction();
    actions.insert(entry);


    //Actions Division
    t = make_tuple("/", REALLIT, INTLIT);
    entry.first = t;
    entry.second = new DivisionSimpleAction();
    actions.insert(entry);

    t = make_tuple("/", INTLIT, REALLIT);
    entry.first = t;
    entry.second = new DivisionSimpleAction();
    actions.insert(entry);

    t = make_tuple("/", REALLIT, REALLIT);
    entry.first = t;
    entry.second = new DivisionSimpleAction();
    actions.insert(entry);

    t = make_tuple("/", RATIONALLIT, REALLIT);
    entry.first = t;
    entry.second = new DivisionSimpleAction();
    actions.insert(entry);

    t = make_tuple("/", REALLIT, RATIONALLIT);
    entry.first = t;
    entry.second = new DivisionSimpleAction();
    actions.insert(entry);

    t = make_tuple("/", RATIONALLIT, RATIONALLIT);
    entry.first = t;
    entry.second = new DivisionRatRatAction();
    actions.insert(entry);

    t = make_tuple("/", RATIONALLIT, INTLIT);
    entry.first = t;
    entry.second = new DivisionRatIntAction();
    actions.insert(entry);

    t = make_tuple("/", INTLIT, RATIONALLIT);
    entry.first = t;
    entry.second = new DivisionIntRatAction();
    actions.insert(entry);

    t = make_tuple("/", INTLIT, INTLIT);
    entry.first = t;
    entry.second = new DivisionIntIntAction();
    actions.insert(entry);

    //Action Puissance (POW)
    t = make_tuple("POW", INTLIT, RATIONALLIT);
    entry.first = t;
    entry.second = new POWSimpleAction();
    actions.insert(entry);

    t = make_tuple("POW", RATIONALLIT, RATIONALLIT);
    entry.first = t;
    entry.second = new POWRatRatRatRealAction();
    actions.insert(entry);

    t = make_tuple("POW", REALLIT, RATIONALLIT);
    entry.first = t;
    entry.second = new POWSimpleAction();
    actions.insert(entry);

    t = make_tuple("POW", INTLIT, REALLIT);
    entry.first = t;
    entry.second = new POWSimpleAction();
    actions.insert(entry);

    t = make_tuple("POW", RATIONALLIT, REALLIT);
    entry.first = t;
    entry.second = new POWRatRatRatRealAction();
    actions.insert(entry);

    t = make_tuple("POW", REALLIT, REALLIT);
    entry.first = t;
    entry.second = new POWSimpleAction();
    actions.insert(entry);

    t = make_tuple("POW", REALLIT, INTLIT);
    entry.first = t;
    entry.second = new POWSimpleAction();
    actions.insert(entry);

    t = make_tuple("POW", INTLIT, INTLIT);
    entry.first = t;
    entry.second = new POWIntIntAction();
    actions.insert(entry);

    t = make_tuple("POW", RATIONALLIT, INTLIT);
    entry.first = t;
    entry.second = new POWRatIntAction();
    actions.insert(entry);

    return actions;
}

bool Action::exist(tuple<string, LitType, LitType> t)
{
    return getActions().count(t) > 0;
}


// Action Addition -------
Litteral* PlusSimpleAction::exec(Litteral* l1, Litteral* l2)
{
    //Additions simples : int + int, int + reel, reel + int, reel + reel, rationnel+reel, reel+rationnel
    NumLit* lit1 = dynamic_cast<NumLit*>(l1);
    NumLit* lit2 = dynamic_cast<NumLit*>(l2);
    //si mantisse nulle le Reel est  simplifié à l'empilement
    return new RealLit(lit1->getValue() + lit2->getValue());
}

Litteral* PlusRatRatAction::exec(Litteral* l1, Litteral* l2)
{
    //Additiion : Rationnel + Rationnel
    RationalLit* rtl1 = dynamic_cast<RationalLit*>(l1);
    RationalLit* rtl2 = dynamic_cast<RationalLit*>(l2);
    int newnum = rtl1->getNum()*rtl2->getDen() + rtl2->getNum()*rtl1->getDen();
    int newden= rtl2->getDen()*rtl1->getDen();
    RationalLit * nrtl = new RationalLit(newnum,newden);
    return nrtl;
}

Litteral* PlusRatIntAction::exec(Litteral* l1, Litteral* l2)
{
    //Addition : Rationnel+Int, Int+rationnel
    RationalLit * rtl = dynamic_cast<RationalLit*>(l1);
    IntLit * i1 = dynamic_cast<IntLit*>(l2);
    int newnum = i1->getValue()*rtl->getDen() + rtl->getNum();
    int newden = rtl->getDen();
    RationalLit * nrtl = new RationalLit(newnum,newden);
    return nrtl;
}

//Action Multiplication -----
Litteral* MulSimpleAction::exec(Litteral* l1, Litteral* l2)
{
    //Multiplication simples : int * int, int * reel, reel * int, reel * reel, rationnel*reel, reel*rationnel
    NumLit* lit1 = dynamic_cast<NumLit*>(l1);
    NumLit* lit2 = dynamic_cast<NumLit*>(l2);
    //si mantisse nulle le Reel est  simplifié à l'empilement
    return new RealLit(lit1->getValue() * lit2->getValue());
}

Litteral* MulRatRatAction::exec(Litteral* l1, Litteral* l2)
{
    //Multiplication : Rationnel * Rationnel
    RationalLit* rtl1 = dynamic_cast<RationalLit*>(l1);
    RationalLit* rtl2 = dynamic_cast<RationalLit*>(l2);
    int newnum = rtl1->getNum()* rtl2->getNum();
    int newden= rtl2->getDen()*rtl1->getDen();
    RationalLit * nrtl = new RationalLit(newnum,newden);
    return nrtl;
}

Litteral* MulRatIntAction::exec(Litteral* l1, Litteral* l2)
{
    //Multiplication : Rationnel * Int, Int * Rationnel
    RationalLit * rtl = dynamic_cast<RationalLit*>(l1);
    IntLit * i1 = dynamic_cast<IntLit*>(l2);
    int newnum = i1->getValue()*rtl->getNum();
    int newden = rtl->getDen();
    RationalLit * nrtl = new RationalLit(newnum,newden);
    return nrtl;
}

//Actions Soustraction -----
Litteral* MoinsSimpleAction::exec(Litteral* l1, Litteral* l2)
{
    //Soustractions simples : int - int, int - reel, reel - int, reel - reel, rationnel-reel, reel-rationnel
    NumLit* lit1 = dynamic_cast<NumLit*>(l1);
    NumLit* lit2 = dynamic_cast<NumLit*>(l2);
    //si mantisse nulle le Reel est  simplifié à l'empilement
    return new RealLit(lit1->getValue() - lit2->getValue());
}

Litteral* MoinsRatRatAction::exec(Litteral* l1, Litteral* l2)
{
    //Soustraction : Rationnel - Rationnel
    RationalLit* rtl1 = dynamic_cast<RationalLit*>(l1);
    RationalLit* rtl2 = dynamic_cast<RationalLit*>(l2);
    int newnum = rtl1->getNum()*rtl2->getDen() - rtl2->getNum()*rtl1->getDen();
    int newden= rtl2->getDen()*rtl1->getDen();
    RationalLit * nrtl = new RationalLit(newnum,newden);
    return nrtl;
}
Litteral* MoinsRatIntAction::exec(Litteral* l1, Litteral* l2)
{
    //Soustraction : Rationnel - Int
    RationalLit * rtl = dynamic_cast<RationalLit*>(l1);
    IntLit * i1 = dynamic_cast<IntLit*>(l2);
    int newnum = rtl->getNum() - i1->getValue()*rtl->getDen();
    int newden = rtl->getDen();
    RationalLit * nrtl = new RationalLit(newnum,newden);
    return nrtl;
}
Litteral* MoinsIntRatAction::exec(Litteral* l1, Litteral* l2)
{
    //Soustraction : Int - Rat
    RationalLit * rtl = dynamic_cast<RationalLit*>(l2);
    IntLit * i1 = dynamic_cast<IntLit*>(l1);
    int newnum = i1->getValue()*rtl->getDen() - rtl->getNum();
    int newden = rtl->getDen();
    RationalLit * nrtl = new RationalLit(newnum,newden);
    return nrtl;
}

//Actions Division -----
Litteral* DivisionSimpleAction::exec(Litteral* l1, Litteral* l2)
{
    std::cout<<"Division Simple"<<endl;
    //Divisions simples : int/reel, reel/int, reel/reel, reel/rationnel, rationnel/reel
    NumLit* lit1 = dynamic_cast<NumLit*>(l1);
    NumLit* lit2 = dynamic_cast<NumLit*>(l2);
    //si mantisse nulle le Reel est  simplifié à l'empilement
    return new RealLit(lit1->getValue() / lit2->getValue());
}

Litteral* DivisionRatRatAction::exec(Litteral* l1, Litteral* l2)
{
    std::cout<<"Division Rat Rat"<<endl;
    //Division : Rationnel / Rationnel
    RationalLit* rtl1 = dynamic_cast<RationalLit*>(l1);
    RationalLit* rtl2 = dynamic_cast<RationalLit*>(l2);
    int newnum = rtl1->getNum()*rtl2->getDen();
    int newden= rtl2->getNum()*rtl1->getDen();
    RationalLit * nrtl = new RationalLit(newnum,newden);
    return nrtl;
}
Litteral* DivisionRatIntAction::exec(Litteral* l1, Litteral* l2)
{
    std::cout<<"Division Rat Int"<<endl;
    //Division : Rationnel/Int
    RationalLit * rtl = dynamic_cast<RationalLit*>(l1);
    IntLit * i1 = dynamic_cast<IntLit*>(l2);
    int newnum = rtl->getNum() ;
    int newden = rtl->getDen() * i1->getValue();
    RationalLit * nrtl = new RationalLit(newnum,newden);
    return nrtl;
}
Litteral* DivisionIntRatAction::exec(Litteral* l1, Litteral* l2)
{
    std::cout<<"Division Int Rat"<<endl;
    //Division : Int/Rationnel
    RationalLit * rtl = dynamic_cast<RationalLit*>(l2);
    IntLit * i1 = dynamic_cast<IntLit*>(l1);
    int newnum = i1->getValue()*rtl->getDen();
    int newden = rtl->getNum();
    RationalLit * nrtl = new RationalLit(newnum,newden);
    return nrtl;
}

Litteral* DivisionIntIntAction::exec(Litteral* l1, Litteral* l2)
{
    std::cout<<"Division Int Int"<<endl;
    //Division : Int/Int
    IntLit* lit1 = dynamic_cast<IntLit*>(l1);
    IntLit* lit2 = dynamic_cast<IntLit*>(l2);
    RationalLit * nrtl = new RationalLit(lit1->getValue(),lit2->getValue());
    return nrtl;

}
Litteral* POWSimpleAction::exec(Litteral* l1, Litteral* l2)
{
    //Puissance : Int^Rationnel, Real^Rationnel, Int^Real, Real^Real, Real^Int
    NumLit* lit1 = dynamic_cast<NumLit*>(l1);
    NumLit* lit2 = dynamic_cast<NumLit*>(l2);

    return new RealLit(pow(lit1->getValue(),lit2->getValue()));
}


Litteral* POWIntIntAction::exec(Litteral* l1, Litteral* l2)
{
    //Puissance : Int ^ Int
    IntLit* lit1 = dynamic_cast<IntLit*>(l1);
    IntLit* lit2 = dynamic_cast<IntLit*>(l2);

    if(lit2->getValue()<0)
    {
        std::cout<<"neg"<<std::endl;
        int puissance = lit2->getValue()*(-1);
        int denominateur = pow(lit1->getValue(),puissance);
        return new RationalLit(1, denominateur);

    }
    else
    return new RealLit(pow(lit1->getValue(),lit2->getValue()));
}

Litteral* POWRatIntAction::exec(Litteral* l1, Litteral* l2)
{
    //Puissance : Rationnel ^ Int
    RationalLit* rtl = dynamic_cast<RationalLit*>(l1);
    IntLit* lit = dynamic_cast<IntLit*>(l2);

    if(lit->getValue()<0)
    {
        int puissance = lit->getValue()*(-1);
        int numerateur = pow(rtl->getDen(),puissance);
        int denominateur = pow(rtl->getNum(),puissance);
        return new RationalLit(numerateur,denominateur);
    }

else
{
    int numerateur = pow(rtl->getNum(),lit->getValue());
    int denominateur = pow(rtl->getDen(),lit->getValue());
    return new RationalLit(numerateur,denominateur);
}
}

Litteral* POWRatRatRatRealAction::exec(Litteral* l1, Litteral* l2)
{
    //Puissance : Rationnel^Rationnel, Rationnel^Real
    RationalLit* lit1 = dynamic_cast<RationalLit*>(l1);
    NumLit* lit2 = dynamic_cast<NumLit*>(l2);
    double numerateur= pow(lit1->getNum(),lit2->getValue());
    double denominateur= pow(lit1->getDen(),lit2->getValue());

    //Cas de la racine carrée, cubique ect
    if((denominateur- floor(denominateur)==0)&&(numerateur - floor(numerateur)==0))
        return new RationalLit(numerateur,denominateur);

    else
          return new RealLit(pow(lit1->getValue(),lit2->getValue()));

}
