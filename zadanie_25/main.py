def task_1(name: str = "task_1.txt"):
    with open(name, "r") as file:
        content = file.readline()
    index = content.find(" ")
    newContent = content[index + 1:]
    with open(f"new_{name}", "w") as file:
        file.write(newContent)


def task_2(name: str = "task_2.txt", n: int = 10, k: int = 17):
    string = ''
    for i in range(n):
        string += k * '*' + '\n'
    with open(name, "w") as file:
        file.write(string)


def task_3(name: str = "task_31.txt", name2: str = "task_32.txt"):
    with open(name, 'r') as file1:
        content = file1.read()
    with open(name2, 'r') as file2:
        with open(name, 'w') as file:
            file.write(file2.read())
            file.write(content)


def task_4(name: str = "task_4.txt"):
    with open(name, 'r') as file:
        content = file.read().split(" ")
    new_content = ""
    for el in content:
        if el == '':
            continue
        new_content += el + " "
    with open(f"new_{name}", 'w') as file:
        file.write(new_content)


def task_5(name: str = "task_5.txt"):
    with open(name, 'r') as file:
        content = file.readlines()
    count = 0
    for line in content:
        if line.strip():
            if line.startswith("     "):
                count += 1
    print(count)


if __name__ == '__main__':
    task_1()
    task_2()
    task_3()
    task_4()
    task_5()
