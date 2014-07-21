//
//  Fraction.cpp
//  A3
//
//  Created by AMIR HAKIM on 2014-07-15.
//  Copyright (c) 2014 AMIR HAKIM. All rights reserved.
//

#include "Fraction.h"


Fraction::Fraction(long numerator,long denominator)
{
    num=numerator;
    den=denominator;
}

Fraction::Fraction(const Fraction& object)
{
    this->num=object.num;
    this->den=object.den;
}

Fraction::~Fraction()
{
    
}

const long Fraction::getDen() const
{
    return den;
}

const long Fraction::getNum() const
{
    return num;
}

void Fraction::setDen(long newDen) const
{
    den=newDen;
}

void Fraction::setNum(long newNum)const
{
    num=newNum;
}

queue<string> Fraction::Tokenize(const string& infixExpression)
{
    queue<string> tokens;
    for (auto ptr :infixExpression)
    {
        string temp=(&ptr);
        string temp1=temp.substr(0,1);
        if (temp1==" ") continue;
        tokens.push(temp1);
    }
    
//    while (!tokens.empty())
//    {
//        cout << (tokens.front());
//        tokens.pop();
//        cout << endl;
//    }
    
    return tokens;
}

Fraction Fraction::evaluateInfix(queue<string> & infixQueue)
{
    Fraction temp;
    stack<Fraction> operands;
    stack<string> operators;
    
//    while (!infixQueue.empty()) {
//        
//        if (isdigit((infixQueue.front())[0]))
//        {
//            operands.push(infixQueue.front());
//        }
//    }
    
    return temp;
}

int Fraction::precedence(string ope)
{
    if (ope=="*" || ope=="/")
    {
        return 2;
    }
    else if (ope=="+" || ope=="-")
    {
        return 1;
    }
    else if (ope=="(" || ope==")")
    {
        return 0;
    }
    return 0;
}

long Fraction::gcd(long first,long second)
{
    int gcd=1;
    for(int i=1;i<=first&&i<=second;i++)
    {
        if(first%i==0 && second%i == 0 ){
            
            gcd= i;
            
        }
    }
    return gcd;
}

Fraction& Fraction::operator=(const Fraction& object)
{
    this->num=object.num;
    this->den=object.den;
    return *this;
}

Fraction& Fraction::operator+=(const Fraction &rhs)
{
    num=((rhs.den*this->num)+(rhs.num*this->den));
    den=(rhs.den*this->den);
    normalize();
    return *this;
}

Fraction& Fraction::operator-=(const Fraction &rhs)
{
    num=((rhs.den*this->num)-(rhs.num*this->den));
    den=(rhs.den*this->den);
    normalize();
    return *this;
}

Fraction& Fraction::operator*= (const Fraction& rhs)
{
    num=num*rhs.num;
    den=den*rhs.den;
    normalize();
    return *this;
}

Fraction& Fraction::operator/= (const Fraction& rhs)
{
    num=num*rhs.den;
    den=den*rhs.num;
    normalize();
    return *this;
}


Fraction& Fraction::operator++()
{
    ++num;
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction temp = *this;
    ++num;
    return temp;
}

Fraction& Fraction::operator--()
{
    num=num-den;
    return *this;
}

Fraction Fraction::operator--(int)
{
    Fraction temp = *this;
    num=num-den;
    return temp;
}


ostream &operator<<(ostream & out, const Fraction & object)
{
    if (object.getDen()==1)
    {
        out << object.num<<"\n";
    }
    else
    {
       out << object.num << "/" << object.den << "\n";
    }
    return out;
}
    
void Fraction::normalize()
{
    float gcdNum = gcd(this->num,this->den);
    den= den/gcdNum;
    num = num/gcdNum;
}


//Fraction operator+ (const Fraction& rhs)
//{
//    long tempNum=(0+(rhs.getNum()));
//    long tempDen=rhs.getDen();
//    Fraction tempF(tempNum,tempDen);
//    return tempF;
//}
//
//Fraction operator- (const Fraction& rhs)
//{
//    Fraction tempF(0-(rhs.getNum()),rhs.getDen());
//    return tempF;
//}
//
//Fraction operator+ (const Fraction& lhs,const Fraction& rhs)
//{
//    Fraction tempF(lhs.getNum(),lhs.getDen());
//    tempF+=rhs;
//    return tempF;
//}
//
//Fraction operator- (const Fraction& lhs,const Fraction& rhs)
//{
//    Fraction tempF(lhs.getNum(),lhs.getDen());
//    tempF-=rhs;
//    return tempF;
//}
//
//Fraction operator* (const Fraction& lhs,const Fraction& rhs)
//{
//    Fraction tempF(lhs.getNum(),lhs.getDen());
//    tempF*=rhs;
//    return tempF;
//}
//
//Fraction operator/ (const Fraction& lhs,const Fraction& rhs)
//{
//    Fraction tempF(lhs.getNum(),lhs.getDen());
//    tempF/=rhs;
//    return tempF;
//}
//
//bool operator==(const Fraction& lhs,const Fraction& rhs)
//{
//    bool test = (lhs.getNum()/lhs.getNum())==(rhs.getNum()/rhs.getNum());
//    return test;
//}
//
//bool operator<(const Fraction& lhs,const Fraction& rhs)
//{
//    bool test = (lhs.getNum()/lhs.getNum())<(rhs.getNum()/rhs.getNum());
//    return test;
//}
//
//bool operator!=(const Fraction& lhs,const Fraction& rhs)
//{
//    bool test = (lhs.getNum()/lhs.getNum())==(rhs.getNum()/rhs.getNum());
//    return !test;
//}
//
//bool operator<=(const Fraction& lhs,const Fraction& rhs)
//{
//    return lhs == rhs || lhs < rhs;
//}
//
//bool operator>(const Fraction& lhs,const Fraction& rhs)
//{
//    bool test = (lhs.getNum()/lhs.getNum())>(rhs.getNum()/rhs.getNum());
//    return test;
//}
//
//bool operator>=(const Fraction& lhs,const Fraction& rhs)
//{
//    return lhs == rhs || lhs > rhs;
//
//}









