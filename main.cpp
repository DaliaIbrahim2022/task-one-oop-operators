#include <iostream>
#include <vector>
#include "BigDecimalIntcass.h"
using namespace std;
// function to subtract two objects and return the result as a new object


int main(){
    BigDecimalInt a("1");
    BigDecimalInt b("-9");
    BigDecimalInt c;
    c=b+a;
    cout<<c<<endl;
    return 0;

}
