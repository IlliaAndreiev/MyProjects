#include <iostream>
#include <cmath>

using namespace std;

double CalcSin(double a, double b, double c, double& G)
{
    G = (pow(sin(a), 8) + pow(sin(b), 8)) / pow(sin(c), 8);
    return G;
}

int main()
{
    double a, b, c;
    double G;

    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;

    cout << "G = " << CalcSin(a, b, c, G) << endl;

    return 0;
}