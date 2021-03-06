# 42-Lem-in project
Lemin is about finding the shortest solution for the ants to traverse an ant colony (or a [graph](https://en.wikipedia.org/wiki/Graph_(discrete_mathematics))) from one cell to another in as few turns as possible.
We need to find the shortest path (and not the simplest) to achieve this.

Both the program input and output are text formatted and have a specific format.
Input contains : number of ants, rooms, connections.
Output contains : the input + the solution.

The project must by written in C language.

The constraints are:
- An ant can only move once per turn.
- A cell can only contain up to one ant (except the start and end cells).
- The program must take less than 8 seconds (ours never takes more than 0.5 seconds).
Therefore the algorithm has to avoid trafic jam and overlapping.
## Usage
```console
make
./lem_in < maps/3-groups.map
```
## The [Edmonds-Karp algorithm](https://en.wikipedia.org/wiki/Edmonds%E2%80%93Karp_algorithm)
### Introduction
EK finds the highest possible flow in a **directed graph** between 2 **edges** (start + end) where **vertices** have a flow limit.
For Lemin, we are using a custom adaption of EK.
### Our adaptation
We need to adapt the EK algorithm because of the following differences with project:
- Our graph is undirected.
- EK does not care about the distances but we do because we need to reach the end as fast as possible.
So we do not only need to find the highest flow **but also the right balance with the shortest paths** .
- EK flow limits are defined by **vertices** (links between cells) instead **edges** (cells) but in Lemin is set to 1 by cell.
## Data model
### t_lem_in
Contains the core project informations :
- Total number of ants
- The start + end room
- The full list of rooms
### t_room
Contains room information : 
- Name
- Previous and next room of the flow (if any)
- Present ant id (if any)
### t_tree
Edmonds-Karp breadth-first traverse tree node information.
### t_route
Full route from start to end or the result of a breadth-first traverse.
Contains a list of rooms.
### t_group
Combination of non conflictual routes and a possible source of solution.
Contains:
- List of routes
- Ants distribution per routes
- The total required turn usign this group
### t_solution
Contains the final solution information to be written as text.
Contains a list of turns which contains a list of moves.
A "move" contains an ant id and its room destination.
## Our algorithm
- Parse the input and builds a graph.
- Delete dead-ends, isolated rooms and duplicate connections for performance.
- Set the group limits to MIN(ANTS_COUNT, START_ROOM_CONNECTIONS, END_ROOM_CONNECTIONS).
- Builds as many combinations (groups) of paths as possible up to the set limit.
	Repeat :
	- Runs an breadth-first traverse and get the shortest augmenting path.
	- Updates the graph flows paths with the result traverse.
	- Create a group of paths and computes the required time.
- Select the best group (=shortest time). This may vary depending on the numbers of ants.
- Generates a solution (ant moves following the group routes until they have all reached the end).
- Prints the solution.
