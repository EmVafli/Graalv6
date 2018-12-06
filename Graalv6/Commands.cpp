#include "Commands.h"



int Commands::GetSize()
{
	int value = listner.ListenSize();
	return value;
}
int Commands::GetCommand()
{
	int lastcommand_type = 0;
	lastcommand_value = listner.ListenCommand();
	if (lastcommand_value == "W" || lastcommand_value == "N" || lastcommand_value == "E" || lastcommand_value == "S") // type - MOVE
	{
		lastcommand_type = 1; // type - MOVE
	}
	if (lastcommand_value.substr(0, 4) == "get ")
	{
		lastcommand_type = 2; 
		lastcommand_value = lastcommand_value.substr(4, lastcommand_value.length());
	}
	if (lastcommand_value.substr(0, 5) == "drop ")
	{
		lastcommand_type = 3; 
		lastcommand_value = lastcommand_value.substr(5, lastcommand_value.length());
	}
	if (lastcommand_value == "open")
	{
		lastcommand_type = 4;
	}
	return lastcommand_type; //0 - type - ERROR
}

std::string Commands::ReturnCommandValue()
{
	return lastcommand_value;
}

Commands::Commands()
{
}


Commands::~Commands()
{
}