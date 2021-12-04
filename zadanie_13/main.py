def task_1():
    n = 3.0

    for i in range(1, 10):
        print(float('0.'+str(i)) * n, end=' ')
    print(n)

def task_2():
    n = 4
    val = 1
    k = 1.1

    for i in range(n):
        val *= k
        k += 0.1
    print(val)

def task_3():
    n = 5
    summ = 0

    for i in range(1, n+1):
        summ += 2*i - 1
    print(summ)

def task_4():
    a = 2.1
    n = 4
    summ = 0

    for i in range(n+1):
        summ += a**i
    print(summ)

def task_5():
    a = 1.3
    n = 3
    summ = 0

    for i in range(n+1):
        summ += (-1)**i * a**i
    print(summ)

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