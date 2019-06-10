// MyExecRefsLib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "MathFuncLib.h"

using namespace std;

int main()
{
	char choice = '0';
	bool cont = true;
	Vector2 tankPos(2, 4);
	Vector2 shipPos;

	Vector3 TankPos(2, 4, 2);
	Vector3 ShipPos;

	float a_x;
	float a_y;
	float a_z;

	Matrix3 Tank;





	float scalar;
	//==================================VECTOR 2=================================================

	/*while (cont)
	{
		cout << "=========ADD(+)===SUBTRACT(-)=====MULTIPLY(*)=====DIVIDE(/)===EXIT(e)==" << endl;
		cout << "==========SWITCH TO VECTOR 3 (3)=================" << endl;
		cin >> choice;
		switch (choice)
		{
		case'+':
			cout << "\t\t\t ADDING..." << endl;
			cout << "--Ship Spawned--" << endl;

			cout << "Enter X:" << endl;
			cin >> a_x;
			shipPos.SetX(a_x);

			cout << "Enter Y:" << endl;
			cin >> a_y;
			shipPos.SetY(a_y);

			system("pause");


			cout << "Ship Pos:";
			shipPos.DisplayVectorCoordinates();
			cout << "=================" << endl;

			cout << "Tank Pos:";
			tankPos.DisplayVectorCoordinates();

			cout << "adding" << endl;
			cin.get();

			cout << "Tank + Ship" << endl;
			tankPos + shipPos;
			tankPos.DisplayVectorCoordinates();

			break;
		case'-':
			cout << "\t\t\t SUBTRACTING..." << endl;
			cout << "--Ship Spawned--" << endl;

			cout << "Enter X:" << endl;
			cin >> a_x;
			shipPos.SetX(a_x);

			cout << "Enter Y:" << endl;
			cin >> a_y;
			shipPos.SetY(a_y);

			system("pause");

			cout << "Ship Pos:";
			shipPos.DisplayVectorCoordinates();
			cout << "=================" << endl;

			cout << "Tank Pos:";
			tankPos.DisplayVectorCoordinates();

			cout << "subtracting" << endl;
			cin.get();

			cout << "Tank - Ship" << endl;
			tankPos -= shipPos;
			tankPos.DisplayVectorCoordinates();

			break;
		case'*':
			cout << "\t\t\t MULTIPLYING..." << endl;

			cout << "Tank Pos:";
			tankPos.DisplayVectorCoordinates();

			cout << "multiply by: " << endl;
			cin >> scalar;
			cin.get();


			cout << "Tank * " << scalar << " =" << endl;
			tankPos * scalar;
			tankPos.DisplayVectorCoordinates();

			break;
		case'/':
			cout << "\t\t\t DIVIDING..." << endl;
			cout << "Tank Pos:";
			tankPos.DisplayVectorCoordinates();

			cout << "divide by: " << endl;
			cin >> scalar;
			cin.get();


			cout << "Tank /= " << scalar << " =" << endl;
			tankPos /= scalar;
			tankPos.DisplayVectorCoordinates();
			break;
		case'e':
			return 0;

		case'3':
			cont = false;

		default:
			cout << "Please Choose One Of The Options" << endl;

		}
	}*/

	//==================================VECTOR 3=================================================
	/*while (cont == false)
	{
		cout << "=========ADD(+)===SUBTRACT(-)=====MULTIPLY(*)=====DIVIDE(/)===EXIT(e)==" << endl;
		cout << "==========SWITCH TO VECTOR 2 (2)=================" << endl;
		cin >> choice;
		switch (choice)
		{
		case'+':
			cout << "\t\t\t ADDING..." << endl;
			cout << "--Ship Spawned--" << endl;

			cout << "Enter X:" << endl;
			cin >> a_x;
			ShipPos.SetX(a_x);

			cout << "Enter Y:" << endl;
			cin >> a_y;
			ShipPos.SetY(a_y);

			cout << "Enter Z:" << endl;
			cin >> a_z;
			ShipPos.SetZ(a_z);

			system("pause");


			cout << "Ship Pos:";
			ShipPos.DisplayVector3Coordinates();
			cout << "=================" << endl;

			cout << "Tank Pos:";
			TankPos.DisplayVector3Coordinates();

			cout << "adding" << endl;
			cin.get();

			cout << "Tank + Ship" << endl;
			TankPos + ShipPos;
			TankPos.DisplayVector3Coordinates();

			break;
		case'-':
			cout << "\t\t\t SUBTRACTING..." << endl;
			cout << "--Ship Spawned--" << endl;

			cout << "Enter X:" << endl;
			cin >> a_x;
			ShipPos.SetX(a_x);

			cout << "Enter Y:" << endl;
			cin >> a_y;
			ShipPos.SetY(a_y);

			cout << "Enter Z:" << endl;
			cin >> a_z;
			ShipPos.SetZ(a_z);

			system("pause");

			cout << "Ship Pos:";
			ShipPos.DisplayVector3Coordinates();
			cout << "=================" << endl;

			cout << "Tank Pos:";
			TankPos.DisplayVector3Coordinates();

			cout << "subtracting" << endl;
			cin.get();

			cout << "Tank - Ship" << endl;
			TankPos -= ShipPos;
			TankPos.DisplayVector3Coordinates();

			break;
		case'*':
			cout << "\t\t\t MULTIPLYING..." << endl;

			cout << "Tank Pos:";
			TankPos.DisplayVector3Coordinates();

			cout << "multiply by: " << endl;
			cin >> scalar;
			cin.get();


			cout << "Tank * " << scalar << " =" << endl;
			TankPos * scalar;
			TankPos.DisplayVector3Coordinates();

			break;
		case'/':
			cout << "\t\t\t DIVIDING..." << endl;
			cout << "Tank Pos:";
			TankPos.DisplayVector3Coordinates();

			cout << "divide by: " << endl;
			cin >> scalar;
			cin.get();


			cout << "Tank /= " << scalar << " =" << endl;
			TankPos /= scalar;
			TankPos.DisplayVector3Coordinates();
			break;
		case'e':
			return 0;

		case'2':
			cont = true;

		default:
			cout << "Please Choose One Of The Options" << endl;

		}
	}*/
}


	//===============Adding Two Vectors===================

	//Vector2 *TankPos = new Vector2(1, 2);
	//Vector2 *ShipPos = new Vector2(2, 4);
	//Vector2 *newVector = new Vector2();
	//cout << "TANK:" << endl;
	//TankPos->DisplayVectorCoordinates();
	//cout << endl;
	//cin.get();
	//cout << "SHIP:" << endl;
	//ShipPos->DisplayVectorCoordinates();
	//cout << endl;
	//cin.get();
	//cout << "DEFAULT" << endl;
	//newVector->DisplayVectorCoordinates();
	//cout << endl;
	//cin.get();
	//newVector->Add(TankPos, ShipPos);
	//cout << "AFTER ADDITION" << endl;
	//newVector->DisplayVectorCoordinates();
	//cout << endl;
	//cin.get();

	/*Vector2 TankPos(2, 2);
	Vector2 ShipPos(2, 2);

	cout << "Before: " << endl;
	TankPos.DisplayVectorCoordinates();
	ShipPos.DisplayVectorCoordinates();

	TankPos /= 2.3;

	cout << "After: " << endl;
	TankPos.DisplayVectorCoordinates();
	ShipPos.DisplayVectorCoordinates();*/

	//================OPERATOR ADD FUNCTION===================

	/*Vector2 TankPos = Vector2(2, 4);

	Vector2 ShipPos(1, 2);

	cout << "Before Tank Position:" << endl;
	TankPos.DisplayVectorCoordinates();

	TankPos + ShipPos;
	cin.get();
	cout << "After Tank Position:" << endl;
	TankPos.DisplayVectorCoordinates();

	cout << "Before Ship Position: " << endl;
	ShipPos.DisplayVectorCoordinates();
	cin.get();

	ShipPos + TankPos;
	cout << "After Ship Position:" << endl;
	ShipPos.DisplayVectorCoordinates();*/

	//===============OPERATOR ADD FUNCTION===================



	//=============OPERATOR MULTIPLY FUNCTION===============
	/*Vector2 t = Vector2(2,4);
	cout << "t: " << endl;
	t.DisplayVectorCoordinates();
	t*2;
	t.DisplayVectorCoordinates();*/
	//=============OPERATOR MULTIPLY FUNCTION===============

	//=====================Multiply To Add To it==================
	/*Vector2 *ShipPos = new Vector2(2,4);

	cout << "Before Change X = " << ShipPos->GetX() << endl;
	cout << "=========================================" << endl;
	cout << "Before Change Y = " << ShipPos->GetY() << endl;
	cout << "=========================================" << endl;

	cin.get();

	ShipPos->operator*(2);
	cout << "After Change X = " << ShipPos->GetX() << endl;
	cout << "=========================================" << endl;
	cout << "After Change Y = " << ShipPos->GetY() << endl;
	cout << "=========================================" << endl;

	cin.get();

	ShipPos->DisplayVectorCoordinates();

	cin.get();*/
	//=====================Multiply To Add To it==================


	//return 0;
//}

//double a = 7.4;
//int b = 99;
//cout << "a + b = " <<
//	MathFuncs::MyMathFuncs::Add(a, b) << endl;
//cout << "a - b = " <<
//	MathFuncs::MyMathFuncs::Subtract(a, b) << endl;
//cout << "a * b = " <<
//	MathFuncs::MyMathFuncs::Multiply(a, b) << endl;
//cout << "a / b = " <<
//	MathFuncs::MyMathFuncs::Divide(a, b) << endl;
//Vector3 myVector;
//Vector3 iterator = Vector3();
//Vector3 position = myVector;
//cout << position[1] << endl;

	//Array
	//Vector3 VectorUse;
	//cout << "x:" << VectorUse[0] << endl; //x
	//cout << "y:" << VectorUse[1] << endl; //y
	//cout << "z:" << VectorUse[2] << endl; //z


//cout << "X Position: " << ShipPos->GetX() << endl;;
	//cout << "=========================================" << endl;
	//cout << "Y Position: " << ShipPos->GetY() << endl;;
	//ShipPos has position (2,4)