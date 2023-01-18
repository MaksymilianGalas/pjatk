#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

void printY(char input, int size, int x, int move_y) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;// Pobranie wymiarów bufora ekranu
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	
    for (int i = 0; i < csbi.srWindow.Bottom; i++) {   //pętla rysujaca Y
        for (int j = 0; j < csbi.srWindow.Right; j++) {
		
            if(i >= move_y && i < move_y + size ){  // Jeżeli aktualna pozycja jest w obszarze rysowania litery
                if(i - move_y < size/2 && j == x - (size/2 - (i - move_y)) && j >= x - size/2) cout << input;  // Rysowanie pierwszej połowy litery
                else if(i - move_y < size/2 && j == x + (size/2 - (i - move_y)) && j <= x + size/2) cout << input;   // Rysowanie drugiej połowy litery
                else if(i - move_y >= size/2 && j == x && j >= x - size/2 && j <= x + size/2) cout << input;   // Rysowanie trzeciej części litery
                else cout << " ";
            }
            else cout << " ";
        }
        cout << endl;
    }

}
// Maksymilian Galas s27479
int main() {

	int size;
    char input;
    cout << "Wprowadz znaczek ASCII jaki chcesz uzyc: ";
    cin >> input;
    error:
    cout << "Wporwadz rozmiar poczatkowy: ";
    cin >> size;
    	if(size < 0){
    		goto error;
		}
	system ("cls");
    CONSOLE_SCREEN_BUFFER_INFO csbi;// Pobranie wymiarów bufora ekranu
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);


    int x = csbi.srWindow.Right / 2;// Obliczenie wspó³rzêdnych œrodka ekranu
    int move_y = csbi.srWindow.Bottom / 2;

    while(true) {
    	system ("cls");
        printY(input, size, x, move_y);
        char key = getch();
	    
        if(key == '+') size++, move_y--;   // Obsługa ruchów litery 'Y'
        else if(key == '-') size--, move_y++;
        else if(key == 72) move_y--;
        else if(key == 80) move_y++;
        else if(key == 75) x--;
        else if(key == 77) x++;
    }
    return 0;
}


