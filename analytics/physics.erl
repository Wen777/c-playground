-module(physics).
-import(math, [pow/2]).
-export([solution/4, force/1, acceleration/1, showAns/0]).

k() ->
    9.0 * pow(10.0, 9).
e() ->
    1.6 * pow(10, -19).
mE() ->
    9.1 * pow(10, -31).

% X2 = X + V * T + 0.5 * A * T**2
newX(X, Velocity, Acceleration, Time) ->
    X + Velocity * Time + 0.5 * Acceleration * pow(Time, 2).

timeIncrement(OldTime) ->
    OldTime + 1 * pow(10, -16).

% Newton Second Law
force(Displacement) ->
    ( k() * 3 * pow(10, -9) * e() / pow((0.25 - Displacement), 2) ) - ( k() * 2 * pow(10, -9) * e() / pow((0.25 + Displacement), 2) ).

% V2 = V1 + A * T
velocity(Velocity, Acceleration, Time) ->
    Velocity + Acceleration * Time.

% F = m * a.
% a = F / m
acceleration(Force) ->
    Force / mE().

solution(X, Velocity, _, _) when X > 0.15 ->
    Velocity;
solution(X, Velocity, Acceleration, Time) ->
    Displacement = newX(X, Velocity, Acceleration, Time),
    F = force(Displacement),
    A = acceleration(F),
    solution(Displacement, velocity(Velocity, A, Time), A, timeIncrement(Time)).

showAns() ->
    F = force(0),
    A = acceleration(F),
    io:format("answer is ~f * 10 ** 6 [m/s] ~n",[solution(0, 0, A, 0) / 1000000 ]).