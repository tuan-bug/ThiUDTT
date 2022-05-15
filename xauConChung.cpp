#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void dayCon(string a, string b){
	int n = a.size();
	int m = b.size();
	int max;
	
	int L[n+1][m+1];
	
	for(int i = 0; i <= n;i++)
		L[i][0] = 0;
		
	for(int j = 0; j <= m;j++)
		L[0][j] = 0;
		
		// viet ma tran
	for(int i = 1; i <= n;i++){
		for(int j = 1; j <= m;j++){
			if(a[i - 1] == b[j - 1]){
				L[i][j] = L[i-1][j] + 1;
			}
			else {
				if(L[i - 1][j] >= L[i][j - 1]){
					L[i][j] = L[i -1][j];
				}else{
					L[i][j] = L[i][j - 1];
				}
			}
		}
	}
	
	for(int i = 0; i <= n;i++){
		for(int j = 0; j <= m; j++){
			cout << L[i][j] <<" ";
		}
		cout << endl;
	}
	
	// truy vet nguoc lai
	
	string kq = "";
	int i = n;
	 int j = m;
	 while(L[i][j] != 0){
	 	if(a [ i - 1] == b[j - 1]){
	 		kq += a[i - 1];
	 		i--; j--;
		}
		else {
			if(L[i - 1][j] >= L[i][j - 1]){
				i--;
			}
			else {
				j --;
			}
		}
	 }
	 
	 ofstream out;
	 out.open("ketquaxau.txt");
	 
	 int do_dai = L[n][m];
	 cout <<"\nKet qua la: ";
	 out <<"\nKet qua la: ";
	 for(int i = kq.size() -1 ; i >= 0;i--){
	 	cout << kq[i];
	 	out << kq[i];
	 	
	 }
	 cout <<"\n\nDo dai: "<< do_dai<< endl;
	 out <<"\n\nDo dai: "<< do_dai<< endl;
	 //cout <<"Ket qua: " << kq;
	
	
}

int main(){
	
	string a,b;
	
	ifstream in;
	in.open("a.txt");
	getline(in,a);
	getline(in,b);
//	cout <<"Nhap a: ";
//	cin >> a;
//	cout <<"Nhap b: ";
//	cin >> b;
	dayCon(a,b);
	
}
