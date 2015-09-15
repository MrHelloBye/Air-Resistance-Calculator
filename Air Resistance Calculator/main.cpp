#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const double pi = 3.14159265358;

double Calcv0y(double v0, double theta) {
    return v0*sin(theta);
}
double Calcv0x(double v0, double theta) {
    return v0*cos(theta);
}

double Calcy(double t, double gamma, double v0y) {
    return -9.81*t/gamma+(v0y+9.81/gamma)/gamma*(1-exp(-gamma*t)); // Defines vertical position
}
double Calcvy(double t, double gamma, double v0y) {
    return (v0y+9.81/gamma)*exp(-gamma*t)-9.81/gamma; // Defines Vertical velocity
}

double Calcx(double t, double gamma, double v0x) {
    return v0x/gamma*(1-exp(-gamma*t)); // Defines horizontal position.
}
double Calcvx(double t, double gamma, double v0x) {
    return v0x*exp(-gamma*t);
}

int main() {
    double delt, tguess = 0, tolerance = 1.0E-8;
    double v0, theta, thetaInRads, gamma, height;
    bool repeatCheck;
    double x, y, v0x, v0y, vx, vy;
    
    do {
        cout << "Enter v0 in m/s:\n";
        scanf("%lf", & v0);
        cout << "Enter theta in degrees:\n";
        scanf("%lf", & theta);
        thetaInRads = theta/180*pi;
        cout << "Enter gamma in s^-1:\n";
        scanf("%lf", & gamma);
        cout << "Enter height in meters:\n";
        scanf("%lf", & height);
        
        for (int repeatCounter; (repeatCounter <= 20) || (delt <= tolerance); repeatCounter++) {
            // Perform Newton's Method.
            y = Calcy(tguess, gamma, v0y);
            if (y) {
                //Add Stuff here.
            }
        }
        
    } while (repeatCheck == true);
    return 0;
}