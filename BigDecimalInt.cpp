#include "BigDecimalInt.h"
#include<bits/stdc++.h>
#include <regex>
using namespace std;


BigDecimalInt::BigDecimalInt(string decStr) {
    regex rej_pattern("[+-]?[0-9]*");
    if(regex_match(decStr,rej_pattern)) {
        c = decStr;
    }
    else
        throw("error name");
}
BigDecimalInt::BigDecimalInt(int decInt) {
    string ss;
    ss= to_string(decInt);
    c=ss;

}
//____________________________________________________________________________________
bool BigDecimalInt::operator>(BigDecimalInt anotherDec) {

    char sign1='+' , sign2='+';
    if(!isdigit(c[0])){
        sign1=c[0];
        c.erase(remove(c.begin(), c.end(), sign1), c.end());
    }
    if(!isdigit(anotherDec.c[0])){
        sign2=anotherDec.c[0];
        anotherDec.c.erase(remove(anotherDec.c.begin(), anotherDec.c.end(), sign2), anotherDec.c.end());
    }
    if (c.size() > anotherDec.c.size()) {
        for (long long i = anotherDec.c.size(); i < c.size(); i++)
            anotherDec.c = "0" + anotherDec.c;
    }

    else if (c.size() < anotherDec.c.size()) {
        for (long long i = c.size(); i < anotherDec.c.size(); i++)
            c = "0" + c;
    }
    if (sign1!= '-' && sign2 != '-') {

        int temp = 0;
        for (long long i = 0; i < c.size(); i++) {
            if (c[i] - '0' > anotherDec.c[i] - '0') {
                temp = 1;
                break;
            } else if (c[i] - '0' < anotherDec.c[i] - '0') {
                temp = -1;
                break;
            } else continue;
        }
        if (temp == -1 || temp==0) return false;
        else return true;
    }

//        //one negative and the other one is positive
    else if (sign2 == '-' && sign1!= '-')
        return true;


//        //one negative and the other one is positive
    else if (sign2 != '-' && sign1 == '-')
        return false;


//        // both signs are negative
    else if (sign2 == '-' && sign1 == '-') {
        int temp = 0;
        for (long long i = 0; i < c.size(); i++) {
            if (c[i] - '0' > anotherDec.c[i] - '0') {
                temp = 1;
                break;
            } else if (c[i] - '0' < anotherDec.c[i] - '0') {
                temp = -1;
                break;
            } else continue;
        }

        if (temp == -1) return true;
        else return false;
    }
}



bool BigDecimalInt::operator==(BigDecimalInt anotherDec) {
    if(c==anotherDec.c&& sign==anotherDec.sign)
        return 1;
    else
        return 0;
}



BigDecimalInt &BigDecimalInt::operator=(const BigDecimalInt & anotherDec){
    c=anotherDec.c;
    sign =anotherDec.sign;
    return *this;
}


int BigDecimalInt::size() {
    return c.size();
}


int BigDecimalInt::get_sign() {

    if (c[0] == '-')
        return 0;
    else
        return 1;
}


ostream &operator<<(ostream &out, const BigDecimalInt &b) {
    if(!b.sign)
        out<<"-";
    out<<b.c;
    return  out;

}