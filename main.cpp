#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>

//��������
bool isAdmin = false;
int userCount = 2;
std::string* loginArr = new std::string[userCount]{"admin", "user"};
std::string* passArr = new std::string[userCount]{"admin", "user"};
//�����
int size = 10;
int* idArr = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
double* priceArr = new double[size];
//�������
void Start();
bool Login();
bool isNumber(std::string);
void CreateStaticStorage();
void ShowAdminMenu();
void ShowUserMenu();
void ShowStorage(int mode = 0);
int GetID();
void RefillProduct();
void Getline(std::string& stringName);

template <typename Arr>
void FillStorage(Arr staticArr, Arr dynamicArr, int staticSize);

//<><><><><><><><><><>
int main()
{
	Start();
	delete[]loginArr;
	delete[]passArr;
	delete[]idArr;
	delete[]nameArr;
	delete[]countArr;
	delete[]priceArr;
	return 0;
}
//<><><><><><><><><><>

void Start()
{
	setlocale(LC_ALL, "ru");
	std::cout << "\t\t���������\n\n";
	if (Login() == true)
	{
		if (isAdmin == true)
		{
			std::string choose;
			while (true)
			{
				std::cout << "1 - ������������ ������� �����\n2 - ������� �����\n����: ";
				std::getline(std::cin, choose, '\n');
				if (choose == "1")
				{
					//������� �����
					break;
				}
				else if (choose == "2")
				{
					//������������ �����
					break;
				}
				else
				{
					std::cout << "\n\n������ �����\n\n";
				}
			}
		}
	}
	else
	{
		std::cerr << "loginErr\n";
	}
}
bool Login()
{
	std::string login, pass;
	while (true)
	{
		std::cout << "������� �����: ";
		std::getline(std::cin, login, '\n');
		std::cout << "������� ������: ";
		std::getline(std::cin, pass, '\n');
		if (login == loginArr[0] && pass == passArr[0])
		{
			std::cout << "����������� ������������: " << loginArr[0] << "\n\n";
			isAdmin = true;
			return true;
		}
		for (int i = 1; i < userCount; i++)
		{
			std::cout << "����������� ������������: " << loginArr[i] << "\n\n";
			isAdmin = false;
			return true;
		}
	}
	system("cls");
	std::cout << "�������� ����� ��� ������\n\n";
}
bool isNumber(std::string string)
{
	for (int i = 0; i < string.size(); i++)
	{
		if (!std::isdigit(string[i]))
		{
			return false;
		}
	}
	return true;
}
void CreateStaticStorage()
{
	const int tempSize = 10;
	int tempId[tempSize]{ 1,2,3,4,5,6,7,8,9,10 };
	std::string tempName[tempSize]
	{
		"�������", "�������", "������",
		"�����", "�������", "����������",
		"������� ��� �����", "������� ��� �����",
		"���� ��� �����", "���� ��� �����"
	};
	int tempCount[tempSize]{ 10,15,5,8,6,3,17,16 };
	double tempPrice[tempSize]{ 239.0,251.0,564.0,553.0,821.0,1517.0,166.0,157.0,880.0,990.0 };
	FillStorage(tempId, idArr, tempSize);
	FillStorage(tempName, nameArr, tempSize);
	FillStorage(tempCount, countArr, tempSize);
	FillStorage(tempPrice, priceArr, tempSize);
}
void ShowAdminMenu()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - ������ �������\n";
		std::cout << "2 - �������� �����\n";
		std::cout << "3 - ��������� �����\n";
		std::cout << "4 - ������� �� ������\n";
		std::cout << "5 - �������� ����\n";
		std::cout << "6 - ��������� ������\n";
		std::cout << "7 - ��������� �����������\n";
		std::cout << "8 - ����� � �������\n";
		std::cout << "0 - ������� �����\n";
		std::cout << "����: ";
		std::getline(std::cin, choose, '\n');
		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			RefillProduct();
		}
		else if (choose == "4")
		{

		}
		else if (choose == "5")
		{

		}
		else if (choose == "6")
		{

		}
		else if (choose == "7")
		{

		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
			Sleep(100);
		}
	}
}
void ShowUserMenu()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - ������ �������\n";
		std::cout << "2 - �������� �����\n";
		std::cout << "3 - ��������� �����\n";
		std::cout << "4 - ������� �� ������\n";
		std::cout << "5 - ����� � �������\n";
		std::cout << "0 - ������� �����\n";
		std::cout << "����: ";
		std::getline(std::cin, choose, '\n');
		if (choose == "1")
		{

		}
		else if (choose == "2")
		{

		}
		else if (choose == "3")
		{

		}
		else if (choose == "4")
		{

		}
		else if (choose == "5")
		{

		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
			Sleep(500);
		}
	}
}
void ShowStorage(int mode)
{
	system("cls");
	if (mode == 0)
	{
		std::cout << "\nID\t" << "��������\t\t\t" << "���-��\t" << "����\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << countArr[i] << "\t" << priceArr[i] << "\n";
		}
		std::cout << "\n\n";
	}
	else if (mode == 1)
	{
		std::cout << "\nID\t" << "��������\t\t\t" << "���-��\t" << "\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << countArr[i] << "\n";
		}
		std::cout << "\n\n";
	}
	else if (mode == 2)
	{
		std::cout << "\nID\t" << "��������\t\t\t" << "����\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << "\t" << priceArr[i] << "\n";
		}
		std::cout << "\n\n";
	}
	else
	{
		std::cerr << "\nMenuModeError\n";
	}
	system("pause");
}
int GetID()
{
	std::string stringID;
	int result{};
	while (true)
	{
		std::cout << "������� ID ������: ";
		Getline(stringID);
		if (isNumber(stringID))
		{
			result = std::stoi(stringID);
			if (result > 0 && result <= size)
			{
				return result;
			}
			else
			{
				std::cout << "\n������������ ID\n";
			}
		}
		else
		{
			std::cout << "\n������ �����\n";
		}
	}
}
void RefillProduct()
{
	std::string choose, chooseCount;
	int id = 0, count;
	while (true)
	{
		std::cout << "1 - ������\n0 - ������\n\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(1);
			id = GetID();
			while (true)
			{
				std::cout << "������� ���-�� ������ ��� ����������: ";
				Getline(chooseCount);
				if (isNumber(chooseCount))
				{
					count = std::stoi(chooseCount);
					if (count > 0 && count <= 1000)
					{
						
					}
					else
					{
						std::cout << "\n������ �����\n";
					}
				}
				else
				{
					std::cout << "\n������ �����\n";
				}
			}
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
		}
	}
}
void Getline(std::string& stringName)
{
	std::getline(std::cin, stringName, '\n');
}

template <typename Arr>
void FillStorage(Arr staticArr, Arr dynamicArr, int staticSize)
{
	for (int i = 0; i < staticSize; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}