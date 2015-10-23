#ifndef NODE_H
#define NODE_H

#include "Sensor.h"
#define NULL 0


class Node
{
public:
	// ------------------------------------------------------ GETERS :
	inline Node *GetLeft() const {return left};
	// Return the node at the left of the current node

	inline Node *GetRight() const {return right};
	// Return the node at the right of the current node

	friend void SwapSensor(Node *target);
	// Exchange this object sensor with the one in target

	inline uint32_t GetSensorID() const {return sensor.GetID()};
	// Get the current node sensor ID

	Node(Sensor *sensor, Node *left = NULL, Node *right = NULL);
	// Node Constructor
	// sensor initialize the Node sensor, and left and right the
	// childs nodes of this node

private:
	Node *left;		//The node on the left
	Node *right;	//The node on the right
	Sensor *sensor;	//The sensor contained in the node
};


#endif	//NODE_H