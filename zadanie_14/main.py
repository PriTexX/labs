def task_1():
    a = 2
    b = 5

    for i in range(a, b + 1):
        for j in range(i):
            print(i, end=" ")


def task_2():
    a = 17
    b = 3
    k = 0

    while k <= a:
        k += b
    if k > a: k -= b
    print(a - k)


def task_3():
    n = 22
    k = 0
    val = 0

    while True:
        val += k
        if val >= n:
            break
        k += 1
    print(k)


def task_4():
    s = 1000
    p = 10 * 0.01 + 1
    k = 0
    while True:
        k += 1
        s *= p
        if s > 1100:
            print(k, s)
            break


def task_5():
    num1 = 44
    num2 = 8
    while num1 != 0 and num2 != 0:
        if num1 >= num2:
            num1 %= num2
        else:
            num2 %= num1
    print(num1 or num2)


def task_6():
    from functools import cache

    @cache
    def fib(n):
        if n <= 2: return 1
        return fib(n - 1) + fib(n - 2)

    # a = [fib(i) for i in range(1,99)]
    # print(a)
    n = 2584
    for i in range(1, n):
        if fib(i) == n:
            print(i)
            break


if __name__ == '__main__':
    task_1()
    print()
    task_2()
    print()
    task_3()
    print()
    task_4()
    print()
    task_5()
    print()
    task_6()
