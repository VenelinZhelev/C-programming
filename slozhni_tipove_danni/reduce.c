#include<stdio.h>
typedef unsigned long long ucll;
typedef ucll(*funcptr)(ucll,ucll);

ucll add(ucll a, ucll b){
    return a+b;
}

ucll reduce(ucll arr[],ucll arrlen,funcptr ptr,ucll argument){
ucll result=argument;
for(int i=0;i<=arrlen;i++){
   result=add(result,arr[i]);
}
return result;
}

int main(){
ucll arr[4] = {1,2,3,4,};
ucll arrlen=4;
ucll (*p)[4]=&arr;
ucll argument =0;
ucll result = reduce(arr,arrlen,add,argument);
printf("%llu",result);
    return 0;
}