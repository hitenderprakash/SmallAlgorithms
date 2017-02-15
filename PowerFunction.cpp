#include <iostream>

using namespace std;
double Power(double x, int n);
//test code
int main()
{
    double x=5;
    int n=5;
    double *arr=new double [n+1]();
    arr[0]=1;
    cout<<"\n"<<long(PowByBits(x,n,arr));
    return 0;
}
//end of test code 

double Power(double x, int ni){
    double res=1;
    long long n=n;//to handle overflow
    if (n<0){
        n=-n;
        x=1/x;
    }
    while(n>0){
        if((n&1)==1){
            res=res*x;
        }
        x=x*x;
        n=n>>1;
    }
    return res;
}

/*//Dynamic Programming soluttion
double Pow(double x, int n,double *arr){
    if (arr[n]){
            return arr[n];
    }
    else {
        arr[n]=Pow(x,n/2,arr)*Pow(x,(n-n/2),arr);
        return arr[n];
    }

}*/
