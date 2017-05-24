def displayPathtoPrincess(n, grid):
    px, py = 0, 0
    for x, y in [(0, 0), (0, n-1), (n-1, 0), (n-1, n-1)]:
        if grid[x][y] == 'p':
            px, py = x, y
    m = n // 2
    dx = 'DOWN' if m < px else 'UP'
    dy = 'LEFT' if m > py else 'RIGHT'
    for _ in range(abs(m - px)):
        print(dx)
    for _ in range(abs(m - py)):
        print(dy)


def main():
    m = int(input())
    grid = []
    for i in range(0, m):
        line = input().strip()
        grid.append(line)

    displayPathtoPrincess(m, grid)


if __name__ == '__main__':
    main()
