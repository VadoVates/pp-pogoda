#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

const int miesiace = 12, p=0, k=100;

void WypelnienieTablicy(int *[miesiace], unsigned int);
void WypisanieTablicy (int *[miesiace], unsigned int, unsigned int);
double SumaOpadowWRoku (int *[miesiace], unsigned int, unsigned int);
double SredniaRocznaOpadow (int *[miesiace], unsigned int, unsigned int);
double SredniaOpadowWMiesiacu (int *[miesiace], unsigned int, unsigned int);
string MaxOpadyWRoku (int *[miesiace], unsigned int, unsigned int);
string KonwerterMiesiecy (int);

int main()
{
	srand(time(0));
	int N, wybor, temp;
	cout << "PROWADZENIE TABELI OPADOW" << endl;
	cout << "Podaj dla ilu lat chcesz wprowadzic dane" << endl;
	cin >> N;
	int **kalendarz = new int *[N];
	for(int i=0; i<N; i++)
		{
			kalendarz[i] = new int [miesiace];
		}
	cout << "Pierwsze wypelnienie tablicy losowymi danymi" << endl;
	WypelnienieTablicy(kalendarz, N);
	
	do
	{
		cout << endl;
		cout << "MENU" << endl;
		cout << "1 - wyswietl tablice" << endl;
		cout << "2 - sprawdz sume opadow w wybranym tempu" << endl;
		cout << "3 - sprawdz srednia opadow w wybranym tempu" << endl;
		cout << "4 - sprawdz srednia opadow w wybranym miesiacu na przekroju lat" << endl;
		cout << "5 - sprawdzenie kiedy byly najwieksze opady" << endl;
		//cout << " - skoryguj dane" << endl;
		cout << "0 - WYJSCIE" << endl;
		
		cin >> wybor;		
		switch (wybor)
		{
			case 1:
			{
				cout << endl << "WYPISANIE TABLICY:" << endl;
				WypisanieTablicy (kalendarz, N, miesiace);
				break;
			}
			case 2:
			{			
				cout << endl << "SUMA OPADOW W WYBRANYM ROKU" << endl;
				cout << "Podaj informacje w ktorym roku z kolei, zyczysz sobie informacje o sumie opadow: ";
				do
				{
					cin >> temp;
					if (temp <1 || temp > N) cout << "Podany rok jest spoza zakresu, prosze podaj temp jeszcze raz" << endl; 
				} while (temp <1 || temp > N);
				cout << "Suma opadow w tempu: " << temp << " wynosi: " << SumaOpadowWRoku(kalendarz, temp-1, miesiace) << endl;
				break;
			}
			case 3:
			{
				cout << endl << "SREDNIA OPADOW W WYBRANYM ROKU" << endl;
				cout << "Podaj informacje w ktorym roku z kolei, zyczysz sobie informacje o sredniej opadow: ";
				do
				{
					cin >> temp;
					if (temp <1 || temp > N) cout << "Podany rok jest spoza zakresu, prosze podaj temp jeszcze raz" << endl; 
				} while (temp <1 || temp > N);
				cout << "Srednia opadow w tempu: " << temp << " wynosi: " << SredniaRocznaOpadow(kalendarz, temp-1, miesiace) << endl;
				break;
			}
			case 4:
			{
				cout << endl << "SREDNIA OPADOW W WYBRANYM MIESIACU NA PRZESTRZENI LAT" << endl;
				cout << "Podaj informacje w ktorym miesiacu z kolei <1-12>, zyczysz sobie informacje o sredniej opadow: ";
				do
				{
					cin >> temp;
					if (temp <1 || temp > miesiace) cout << "Podany miesiac jest spoza zakresu, prosze podaj miesiac jeszcze raz" << endl; 
				} while (temp <1 || temp > miesiace);
				cout << "Srednia opadow w miesiacu " << KonwerterMiesiecy(temp-1) << " wynosi: " << SredniaOpadowWMiesiacu(kalendarz, N, temp-1) << endl;
				break;
			}
			case 5:
			{
				cout << endl << "KIEDY BYLY NAJWIEKSZE OPADY" << endl;
				for (int i=0;i<N;i++)
				{
					cout << "Najwieksze opady w roku " << i+1 << " byly w miesiacu: " << MaxOpadyWRoku(kalendarz, i, miesiace) << endl;
				}
				break;
			}
			/*
			case :
			{
				cout << "Korekcja danych" << endl;
				
				break;
			}
			*/
			case 0:
			{
				cout << "Wyjscie z programu" << endl;
				break;
			}
			default:
			{
				cout << "Wprowadzono nieprawidlowa liczbe. Prosze wprowadzic ponownie" << endl;
				break;
			}
		}
	} while (wybor!=0);
	
	return 0;
}

void WypelnienieTablicy(int **tab, unsigned int wiersz)
{
	for (int i=0;i<wiersz;i++)
	{
		for (int j=0;j<miesiace;j++)
		{
			tab[i][j]=rand()%(k+1-p)+p;
		}
	}
}

void WypisanieTablicy (int **tab, unsigned int wiersz, unsigned int kolumna)
{
	for (int i=0;i<kolumna;i++)
	{
		for (int j=0;j<wiersz;j++)
		{
			cout << setw(3) << KonwerterMiesiecy(i) << "." << setw(2) << j+1 << ": " << setw(4) << tab[j][i]/10.0 << "|";
		}
		cout << endl;
	}
}

double SumaOpadowWRoku (int **tab, unsigned int wiersz, unsigned int kolumna)
{
	long long suma=0;
	for (int j=0;j<kolumna;j++)
	{
		suma+=tab[wiersz][j];
	}
	return (suma/10.0);
}

double SredniaRocznaOpadow (int **tab, unsigned int wiersz, unsigned int kolumna)
{
	return (SumaOpadowWRoku(tab, wiersz, kolumna)/12.0);
}

double SredniaOpadowWMiesiacu (int **tab, unsigned int wiersz, unsigned int kolumna)
{
	long long suma=0;
	for (int i=0;i<wiersz;i++)
	{
		suma+=tab[i][kolumna];
	}
	return ((double)suma/wiersz/10.0);
}

string KonwerterMiesiecy (int miesiac)
{
	string nazwa;
	switch (miesiac)
	{
		case 0: nazwa="sty"; break;
		case 1: nazwa="lut"; break;
		case 2: nazwa="mar"; break;
		case 3: nazwa="kwi"; break;
		case 4: nazwa="maj"; break;
		case 5: nazwa="cze"; break;
		case 6: nazwa="lip"; break;
		case 7: nazwa="sie"; break;
		case 8: nazwa="wrz"; break;
		case 9: nazwa="paz"; break;
		case 10: nazwa="lis"; break;
		case 11: nazwa="gru"; break;
	}
	return nazwa;
}

string MaxOpadyWRoku (int **tab, unsigned int wiersz, unsigned int kolumna)
{
	float max=tab[wiersz][0];
	string counter=KonwerterMiesiecy(0);
	for (int i=1; i<kolumna; i++)
	{
		if (tab[wiersz][i] > max)
		{
			max=tab[wiersz][i];
			counter=KonwerterMiesiecy(i);
		}
		else if (tab[wiersz][i] == max)
		{
			counter+=", ";
			counter+=KonwerterMiesiecy(i);
		}
	}
	return counter;
}
