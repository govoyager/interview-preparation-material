#include <stdio.h>
#include <math.h>

int main(){
    int a,b,c;
    printf("Enter a,b,c:");
    scanf("%d %d %d",&a,&b,&c);
    if(a == 0 && b == 0){
        printf("No solution: a & b both zero");
    }
    else if (a == 0)
    {
        printf("The root is real: %.3f",-1 * (c/b));
            
    }
    else {
        double dis = (b*b) - (4 * a * c);
        if(dis<0){
            double c = -1 * (b/(2*a));
            double d = sqrt(-1* dis)/ (2*a);
            printf("The roots are complex: %.3f+%.3f i and %.3f-%.3f i ",c,d,c,d);
        }
        else {
            double c = ((-1 * b) + sqrt(dis))/(2 *a);
            double d = ((-1 * b) - sqrt(dis))/(2 *a); 
            printf("The roots are real: %.3f and %.3f ",c,d);
        }
    }
    
    return 0;
}