
#include <iostream>

using namespace std;


//Juego Gato Yacdany Arguedas

string cuadros[4][4] = { {"[ ]","[ ]","[ ]","[ ]"},
{"[ ]","[ ]","[ ]","[ ]"} ,{"[ ]","[ ]","[ ]","[ ]"} ,{"[ ]","[ ]","[ ]","[ ]"} };

int fila, colummna;
int player = 1, ganador = false;


void mostrarCuadro() {
    cout << "\n\n     0  1  2  " << endl;
    for (int f = 0;f < 3;f++) {
        cout << f << "<- ";
        for (int c = 0;c < 3;c++) {
            cout << cuadros[f][c];
        }
        cout << endl;
    }
}

void colocarFicha(int fila, int colummna, int jugador) {
    if (jugador == 1) {
        cuadros[fila][colummna] = "[X]";
        player = 2;
    }
    else {
        cuadros[fila][colummna] = "[O]";
        player = 1;
    }
}

//DETERMINA EL GANADOR EN FILAS DE IZQUIERDA A DERECHA
int ganadorPlayerFilas() {

    int flag_1 = 0, puntos_jugador_1 = 0, puntos_jugador_2 = 0;

    for (int f = 0;f < 3;f++) {
        for (int c = 0;c < 3;c++) {
            if (flag_1 == f && cuadros[f][c] == "[X]") {
                puntos_jugador_1++;
            }
            else if (flag_1 == f && cuadros[f][c] == "[O]") {
                puntos_jugador_2++;
            }
        }
        flag_1++;

        if (puntos_jugador_1 < 3) {
            puntos_jugador_1 = 0;
        }
        if (puntos_jugador_2 < 3) {
            puntos_jugador_2 = 0;
        }
    }

    if (puntos_jugador_1 == 3) {
        return 1;
    }
    else if (puntos_jugador_2 == 3) {
        return 2;
    }
}

//DETERMINA EL GANADOR EN COLUMNAS
int ganadorPlayerColumnas() {
    int flag_1 = 0, flag_2 = 0, punto_jugador_1 = 0, puntos_jugador_2 = 0;

    // VERIFICANDO DE COLUMNA 0 A FILA 0
    for (int f = 0;f < 3;f++) {
        for (int c = 0;c < 3;c++) {
            if (flag_1 == f && cuadros[f][c] == "[X]") {
                punto_jugador_1++;

            }
            else if (flag_1 == f && cuadros[f][c] == "[O]") {
                puntos_jugador_2++;
            }
        }
        flag_1++;
    }

    //SI DE LA PRIMER COUMNA NINGUNO GANA ENTRA EN ESTA EXPRESION
    if (punto_jugador_1 < 3 && puntos_jugador_2 < 3) {
        // VERIFICANDO DE COLUMNA 1 A FILA 1
        punto_jugador_1 = 0;
        puntos_jugador_2 = 0;

        flag_1 = 0;
        flag_2 = 1;//columna
        for (int f = 0;f < 3;f++) {
            for (int c = 0;c < 3;c++) {
                if ((flag_1 == f) && (flag_2 == c) && (cuadros[f][c] == "[X]")) {
                    punto_jugador_1++;
                    

                }
                else if ((flag_1 == f) && (flag_2 == c) && (cuadros[f][c] == "[O]")) {
                    puntos_jugador_2++;
                   
                }
            }
            flag_1++;
        }
    }
    else {
        // VERIFICANDO LA ULTIMA COLLUMNA
        punto_jugador_1 = 0;
        puntos_jugador_2 = 0;

        flag_1 = 0;
        flag_2 = 2;//columna
        for (int f = 0;f < 3;f++) {
            for (int c = 0;c < 3;c++) {
                if ((flag_1 == f) && (flag_2 == c) && (cuadros[f][c] == "[X]")) {
                    punto_jugador_1++;


                }
                else if ((flag_1 == f) && (flag_2 == c) && (cuadros[f][c] == "[O]")) {
                    puntos_jugador_2++;

                }
            }
            flag_1++;
        }
    }


    if (punto_jugador_1 == 3) {
        return 1;
    }
    else if (puntos_jugador_2 == 3) {
        return 2;
    }
}

int ganadorPlayerDiagonal() {
    int flag_1 = 0,flag_2=0,puntos_jugador_1=0,puntos_jugador_2=0;

    //DIAGONAL DE F[0]C[0] A F[2]C[2]
    for (int f = 0;f < 3;f++) {
        for (int c = 0;c < 3;c++) {
            if (flag_1 == f && flag_2 == c && cuadros[f][c] == "[X]") {
                puntos_jugador_1++;
            }
            else if (flag_1 == f && flag_2 == c && cuadros[f][c] == "[O]") {
                puntos_jugador_2++;

            }
        }
        flag_1++;
        flag_2++;
    }

    //DIAGONAL DE F[0]C[2] A F[2]C[0]
    
        puntos_jugador_1 = 0;
        puntos_jugador_2 = 0;

        flag_1 = 0;
        flag_2 = 2;

        for (int f = 0;f < 3;f++) {
            for (int c = 0;c < 3;c++) {
                if (flag_1 == f && flag_2 == c && cuadros[f][c] == "[X]") {
                    puntos_jugador_1++;
                    
                }
                else if (flag_1 == f && flag_2 == c && cuadros[f][c] == "[O]") {
                    puntos_jugador_2++;
                   
                }
            }
            flag_1++;
            flag_2--;
        }
    

    if (puntos_jugador_1 == 3) {
        return 1;
    }
    else if (puntos_jugador_2 == 3) {
        return 2;
    }
}

int main()
{

    while (ganador == false)
    {
        cout << "Juego Gato" << endl << endl;

        mostrarCuadro();

        cout << "Fila -> ";cin >> fila;
        cout << "Colummna -> ";cin >> colummna;


        colocarFicha(fila, colummna, player);
        if (ganadorPlayerFilas() == 1 || ganadorPlayerFilas() == 2) {
            ganador = true;

        }
        else if (ganadorPlayerColumnas() == 1 || ganadorPlayerColumnas() == 2) {
            ganador = true;
        }
        else if (ganadorPlayerDiagonal() == 1 || ganadorPlayerDiagonal() == 2) {
            ganador = true;
        }
        system("cls");
    }

    if ((ganadorPlayerFilas() == 1) || (ganadorPlayerColumnas() == 1) || ganadorPlayerDiagonal()==1
        ) {
        cout << "\nGano el Jugador 1";
        mostrarCuadro();
    }
    else {
        cout << "\nGano el jugador 2";
        mostrarCuadro();
    }

    return 0;
}

