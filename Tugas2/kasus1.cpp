#include<iostream>
using namespace std;

int main(){
	int x[99];
	int n,maks,i;
	
	cout<<"Masukkan Jumlah Array :";cin>>n;
	for(int i=0;i<n;){
		cout<<"Bilangan ke - "<<++i<<" : ";cin>>x[i];
	}
	
	maks = x[1];
	
	i = 2;
	
	do{
		if(x[i]>maks){
			maks=x[i];
		}
		i=i+1;
	}while(i<=n);
	cout<<"Output = "<<maks<<endl;
}