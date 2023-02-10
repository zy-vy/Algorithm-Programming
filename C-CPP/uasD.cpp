#include <stdio.h>
#include <math.h>

int main (){
	int w;
	scanf ("%d",&w);
	for (int t=1;t<=w;t++){
		int dd,mm,yy;
		scanf ("%d/%d/%d",&dd,&mm,&yy);
		int d,m,c,k;
		d=dd;
		if (mm==1||mm==2){
			m=mm+12;
			c=yy/100;
			k=(yy%100)-1;
		}
		else {
			m=mm;
			c=yy/100;
			k=(yy%100);
		}
//		printf ("%d %d %d %d\n",d,m,c,k);
		int k2,c2;
		float day;
//
		c2=c/4;
		k2=k/4;
		float day1;
		day = (2.6*m)-5.39;
		day1=day;
//		printf ("day1 %f\n",day1);
		if (day +  c2 + k2 + d + k - (2*c)>=0){
			day= day +  c2 + k2 + d + k - (2*c);
			day=(int)day%7;
//			printf ("day1 %f\n",day1);
		}
		else {
			day1 =(int)day1 +  c2 + k2 + d + k - (2*c);
//			printf ("day1 %f\n",day1);
		//	day=(day1+(7*ceil(fabs(day1)/7)));
			day=fabs(day1);
//			printf ("%f day\n",day);
			day = ceil(day/7);
//			printf ("%f day\n",day);
			day = 7*day;
//			printf ("%f day\n",day);
			day = day1 +day;
//			printf ("%f day\n",day);
			day=(int)day%7;
		}
//		printf ("%f %d %d %d %d %d\n",day,c2,k2,d,k,2*c);
		printf ("Case #%d: ",t);
		switch ((int)day){
			case 0:{
				printf ("Sunday\n");
				break;
			}
			case 1:{
				printf ("Monday\n");
				break;
			}
			case 2:{
				printf ("Tuesday\n");
				break;
			}
			case 3:{
				printf ("Wednesday\n");
				break;
			}
			case 4:{
				printf ("Thursday\n");
				break;
			}
			case 5:{
				printf ("Friday\n");
				break;
			}
			case 6:{
				printf ("Saturday\n");
				break;
			}

		}



	}



	return 0;
}
