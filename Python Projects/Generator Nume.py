"""
Let's write a menu-driven application. What does the menu look like?
    1. Generate (random) person names
    2. Exit
"""
import random
def generate_names():
    count = int(input("How many names do you want: ")  )
    family_names=["Albu","Pop","Gheorghe","Morar","Negrea","Bondar"]
    given_names= ["Ana","Ghita","Mihai","Andra","Lica","Vasile"]
    result=[]

    for i in range(count):
        family_name=random.randint(0,len(family_names)-1)
        given_name=random.randint(0,len(given_names)-1)
        name=family_names[family_name] + " " + given_names[given_name]
        result.append(name)

    print(result)
    return  result


def start():

    while True:
        print("1. Generate (random) person names")
        print("2. Exit")

        opt=input(">")

        if opt == "1" :
            generate_names()
        elif opt== "2" :
            return # break would have also been acceptable
        else:
            print("Bad command or file name")


start()
