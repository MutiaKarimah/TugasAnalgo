#include <iostream>
using namespace std;

int main(){
	int i,j,mid,n,x[100],y,idx;
	bool found=false;
	
	cout<<"Masukkan Jumlah Array : ";cin>>n;
	for (int i=0; i<n;){
		cout<<"Bilangan ke - :"<<++i<<" : ";cin>>x[i];
	}
	i=1;j=n;
	cout<<"Cari elemen : ";cin>>y;
	do{
		mid=(i+j)/2;
		if (x[mid]==y)
			found=true;
		else if (x[mid]<y)
			i=mid+1;
		else
			j=mid-1;
	}while(found==false&&i<=j);
	
	if (found==true)
		idx=mid;
	else
		idx=0;
	
	cout<<"Bilangan berada di index ke - "<<idx;	
}
