#include "SVGdraw.h"
#include <iostream>
using namespace std;

void kaktus(int n, int m, double V, double S[], double alfa, double alfa2,
    double beta[], Turtle& turtle) {
    if (n == 0) {
        // trivialny pripad: vykreslime ciaru a vratime sa spat dole
        turtle.forward(V);
        turtle.forward(-V);
    }
    else {
        turtle.forward(V * beta[m-1]);
        turtle.turnLeft(90);
        turtle.forward(S[m-1]);
        turtle.turnRight(90);
        kaktus(n - 1, m-1, V * (1 - beta[m]), S, alfa, alfa2, beta, turtle);
        turtle.turnLeft(90);
        turtle.forward(-S[m-1] * 2);
        turtle.turnRight(90);
        kaktus(n - 1, m - 1, V * (1 - beta[m]), S, alfa, alfa2, beta, turtle);
        turtle.turnLeft(90);
        turtle.forward(S[m-1]);
        turtle.turnRight(90);
        turtle.forward(-V * beta[m-1]);
        turtle.forward(V);
        turtle.forward(-V);
    }
}

int main(void) {
    /* rozmery obrazku */
    double sirka, vyska;
    cin >> sirka >> vyska;

    const int MAXM = 10;
    double S[MAXM];
    double beta[MAXM];

    int n, m;
    double V, alfa;
    cin >> n >> m >> V >> alfa;
    for (int i = 0; i < m; i++) {
        cin >> S[i] >> beta[i];
    }

    /* vytvor korytnacku otocenu hore */
    Turtle turtle(sirka, vyska, "kaktus.svg",
        sirka / 2, vyska - 10, 90);

    /* nakresli strom rekurzivne */
    kaktus(n, m, V, S, alfa, 1, beta, turtle);

    /* ukonci vykreslovanie */
    turtle.finish();
}