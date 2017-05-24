from sympy.abc import x, y
from sympy.solvers import solve

y = solve(20 * x - 9 * y - 107, x)[0].subs(y, 7).evalf()
print('{:.1f}'.format(y))
