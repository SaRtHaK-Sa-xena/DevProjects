#pragma once
#include "ColliderWall.h"

enum ItemName
{
	ItemNO1, ItemNO2, ItemNO3, ItemNO4, ItemNO5,
	ItemNO6, ItemNO7, ItemNO8, ItemNO9, ItemNO10
};


struct collectCollision
{
	Vector2 topLeftPosition;
	Vector2 botttomRightPosition;

	wallSide sideOfItem;

	ItemName nameOfItems;
};