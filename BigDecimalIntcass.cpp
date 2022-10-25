#include "BigDecimalIntcass.h"
#include<bits/stdc++.h>
#include <regex>
using namespace std;


BigDecimalInt::BigDecimalInt(string decStr) {
    regex rej_pattern("[+-]?[0-9]*");
    if(regex_match(decStr,rej_pattern)) {
        if(decStr[0] =='-') {
            sign=0;
           decStr.erase(decStr.begin());
        }
        else {
            sign=1;
            if(decStr[0]=='+')
                decStr.erase(decStr.begin());
        }

        string temp="";
        bool t=0;
        for(long long i=0; i<decStr.size() ; i++){
            if(decStr[i]=='0'&& t==0 ){
                continue;
            }
            else {
                t=1;
                temp+=decStr[i];
            }

        }
        c=temp;
    }

    else
        throw("error name");
}



BigDecimalInt::BigDecimalInt(int decInt) {
    string ss ;
    if(decInt>=0)  sign=1;
    else  sign=0;
    c=to_string(abs(decInt));

}

BigDecimalInt::BigDecimalInt() {
    c="0";
}


BigDecimalInt BigDecimalInt::operator+(const BigDecimalInt &anotherDec) {
    if(sign==anotherDec.sign) {
        int carry = 0;
        string number2 = anotherDec.c;
        int s1 = c.size(), s2 = anotherDec.c.size();
        if (s1 < s2) {
            c = string(s2 - s1, '0') + c;
        } else if (s1 > s2) {
            number2 = string(s1 - s2, '0') + number2;
        }
        if (sign == 1 == anotherDec.sign) {
            string s = number2, finalresult = "";
            int x = number2.size();
            for (int i = x - 1; i >= 0; i--) {
                int res = (s[i] - '0') + (c[i] - '0') + carry;
                carry = 0;
                string st;
                st = to_string(res);
                if (st.size() == 1) {
                    finalresult += to_string(res);
                } else {
                    carry = st[0] - '0';
                    finalresult += st[1];
                }
            }
            if (carry) {
                finalresult.push_back(carry + '0');
            }
            BigDecimalInt b;
            reverse(finalresult.begin(), finalresult.end());
            b.c = finalresult;
            if (sign == 1)
                return b;
            else {
                b = "-" + finalresult;
                return b;
            }
        }
    }
    else{
        if(sign==1){
            BigDecimalInt b;
            b.c=anotherDec.c;
            b.sign=1;
            return *this-b;
        }
        else{
            BigDecimalInt b;
            b.c=c;
            b.sign=1;
            return anotherDec- b;
        }
    }
}




BigDecimalInt BigDecimalInt::operator-(const BigDecimalInt &anotherDec) const{
    BigDecimalInt cc=c , another=anotherDec.c;
    if(sign!=anotherDec.sign){
        if(sign==1) {
            cc.sign=1;
            return cc+another;
        }
        else {
            cc.sign = 0;
            return cc + another;
        }
    }
    // two numbers have the same sign
    BigDecimalInt ret;
    cc.sign = 1;
    another.sign = 1;
    if(c == anotherDec.c) return ret;
    ret.sign = this->sign;
    if(cc < another) {
        BigDecimalInt temp;
        temp = cc;
        cc = another;
        another = temp;
        ret.sign = !ret.sign;
    }

    // make the two string the same size
    if(cc.size() != another.size()) another.c = string(cc.size() - another.size(), '0') + another.c;
    ret.c = string(cc.size(), '0');
    for(int i = cc.c.size() - 1; i >= 0; i--){
        if(cc.c[i] < another.c[i]){
            cc.c[i - 1] -= 1;
            cc.c[i] += 10;
        }
        ret.c[i] = ((cc.c[i] - '0') - (another.c[i] - '0')) + '0';
    }

    // remove leading zeros
    while(ret.c[0] == '0' && ret.c.size() > 1) ret.c.erase(0, 1);

    return ret;


}



bool BigDecimalInt::operator < (const BigDecimalInt anotherDec)const {
    if(sign==1 && anotherDec.sign==1){
        if(anotherDec.c.size()<c.size())
            return false;
        else if( c.size() <anotherDec.c.size())
            return true;
        else if(c.size() ==anotherDec.c.size()){
            if(c==anotherDec.c)
                return false;
            else{
                for(long long i=0 ; i<c.size(); i++){
                    if(c[i]-'0'<anotherDec.c[i]-'0')
                        return true;
                    else if(c[i]-'0'>anotherDec.c[i]-'0')
                        return false;
                }
            }
        }
    }
    else if(sign==0 && anotherDec.sign==0){
        if(anotherDec.c.size()<c.size())
            return true;
        else if(anotherDec.c.size()>c.size())
            return false;
        else if(c.size() ==anotherDec.c.size()){
            if(c==anotherDec.c)
                return false;
            else{
                for(long long i=0 ; i<c.size(); i++){
                    if(c[i]-'0'<anotherDec.c[i]-'0')
                        return false;
                    else if(c[i]-'0'>anotherDec.c[i]-'0')
                        return true;
                }
            }
        }
    }

    else if(sign==1 &&anotherDec.sign==0){
        return false;
    }

    else if(sign==0 &&anotherDec.sign==1){
        return true;
    }

}



bool BigDecimalInt:: operator > (const BigDecimalInt & anotherDec) const {
    return anotherDec < *this ;
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


