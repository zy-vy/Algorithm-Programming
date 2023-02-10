#include <stdio.h>
int main () {
int a;
printf("Masukan nilai:",&a);
scanf("%d",&a);
if (a>100){
    printf("homina homina homina");
}
else if (a=100){
    printf("sempurna");
}
else if(a>=90){
    printf("A");
}
else if (a>=80){
    printf("B");
}
else if (a>=70){
    printf("C");
}
else if (a>=60){
    printf("D");
}
else {printf("tidak lulus");}
return 0;
}
