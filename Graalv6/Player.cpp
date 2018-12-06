#include "Player.h"



void Player::PlayerInit(int x, int y)
{
	initial_life = (x + y) * 2;
	life = initial_life;
}

void Player::AddToInventory(Item & itemposition)
{
	inventory.push_back(itemposition);
}

int Player::CheckInventory(std::string itemname_compare)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		if (inventory[i].itemname == itemname_compare)
		{
			return i;
		}
	}
	return -1;
}

Item Player::PassFromInv(int itemposition)
{
	return inventory[itemposition];
}

void Player::RemoveFromInv(int itemposition)
{
	inventory.erase(inventory.begin() + itemposition);
}

void Player::Move(int direction, int x)
{
	life -= 1;
	switch (direction)
	{
	case 0:
		position -= 1;
		break;
	case 1:
		position += x;
		break;
	case 2:
		position += 1;
		break;
	case 3:
		position -= x;
		break;
	default:
		break;
	}
}

void Player::RestoreLife()
{
	life = life + (initial_life % 10);
	if (life > initial_life)
	{
		life = initial_life;
	}
}

Player::Player()
{
}


Player::~Player()
{
}
