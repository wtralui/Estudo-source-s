#include <windows.h>
#include <iostream>
#include <conio.h>
#include <random>

using namespace std;

bool GameOver;
int x, y, FrutaX, FrutaY, pontos;
int largura = 20;
int altura = 20;
int raboX[100], raboY[100];
int nRabo;
enum Movimento { stop = 0, direita, esquerda, cima, baixo};
Movimento mov;

void Ini() {
    GameOver = false;
    x = largura / 2;
    y = altura / 2;
    FrutaX = rand() % largura;
    FrutaY = rand () % altura;
    mov = stop;
    pontos = 0;

}


void Quadrado() {
    system("cls");
    for(int i = 0; i <= largura; i++)
        cout << "#";
    for(int j = 0; j < altura; j++) {
        cout << "\n#";
        for(int i = 0; i < largura-1; i++) {
            if(i == x && j == y) {
                cout << "O";
            } else if(i == FrutaX && j == FrutaY) {
                cout << "F";
            } else {
                bool adc = false;
                for(int k = 0; k < nRabo; k++) {
                    if(raboX[k] == i && raboY[k] == j) {
                        adc = true;
                        cout << "o";
                    }
                }
                if(!adc) {
                    cout << " ";
                }



            }

        }
        for(int j = 0; j < 1; j++) {
            cout << "#";
        }

    }
    cout << endl;
    for(int i = 0; i <= largura; i++)
        cout << "#";

}

void Teclas() {


    if(_kbhit()) {
        switch(_getch()) {
        case 'a':
            mov = esquerda;
            break;
        case 'w':
            mov = cima;
            break;
        case 's':
            mov = baixo;
            break;
        case 'd':
            mov = direita;
            break;
        case 'x':
            GameOver = true;
            break;

        }
    }
}

void Logic() {

    int adcx,adcy,adc2x,adc2y;
    adcx = raboX[0];
    adcy = raboY[0];
    raboX[0] = x;
    raboY[0] = y;

    for(int i = 1; i < nRabo; i++)
    {
        adc2x = raboX[i];
        adc2y = raboY[i];
        raboX[i] = adcx;
        raboY[i] = adcy;
        adcx = adc2x;
        adcy = adc2y;

    }


//if(x > largura || x <= 0 || y > altura || y <= 0)
// GameOver = true;

 if(x >= largura)
    x = 0;
    else if(x < 0)
        x = largura - 1;

   if(y >= largura)
    y = 0;
    else if(y < 0)
        y = altura- 1;





if(x == FrutaX && y == FrutaY){
    FrutaX = rand () % largura;
    FrutaY = rand() % altura;
    pontos++;
    nRabo++;

}
cout << endl << "Pontos: " << pontos;



    switch(mov) {
    case cima:
        y--;
        break;
    case baixo:
        y++;
        break;
    case direita:
        x++;
        break;
    case esquerda:
        x--;
        break;
    default:
        break;



    }
    for(int i = 0; i < nRabo; i++)
        if(raboX[i] == x && raboY[i] == y)
        GameOver = true;



}



int main () {
    Ini();
    while(!GameOver) {
        Quadrado();
        Teclas();
        Logic();
        Sleep(40);
            }


}
