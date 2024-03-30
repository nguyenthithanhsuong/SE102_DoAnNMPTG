#include "BinaryTree.h"
QNode::QNode()
{
	level = 0;
	leftx = 0; topy = SCREEN_HEIGHT;
	rightx = LEVEL_LENGTH; boty = 0;
	left = NULL; right = NULL;
	Split();
}
QNode::QNode(int level, float a1, float b1, float a2, float b2)
{
	this->level = level;
	leftx = a1; topy = b1;
	rightx = a2; boty = b2;
	Split();
}
void QNode::Clear(QNode* node)
{
	if (node == nullptr) {
		return;
	}

	Clear(node->left);
	Clear(node->right);
	node->objects.clear(); // Clear the objects list
	delete node;
}

bool QNode::IsContain(CGameObject* object)
{
	if (object == nullptr)
		return false;
	float l, t, r, b;
	object->GetBoundingBox(l, t, r, b);
	if ((l >= leftx && r <= rightx) || (l <= leftx && r >= leftx))//object auto get placed on the left node
		return true;
	else
		return false;
}

void QNode::Split()
{
	if ((rightx - leftx) / 2 > SCREEN_WIDTH)
	{
		float midx = (leftx + rightx) / 2;
		left = new QNode(level + 1, leftx, topy, midx, boty);
		right = new QNode(level + 1, midx, topy, rightx, boty);
	}
	if ((topy - boty) / 2 > SCREEN_HEIGHT)
	{
		float midy = (topy + boty) / 2;
		left = new QNode(level + 1, leftx, midy, rightx, boty);
		right = new QNode(level + 1, leftx, topy, rightx, midy);
	}
}
void QNode::Insert(CGameObject* object)
{
	// Check if the object intersects with the current node
	if (IsContain(object))
	{
		// Insert the object into this node
		objects.push_back(object);

		// Split the node if it hasn't been split yet
		if (left == nullptr && right == nullptr)
		{
			Split();
		}

		// Insert the object into child nodes if necessary
		if (left != nullptr && right != nullptr)
		{
			if (left->IsContain(object))
				left->Insert(object);
			if (right->IsContain(object))
				right->Insert(object);
		}
	}
}

void QNode::Move(CGameObject* object, QNode* node, QNode* Tree)
{
	if (!node->IsContain(object))
	{
		if (left == nullptr && right == nullptr)
		{
			for (auto i = node->objects.begin(); i != node->objects.end(); ++i)
			{
				if (*i == object)
				{
					Tree->Insert(object);
					*i = new Deleted();
					break;
				}
			}
		}
		else
		{
			if (left != nullptr && left->IsContain(object))
				left->Move(object, left, Tree);
			else if (right != nullptr && right->IsContain(object))
				right->Move(object, right, Tree);
		}
	}
}



int QNode::HighestLevel(QNode* node)
{
	if(node == nullptr)
	{
		return -1; // or any other suitable value indicating no nodes
	}

	int maxLevel = node->level;

	if (node->left != nullptr)
	{
		int leftMaxLevel = HighestLevel(node->left);
		if (leftMaxLevel > maxLevel)
		{
			maxLevel = leftMaxLevel;
		}
	}

	if (node->right != nullptr)
	{
		int rightMaxLevel = HighestLevel(node->right);
		if (rightMaxLevel > maxLevel)
		{
			maxLevel = rightMaxLevel;
		}
	}

	return maxLevel;
}
