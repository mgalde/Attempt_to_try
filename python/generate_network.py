import pyshark
import pygraphviz as pgv

# Read the PCAP file using pyshark
capture = pyshark.FileCapture('capture.pcap')

# Create a new Graphviz graph
graph = pgv.AGraph(directed=True, overlap=False)

# Iterate over the packets in the PCAP file
for packet in capture:
    # Get the source and destination IP addresses from the packet
    src_ip = packet.ip.src
    dst_ip = packet.ip.dst

    # Add the source and destination IP addresses to the Graphviz graph as nodes
    graph.add_node(src_ip)
    graph.add_node(dst_ip)

    # Add an edge between the source and destination nodes
    graph.add_edge(src_ip, dst_ip)

# Generate a PNG image of the graph
graph.draw('network_map.png', prog='dot')
