 
1)Name- N.Jithendra Chowdary , BITS ID - 2021H1030032G

2) CONTENTS IN THE DIRECTORY ARE:
    main.c sortpoints.h sortpt.c README makefile input.txt

    i)main.c contains the code for Stadium manager process creation and scheduling the matches.
    ii)sortpoints.h declares the header for function which sorts he points table according to the points.
    iii)sortpt.c defines the function bsort through which we sort the actual points table based on points.
    iv)makefile contains all the compilation part and object creation too.
    v)README contains description about how to do and what to do.
    vi)input.txt contains all the inputs based on which schedule is to be run.

3) makefile is used to compile my program easily. usage: simply enter "make" command in the terminal containing the folder

4) After opening the terminal

    0) Enter "make" in the terminal then files get compiled and a new object called "premierleague.out" will be created .

    i) Enter ./premierleague.out with one command line argument..
        --> argument passed is textfile name with extension(.txt)

    syntax: ./premierleague.out FILENAME.txt

    ii)  USAGE:  ./premierleague.out input.txt

5)
    i)main.c has the code for Stadium manager process creation and function for creating schedule between the teams and also the function which reads the values into the structure
    ii)sortpoints.h is the header file which declares only the function for sorting the structure and is extended in another program called sortpt.c
    iii)sortpt.c contains the function called bsort which takes the structure as parameter and sorts the table based on the points filed in the structure.


6) Everything in my program is working well.
    SUCCESSFULLY DONE :
        1)scheduling matches between the teams SUCCESSFULLY
        2)Each stadium manager waits till all the matches at that particular stadium is finished
        3)Prints the table according to the points scored by each team.
        4)Each Match is held succesfully for 3 seconds.
