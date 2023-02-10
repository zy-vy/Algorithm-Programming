#include <stdio.h>
#include <math.h>

int main (){
    int w;
    scanf ("%d",&w);
    for (int t=1;t<=w;t++){

        int day,month,year;
        scanf ("%d/%d/%d",&day,&month,&year);
        int mon;
       if(month > 2)
          mon = month;    //for march to december month code is same as month
       else {
          mon = (12+month);    //for Jan and Feb, month code will be 13 and 14
          year--; //decrease year for month Jan and Feb
       }

       int y = year % 100;    //last two digit
       int c = year / 100;    //first two digit
       int w = (day + floor((13*(mon+1))/5) + y + floor(y/4) + floor(c/4) + (5*c));
       w = w % 7;
        printf ("Case #%d: ",t);
		switch (w){
			case 1:{
				printf ("Sunday\n");
				break;
			}
			case 2:{
				printf ("Monday\n");
				break;
			}
			case 3:{
				printf ("Tuesday\n");
				break;
			}
			case 4:{
				printf ("Wednesday\n");
				break;
			}
			case 5:{
				printf ("Thursday\n");
				break;
			}
			case 6:{
				printf ("Friday\n");
				break;
			}
			case 0:{
				printf ("Saturday\n");
				break;
			}

		}
    }



return 0;
}
