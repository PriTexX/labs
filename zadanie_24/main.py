def task_1(string="ght sdfsd fgf sdfsd"):
    length = len(string.split())
    print(length)


def task_2(string="ght sdfsd fgf sdfsd"):
    words = string.split()
    maxx = max([len(word) for word in words])
    print(maxx)


def task_3(string="  FGHFHV   JJJNMDHFJ  RYFHBF    FF"):
    new_word = True
    for j in range(len(string)):
        i = string[j]
        if i == " ":
            new_word = True
            continue
        if new_word == True:
            letter = i
            new_word = False
        else:
            if i == letter:
                string = string[0:j] + '.' + string[j + 1:]
    print(string)


def task_4(string="Апоомралалвраг уаннпвыалыа апавоыа амвыраыв"):
    vowels = "уеэоаыяию"
    count = 0
    for i in string.lower():
        count += 1
    print(count)


def task_5(string="/home/pritexx/CLionProjects/labs_VVP/zadanie_24/main.py"):
    file = string.split('/')[-1]
    print(file.split(".")[0])


def task_6(string="/home/pritexx/CLionProjects/labs_VVP/zadanie_24/main.py"):
    print(string.split("/")[-2])


def task_7(string="Программа"):
    end = (len(string) + 1) % 2
    new_string = ""
    for i in range(1, len(string), 2):
        new_string += string[i]
    for i in range(len(string) - end - 1, -1, -2):
        new_string += string[i]
    print(new_string)


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
    print()
    task_7()
