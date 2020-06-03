# Greedy-Algorithms
A set of greedy algorithms, implemented in C++ Language.

## Running the program

### Running all input files (all instances)
Follow the below steps to running the program:
- Open a new treminal in folder "Greedy-Algorithms"
- If exceutable file "greedy-algorithms" does not exist, execute the command "make"
```sh
$ make
```
- Execute the python script "run.py", choosing the greedy method
```sh
$ python3 run.py Dijkstra
```
```sh
$ python3 run.py Prim
```
```sh
$ python3 run.py Kruskal
```
### Running specific input file (one instance)
Follow the below steps to running the program:
	
- Open a new treminal on folder "Greedy-Algorithms"
- Execute the command "make" to compile source files
```sh
$ make
``` 
- Execute the command "./greedy-algorithms 'method' 'inputFile'"
```sh
$ ./greedy-algorithms Dijkstra dij10.txt
```
```sh
$ ./greedy-algorithms Prim dij10.txt
```
```sh
$ ./greedy-algorithms Kruskal dij10.txt
```
