
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;

int ExTwo();

int menu();
char q;
struct Watch {
	string name;
	string country;
	int price;
	string dial;
};
int ExOne()
{

	int i = 2;

	while (i < 8) {
		cout << setfill('?') << setw(3) << i << setfill('?') << setw(4) << " " << endl;
		i += 1;
	}
	cout << "\nput any key to go in menu\n";
	cin >> q;
	system("cls");
	return menu();
}
int ExTwo() {
	string* str = new string("One Five Zero");
	char symbol = 'o';
	int SymbOinStr = count((*str).begin(), (*str).end(), symbol);
	cout << "'o' in " << *str << " - " << SymbOinStr << endl;

	cout << "\nput any key to go in menu\n";
	cin >> q;

	system("cls");
	return menu();


}
int ExThree() {
	int maxprice = 0;
	struct Watch model[5];
	model[0] = { "Casio MRG-B2000B-1A4DR","Japan",364000,"arrows" };
	model[1] = { "Apple Watch Series 8","USA",35740,"Display" };
	model[2] = { "Redmi Watch 2 Lite GL","China",4990,"Display" };
	model[3] = { "Swatch YVS441G","Switzerland",19400,"arrows" };
	model[4] = { "Rolex Day-Date 40mm","Switzerland",3320000,"arrows" };
	for (int i = 0; i < 5; i++) {
		if (maxprice < model[i].price) maxprice = model[i].price;
	}
	cout << "max price is " << maxprice << " rub " << endl;

	ofstream file;
	file.open("file.txt");

	file << setw(22) << model[0].name << " " << left << setw(22) << model[1].name << " " << left << setw(22) << model[2].name << " " << left << setw(15) << model[3].name << " " << left << setw(22) << model[4].name << endl;
	file << setw(22) << model[0].country << " " << left << setw(22) << model[1].country << " " << left << setw(22) << model[2].country << " " << left << setw(15) << model[3].country << " " << left << setw(22) << model[4].country << endl;
	file << setw(22) << model[0].price << " " << left << setw(22) << model[1].price << " " << left << setw(22) << model[2].price << " " << left << setw(15) << model[3].price << " " << left << setw(22) << model[4].price << endl;
	file << setw(22) << model[0].dial << " " << left << setw(22) << model[1].dial << " " << left << setw(22) << model[2].dial << " " << left << setw(15) << model[3].dial << " " << left << setw(22) << model[4].dial << endl;
	file.close();

	cout << "\nput any key to go in menu\n";
	cin >> q;
	system("cls");
	return menu();

}

int bAsk() {
	char symb;
	string array[5][4];
	ifstream fromfile;
	fromfile.open("file.txt");
	fromfile >> array[0][0] >> array[1][0] >> array[2][0] >> array[3][0] >> array[4][0] >> array[0][1] >> array[1][1] >> array[2][1] >> array[3][1] >> array[4][1] >> array[0][2] >> array[1][2] >> array[2][2] >> array[3][2] >> array[4][2] >> array[0][3] >> array[1][3] >> array[2][3] >> array[3][3]>>array[4][3];
	fromfile.close();
	cout << "Choose which watch you are interested in\n1.First watch.\n2.Second watch\n3.Third watch\n4.Fourth watch\n5.Fifth watch";
	cin >> symb;
	switch (symb)
	{
	case'1':cout << endl << array[0][0] << endl << array[0][1] << endl << array[0][2] << array[0][3]; break;
	case'2':cout << endl << array[1][0] << endl << array[1][1] << endl << array[1][2] << array[1][3]; break;
	case'3':cout << endl << array[2][0] << endl << array[2][1] << endl << array[2][2] << array[2][3]; break;
	case'4':cout << endl << array[3][0] << endl << array[3][1] << endl << array[3][2] << array[3][3]; break;
	case'5':cout << endl << array[4][0] << endl << array[4][1] << endl << array[4][2] << array[4][3]; break;
	default:cout << "\nTepeat input"; return bAsk();
	}

	cout << "\nput any key to go in menu\n";
	cin >> q;
	system("cls");
	return menu();
}

int menu() {
	char input;
	cout << "what task do you want to complete?\n1.Matrix\n2.Function\n3.Structure\n4.Watc info\n5.Exit\n";
	cin >> input;
	switch (input)
	{
	case'1':
		return ExOne();
	case'2':
		return ExTwo();
	case'3':
		return ExThree();
	case'4':
		return bAsk();
	case'5':
		exit(0);

	default:
		cout << "\nRepeat input\n";

	}
}
int main() {

	while (true) {
		menu();
	}
}
