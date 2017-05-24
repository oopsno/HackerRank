def searchPrincess(n, grid):
    for x in range(n):
        for y in range(n):
            if grid[x][y] == 'p':
                return x, y


def displayPathtoPrincess(n, grid, mx, my):
    px, py = searchPrincess(n, grid)
    dx = 'DOWN' if mx < px else 'UP'
    dy = 'LEFT' if my > py else 'RIGHT'
    if abs(mx - px) > 0:
        print(dx)
        return
    if abs(my - py) > 0:
        print(dy)
        return


def main():
    m = int(input())
    mx, my = [int(i) for i in input().strip().split()]
    grid = []
    for i in range(0, m):
        line = input().strip()
        grid.append(line)

    displayPathtoPrincess(m, grid, mx, my)


if __name__ == '__main__':
    main()
