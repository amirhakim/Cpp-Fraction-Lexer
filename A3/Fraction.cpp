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
    normalize();
}

Fraction::Fraction(const Fraction& object)
{
    this->num=object.num;
    this->den=object.den;
    normalize();
}

Fraction::Fraction(const string & number)
{
	queue<string> infix = Tokenize( number );
	*this = evaluateInfix( infix );
	this->normalize();

}

Fraction::Fraction (const char* number)
{
	if ( number == 0 ) *this = Fraction( 0, 1 );
	else *this = Fraction( string( number ) );
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
    string temp1;
    for (auto ptr :infixExpression)
    {
        string temp=(&ptr);
        string temp0=temp.substr(0,1);
        if (temp0==" ") continue;
        if (isdigit(temp0[0])) {
            temp1 = temp1 + temp0;
            continue;
        }
        else
        {
            if (!temp1.empty())tokens.push(temp1);
            tokens.push(temp0);
            temp1.erase();
        }
    }
    if (!temp1.empty())tokens.push(temp1);
    
//    while (!tokens.empty())
//    {
//        cout << (tokens.front());
//        tokens.pop();
//        cout << endl;
//    }
    
    return tokens;
}

Fraction Fraction::evaluateInfix(queue<string> & tokens)
{
    Fraction temp;
    stack<Fraction> operands;
    stack<string> operators;
    
    while (!tokens.empty())
    {
        string prevToken=(tokens.front());
        if (isnumber(prevToken[0]))
        {
            //cout << prevToken << endl;
            operands.emplace(stoi(prevToken));
        }
        else if(!(prevToken=="(" || prevToken==")"))
        {
            while (!operators.empty() && precedence(operators.top())>=(precedence(prevToken)))
            {
                Fraction lastIn=operands.top();
                operands.pop();
                Fraction firstIn=operands.top();
                operands.pop();
                Fraction result;
                string op = operators.top();
                operators.pop();
                evaluateFraction(firstIn, op,lastIn,result);
                operands.push(result);
            }
            operators.push(prevToken);
        }
        
        else if (prevToken=="(")
        {
            operators.push(prevToken);
        }
        
        else if (prevToken==")")
        {
            while (!operators.empty() && operators.top()!="(")
            {
                Fraction lastIn=operands.top();
                operands.pop();
                Fraction firstIn=operands.top();
                operands.pop();
                Fraction result;
                string op = operators.top();
                operators.pop();
                evaluateFraction(firstIn, op,lastIn,result);
                operands.push(result);
            }
            operators.pop();
        }
        tokens.pop();  
    }
    
    while (!operators.empty())
    {
        Fraction lastIn=operands.top();
        operands.pop();
        Fraction firstIn=operands.top();
        operands.pop();
        Fraction result;
        string op = operators.top();
        operators.pop();
        evaluateFraction(firstIn, op,lastIn,result);
        operands.push(result);
    }
    
    temp=operands.top();
    operands.pop();
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

istream& operator>>(istream& in, Fraction& destination) {
	string inputExpression;
	in >> inputExpression;
	Fraction temp = Fraction( inputExpression );
	destination = temp;
	return in;
}
    
void Fraction::normalize()
{
    float gcdNum = gcd(this->num,this->den);
    den= den/gcdNum;
    num = num/gcdNum;
}

Fraction operator+ (const Fraction& rhs)
{
    long tempNum=(0+(rhs.getNum()));
    long tempDen=rhs.getDen();
    Fraction tempF(tempNum,tempDen);
    return tempF;
}

Fraction operator+ (const Fraction& lhs,const Fraction& rhs)
{
    Fraction tempF(lhs.getNum(),lhs.getDen());
    tempF+=rhs;
    return tempF;
}

Fraction operator- (const Fraction& rhs)
{
    Fraction tempF(0-(rhs.getNum()),rhs.getDen());
    return tempF;
}



Fraction operator- (const Fraction& lhs,const Fraction& rhs)
{
    Fraction tempF(lhs.getNum(),lhs.getDen());
    tempF-=rhs;
    return tempF;
}

Fraction operator* (const Fraction& lhs,const Fraction& rhs)
{
    Fraction tempF(lhs.getNum(),lhs.getDen());
    tempF*=rhs;
    return tempF;
}

Fraction operator/ (const Fraction& lhs,const Fraction& rhs)
{
    Fraction tempF(lhs.getNum(),lhs.getDen());
    tempF/=rhs;
    return tempF;
}

bool operator==(const Fraction& lhs,const Fraction& rhs)
{
    bool test = ((lhs.getNum()*(float)1.000)/(lhs.getDen()*(float)1.000))==((rhs.getNum()*(float)1.000)/(rhs.getDen()*(float)1.000));
    return test;
}

bool operator==(int lhsF,const Fraction& rhs)
{
    Fraction lhs(lhsF);
    bool test = ((lhs.getNum()*(float)1.000)/(lhs.getDen()*(float)1.000))==((rhs.getNum()*(float)1.000)/(rhs.getDen()*(float)1.000));
    return test;
}

bool operator<(const Fraction& lhs,const Fraction& rhs)
{
    bool test = ((lhs.getNum()*(float)1.000)/(lhs.getDen()*(float)1.000))<((rhs.getNum()*(float)1.000)/(rhs.getDen()*(float)1.000));
    return test;
}

bool operator<(int lhsF,const Fraction& rhs)
{
    Fraction lhs(lhsF);
    bool test = ((lhs.getNum()*(float)1.000)/(lhs.getDen()*(float)1.000))<((rhs.getNum()*(float)1.000)/(rhs.getDen()*(float)1.000));
    return test;
}

bool operator!=(const Fraction& lhs,const Fraction& rhs)
{
    bool test = !(lhs==rhs);
    return test;
}

bool operator<=(const Fraction& lhs,const Fraction& rhs)
{
    return lhs == rhs || lhs < rhs;
}

bool operator>(const Fraction& lhs,const Fraction& rhs)
{
    return !(lhs==rhs) || (lhs < rhs);
}

bool operator>=(const Fraction& lhs,const Fraction& rhs)
{
    return lhs == rhs || lhs > rhs;
    
}

void evaluateFraction(const Fraction& lhs,const string& op,const Fraction& rhs,Fraction& result)
{
    switch (op[0]) {
        case('*'):
            result=lhs*rhs;
            break;
        case ('+'):
            result=lhs+rhs;
            break;
        case ('-'):
            result=lhs-rhs;
            break;
        case ('/'):
            result=lhs/rhs;
            break;
        default:
            break;
    }
}

void evaluateFraction(Fraction& lhsResult,const string& op)
{
    
}

void evaluateFraction(const string& op,Fraction& rhsResult)
{
    
}





