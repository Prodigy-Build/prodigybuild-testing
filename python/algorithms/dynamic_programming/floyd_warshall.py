

# python/algorithms/dynamic_programming/floyd_warshall.py

import math
import unittest


class Graph:
    def __init__(self, n=0):  # a graph with Node 0,1,...,N-1
        self.n = n
        self.w = [
            [math.inf for j in range(0, n)] for i in range(0, n)
        ]  # adjacency matrix for weight
        self.dp = [
            [math.inf for j in range(0, n)] for i in range(0, n)
        ]  # dp[i][j] stores minimum distance from i to j

    def add_edge(self, u, v, w):
        self.dp[u][v] = w

    def floyd_warshall(self):
        for k in range(0, self.n):
            for i in range(0, self.n):
                for j in range(0, self.n):
                    self.dp[i][j] = min(self.dp[i][j], self.dp[i][k] + self.dp[k][j])

    def show_min(self, u, v):
        return self.dp[u][v]


class TestFloydWarshall(unittest.TestCase):
    def setUp(self):
        self.graph = Graph(5)
        self.graph.add_edge(0, 2, 9)
        self.graph.add_edge(0, 4, 10)
        self.graph.add_edge(1, 3, 5)
        self.graph.add_edge(2, 3, 7)
        self.graph.add_edge(3, 0, 10)
        self.graph.add_edge(3, 1, 2)
        self.graph.add_edge(3, 2, 1)
        self.graph.add_edge(3, 4, 6)
        self.graph.add_edge(4, 1, 3)
        self.graph.add_edge(4, 2, 4)
        self.graph.add_edge(4, 3, 9)

    def test_floyd_warshall(self):
        self.graph.floyd_warshall()
        self.assertEqual(self.graph.show_min(1, 4), 8)
        self.assertEqual(self.graph.show_min(0, 3), 12)


if __name__ == "__main__":
    unittest.main()