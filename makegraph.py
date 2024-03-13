import networkx as nx
import matplotlib.pyplot as plt
import sys

def read_graph_from_matrix(matrix):
    graph_adjacency_list = {}
    for i, row in enumerate(matrix):
        graph_adjacency_list[i] = {j: val for j, val in enumerate(row) if val != 0}
    return graph_adjacency_list


# Updated function to handle edge weights
def read_graph_from_matrix(matrix):
    graph_adjacency_list = {}
    for i, row in enumerate(matrix):
        graph_adjacency_list[i] = {j: val for j, val in enumerate(row) if val != 0}
    return graph_adjacency_list

# Read matrix input from stdin
matrix_input = [list(map(int, line.strip().split())) for line in sys.stdin]
graph_data = read_graph_from_matrix(matrix_input)
G = nx.DiGraph()

for node, neighbors in graph_data.items():
    for neighbor, weight in neighbors.items():
        G.add_edge(node, neighbor, weight=weight)

pos = nx.spring_layout(G)
nx.draw(G, pos, with_labels=True, node_color="c", edge_color="k", font_size=8)

edge_labels = {(u, v): d['weight'] for u, v, d in G.edges(data=True)}
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)

plt.axis('off')
plt.savefig("graph.pdf")
