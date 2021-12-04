def task_1():
    n = 9
    arr = []
    for i in range(1, n*2, 2):
        arr.append(i)
    print(arr)

def task_2():
    n = 5
    a = 1
    d = 2
    arr = [a]

    for i in range(n-1):
        arr.append(arr[-1]*d)
    print(arr)

def task_3():
    n = 7
    a = 2
    b = 6
    arr = [a,b]

    for i in range(2, n):
        arr.append(arr[i-2]+arr[i-1])
    print(arr)

def task_4():
    from random import randint
    n = 5
    a = [randint(1, 99) for i in range(n)]
    k = n-1
    print(a)
    for i in range(n//2):
        print(a[i], a[i+k], end=' ')
        k -= 2
    if n%2==1:
        print(a[n//2])

def task_5():
    from random import randint
    n = 7
    a = [randint(1,99) for i in range(n)]
    print(a)
    for i in range(0, n, 2):
        print(a[i], end=' ')
    for i in range(1, n, 2)[::-1]:
        print(a[i], end=' ')


if __name__ == '__main__':
    task_1()
    task_2()
    task_3()
    print()
    task_4()
    print()
    task_5()