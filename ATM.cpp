#include<iostream>
#include<fstream>
#include<math.h>
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
	int c, atm;
	int a[100];
	int dem=0;
	ifstream fileIn;
	fileIn.open("a.txt",ios_base::in);
	while(!fileIn.eof()){
		fileIn >> a[dem];
		
		dem++;
	}
	fileIn.close();
	atm = a[0];
	c = a[1];
	int b[10];
	int mc = 0;
	for(int i = 2; i < dem;i++){
		b[mc] = a[i];
		mc++;
	}

cout <<"tien muon rut: " << atm << endl;
cout <<"c: " << c << endl;
for(int i = 0; i < mc;i++){
		cout << b[i] <<"  ";
	}

	int mg[100];
	int d = 0;

	for(int i = 0; i < mc;i++){
		for(int j = 0; j <= c;j++){
			mg[d] = b[i]*pow(10,j);
			d++;
		}
	}
	
	cout <<"\nCac menh gia: ";
	sapxep(mg,d);
	for(int i=0;i<d;i++){
		cout<<mg[i]<<" ";
	}
	
	int tien[100];
	

	int to;
	if(atm % mg[d - 1] == 0){
		for(int i = 0; i < d;i++){
		tien[i] = atm/mg[i];
		if(tien[i] > 0){
			cout <<"\nMenh  gia " <<mg[i] << " co: "<< tien[i] << endl;
			to += tien[i];
		}
		
		atm = atm - tien[i]* mg[i];
		}
	}else{
			cout <<"\nK rut dc";
	}
	
		
	
	
	return 0;
}
