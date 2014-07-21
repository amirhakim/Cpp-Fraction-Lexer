//
//  Fraction.h
//  A3
//
//  Created by AMIR HAKIM on 2014-07-15.
//  Copyright (c) 2014 AMIR HAKIM. All rights reserved.
//

#ifndef __A3__Fraction__
#define __A3__Fraction__

#include <iostream>
#include <stack>
#include <queue>
#include <cstring>

using std::stack;
using std::cout;
using std::endl;
using std::queue;
using std::string;
using std::ostream;

class Fraction
{
public:
    //Fraction() = default;
    Fraction(long=0,long=1);
    Fraction(const Fraction&);
    //Fraction(const string &);
    //Fraction (const char*);
    ~Fraction();
    
    const long getDen() const;
    const long getNum()const;
    void setDen(long) const;
    void setNum(long) const;
    static queue<string> Tokenize(const string& infixExpression);
    static Fraction evaluateInfix(queue<string> & infixQueue);
    static int precedence(string ope);
    static long gcd(long,long);
    Fraction& operator=(const Fraction&);
    Fraction& operator+= (const Fraction& rhs);
    Fraction& operator-= (const Fraction& rhs);
    Fraction& operator*= (const Fraction& rhs);
    Fraction& operator/= (const Fraction& rhs);
    Fraction& operator++ ();
    Fraction operator++ (int);
    Fraction& operator-- ();
    Fraction operator-- (int);
    friend ostream &operator<<(ostream &, const Fraction &);
    
private:
    mutable long den,num;
    void normalize();
    
};


#endif /* defined(__A3__Fraction__) */








