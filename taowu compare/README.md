LS.c is Left Shift Algorithm (Lorencz).
Before compiling call "set PATH=C:\mingw\bin;%PATH%", 
then compile with "gcc LS.c -o LS"
and execute with "LS a p" where a integer, p prime, 1 < a < p.

Now the counting. We count shifts, additions and subtractions, tests if greater (realized by subtraction), test if even and test if greater than zero.
- shift
- add
- sub
- even
- poz
added:
loop  //while loop iterations, should be fbr+sbr+tbr = loop
fbr   //first branch
sbr   //second branch
tbr   //third branch
sign  //checking the sign in the third branch