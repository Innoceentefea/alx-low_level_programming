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
    width = len(grid[0])
    height = len(grid)
    grid_edges = 0
    grid_size = 0

    for k in range(height):
        for i in range(width):
            if(grid[k][i] == 1):
                grid_size += 4
                if (i > 0 and grid[k][i - 1] == 1):
                    grid_edges -= 2
                    if (k > 0 and grid[k - 1][i] == 1):
                        grid_edges -= 2
    return (grid_size * 4 - grid_edges(* )2)
