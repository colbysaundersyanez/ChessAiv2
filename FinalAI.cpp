#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include "Moving.cpp"

using namespace std;

class chessMatchInfo {
public:
	static const int row = 8;
	static const int column = 8;
	bool newGame;
	int pieceArray[row][column];
	int piecePosition[64];

	void arrayPrinter(int arrayType[8][8]){
		for(int one = 0; one < 8; one++){
			for(int two = 0; two < 8; two++){
				std::cout << "[" <<arrayType[one][two] << "]" << ' ';
			}
			cout << "\n";
		}
	}
};

void start(int mainArray[8][8]){
	movingClass movingClassVar;
	int i;
	int pos;
	int posTwo;
	int placeTwo;
	//mainArray[8][8] =  mainClass.pieceArray;
	cout << "Enter Piece Type: "; cin >> i;
	cout << "Enter Piece Position 1/2: "; cin >> pos; cout << " "; cin >> posTwo;
	cout << "how far do you want to move it? "; cin >> placeTwo;
	movingClassVar.moving(i,pos,posTwo,0,placeTwo, mainArray[8][8]);
}

int main() {
	chessMatchInfo mainClass;
	mainClass.newGame = true;
	bool mainNewGame = mainClass.newGame;
	if (mainClass.newGame == true) {
		for (int x = 0; x < 8; x++) {
			for (int j = 0; j < 8; ++j)
			{
				mainClass.pieceArray[x][j] = 0;
				std::cout << "[" <<mainClass.pieceArray[x][j] << "]" << ' ';
			}
			cout << "\n";
		}
	}
	else {cout << "not programmed";}
	string fileInt;
	ifstream myFile;
	int xCounter = 0;
	myFile.open("text.txt");
	if (myFile.is_open()) {
		while (getline(myFile, fileInt)) {
			stringstream streamItem(fileInt);
			int fileInteger = 0;
			streamItem >> fileInteger;
			cout << fileInteger;
			mainClass.piecePosition[xCounter] = fileInteger;
			xCounter++;
		}
		myFile.close();
	}
	else { cout << "file is not open"; }
	int counter = 0;
	for (int x = 0; x < 8; x++) {
		for (int j = 0; j < 8; ++j){
			mainClass.pieceArray[x][j] = mainClass.piecePosition[counter];
			counter++;
		}
		cout << "\n";
	}
	mainClass.arrayPrinter(mainClass.pieceArray);
	start(mainClass.pieceArray);
}

