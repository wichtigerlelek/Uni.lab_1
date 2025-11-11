#include "Node.h"

Node::Node(std::int32_t id) {
	this->id = id;
}

Node::~Node() {}

std::int32_t Node::get_id() {
	return this->id;
}

void Node::add_in_edge(Node* source) {
	this->in_edges.push_back(source);
}

void Node::add_out_edge(Node* target) {
	this->out_edges.push_back(target);
}

std::vector<Node*> Node::get_in_edges() { 
	return this->in_edges;
}

std::vector<Node*> Node::get_out_edges() { 
	return this->out_edges;
}