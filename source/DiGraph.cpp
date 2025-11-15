#include "DiGraph.h"
#include "Matrix.h"
#include <stdexcept>
#include <iostream>
#include <fstream>


DiGraph::DiGraph() {
	this->next_free_node_id = 0;
}

DiGraph::~DiGraph() {
	for (auto &entry : this->node_map)
	{
		delete entry.second;
	}
	this->node_map.clear(); // Deletes all elements in the map (probably not even nessesary)
}

std::int32_t DiGraph::get_node_count() const { 
	return this->node_map.size();
}

Node* DiGraph::add_node()
{
	Node* new_node = new Node(this->next_free_node_id);
	this->node_map[this->next_free_node_id] = new_node;
	this->next_free_node_id++;
	return new_node;
}

Node* DiGraph::add_node_carelessly(int32_t new_node_id)
{
	Node* new_node = new Node(new_node_id);
	this->node_map[new_node_id] = new_node;
	return new_node;
}

void DiGraph::set_next_free_node_id(std::int32_t value) {
	this->next_free_node_id = value;
}

Node* DiGraph::get_node_by_id(std::int32_t node_id) const {
	Node* node = this->node_map.at(node_id);
	return node;
}

void DiGraph::add_edge(int32_t source_id, int32_t target_id) {
	if (node_map.find(source_id) == node_map.end() ||
		node_map.find(target_id) == node_map.end())
		throw std::invalid_argument("ERROR: Both Nodes id's must be in the source map");

	Node* start_node = DiGraph::get_node_by_id(source_id);
	Node* target_node = DiGraph::get_node_by_id(target_id);

	start_node->add_out_edge(target_node);
	target_node->add_in_edge(start_node);

}

void DiGraph::export_to_dot_file(std::string file_path) const {}

Matrix<bool> DiGraph::get_adjacency_matrix_from_graph() const { return Matrix<bool>(1, 1); }

/* Do not change the code below here */

/* These functions are used for importing graph from .dot files. */
std::int32_t* DiGraph::get_next_free_node_id_ptr() {
	return &next_free_node_id;
}

std::unordered_map<int32_t, Node*>* DiGraph::get_node_map_ptr() {
	return &node_map;
}
