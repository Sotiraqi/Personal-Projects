 #!/usr/bin/python3

def activities_selection(start, finish):

        i, j = None
        print("Please select the activities to check if they are mutually compatible: \n")

        i=input("First activity selected: ")
        j=input("Second activity selected: ")


        if (start[j] >= finish[i] or start[i] >= finish[j]):

            print("Selected activities are mutually compatible")
            i = j

        else:
                print("Selected activities are not mutually compatible")
