from collections import deque
from edx_io import edx_io

with edx_io() as io:
    stack = deque()
    io.next_int()
    input = deque(io.all_tokens())
    for i in input:
        if i.isdigit():
            stack.append(int(i))
        elif i == b'+':
            stack.append(stack.pop() + stack.pop())
        elif i == b'-':
            tmp = stack.pop()
            stack.append(stack.pop() - tmp)
        else:
            stack.append(stack.pop() * stack.pop())
    io.write(stack)
