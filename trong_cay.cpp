#include<iostream>
#include<fstream>
using namespace std;
void sapxep(int a[],int n){
	
	for(int i = 0; i < n - 1;i++){
		for(int j =i + 1;j < n;j++){
			if(a[i] < a[j]){
				int t = a[i];
				a[i]=  a[j];
				a[j] = t;
			}
		}
	}
}
int main(){
	int a[100];
	int dem=0;
	ifstream fileIn;
	fileIn.open("a.txt",ios_base::in);
	while(!fileIn.eof()){
		fileIn >> a[dem];
		dem++;
	}
	fileIn.close();
	for(int i=0;i<dem;i++){
		cout<<a[i]<<" ";
	}

	sapxep(a,dem);
	for(int i = 0;i < dem;i++){
		a[i] = a[i] + i + 1;
	}
	int max= a[0];
	
	for(int i = 1;i <dem;i++){
		if(max<a[i])
			max = a[i];
	}
	
	cout <<"\nNgay to chuc bua tiec: " << max+1;
	
	ofstream fileOut;
	fileOut.open("ngaytochuc.txt",ios_base::out);
		fileOut <<"Ngay to chu tiec: " << max +1 << endl;
	fileOut.close();
	
	return 0;
}
