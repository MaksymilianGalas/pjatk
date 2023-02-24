#include <string>
#include <cmath>
#include <iostream>
using namespace std;
int a,ostatnia,pesel, suma_kontrolna, pomocnicza,pom1;
int spr[10] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};

int main()
{
	start:

	cout << "podaj numer pesel: "<<endl;
	string pesel; getline(cin, pesel);

	while(pesel.size() != 11)
	{
		goto start;
	}
	
	ostatnia = pesel.at(10) - 48;
	suma_kontrolna = 0;

	for(int i = 0; i < 10; i++)
	{
		suma_kontrolna += spr[i] * (pesel.at(i) - 48);
	}
	
	pomocnicza = suma_kontrolna;
	while(pomocnicza > 10){
		pomocnicza= pomocnicza%10;
	}
	pom1 = abs(pomocnicza-10);
	if(pom1 == ostatnia){
		cout << "podany pesel jest prawidlowy" << endl;
	}
	else{
		cout << "podany psesel jest nieprawidlowy" << endl;
	}
	cout << "chcesz ponownie uruchomic program?: tak-1 / nie-0" << endl;
	cin >> a;
	if(a == 1){
		goto start;
	}
}
