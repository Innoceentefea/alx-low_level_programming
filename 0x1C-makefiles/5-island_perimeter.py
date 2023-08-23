#!/usr/bin/python3
"""Create a function def island_perimeter(grid)"""


def island_perimeter(grid):
    """Returns the island perimeter of a grid

    grid is a list of list of integers:

        0 represents a water zone
        1 represents a land zone
        One cell is a square with side length 1
        Grid cells are connected horizontally/vertically (not diagonally).
        Grid is rectangular, width and height don’t exceed 100
        Grid is completely surrounded by water,
        and there is one island(or nothing).
        The island doesn’t have “lakes” (water inside that isn’t
        connected to the water around the island).
    """
    
    grid_edges = 0

    for k in range(len(grid)):
        for i in range(len(grid[0])):
            if grid[k][i] == 1:
                grid_edges += 4
                if k > 0 and grid[k - 1][i] == 1:
                    grid_edges -= 2
                if i > 0 and grid[k][i - 1] == 1:
                    grid_edges -= 2
    return (grid_edges)
