#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void bienDoi(string a, string b){
	ofstream fileOut;
	fileOut.open("baby.txt",ios_base::out);
	int n = a.size();
	int m = b.size();
	int L[n+1][m+1];
	for(int i = 0; i <=n;i++)
		L[i][0] = i;
	for(int i = 0; i <=m;i++)
		L[0][i] = i;
		
	for(int i = 1; i <=n;i++){
		for(int j = 1; j <= m;j++){
			if(a[i -1] == b[j - 1]){
				L[i][j] = L[i - 1][j - 1];
			}
			else {
				L[i][j] = min(L[i - 1][j], min(L[i -1][j - 1],L[i][j - 1]) ) + 1;
			}
		}
	}
	cout << endl;
	for(int i = 0; i < n;i++){
		for(int j = 0; j < m;j++){
		cout << L[i][j] << "  ";
		}
		cout << endl;
	}
	int sobuoc = L[n][m];
	
	cout <<"So buoc thuc hien: " << sobuoc << endl;
	fileOut << "So buoc thuc hien: "<<sobuoc << endl;
	// Truy v?t
	int i = n;
	int j = m;
	string kq;
	if(n == 0){
		for(int i = 0; i < m;i++){
			kq += b[i];
		}
	}
	while(i >= 0 && j >= 0){
		
		if(a[i - 1] == b[j - 1]){
			i--, j--;
		}
		else {
			if(L[i - 1][j] <= L[i - 1][j - 1] && L[i -1][j] <= L[i][j - 1]){
				cout <<"Xoa : " << a[i - 1] << endl;
				fileOut << "Xoa: "<<a[i - 1] << endl;
				i--;
				kq += a[i];
			}
			else if(L[i - 1][j - 1] < L[i - 1][j] && L[i - 1][j - 1] <= L[i][j - 1]){
				cout <<"Thay the: " << a[i - 1] <<" boi: " << b[j - 1] << endl;
				fileOut <<"Thay the: " << a[i - 1] <<" boi: " << b[j - 1] << endl;
				i--;
				j--;
			}
			else{
				cout <<"Chen: " << b[j - 1] <<" sau: " <<a[i - 1] << endl;
				fileOut <<"Chen: " << b[j - 1] <<" sau: " <<a[i - 1] << endl;
				j--;
			//	cout <<"\n CHuoi con lai: " << a << endl;
			}
		}
		kq += a[i];	
		
		
	}	
}

int main(){
	string a,b;
    ifstream doc;
    doc.open("a.txt");
    
    getline (doc,a) ;
    
    cout <<"hgfsdh: " << a;
    getline (doc,b) ;
    cout <<"\nhgfsdh: " << b;
    doc.close();
//	cout <<"Nhap a: "; cin >> a;
//	cout <<"Nhap b: "; cin >> b;
	bienDoi(a,b);
	
}















