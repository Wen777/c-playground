#include<stdio.h>
#include<math.h>
#include<stdlib.h>


double Xend    = 0.15;
double Vinit = 0;
long double tDelta = 1e-16;

long double k = 9.0e9;
long double e = 1.6e-19;
long double Me = 9.1e-31;

// input
// x: displacement
// velocity: velocity
// acceleration acceleration
// time time

typedef struct {
    long double x;
    long double velocity;
    long double acceleration;
    long double time;
} Compute;


void solution(Compute *obj) {
	long double x2 = obj->x + obj->velocity * obj->time + 0.5*obj->acceleration*(pow(obj->time, 2));
	long double F = (k * 3 * pow(10, -9) * e / pow((0.25-x2), 2)) - (k * 2 * pow(10, -9) * e / pow((0.25+x2), 2));
	long double a = F / Me;
	long double v = obj->velocity + a* obj->time;
	obj->time = obj->time + tDelta;
    obj->acceleration = a;
    obj->x = x2;
    obj->velocity = v;
}
int main(void) {

long double Finit = (k * 3 * pow(10, -9) * e / pow((0.25), 2)) - (k * 2 * pow(10, -9) * e / pow((0.25), 2));
long double Ainit = Finit / Me;
long double timeInit  = 0;
long double velocity = Vinit;
long double acceleration  = Ainit;
long double x = 0;
long double time = timeInit;

Compute *obj;
obj = (Compute *) malloc(sizeof(Compute));
obj->x = x;
obj->time = time;
obj->acceleration = acceleration;
obj->velocity = velocity;


	//console.log(solution(x, velocity, acceleration, time));
	while (1) {
		solution(obj);
		if (obj->x >= Xend) {
			printf("Ans is %Lf  * 10^6 [m/s]", obj->velocity / pow(10, 6));
			break;
		}
	}

    return 0;
}
