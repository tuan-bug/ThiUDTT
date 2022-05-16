#include <iostream>
#include <stdlib.h>
#include<fstream>
using namespace std;
int N;
int M;
int b1,b2;
int e1,e2;
//Chung ta co mot me cung dang ma tran: maze[5][5]
int maze[100][100] ;

//Mot ma tran de luu cach giai
int solution[100][100];

//Ham in cach giai
void Output(int arr[100][100])
{
    int i,j;
    for(i=0;i<=N+1;i++)
    {
        for(j=0;j<=M+1;j++)
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}
void Output2(int arr[100][100]){
	ofstream out;
	out.open("ketquaMT.txt");
    int i,j;
    for(i=1;i<N+1;i++)
    {
        for(j=1;j<M+1;j++)
        {
            cout<<arr[i][j]<<"  ";
            out<<arr[i][j]<<"  ";
            
        }
        cout<<endl;
        out << endl;
    }
    out.close();
}
//Ham giai dung backtracking
int solvemaze(int r, int c){
    //Diem xuat phat luon la o vi tri 1,1
    //Diem ket thuc luon la o vi tri cuoi cung là N,N
    //Khi o vi tri cuoi cung ket thuc recursive
    if((r==e1)  && (c==e2) ){
        solution[r][c] = 1;
        return 1;
    }
    
    while(r == N && maze[r][c] == 0 && c < N && solution[r][c] == 0){
    	solution[r][c] = 1;
    	// dex phai
    	 if(solvemaze(r, c+1))
            return 1;
         //di len
        if(solvemaze(r-1, c))
            return 1;
        //re trai
        if(solvemaze(r, c-1))
            return 1;
        // lên chéo phai
        if(solvemaze(r - 1, c+1))
            return 1;
    	// cheo len trai
        if(solvemaze(r-1, c-1))
            return 1;
	}
	// doc
	while(c == N && maze[r][c] == 0 && solution[r][c] == 0 && maze[r][c] == 0 && r < N){
    	solution[r][c] = 1;
    	//di xuong
        if(solvemaze(r+1, c))
            return 1;
         //di len
        if(solvemaze(r-1, c))
            return 1;
        //re trai
        if(solvemaze(r, c-1))
            return 1;
    	// cheo len trai
        if(solvemaze(r-1, c-1))
            return 1;
        
           // cheo xuong trai
        if(solvemaze(r+1, c-1))
            return 1;
	}
    //Dat if kiem tra xem co the di duoc khong?
    //Tat ca cac o phai nam trong khoang (0,N-1) nam ngoai khoang khong the di duoc
    //Kiem tra cach giai solution[r][c] da di chua?, neu nam trong cac duong da di thi lien tuc backtracking
    //kiem tra maze[r][c] xem co bi chan khong?
    if((r < N || c < N )&& solution[r][c] == 0 && maze[r][c] == 0)
    {
        //Thoa man dieu kien tren thi duoc di, gan 1
        solution[r][c] = 1;
        //di xuong
        if(solvemaze(r+1, c))
            return 1;
        //re phai
        if(solvemaze(r, c+1))
            return 1;
        //di len
        if(solvemaze(r-1, c))
            return 1;
        //re trai
        if(solvemaze(r, c-1))
            return 1;
        // lên chéo phai
        if(solvemaze(r - 1, c+1))
            return 1;
        // cheo xuong phai
        if(solvemaze(r+ 1, c+1))
            return 1;
           // cheo xuong trai
        if(solvemaze(r+1, c-1))
            return 1;
        // cheo len trai
        if(solvemaze(r-1, c-1))
            return 1;
        //backtracking neu tat ca cac dieu kien sai het
        solution[r][c] = 0;
        return 0;
    }
    return 0;

}

int main(){
	ifstream f;
	f.open("matran.txt");
	if (f == NULL)
		return false;
	f >> N;
	f >> M;
	f >> b1;
	f >> b2;
	f >> e1;
	f >> e2;
	for(int i=1; i<N+1; i++){
		for(int j= 1; j<M+1; j++)
			f >> maze[i][j];		
	}
	
	f.close();
	

for(int i = 0; i < N+2;i++){
	for(int j = 0; j < M+2;j++){
		if(i == 0 || i == N + 1 || j == 0 || j == M+1){
			maze[i][j] = 1;
		}
	}
}
    //Khoi tao cach giai: ma tran solution = 0
    int i,j;
    for(i=0; i<=N+1; i++)
    {
        for(j=0; j<=M+1; j++)
        {
            solution[i][j] = 0;
        }
    }
    //Trong ma tran da cho, 1 la diem chan khong the di, 0 la duong di
    cout<<"Maze input:\n";
    Output(maze);
    
    //Trong ma tran solution, 1 la duong di ma thuat toan Backtracking da giai
    //Di vao dieu kien goi de quy
    if (solvemaze(b1,b2)){
    	cout<<"\nSolution: \n";
        Output2(solution);
	}	
    else
        cout<<"Khong the giai me cung tren !";
    return 0;
}
