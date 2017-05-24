"""
\hat{\beta} = \frac{Cov[X, Y]}{Var[X]}
"""

from sympy.core import Symbol, Rational, Eq
from sympy.solvers import solve

cxy = Symbol('Cov[X, Y]')
cyx = Symbol('Cov[Y, X]')
vx = Rational(9)  # σx = 3
vy = Symbol('Var[Y]')
wx = Rational(4, 5)  # wx = 4/5
wy = Rational(9, 20)  # wy = 9/20

vy = solve([Eq(cxy / vx, wx),
            Eq(cyx / vy, wy),
            Eq(cxy, cyx)],
           vy, cxy, cyx)[vy]

print(vy.evalf())
