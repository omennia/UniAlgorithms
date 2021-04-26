#include <stdio.h>

double f(double x){ // Insert the function f(x)
    return 3*x*x - 2*x - 7;
}

double bissect(double lo, double hi, double tol);

int main(){
    double num; scanf("%lf", &num);
    printf("f(%.1lf) = %.1lf\n", num, f(num));
    // Finding zero between 0 and 5
    double res = bissect(0, 5, 0.0001);
    printf("O zero da funcao está em %lf\n", res);
    return 0;
}

double bissect(double lo, double hi, double tol){
    double fmid, fa = f(hi);
    while(hi-lo > tol){
        double mid = lo + (hi - lo) / 2;
        fmid = f(mid);
        if(fmid * fa > 0){
            hi = mid; fa = fmid;
        } 
        else{
            lo = mid;
        }
    }
    return lo + (hi - lo) / 2;
}