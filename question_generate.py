import random
import os
# Status : Working Perfectly
# function to calculate calculate answer


def calculate_answer(a, b, ch):
    if(ch == '+'):
        return a + b
    if(ch == '-'):
        return a - b
    if(ch == '*'):
        return a * b
    if(ch == '/'):
        return a/b

# Generate a random number


def generate_number(MAX):
    return random.randint(0, MAX)

# Make a question


def make_question():
    MAX = 123456
    s = "+*+*"
    first = generate_number(MAX)
    second = generate_number(MAX)
    op = s[generate_number(3)]
    answer = calculate_answer(first, second, op)

    return first, op, second, answer


def write_questions(s):
    dirc = "C:/cp/templates/generator/Akshara/Tasks"
    path = dirc + s
    # s = s + "/" + s
    os.mkdir(path)
    s_ans = s + "_ans.txt"
    s += ".txt"
    s = path + "/" + s
    s_ans = path + "/" + s_ans
    f1 = open(s, "w")
    f2 = open(s_ans, "w")
    n = 50
    for i in range(n):
        first, op, second, answer = make_question()
        question_text = str(first) + " " + str(op) + " " + str(second) + "\n"
        answer_text = str(first) + " " + str(op) + " " + \
            str(second) + " = " + str(answer) + "\n"
        f1.write(question_text)
        f2.write(answer_text)
    f1.close()
    f2.close()


def date_wise_generate():
    for i in range(26, 30):
        s = str(i) + "-04-2021"
        write_questions(s)


date_wise_generate()
