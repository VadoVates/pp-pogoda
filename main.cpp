//Autor Marek Gorski, nr indeksu 155647, grupa D1, semestr II, Wydzial Informatyki, Zarzadzania i Transportu,
//rok akademicki 2022/2023

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

const unsigned int miesiace = 12, p=0, k=100;

void WypelnienieTablicy(int *[miesiace], unsigned int);
void WypisanieTablicy (int *[miesiace], unsigned int, unsigned int, int);
double SumaOpadowWRoku (int *[miesiace], unsigned int, unsigned int);
double SredniaRocznaOpadow (int *[miesiace], unsigned int, unsigned int);
double SredniaOpadowWMiesiacu (int *[miesiace], unsigned int, unsigned int);
string KonwerterMiesiecy (unsigned int);
string MaxOpadyWRoku (int *[miesiace], unsigned int, unsigned int, unsigned int &);

int main()
{
	srand(time(0));
	unsigned int wybor, temp, maxOpadyRok, maxOpady;
	int poczatek, koniec, N;
	string data;
	cout << "PROWADZENIE TABELI OPADOW" << endl;
	/*
	do
	{
		cout << "Podaj od ktorego roku wlacznie maja byc wprowadzone dane: ";
		cin >> poczatek;
		cout << "Podaj do ktorego roku wlacznie maja byc wprowadzone dane: ";
		cin >> koniec;
		N=koniec-poczatek+1;
		if (N<0) cout << "Podaj dane jeszcze raz - jest jakas pomylka" << endl;
	} while (N<0);
	*/
	poczatek=2018;
	koniec=2022;
	N=koniec-poczatek+1;
	int **kalendarz;
	kalendarz = new int *[N];
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
		cout << "2 - sprawdz sume opadow w wybranym roku" << endl;
		cout << "3 - sprawdz srednia opadow w wybranym roku" << endl;
		cout << "4 - sprawdz srednia opadow w wybranym miesiacu na przekroju lat" << endl;
		cout << "5 - sprawdzenie kiedy byly najwieksze opady" << endl;
		cout << "6 - skoryguj dane" << endl;
		cout << "0 - WYJSCIE" << endl;
		
		cin >> wybor;		
		switch (wybor)
		{
			case 1:
			{
				cout << endl << "WYPISANIE TABLICY:" << endl;
				WypisanieTablicy (kalendarz, N, miesiace, poczatek);
				break;
			}
			case 2:
			{			
				cout << endl << "SUMA OPADOW W WYBRANYM ROKU" << endl;
				cout << "Wybor roku, dla ktorego dostaniesz informacje o sumie opadow: ";
				do
				{
					cin >> temp;
					if (temp < poczatek || temp > koniec) cout << "Podany rok jest spoza zakresu, prosze podaj rok jeszcze raz" << endl; 
				} while (temp < poczatek || temp > koniec);
				cout << "Suma opadow w roku: " << temp << " wynosi: " << SumaOpadowWRoku(kalendarz, temp-poczatek, miesiace) << endl;
				break;
			}
			case 3:
			{
				cout << endl << "SREDNIA OPADOW W WYBRANYM ROKU" << endl;
				cout << "Wpisz rok, z ktorego potrzebujesz sredniej opadow: ";
				do
				{
					cin >> temp;
					if (temp < poczatek || temp > koniec) cout << "Podany rok jest spoza zakresu, prosze podaj rok jeszcze raz" << endl; 
				} while (temp < poczatek || temp > koniec);
				cout << "Srednia opadow w roku: " << temp << " wynosi: " << SredniaRocznaOpadow(kalendarz, temp-poczatek, miesiace) << endl;
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
				maxOpady=kalendarz[0][0];
				maxOpadyRok=0;
				for (int i=0;i<N;i++)
				{
					cout << "Najwieksze opady w roku " << setw(2) << poczatek+i << " byly w: " << MaxOpadyWRoku(kalendarz, i, miesiace, maxOpadyRok) << " i wynosily: " << maxOpadyRok/10.0 << endl;
					if (maxOpadyRok>maxOpady)
					{
						maxOpady=maxOpadyRok;
						data=to_string(poczatek+i);
					}
					else if (maxOpadyRok == maxOpady)
					{
						data+=", ";
						data+=to_string(poczatek+i);
					}
				}
				cout << "Sposrod wyzej wymienionych, najwieksze opady wyniosly: " << maxOpady/10.0 << " w roku: " << data << "." << endl;
				break;
			}
			case 6:
			{
				do
				{
					cout << endl << "KOREKTA DANYCH (UWAGA, wybor ponizszych opcji, moze prowadzic do utraty danych)" << endl;
					cout << "MENU korekty danych" << endl;
					cout << "1 - ponowne losowanie tablicy" << endl;
					cout << "2 - zmiana ilosci lat do wprowadzenia" << endl;
					cout << "3 - zmiana poszczegolnych pomiarow" << endl;
					cout << "0 - wyjscie do glownego menu" << endl;
					cin >> temp;
					switch (temp)
					{
						case 1:
						{
							cout << endl << "PONOWNE LOSOWANIE TABLICY" << endl;
							WypelnienieTablicy(kalendarz, N);
							cout << "Tablica wylosowana na nowo." << endl;
							WypisanieTablicy (kalendarz, N, miesiace, poczatek);
							break;
						}
						case 2:
						{
							cout << endl << "ZMIANA PRZEDZIALU CZASOWEGO ZAPISANYCH DANYCH" << endl;
							for(int i=0; i<N; i++)
							{
								delete [] kalendarz[i];
							}
							delete []kalendarz;
							do
							{
								cout << "Podaj od ktorego roku wlacznie maja byc wprowadzone dane: ";
								cin >> poczatek;
								cout << "Podaj do ktorego roku wlacznie maja byc wprowadzone dane: ";
								cin >> koniec;
								N=koniec-poczatek+1;
								if (N<=0) cout << "Podaj dane jeszcze raz - jest jakas pomylka" << endl;
							} while (N<=0);
							kalendarz = new int *[N];
							for(int i=0; i<N; i++)
							{
								kalendarz[i] = new int [miesiace];
							}
							WypelnienieTablicy(kalendarz, N);
							cout << "Tablica wylosowana na nowo." << endl;
							WypisanieTablicy (kalendarz, N, miesiace, poczatek);
							break;
						}
						case 3:
						{
							cout << endl << "ZMIANA POSZCZEGOLNYCH POMIAROW" << endl;
							cout << "Z ktorego roku chcesz wprowadzic dane? Do wyboru z przedzialu: " << poczatek << " - " << koniec << endl;
							int rok;
							float opady;
							do
							{
								cin >> rok;
								if (rok < poczatek || rok > koniec) cout << "Podany rok jest spoza zakresu, prosze podaj rok jeszcze raz" << endl; 
							} while (rok < poczatek || rok > koniec);
							for (int i=0;i<miesiace;i++)
							{
								do
								{
									cout << "Podaj z przedzialu <0;10> (z dokladnoscia do jednego miejsca po przecinku) opady dla miesiaca " << KonwerterMiesiecy(i) << ": ";
									cin >> opady;
									if (opady < 0 || opady > 10) cout << "Podano opad spoza zakresu. Jeszcze raz." << endl;
								} while (opady < 0 || opady > 10);
								kalendarz[rok-poczatek][i] = (int) (opady*10);
							}
							break;
						}
						case 0:
						{
							cout << "Powrot do glownego menu." << endl;
							break;
						}
						default:
						{
							cout << "Wprowadzono nieprawidlowa liczbe. Prosze wprowadzic ponownie." << endl;
							break;
						}
					}
				} while (temp!=0);
				break;
			}
			case 0:
			{
				cout << "Wyjscie z programu" << endl;
				for(int i=0; i<N; i++)
				{
					delete [] kalendarz[i];
				}
				delete []kalendarz;
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

void WypisanieTablicy (int **tab, unsigned int wiersz, unsigned int kolumna, int poczatek)
{
	for (int i=0;i<kolumna;i++)
	{
		for (int j=0;j<wiersz;j++)
		{
			cout << setw(3) << KonwerterMiesiecy(i) << "." << setw(4) << poczatek+j << ": " << setw(4) << tab[j][i]/10.0 << "|";
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

string KonwerterMiesiecy (unsigned int miesiac)
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

string MaxOpadyWRoku (int **tab, unsigned int wiersz, unsigned int kolumna, unsigned int &max)
{
	max=tab[wiersz][0];
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
