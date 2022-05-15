#include<iostream>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double PI = 3.1415926;
int x,y;
int nguoi=0;
int soluong=0;
double a[10001];
double *b = new double[100];
double Max(double x,double y)
{
    if(x>=y)
    return x;
    else return y;
}
double p(double m)
{
    int sum=0;
    for(int i=0;i<soluong;i++){
    	 //printf("\nThe tich 111: %.6f",b[i]);
        sum = floor(sum + b[i] / m);
        printf("\nThe tich 111: %d",sum);
    }
    cout <<endl;
    if(sum >= nguoi + 1)
    	return sum;
    return 0;
}
int main()
{
	
	ifstream a;
	a.open("a.txt", ios_base::in);
	if (a.fail() == true)
	{
		cout << "\nFile khong ton tai";
		system("pause");
		return 0; 
	}
	double *arr;
	arr = new double[100];
	int i = 0;
	int j=0;
	int dem = 0;
	while (!a.eof()){	
		a >> arr[i]; 
		i++;
		dem++;
	}
	for(int i=0;i<dem;i++){
		soluong=arr[0];
		nguoi=arr[1];
		if(i>1){
			b[j]=arr[i];
			j++;
		}
	}
//	y = soluong;
	cout<<"so luong: "<<soluong<<endl;
	cout<<"nguoi: "<<nguoi<<endl;
	for(int k=0;k<j;k++){
		cout<<b[k]<<"\t";
	}
	a.close();

   double max = 0;
    cout <<"\n === Nhap the tich cua banh ===\n";
    for(int i = 0; i < soluong; i++){
        // tính th? tích c?a nh?ng cái bánh, d? cao c?a bánh luôn b?ng 1 theo d? bài
        b[i] = b[i] * b[i] * PI * 1;
         printf("\nThe tich: %.6f",b[i]);
        // Tìm cái bánh có th? tích l?n nh?t
        max = Max( max, b[i] );
    }
    printf("\nThe tich max: %.6f",max);
    
    double lo = 0.0 , hi = max;
    while( hi - lo > 0.00001){
            double mid = ( lo + hi ) / 2.0;
            if ( p(mid) ) {
            	lo = mid;
            	cout <<"Lo: " << lo;
			}
            else {
            	hi = mid;
            	cout <<"Hi : " << hi;
			}
                
        }
        printf("\nThe tich nhan dc: %.6f",lo);
    return 0;
}

