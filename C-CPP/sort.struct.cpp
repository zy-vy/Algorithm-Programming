#include <stdio.h>
struct data {
    char nama[20];
    int nim;
}temp,mhs[10];


void swap (data *a,data *b){
    temp = *a;
    *a=*b;
    *b=temp;
    return;
}
void quicksort (data arr[],int min,int max){
    if (min < max){
        int pivot = max;
        int index = min;
        for (int i=min;i<max;i++){
            if (arr[i].nim<arr[pivot].nim){
                swap (&arr[i],&arr[index]);
                index++;
            }
        }
        swap(&arr[index],&arr[pivot]);
        quicksort (arr,min,index-1);
        quicksort (arr,index+1,max);

    }
    return;
}


int main (){
    FILE *fp = fopen ("testdata.txt","r");
  //  data mhs[10];
    int n=0;
    while (!feof(fp)){
        fscanf (fp,"%[^\n]\n%d\n",&mhs[n].nama,&mhs[n].nim);
        n++;
        printf ("%s %d\n",mhs[n-1].nama,mhs[n-1].nim);
    }
    quicksort (mhs,0,3);
    for (int i=0;i<n;i++){
        printf ("  %s %d\n",mhs[i].nama,mhs[i].nim);
    }

    fclose (fp);
return 0;
}
