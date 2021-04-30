 #!/usr/bin/python3
 
from random import randint

def random_selection(start, finish, number):

        i, j = None
        
        i=randint(0, number)
        j=randint(0, number)

        temp = 0

        while (temp != 3):
                            
            if (i == j):

                print("Selected activities are the same trying again...")
                temp = temp + 1

            else:
                    temp = 3

        if (start[j] >= finish[i] or start[i] >= finish[j]):

            print("Selected activities are mutually compatible")
            i = j

        else:
                print("Selected activities are not mutually compatible")
