#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Customer{
	char ID[20];
	char name[100];
	char city[20];
	char gender[5];
	char car[5];
	char property[5];
};

int main(){

	struct Customer data[110];

	char temp[200];

	char filter[200];
	char key[200];
	char value[200];

	char check[5];
	char requirement1[10];
	char requirement2[10];
	char print[6][30];

	bool show_ID = false;
	bool show_name = false;
	bool show_city = false;
	bool show_gender = false;
	bool show_car = false;
	bool show_property = false;

	bool search_ID = false;
	bool search_name = false;
	bool search_city = false;
	bool search_gender = false;
	bool search_car = false;
	bool search_property = false;

	bool print_all = false;
	bool printing = false;

	int jumlah = 0;
	int siklus = 0;
	int lokasi = 0;


	FILE *fp;
	fp = fopen("customer_app_data.csv","r");
	fgets(temp, 200, fp);


	while (fgets(temp, 200, fp)){

		siklus = 0;
		lokasi = 0;

		int len = strlen(temp);

		for(int i = 0; i < len;i++){

			if(temp[i] != ',' && siklus == 0){
				data[jumlah].ID[lokasi] = temp[i];
				lokasi++;
			}
			else if(temp[i] != ',' && siklus == 1){
				data[jumlah].name[lokasi] = temp[i];
				lokasi++;
			}
			else if(temp[i] != ',' && siklus == 2){
				data[jumlah].city[lokasi] = temp[i];
				lokasi++;
			}
			else if(temp[i] != ',' && siklus == 3){
				data[jumlah].gender[lokasi] = temp[i];
				lokasi++;
			}
			else if(temp[i] != ',' && siklus == 4){
				data[jumlah].car[lokasi] = temp[i];
				lokasi++;
			}
			else if(temp[i] != ',' && siklus == 5){
				data[jumlah].property[lokasi] = temp[i];
				lokasi++;
			}
			else{
				lokasi = 0;
				siklus++;
			}
		}
		jumlah++;
    }

	while(true){
		for(int i = 0; i < 200;i++){
			filter[i] = '\0';
			key[i] = '\0';
			value[i] = '\0';
		}

		for(int i = 0; i < 6;i++){
			for(int j = 0; j < 30;j++){
				print[i][j] ='\0';
			}
		}

		show_ID = false;
		show_name = false;
		show_city = false;
		show_gender = false;
		show_car = false;
		show_property = false;

		search_ID = false;
		search_name = false;
		search_city = false;
		search_gender = false;
		search_car = false;
		search_property = false;

		print_all = false;

		siklus = 0;
		lokasi = 0;

	//	system("CLS");
		printf("Welcome to Michael 2301887212 Issurance Database\n");
		printf("Please Input Command/[SHOW <coloum-filter> WHERE <search-key> equals <search-value>]\n");
	//	printf(">");

		scanf("%[^\n]", temp);
		system("CLS");

		if(temp[0] != 'S' || temp[1] != 'H' || temp[2] != 'O' || temp[3] != 'W'){
			printf("Wrong Input\nPress Enter to Continue");
			getchar();
			getchar();
		}
		else{
			int len = strlen(temp);
			//Memisahkan semua value input
			for(int i = 5; i < len;i++){
				if(temp[i] != ' ' && siklus == 0){
					filter[lokasi] = temp[i];
					lokasi++;
				}
				else if(temp[i] != ' ' && siklus == 1){
					requirement1[lokasi] = temp[i];//where
					lokasi++;
				}
				else if(temp[i] != ' ' && siklus == 2){
					key[lokasi] = temp[i];
					lokasi++;
				}
				else if(temp[i] != ' ' && siklus == 3){
					requirement2[lokasi] = temp[i];//euals
					lokasi++;
				}
				else if(temp[i] != ' ' && siklus == 4){
					value[lokasi] = temp[i];
					lokasi++;
				}
				else{
					lokasi = 0;
					siklus++;
				}
			}

			check[0] = filter[0];
			//cek output column
			if(check[0] == '*'){
				show_ID = true;
				show_name = true;
				show_city = true;
				show_gender = true;
				show_car = true;
				show_property = true;
			}
			else{
				int len = strlen(filter);
				int j = 0;
				int k = 0;

				for(int i = 0; i < len;i++){
					if(filter[i] != ','){
						print[j][k] = filter[i];
						k++;
					}
					else{
						j++;
						k = 0;
					}
				}
				for(int i = 0; i < 6; i++){
					if(strcmp(print[i],"id") == 0){
						show_ID = true;
					}
					else if(strcmp(print[i],"first_name") == 0){
						show_name = true;
					}
					else if(strcmp(print[i],"city") == 0){
						show_city = true;
					}
					else if(strcmp(print[i],"gender") == 0){
						show_gender = true;
					}
					else if(strcmp(print[i],"has_car") == 0){
						show_car = true;
					}
					else if(strcmp(print[i],"has_property") == 0){
						show_property = true;
					}
				}
			}

			//cek output row
			if(strcmp(requirement1,"WHERE") != 0){
				print_all = true;
			}

			if(strcmp(key,"id") == 0){
				search_ID = true;
			}
			else if(strcmp(key,"first_name") == 0){
				search_name = true;
			}
			else if(strcmp(key,"city") == 0){
				search_city = true;
			}
			else if(strcmp(key,"gender") == 0){
				search_gender = true;
			}
			else if(strcmp(key,"has_car") == 0){
				search_car = true;
			}
			else if(strcmp(key,"has_property") == 0){
				search_property = true;
			}




			//print
			for(int i = 0; i < jumlah;i++){
				printing = false;

				if(print_all != true){
					if(search_ID == true){
						if(strcmp(data[i].ID,value) == 0){
							printing = true;
						}
					}
					else if(search_name == true){
						if(strcmp(data[i].name,value) == 0){
							printing = true;
						}
					}
					else if(search_city == true){
						if(strcmp(data[i].city,value) == 0){
							printing = true;
						}
					}
					else if(search_gender == true){
						if(strcmp(data[i].gender,value) == 0){
							printing = true;
						}
					}
					else if(search_car == true){
						if(strcmp(data[i].car,value) == 0){
							printing = true;
						}
					}
					else if(search_property == true){
						if(strcmp(data[i].property,value) == 0){
							printing = true;
						}
					}
				}
				else{
					printing = true;
				}

				if(printing == true){
					if(show_ID == true){
						printf("id: %s",data[i].ID);
					}
					if(show_name == true){
						if(show_ID == true){
							printf(", ");
						}
						printf("first_name: %s",data[i].name);
					}
					if(show_city == true){
						if(show_ID == true || show_name == true){
							printf(", ");
						}
						printf("city: %s",data[i].city);
					}
					if(show_gender == true){
						if(show_ID == true || show_name == true || show_city == true){
							printf(", ");
						}
						printf("gender: %s",data[i].gender);
					}
					if(show_car == true){
						if(show_ID == true || show_name == true || show_city == true || show_gender == true){
							printf(", ");
						}
						printf("has_car: %s",data[i].car);
					}
					if(show_property == true){
						if(show_ID == true || show_name == true || show_city == true || show_gender == true || show_car == true){
							printf(", ");
						}
						printf("has_property: %s",data[i].property);
					}
					puts("");
				}
			}
			getchar();
			printf("Press Enter for next search");
			getchar();
		}
	}


	fclose(fp);
	return 0;
}
