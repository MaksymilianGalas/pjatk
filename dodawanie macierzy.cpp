#include <iostream>
using namespace std;
int tab[100][100];
int tab1[100][100];
int odp[100][100];
int a,b,c,d;
int main(){
	cout << "podaj wysokosc i szerokosc pierwszej tabeli" << endl;
	cin >> a >> b;
	cout << "podaj wysokosc i szerokosc drugiej tabeli" << endl;
	cin >> c >> d;
	for(int i=0; i<b; i++){
		for(int j=0; j<a; j++){
			cin>>tab[i][j];
		}	
	}
	for(int i=0; i<c; i++){
		for(int j=0; j<d; j++){
			cin>>tab1[i][j];
		}	
	}
	if(a!=c || b!=d or a!=c or b!=d){
		cout << "B£¥D";
	}
	else{
		for(int i=0; i<c; i++){
			for(int j=0; j<d; j++){
				odp[i][j]=tab[i][j]+tab1[i][j];
			}	
		}
	}
	for(int i=0; i<c; i++){
		for(int j=0; j<d; j++){
			cout<<odp[i][j]<<" ";
		}
		cout<<endl;	
	}
}
