#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int rowDir[] = {-1, 0, 0, 1};
int colDir[] = {0, -1, 1, 0};
// int rowDir[]= { -1, -1, -1, 0, 0, 1, 1, 1 };
// int colDir[]= { -1, 0, 1, -1, 1, -1, 0, 1 };

int n = 0;
int arr[1001][1001] = {0};
bool visited[1001][1001] = {0};

void printVisited()
{
    cout << "visited" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
}

void printArr()
{
    cout << "arr" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void setNumberEaten (int num){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (arr[i][j]==num){
				arr[i][j]=0;
			}
		}
	}
}

int isSafe(int row, int col, int maxRow, int maxCol)
{
    if ((row >= 0) && (row < maxRow) && (col >= 0) && (col < maxCol) && (arr[row][col] != 0 && !visited[row][col]))
    {
        return 1;
    }
    return 0;
}

void dfs(int row, int col, int maxRow, int maxCol)
{

    visited[row][col] = true;

//    printVisited();

    for (int i = 0; i < 4; ++i)
    {
        if (isSafe(row + rowDir[i], col + colDir[i], maxRow, maxCol) == 1)
        {
            dfs(row + rowDir[i], col + colDir[i], maxRow, maxCol);
        }
    }
}

int countChunks(int row, int col)
{

//    bool visited[row + 1][col + 1] = {0};
//    printVisited();

    int countChunk = 0;
//    cout << "start for " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
//        	cout << "i , j = "<< i << ","<< j<< endl;
//        	cout << "visited i,j = "<<visited[i][j]<< endl;
            if (arr[i][j] != 0 && visited[i][j]== 0)
            {
                dfs(i, j, row, col);
//                printVisited();
                countChunk++;
//                cout << "chunks " << countChunk<<endl;
            }
        }
    }
//    cout << "end for chunks = " << countChunk<<endl;
    if (countChunk==0)return 1;
    return countChunk;
}

int main()
{

    int N;
    cin >> N;
    for (int t = 0; t < N; t++)
    {
        // int n=0;

        cin >> n;
        // int arr[n+1][n+1];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }

//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                cout << arr[i][j] << " ";
//            }
//            cout << endl;
//        }

        cout << "=============" << endl;
        
		int maxNum=0;
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				if (arr[i][j]>maxNum){
					maxNum= arr[i][j];
				}
				if (arr[i][j]==1){
					arr[i][j]=0;
				}
			}
		}
//		cout << "max num " << maxNum;
        int maxChunks = 0;

        for (int i=1;i<=maxNum;i++){   
			
			if (i!=1){
				setNumberEaten(i);
			}
//			printArr();
			memset(visited, 0, sizeof(visited));
            int chunks =countChunks(n, n);
            if (maxChunks<chunks){
                maxChunks=chunks;
            }
            
        }
        cout << "#" << t + 1 << " " << maxChunks<< endl;

//        printVisited();
    }

    return 0;
}

