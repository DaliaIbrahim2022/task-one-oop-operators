
#include<iostream>
using namespace std;


class BigDecimalInt {
private :
    string c;
    int sign;
public:
    BigDecimalInt(string decStr);
    BigDecimalInt (int decInt);
    BigDecimalInt();
    BigDecimalInt operator + (const BigDecimalInt& anotherDec);
    BigDecimalInt operator-(const BigDecimalInt &anotherDec) const;
    bool operator< (const BigDecimalInt anotherDec) const;
    bool operator > (const BigDecimalInt & anotherDec) const;
    bool operator == (BigDecimalInt anotherDec);
    BigDecimalInt & operator =(const BigDecimalInt &anotherDec);
    int get_sign();
    int size();
    friend ostream &operator << (ostream &  out , const BigDecimalInt & b);

};
