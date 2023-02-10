#include <stdio.h>
#include <string.h>

int main (){
    FILE *fp = fopen ("customer_app_data.csv","r");
    char id[1000][100],name[1000][120],city[1000][210],gender[1000][120],car[1000][120],property[1000][20],dump[1000];
    fscanf(fp,"%[^\n]\n",dump);
    printf ("%s\n",dump);
    int i=0;
    while (!feof(fp)){
        //fscanf (fp,"%[^\n]",id[i]);
        fscanf(fp,"%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",&id[i],&name[i],&city[i],&gender[i],&car[i],&property[i]);
    //    printf ("%s %s %s %s %s %s\n",id[i],name[i],city[i],gender[i],car[i],property[i]);
           i++;
    }
    FILE *f=fopen ("test.txt","w");
    for (int j=0;j<i;j++){
    //    printf ("%s %s %s %s %s %s\n",id[j],name[j],city[j],gender[j],car[j],property[j]);
    //    printf ("%d\n",j);
    }
    int id_stt=0,name_stt=0,city_stt=0,gender_stt=0,car_stt=0,property_stt=0;
    int show_all=0,print_ato_gk=0;
    int id_cari=0,name_cari=0,city_cari=0,gender_cari=0,car_cari=0,property_cari=0;
    char temp[1000];
    int count=0,index=0;
    char show[1000],dimana[1000],samadengan[1000];
    char WHERE[6],EQUALS[7],check[1000];
    char print[100][100];
    printf ("cari pakai \"SHOW <coloum-filter> WHERE <search-key> equals <search-value>\"\n");
    scanf("%[^\n]", temp);
    if(temp[0] != 'S' || temp[1] != 'H' || temp[2] != 'O' || temp[3] != 'W'){
			printf("Wrong Input\n");
			return -1;
		}
    else{
			int len = strlen(temp);
			for(int i = 5; i < len;i++){
				if(temp[i] != ' ' && count == 0){
					show[index] = temp[i];
					index++;
				}
				else if(temp[i] != ' ' && count == 1){
					WHERE[index] = temp[i];
					index++;
				}
				else if(temp[i] != ' ' && count == 2){
					dimana[index] = temp[i];
					index++;
				}
				else if(temp[i] != ' ' && count == 3){
					EQUALS[index] = temp[i];
					index++;
				}
				else if(temp[i] != ' ' && count == 4){
					samadengan[index] = temp[i];
					index++;
				}
				else{
					index = 0;
					count++;
				}
			}
			check[0]=show[0];
			if (check[0]=='*'){
            id_stt=1;
            name_stt=1;
            city_stt=1;
            gender_stt=1;
            car_stt=1;
            property_stt=1;
			}
			else{
                int len=strlen(show);
                int j = 0;
				int k = 0;

				for(int i = 0; i < len;i++){
					if(show[i] != ','){
						print[j][k] = show[i];
		//				printf ("%s\n",print[j][k]);
						k++;
					}
					else{
						j++;
						k = 0;
					}
				}
				for(int i = 0; i < 6; i++){
					if(strcmp(print[i],"id") == 0){
						id_stt=1;
					}
					else if(strcmp(print[i],"first_name") == 0){
						name_stt=1;
					}
					else if(strcmp(print[i],"city") == 0){
						city_stt=1;
					}
					else if(strcmp(print[i],"gender") == 0){
						gender_stt=1;
					}
					else if(strcmp(print[i],"has_car") == 0){
						car_stt=1;
					}
					else if(strcmp(print[i],"has_property") == 0){
						property_stt=1;
					}
		//			printf ("%d\n",i);
				}
			}
			if(strcmp(WHERE,"WHERE") != 0){
				show_all = 1;
			}

			if(strcmp(dimana,"id") == 0){
				id_cari = 1;
			}
			else if(strcmp(dimana,"first_name") == 0){
				name_cari = 1;
			}
			else if(strcmp(dimana,"city") == 0){
				city_cari = 1;
			}
			else if(strcmp(dimana,"gender") == 0){
				gender_cari = 1;
			}
			else if(strcmp(dimana,"has_car") == 0){
                car_cari = 1;
			}
			else if(strcmp(dimana,"has_property") == 0){
				property_cari = 1;
			}

			for(int t = 0; t < i;t++){
				print_ato_gk = 0;
				if(show_all != 1){
					if(id_cari == 1){
						if(strcmp(id[t],samadengan) == 0){
							print_ato_gk = 1;
						}
					}
					else if(name_cari == 1){
						if(strcmp(name[t],samadengan) == 0){
							print_ato_gk = 1;
						}
					}
					else if(city_cari == 1){
						if(strcmp(city[t],samadengan) == 0){
							print_ato_gk = 1;
						}
					}
					else if(gender_cari == 1){
						if(strcmp(gender[t],samadengan) == 0){
							print_ato_gk = 1;
						}
					}
					else if(car_cari == 1){
						if(strcmp(car[t],samadengan) == 0){
							print_ato_gk = 1;
						}
					}
					else if(property_cari == true){
						if(strcmp(property[t],samadengan) == 0){
							print_ato_gk = 1;
						}
					}
				}
				else{
					print_ato_gk = 1;
				}

				if(print_ato_gk == 1){
					if(id_stt == 1){
						printf("id: %s",id[t]);
					}
					if(name_stt == 1){
						if(id_stt == 1){
							printf(", ");
						}
						printf("first_name: %s",name[t]);
					}
					if(city_stt== 1){
						if(id_stt == 1|| name_stt == 1){
							printf(", ");
						}
						printf("city: %s",city[t]);
					}
					if(gender_stt == 1){
						if(id_stt == 1 || name_stt == 1 || city_stt == 1){
							printf(", ");
						}
						printf("gender: %s",gender[t]);
					}
					if(car_stt == 1){
						if(id_stt== 1 || name_stt == 1 || city_stt == 1 || gender_stt == 1){
							printf(", ");
						}
						printf("has_car: %s",car[t]);
					}
					if(property_stt == 1){
						if(id_stt== 1 || name_stt == 1 || city_stt ==1 || gender_stt == 1 || car_stt == 1){
							printf(", ");
						}
						printf("has_property: %s",property[t]);
					}
					printf ("\n");
				}
			}




    }

    fclose (fp);

return 0;
}
