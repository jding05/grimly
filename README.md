# grimly
Grimly is 42 Starfleet second project!!!
In this project, you have to find the shortest path to solve a maze

# How to test it
1. Make (to compile it & make a executive file called grimly)
2. ./grimly resources/01.map resources/02.map resources/03.map ...
or ./grimly and write on the stdin
or cat name_of_map | ./grimly

# How it works
The algorithm uses BFS (Breadth-First Search)

Initially the algorithm reads the input and checks for errors. 
Errors in the maze considered are: 
All lines must respect the sizes given in the first line (LINExCOL). 

  ■  There can only be one entrance. ∗ There must be at least one exit. 
  ■  There must be a solution to the labyrinth. 
  ■  The labyrinth will not be more than a billion square. 
  ■  At the end of each line, there is a new line. 
  ■  The characters present in the card must be only those shown on the first line.
 
The program starts from the entrance, and finds all adjacent "empty" spot, assigns a character in the spot as the realative direction of current spot (UP, DOWN, RIGHT, LEFT). Later, put it in the Queue. With the while loop, repeat this assignment until 1. there is no spot left or 2. find an exit. In the first case, there will be empty queue, and you program fail to find the exit, so return an error. In the second case, it will print_path from the exit_spot to entrance.

# Note
1. first time implementing queue data structure
2. first time implementing doubly linked list
3. first time using BFS Algorithm
