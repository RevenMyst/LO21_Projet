#include "Action.h"
#include "Litteral.h"
#include<iostream>

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
    //Divisions simples : int/reel, reel/int, reel/reel, reel/rationnel, rationnel/reel
    NumLit* lit1 = dynamic_cast<NumLit*>(l1);
    NumLit* lit2 = dynamic_cast<NumLit*>(l2);
    //si mantisse nulle le Reel est  simplifié à l'empilement
    return new RealLit(lit1->getValue() / lit2->getValue());
}

Litteral* DivisionRatRatAction::exec(Litteral* l1, Litteral* l2)
{
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
    //Division : Int/Int
    IntLit* lit1 = dynamic_cast<IntLit*>(l1);
    IntLit* lit2 = dynamic_cast<IntLit*>(l2);

    //Si mantisse nulle : creation d'un Int
    double val = lit1->getValue()/lit2->getValue();
    if((val - floor(val))==0){
       IntLit * nil = new IntLit(val);
       return nil;

       }
    //Sinon : creation d'un Rationnel
    else{
        RationalLit * nrtl = new RationalLit(lit1->getValue(),lit2->getValue());
        return nrtl;
    }
}
