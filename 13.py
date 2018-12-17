with open('./input.txt') as f:
    board = f.readlines()

carts = []
directions = ('>', '<', '^', 'v')
replaced = ('-', '-', '|', '|')

for x, row in enumerate(board):
    for y, col in enumerate(row):
        if col == '>' or col == '<' or col == '^' or col == 'v':
            carts.append([x, y, 0, directions.index(board[x][y])])
            board[x] = board[x][:y - 1] + replaced[directions.index(board[x][y])] + board[x][y + 1:]

while True:
    carts_new = []
    for x, y, cnt, state_no in carts:
        state = directions[state_no]
        if state == '>':
            if board[x][y + 1] == '\\':
                state = 'v'
            elif board[x][y + 1] == '+':
                if cnt == 0:
                    state = '>'
                elif cnt == 1:
                    state = '>'
                elif cnt == 2:
                    state = '<'
                cnt = (cnt + 1) % 3
            elif board[x][y + 1] == '-':
                state = '>'
            else:
                raise Exception("error")
            y = y + 1
        elif state == '<':
            if board[x][y - 1] == '/':
                state = 'v'
            elif board[x][y - 1] == '+':
                if cnt == 0:
                    state = '>'
                elif cnt == 1:
                    state = '<'
                elif cnt == 2:
                    state = '<'
                cnt = (cnt + 1) % 3
            elif board[x][y - 1] == '-':
                state = '<'
            else:
                raise Exception("error")
            y = y - 1
        elif state == 'v':
            if board[x + 1][y] == '/':
                state = '<'
            elif board[x + 1][y] == '\\':
                state = '>'
            elif board[x + 1][y] == '+':
                if cnt == 0:
                    state = '>'
                elif cnt == 1:
                    state = 'v'
                elif cnt == 2:
                    state = '<'
                cnt = (cnt + 1) % 3
            elif board[x + 1][y] == '|':
                state = 'v'
            else:
                raise Exception("error")
            x = x + 1
        elif state == '^':
            if board[x - 1][y] == '/':
                state = '>'
            elif board[x - 1][y] == '\\':
                state = '<'
            elif board[x - 1][y] == '+':
                if cnt == 0:
                    state = '>'
                elif cnt == 1:
                    state = '^'
                elif cnt == 2:
                    state = '<'
                cnt = (cnt + 1) % 3
            elif board[x - 1][y] == '|':
                state = '^'
            else:
                raise Exception("error")
            x = x - 1
        else:
            raise Exception("error")
        carts_new.append([x, y, cnt, directions.index(state)])

    carts_new.sort(key=lambda tup: tup[0])
    deduped = [carts_new[i] for i in range(len(carts_new)) if i == 0 or carts_new[i][0] != carts_new[i - 1][0] or
               carts_new[i][1] != carts_new[i-1][1]]
    if len(carts_new) == len(deduped):
        carts = carts_new
    else:
        break
