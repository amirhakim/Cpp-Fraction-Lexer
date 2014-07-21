//
//  main.cpp
//  A3
//
//  Created by AMIR HAKIM on 2014-07-15.
//  Copyright (c) 2014 AMIR HAKIM. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <iomanip>
#include <string>
#include "Fraction.h"

using namespace std;

Fraction operator+ (const Fraction& rhs)
{
    long tempNum=(0+(rhs.getNum()));
    long tempDen=rhs.getDen();
    Fraction tempF(tempNum,tempDen);
    return tempF;
}

Fraction operator- (const Fraction& rhs)
{
    Fraction tempF(0-(rhs.getNum()),rhs.getDen());
    return tempF;
}

Fraction operator+ (const Fraction& lhs,const Fraction& rhs)
{
    Fraction tempF(lhs.getNum(),lhs.getDen());
    tempF+=rhs;
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




int main(int argc, const char * argv[])
{

    
    cout << "Test Fraction and Fractional Computation" << '\n';
    cout << "----------------------------------------\n\n";
    cout << "testing default ctor with Fraction f0;" <<'\n';
    Fraction f0; // test default ctor
    cout << "testing fraction == integer with f0 == 0" << '\n';
    assert(f0 == 0); // test fraction == integer
    cout << "f0: " << f0 <<'\n';
    cout << "ok\n\n";
    cout << "testing 1-arg ctor with Fraction f1(5);" << '\n';
    Fraction f1(5); // test 1 arg ctor
    assert(5 == f1); // test integer = fraction
    cout << "f1: " << f1 << "\n\n";
    cout << "ok\n\n";
    cout << "testing copy ctor with Fraction f2 = f1;" <<'n';
    Fraction f2 = f1; // test ctor
    assert(f2 == f1); // test fraction == fraction
    cout << "f2: " << f2 << "\n\n";
    cout << "ok\n\n";
    cout << "testing fraction == integer with f1 == 5;" <<'\n';
    assert(f1 == 5); // test fraction == integer
    cout << "ok\n\n";
    cout << "testing fraction == fraction with f1 == f2;" <<'\n';
    assert(f1 == f2); // test fraction == fraction
    cout << "ok\n\n";
    cout << "testing fraction != fraction with !(f1 != f2);" <<'\n';
    assert(!(f1 != f2)); // test fraction != fraction
    cout << "ok\n\n";
    cout << "testing 2 args ctor with Fraction half = Fraction(1, 2);" <<'\n';
    Fraction half = Fraction(1, 2); // 2 args ctor
    cout << "half: " << half << "\n\n";
    cout << "testing operator+ with f2 = f1 + half;" <<'\n';
    f2 = f1 + half; // test operator+
    cout << "f2: " << f2 << "\n\n";
    cout << "testing operator< with f1 < f2;" <<'\n';
    assert(f1 < f2); // operator <
    cout << "ok\n\n";
    
    cout << "testing operator<= with f1 <= f2;" <<'\n';
    assert(f1 <= f2); // operator <=
    cout << "ok\n\n";
    cout << "testing operator> with f2 > f1;" <<'\n';
    assert(f2 > f1); // operator >
    cout << "ok\n\n";
    cout << "testing operator>= with f2 >= f1;" <<'\n';
    assert(f2 >= f1); // operator >=
    cout << "ok\n\n";
    cout << "testing operator!= with f2 != f1;" <<'\n';
    assert(f2 != f1); // operator !=
    cout << "ok\n\n";
    cout << "testing operator==, operator- with f1 == f2 - half;" <<'\n';
    assert(f1 == f2 - half); // operator −
    cout << "ok\n\n";
    cout << "testing 2 args ctor with Fraction oneThird (1, 3);" <<'\n';
    Fraction oneThird(1, 3);
    cout << "oneThird: " << oneThird << "\n\n";
    cout << "testing assignment=, binary +, -, and unary - with \n";
    cout<< " f2 = f1 + oneThird - ( - oneThird );" <<'\n';
    f2 = f1 + oneThird -(-oneThird); // assignment=, binary +, −, and unary −
    cout << "f2: " << f2 <<'\n';
    assert(f2 == Fraction(17, 3));
    cout << "ok\n\n";
    cout << "testing fractional expression with f2 = f1 - oneThird + ( - oneThird );"<<'\n';
    f2 = f1 - oneThird +(-oneThird); // assignment=, binary +, −, and unary +
    cout<<"f2 *: "<<f2<<'\n';
    assert(f2 == Fraction(13, 3));
    cout << "ok\n\n";
    cout << "testing post++ with f2 = f1++;" <<'\n';
    f2 = f1++;
    cout<<"f1 : "<<f1<<'\n';
    cout<<"f2 : "<<f2<<'\n';
    assert(f1 == Fraction(6));
    assert(f2 == Fraction(5));
    cout << "ok\n\n";
    cout << "testing pre++ with f2 = ++f1;" <<'\n';
    f2 = ++f1;
    cout<<"f1 : "<<f1<<'\n';
    cout<<"f2 : "<<f2<<'\n';
    assert(f1 == Fraction(7));
    assert(f2 == Fraction(7));
    cout << "ok\n\n";
    cout << "testing post-- with f2 = f1--;" <<'\n';
    f2 = f1--;
    cout<<"f1 : "<<f1<<'\n';
    cout<<"f2 : "<<f2<<'\n';
    assert(f1 == Fraction(6));
    assert(f2 == Fraction(7));
    cout << "ok\n\n";
    cout << "testing pre-- with f2 = --f1;" <<'\n';
    f2 = --f1;
    cout<<"f1 : "<<f1<<'\n';
    cout<<"f2 : "<<f2<<'\n';
    assert(f1 == Fraction(5));
    assert(f2 == Fraction(5));
    cout << "ok\n\n";
    
    string test = "1/2 + 1/4 + 1/6 + 1/8 + 1/10";
    Fraction::Tokenize(test);
//    cout << "testing conversion constructor with f1 = \"3/5\";" <<'\n';
//    cout<< "testing infix evaluation with f1 = \"3/5\";" <<'\n';
//    f1 = "3/5";
//    129 cout<<"f1 : "<<f1<<’\n’;
//    130 assert(f1 == Fraction(3, 5));
//    131 cout << "ok\n\n";
//    132
//    133 cout << "testing normalization with f1 == \"6/10\";" << ’\n’;
//    134 assert(f1 == "6/10");
//    135 cout<<"f1 : "<<f1<<’\n’;
//    136 cout << "ok\n\n";
    
    
    return 0;
}
