#pragma once

class NodeClass
{
public:
	//Changes Colour To White
	void SetValue(float value);
	//changes Colour to White(-1 = White || 100 = Original)


	//To Set Values
	void setRight(NodeClass* current);

	//To Check Values 
	NodeClass *getRight();

	void setData(int a_nValue);
	int getData();

private:
	NodeClass *m_right = nullptr;
	NodeClass *m_left = nullptr;

	int m_value;
};