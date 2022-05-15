#include<fstream>
#include <iostream>

#include<bits/stdc++.h>
using namespace std;
int a;
int b;
int c;

int min(int w, int z){
if (w < z)
    return w;
else
    return z;
}
void show(int a, int b){
	cout << "(" << a << " , " << b <<")"<<endl;
//	ofstream fileOut;
//	fileOut.open("rotnuoc.txt",ios_base::out);
//	fileOut << "(" << a << " , " << b <<")"<<endl;
//	fileOut.close();

}

void tim_toa_do(int c, int a, int b)
{
int xq = 0, yq = 0;
int t;
cout << "Toa do cac dinh:" <<endl;
ofstream fileOut;
fileOut.open("rotnuoc.txt",ios_base::out);
while (xq != c && yq != c ){
  if (xq == 0){ //1
    xq = a;
    show(xq, yq);
    fileOut << "(" << xq << " , " << yq <<")"<<endl;
  }
  else if (yq == b){ //2
    yq = 0;
    show(xq, yq);
    fileOut << "(" << xq << " , " << yq <<")"<<endl;
  }
  else{ //3
    t = min(b - yq, xq);
    yq= yq + t;
    xq = xq - t;
    show(xq, yq);
    fileOut << "(" << xq << " , " << yq <<")"<<endl;
    }
}
fileOut.close();
    //fileOut << "(" << a << " , " << b <<")"<<endl;
}

int main(){
	
	ifstream fileIn;
	fileIn.open("C:\\Users\\PC\\Downloads\\UDTT\\a.txt",ios_base::in);
	
	int ab[100]; int dem = 0;
	
	while(!fileIn.eof()){
		fileIn >> ab[dem];
		dem++;
	}
	c = ab[0];
	a = ab[1];
	b = ab[2];

//cout << "Nhap vao binh c can tim ";
//cin >> c;
//cout << "Nhap vao binh a:  ";
//cin >> a;
//cout << "Nhap vao binh b: ";
//cin >> b;
if(c < a || c < b){ 
    
    if( c % ( __gcd(a,b) ) == 0 )
        tim_toa_do(c, a,b);
    else
        cout<<"K the tim duoc....\n";  
}
else
  cout<<"K the tim dc..(*_*)\n"; 
}
