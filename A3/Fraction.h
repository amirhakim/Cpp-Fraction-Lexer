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

using std::stack;
using std::cout;
using std::endl;
using std::queue;
using std::string;

class Fraction
{
public:
    Fraction();
    Fraction(long);
    Fraction(long,long);
    Fraction(const string &);
    ~Fraction();
    
    long getDen();
    long getNum();
    void setDen(long);
    void setNum(long);
    static queue<string> Tokenize(const string& infixExpression);
    static Fraction evaluateInfix(queue<string> & infixQueue);
    static int precedence(string ope);
    static long gcd(long,long);
    Fraction& operator+= (const Fraction& rhs);
    Fraction& operator-= (const Fraction& rhs);
    Fraction& operator*= (const Fraction& rhs);
    Fraction& operator/= (const Fraction& rhs);
    Fraction& operator++ ();
    Fraction operator++ (int);

    
private:
    long den,num;
    void normalize();
    
};

#endif /* defined(__A3__Fraction__) */








