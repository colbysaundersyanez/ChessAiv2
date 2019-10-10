#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <fstream>
#include <sstream>

class movingClass{
    public:
    int moving(int piece, int posOne, int posTwo, int placeOne, int placeTwo, int piecePosArray[8][8]){
        switch(piece){
            case 1:
                if(placeOne <= 0 && placeTwo <= 2){piecePosArray[posOne][posTwo] = 0; piecePosArray[posOne][posTwo + placeTwo] = piece;}
            break;
            //cout << "none";
        }      
        return 1;
    }
};