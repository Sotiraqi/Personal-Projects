 #!/usr/bin/python3

from functions import activities_selection
from function2 import random_selection

def main():
  
    number = input("Activity number: ")

    for i in range (0,number):
        start_time = input("Enter the start time for activity " + i)
        finish_time = input("Enter the finish time for activity " + i)


    activities_selection(start_time, finish_time)
    #random_selection(start_time, finish_time, number)
    main()
