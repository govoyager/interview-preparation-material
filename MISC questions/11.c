#include <stdio.h>
void main(){
    long long int next;
    int first =0,second=1,n,c;
    for(c = 0;c<100;c++){
        if(c == 0 || c == 1){
            next =c;
        }
    else
    {
        next = first + second;
        first = second;
        second = next;
    }
    printf("%d\n",next);
      }
}


