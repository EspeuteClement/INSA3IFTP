#include <iostream>
#include "Node.h"

Node::Node(Sensor *sensor, Node *left = NULL, Node *right = NULL):
	sensor(sensor),left(left),right(right)
{
#ifdef MAP
	std::cout << "Constructing a <None>";
#endif	
}

void Node::SwapSensor(Node *target)
{
	Node *tmp = target->sensor; // Buffer target sensor

	//Perform the swap
	this->sensor = target->sensor;
	target->sensor = tmp;
}