#include<stdio.h>

char BlackBoard[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};;
char WhiteBoard[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};;
char WhiteLetter, WhiteNumber, BlackLetter, BlackNumber;
int MaxMove;
void prin(char a[9][9]){

    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            printf ("%c",a[i][j]);
        }printf("\n");
    }
    printf("\n");
}
int WhiteKnight(int WhiteLetter, int WhiteNumber, int KnightMove){
 	if(WhiteBoard[WhiteLetter - 'A'][WhiteNumber - '1'] || WhiteLetter < 'A' || WhiteLetter > 'H' || WhiteNumber < '1' || WhiteNumber > '8'){
 		return 0;
 	}
 	if(KnightMove > MaxMove){
  		return 0;
 	}
 	printf ("White\n");
    prin(WhiteBoard);
  	KnightMove++;
  	WhiteBoard[WhiteLetter - 'A'][WhiteNumber - '1'] = 1;
  	WhiteKnight(WhiteLetter+1, WhiteNumber-2, KnightMove);
  	WhiteKnight(WhiteLetter+2, WhiteNumber+1, KnightMove);
 	WhiteKnight(WhiteLetter+2, WhiteNumber-1, KnightMove);
  	WhiteKnight(WhiteLetter-1, WhiteNumber+2, KnightMove);
  	WhiteKnight(WhiteLetter-2, WhiteNumber-1, KnightMove);
  	WhiteKnight(WhiteLetter-2, WhiteNumber+1, KnightMove);
  	WhiteKnight(WhiteLetter-1, WhiteNumber-2, KnightMove);
  	WhiteKnight(WhiteLetter+1, WhiteNumber+2, KnightMove);

 	return 0;
}

int BlackKnight(int BlackLetter, int BlackNumber, int KnightMove){
 	if(BlackBoard[BlackLetter - 'A'][BlackNumber - '1'] || BlackNumber < '1' || BlackNumber > '8' || BlackLetter < 'A' || BlackLetter > 'H'){
  		return 0;
 	}
 	if(KnightMove > MaxMove){
  		return 0;
 	}
 	printf("Black\n");
 	prin(BlackBoard);
  	KnightMove++;
  	BlackBoard[BlackLetter - 'A'][BlackNumber - '1'] = 1;
  	BlackKnight(BlackLetter+2, BlackNumber+1, KnightMove);
  	BlackKnight(BlackLetter-2, BlackNumber-1, KnightMove);
  	BlackKnight(BlackLetter+1, BlackNumber+2, KnightMove);
  	BlackKnight(BlackLetter+1, BlackNumber-2, KnightMove);
  	BlackKnight(BlackLetter-2, BlackNumber+1, KnightMove);
  	BlackKnight(BlackLetter-1, BlackNumber-2, KnightMove);
  	BlackKnight(BlackLetter+2, BlackNumber-1, KnightMove);
  	BlackKnight(BlackLetter-1, BlackNumber+2, KnightMove);

 	return 0;
}

int CountMove(){
 	for(int i = 0; i < 9; i++){
  		for(int j = 0; j < 9; j++){
   			if(BlackBoard[i][j] == 1 && WhiteBoard[i][j] == 1){
    		printf("YES\n");
			return 0;
   			}
  		}
 	}
 	printf("NO\n"); return 0;
}

void reset(){
	for(int i =0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			WhiteBoard[i][j] = 0;
			BlackBoard[i][j] = 0;
		}
	}
}

int main(){

	int tc;
	scanf("%d", &tc);
    getchar();
	for(int t = 1; t <= tc; t++){
 	scanf("%d", &MaxMove); getchar();
 	scanf("%c%c", &WhiteLetter, &WhiteNumber); getchar();
 	scanf("%c%c", &BlackLetter, &BlackNumber); getchar();

 	reset();

 	WhiteKnight(BlackLetter, BlackNumber, 0);
 	BlackKnight(WhiteLetter, WhiteNumber, 0);

 	printf("Case #%d: ", t);

 	CountMove();

 	}

 	return 0;
}
