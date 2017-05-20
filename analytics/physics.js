// variables
var Xend = 0.15
var Vinit = 0
var tDelta = 1 * (10 ** -16)

// constant
const k = 9.0 * (10.0 ** 9)
const e = 1.6 * (10 ** -19)
const Me = 9.1 * (10 ** -31)

// input
// x: displacement
// velocity: velocity
// acceleration acceleration
// time time
function solution(x, velocity, acceleration, time){
    var x2 = x + velocity * time + 0.5 * acceleration * (time ** 2);
    var F = ( k * 3 * (10 ** -9) * e / ((0.25 - x2) ** 2) ) - ( k * 2 * (10 ** -9) * e / ((0.25 + x2) ** 2) );
    var a = F / Me;
    var v = velocity + a * time;
    var time = time + tDelta;
    return [x2, v, a, time];
}

var Finit = ( k * 3 * (10 ** -9) * e / ((0.25) ** 2) ) - ( k * 2 * (10 ** -9) * e / ((0.25) ** 2) );
var Ainit = Finit / Me;
var timeInit = 0;
var velocity = Vinit;
var acceleration = Ainit;
var x = Xstart = 0;
var time = timeInit;
//console.log(solution(x, velocity, acceleration, time));
while (true) {
    [x, velocity, acceleration, time] = solution(x, velocity, acceleration, time);
    if (x >= Xend){
        console.log(`Ans is ${velocity / (10 ** 6)} * 10^6 [m/s]`)
        break;
    }
}

