package main

import "fmt"
import "math"

// variables
var (
	Xend   float64 = 0.15
	Vinit  float64 = 0
	tDelta float64 = 1 * math.Pow(10, -16)
)

// constant
const k = 9.0e9
const e = 1.6e-19
const Me = 9.1e-31

// input
// x: displacement
// velocity: velocity
// acceleration acceleration
// time time
func solution(x, velocity, acceleration, time float64) (float64, float64, float64, float64) {
	x2 := x + velocity*time + 0.5*acceleration*(math.Pow(time, 2))
	F := (k * 3 * math.Pow(10, -9) * e / math.Pow((0.25-x2), 2)) - (k * 2 * math.Pow(10, -9) * e / math.Pow((0.25+x2), 2))
	a := F / Me
	v := velocity + a*time
	time = time + tDelta
	return x2, v, a, time
}

var Finit float64 = (k * 3 * math.Pow(10, -9) * e / math.Pow((0.25), 2)) - (k * 2 * math.Pow(10, -9) * e / math.Pow((0.25), 2))
var Ainit float64 = Finit / Me
var timeInit float64 = 0
var velocity float64 = Vinit
var acceleration float64 = Ainit
var x float64 = 0
var time float64 = timeInit

func main() {

	//console.log(solution(x, velocity, acceleration, time));
	for true {
		x, velocity, acceleration, time = solution(x, velocity, acceleration, time)
		if x >= Xend {
			fmt.Printf("Ans is %v  * 10^6 [m/s]", velocity/math.Pow(10, 6))
			break
		}
	}
}
