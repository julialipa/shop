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
//�����
double cash = 9876;
double cashMoney{};
double webMoney{};
//���
int checkSize = 1;
std::string* nameCheckArr = new std::string[checkSize];
int* countCheckArr = new int[checkSize];
double* priceCheckArr = new double[checkSize];
double* totalPriceCheckArr = new double[checkSize];
//�������
void Start();
bool Login();
bool isNumber(std::string);
void CreateStaticStorage();
void ShowAdminMenu();
void ShowUserMenu();
void ShowStorage(int mode = 0);
int GetID(int mode = 0);
void RefillProduct();
void RemoveProduct();
void ChangePrice();
void ChangeStorage();
void AddNewProduct();
void EditProduct();
void DeleteProduct();
void ChangeEmployee();
void AddNewEmployee();
void EditEmployee();
void DeleteEmployee();
void Selling();
void AddNewCheckSize();
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
	delete[]totalPriceCheckArr;
	delete[]countCheckArr;
	delete[]priceCheckArr;
	delete[]nameCheckArr;
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
					ShowAdminMenu();
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
			Selling();
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
			RemoveProduct();
		}
		else if (choose == "5")
		{
			ChangePrice();
		}
		else if (choose == "6")
		{
			ChangeStorage();
		}
		else if (choose == "7")
		{
			ChangeEmployee();
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
	else if (mode == 3)
	{
		std::cout << "\nID\t" << "��������\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\n";
		}
		std::cout << "\n\n";
	}
	else
	{
		std::cerr << "\nMenuModeError\n";
	}
	system("pause");
}
int GetID(int mode)
{
	std::string stringID;
	int result{};
	int currentSize = 0;
	if (mode == 1)
	{
		currentSize = userCount;
	}
	else if (mode == 0)
	{
		currentSize = size;
	}
	while (true)
	{
		std::cout << "������� ID: ";
		Getline(stringID);
		if (isNumber(stringID))
		{
			result = std::stoi(stringID);
			if (result > 0 && result <= currentSize)
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
		system("cls");
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
						countArr[id - 1] += count;
						std::cout << "\n\n����� ������� ��������";
						Sleep(800);
						break;
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
void RemoveProduct()
{
	std::string choose, chooseCount;
	int id = 0, count;
	while (true)
	{
		system("cls");
		std::cout << "1 - ������\n0 - ������\n\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(1);
			id = GetID();
			while (true)
			{
				std::cout << "������� ���-�� ������ ��� ��������: ";
				Getline(chooseCount);
				if (isNumber(chooseCount))
				{
					count = std::stoi(chooseCount);
					if (count > 0 && count <= countArr[id - 1])
					{
						countArr[id - 1] -= count;
						std::cout << "\n\n����� ������� ������";
						Sleep(800);
						break;
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
void ChangePrice()
{
	std::string choose, choosePrice;
	int id = 0;
	double price{};
	while (true)
	{
		system("cls");
		std::cout << "1 - ������\n0 - ������\n\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(2);
			id = GetID();
			while (true)
			{
				std::cout << "������� ����� ����: ";
				Getline(choosePrice);
				if (isNumber(choosePrice))
				{
					price = std::stod(choosePrice);
					if (price >= 0 && price <= 10000.0)
					{
						countArr[id - 1] = price;
						std::cout << "\n\n���� ������� ��������\n\n";
						Sleep(800);
						break;
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
void ChangeStorage()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - ���������� ������ ������\n2 - �������������� ��������\n3 - �������� ������\n0 - ������\n\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			AddNewProduct();
		}
		else if (choose == "2")
		{
			EditProduct();
		}
		else if (choose == "3")
		{
			ChangeStorage();
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
			Sleep(800);
		}
	}
}
void AddNewProduct()
{
	std::string choose, nameStr, priceStr, countStr;
	while (true)
	{
		system("cls");
		std::cout << "1 - ������\n0 - ������\n\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			int* tempID = new int[size];
			int* tempCount = new int[size];
			double* tempPrice = new double[size];
			std::string* tempName = new std::string[size];
			for (int i = 0; i < size; i++)
			{
				tempID[i] = idArr[i];
				tempCount[i] = countArr[i];
				tempPrice[i] = priceArr[i];
				tempName[i] = nameArr[i];
			}
			delete[]idArr;
			delete[]countArr;
			delete[]priceArr;
			delete[]nameArr;
			size++;
			idArr = new int[size];
			countArr = new int[size];
			priceArr = new double[size];
			nameArr = new std::string[size];
			for (int i = 0; i < size - 1; i++)
			{
				idArr[i] = tempID[i];
				countArr[i] = tempCount[i];
				priceArr[i] = tempPrice[i];
				nameArr[i] = tempName[i];
			}
			while (true)
			{
				std::cout << "������� �������� ������ ������: ";
				Getline(nameStr);
				if (nameStr.size() <= 60 && nameStr.size() >= 2)
				{
					nameArr[size - 1] = nameStr;
					break;
				}
				std::cout << "\n������ �����. �� 2 �� 60 ��������\n";
			}
			while (true)
			{
				std::cout << "������� ���-�� ������: ";
				Getline(countStr);
				if (isNumber(countStr))
				{
					if (std::stoi(countStr) >= 0 && std::stoi(countStr) <= 1000)
					{
						countArr[size - 1] = std::stoi(countStr);
						break;
					}
				}
				else
				{
					std::cout << "\n������ �����\n";
				}
			}
			while (true)
			{
				std::cout << "������� ���� ������: ";
				Getline(priceStr);
				if (isNumber(priceStr))
				{
					if (std::stod(priceStr) > 0 && std::stod(priceStr) <= 10000.0)
					{
						priceArr[size - 1] = std::stoi(priceStr);
						break;
					}
				}
				else
				{
					std::cout << "\n������ �����\n";
				}
			}
			idArr[size - 1] = size;
			delete[]tempID;
			delete[]tempCount;
			delete[]tempPrice;
			delete[]tempName;
			std::cout << "\n" << idArr[size - 1] << "\t" << std::left << std::setw(30) << nameArr[size - 1] << "\t" << countArr[size - 1] << "\t" << priceArr[size - 1] << "\n\n";
			std::cout << "����� ����� ������� ��������\n";
			Sleep(2000);
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
void EditProduct()
{
	std::string choose, newName;
	int id{};
	while (true)
	{
		system("cls");
		std::cout << "1 - ������\n0 - ������\n\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(3);
			id = GetID();
			while (true)
			{
				std::cout << "������� �������� ������ ������: ";
				Getline(newName);
				if (newName.size() <= 60 && newName.size() >= 2)
				{
					nameArr[id - 1] = newName;
					break;
				}
				std::cout << "\n������ �����. �� 2 �� 60 ��������\n";
			}
			std::cout << "�������� ��������\n";
			Sleep(2000);
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
void DeleteProduct()
{
	std::string choose;
	int id{};
	while (true)
	{
		system("cls");
		std::cout << "1 - ������\n0 - ������\n\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage();
			int* tempID = new int[size];
			int* tempCount = new int[size];
			double* tempPrice = new double[size];
			std::string* tempName = new std::string[size];
			for (int i = 0; i < size; i++)
			{
				tempID[i] = idArr[i];
				tempCount[i] = countArr[i];
				tempPrice[i] = priceArr[i];
				tempName[i] = nameArr[i];
			}
			delete[]idArr;
			delete[]countArr;
			delete[]priceArr;
			delete[]nameArr;
			id = GetID();
			size--;
			idArr = new int[size];
			countArr = new int[size];
			priceArr = new double[size];
			nameArr = new std::string[size];
			for (int i = 0, j = 0; i < size, j < size + 1; i++, j++)
			{
				if (j == id - 1)
				{
					if (id == size + 1)
					{
						break;
					}
					j++;
					idArr[i] = tempID[i];
					countArr[i] = tempCount[j];
					priceArr[i] = tempPrice[j];
					nameArr[i] = tempName[j];
				}
				else
				{
					idArr[i] = tempID[i];
					countArr[i] = tempCount[j];
					priceArr[i] = tempPrice[j];
					nameArr[i] = tempName[j];
				}
			}
			std::cout << "����� ������� �����\n";
			delete[]tempID;
			delete[]tempCount;
			delete[]tempPrice;
			delete[]tempName;
			Sleep(2000);
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
void ChangeEmployee()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - ���������� ������ ����������\n2 - �������������� ������/������\n3 - �������� ����������\n0 - ������\n\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			
		}
		else if (choose == "2")
		{
			
		}
		else if (choose == "3")
		{
			if (userCount > 1)
			{

			}
			else
			{
				std::cout << "��� ������������� ��� ��������";
			}
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
			Sleep(800);
		}
	}
}
void AddNewEmployee()
{
	std::string choose, newLogin, newPass;
	while (true)
	{
		system("cls");
		std::cout << "1 - ������\n0 - ������\n\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			std::string* tempLogin = new std::string[userCount];
			std::string* tempPass = new std::string[userCount];
			for (int i = 0; i < userCount; i++)
			{
				tempLogin[i] = loginArr[i];
				tempPass[i] = passArr[i];
			}
			delete[]loginArr;
			delete[]passArr;
			userCount++;
			loginArr = new std::string[userCount];
			passArr = new std::string[userCount];
			
			for (int i = 0; i < userCount - 1; i++)
			{
				loginArr[i] = tempLogin[i];
				passArr[i] = tempPass[i];
			}
			
			while (true)
			{
				std::cout << "������� ����� ������ ������������: ";
				Getline(newLogin);
				if (newLogin.size() <= 15 && newLogin.size() >= 4)
				{
					loginArr[userCount - 1] = newLogin;
					break;
				}
				std::cout << "\n������ �����. �� 4 �� 15 ��������\n";
			}
			while (true)
			{
				std::cout << "������� ������ ������ ������������: ";
				Getline(newPass);
				if (newPass.size() <= 15 && newPass.size() >= 4)
				{
					passArr[userCount - 1] = newPass;
					break;
				}
				std::cout << "\n������ �����. �� 4 �� 15 ��������\n";
			}
			std::cout << "����� ������������ ������� ��������\n";
			delete[]tempLogin;
			delete[]tempPass;
			Sleep(2000);
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
void EditEmployee()
{
	std::string choose, currentPass, newPass;
	int id{};
	while (true)
	{
		system("cls");
		std::cout << "1 - ������\n0 - ������\n\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			id = GetID();
			while (true)
			{
				std::cout << "������� ������� ������ ������������: " << loginArr[id - 1] << "\n0 - �����\n����: ";
				Getline(currentPass);
				{
					if (currentPass == passArr[id - 1])
					{
						while (true)
						{
							std::cout << "������� ����� ������ ������������ " << loginArr[id - 1] << ": ";
							Getline(newPass);
							if (newPass.size() <= 15 && newPass.size() >= 4)
							{
								passArr[id - 1] = newPass;
								std::cout << "������ ������� �������\n";
								break;
							}
							std::cout << "\n������ �����. �� 4 �� 15 ��������\n";
						}
					}
					else if (currentPass == "0")
					{
						break;
					}
					else
					{
						std::cout << "\n�������� ������\n";
					}
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
void DeleteEmployee()
{
	std::string choose;
	int id{};
	while (true)
	{
		system("cls");
		std::cout << "1 - ������\n0 - ������\n\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			std::string choose;
			int id{};
			while (true)
			{
				system("cls");
				std::cout << "1 - ������\n0 - ������\n\n����: ";
				Getline(choose);
				if (userCount <= 1)
				{
					std::cout << "������������ ������ ���\n";
					Sleep(1000);
					break;
				}
				if (choose == "1")
				{
					for (int i = 1; i < userCount; i++)
					{
						std::cout << i << " " << loginArr[i] << "\n";
					}
					std::cout << "\n";
					std::string *tempLogin = new std::string[userCount];
					std::string *tempPass = new std::string[userCount];
					for (int i = 0; i < userCount; i++)
					{
						tempLogin[i] = loginArr[i];
						tempPass[i] = passArr[i];
					}
					delete[]loginArr;
					delete[]passArr;
					id = GetID(1);
					userCount--;
					loginArr = new std::string[userCount];
					passArr = new std::string[userCount];
					loginArr[0] = tempLogin[0];
					passArr[0] = tempPass[0];
					for (int i = 1, j = 1; i < userCount, j < userCount + 1; i++, j++)
					{
						if (j == id)
						{
							if (id == userCount)
							{
								break;
							}
							j++;
							loginArr[i] = tempLogin[j];
							passArr[i] = tempPass[j];
						}
						else
						{
							loginArr[i] = tempLogin[j];
							passArr[i] = tempPass[j];
						}
					}
					std::cout << "������������ ������� ������";
					delete[]tempLogin;
					delete[]tempPass;	
					Sleep(800);
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
	}
}
void Selling()
{
	std::string choose, chooseID, chooseCount;
	bool isFirst = true;
	int id{}, count{};
	while (true)
	{
		system("cls");
		std::cout << "1 - ������ ����� �������\n0 - ������\n\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			isFirst = true;
			delete[]totalPriceCheckArr;
			delete[]countCheckArr;
			delete[]priceCheckArr;
			delete[]nameCheckArr;
			checkSize = 1;
			totalPriceCheckArr = new double[checkSize];
			countCheckArr = new int[checkSize];
			priceCheckArr = new double[checkSize];
			nameCheckArr = new std::string[checkSize];
			while (true)
			{
				system("cls");
				ShowStorage();
				std::cout << "������� ID ������ ��� \"exit\" ���������� �������\n\n����: ";
				Getline(chooseID);
				if (chooseID == "exit")
				{
					break;
				}
				else if (isNumber(chooseID))
				{
					id = std::stoi(chooseID);
					if (id > 0 && id <= size)
					{
						std::cout << "������� ���-�� " << nameArr[id - 1] << " ��� �������: ";
						Getline(chooseCount);
						if (isNumber(chooseCount))
						{
							count = std::stoi(chooseCount);
							if (count >= 0 && count <= countArr[id - 1])
							{
								if (isFirst)
								{
									nameCheckArr[checkSize - 1] = nameArr[id - 1];
									countCheckArr[checkSize - 1] = count;
									priceCheckArr[checkSize - 1] = priceArr[id - 1];
									totalPriceCheckArr[checkSize - 1] = count * priceArr[id - 1];
									isFirst == false;
									//�������� �� ������
								}
								else
								{
									AddNewCheckSize();
									nameCheckArr[checkSize - 1] = nameArr[id - 1];
									countCheckArr[checkSize - 1] = count;
									priceCheckArr[checkSize - 1] = priceArr[id - 1];
									totalPriceCheckArr[checkSize - 1] = count * priceArr[id - 1];
								}
							}
							else
							{
								std::cout << "\n������ ���-��\n";
								Sleep(1000);
							}
						}
						else
						{
							std::cout << "\n������ �����\n";
							Sleep(1000);
						}
					}
					else
					{
						std::cout << "\n������ ID\n";
						Sleep(1000);
					}
				}
				else
				{
					std::cout << "\n������ �����\n";
					Sleep(1000);
				}
			}
			if (!isFirst)
			{
				//����� ����!!!
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
void AddNewCheckSize()
{
	int* tempCount = new int[checkSize];
	double* tempTotalPrice = new double[checkSize];
	double* tempPrice = new double[checkSize];
	std::string* tempName = new std::string[checkSize];
	for (int i = 0; i < size; i++)
	{
		tempTotalPrice[i] = totalPriceCheckArr[i];
		tempCount[i] = countCheckArr[i];
		tempPrice[i] = priceCheckArr[i];
		tempName[i] = nameCheckArr[i];
	}
	delete[]totalPriceCheckArr;
	delete[]countCheckArr;
	delete[]priceCheckArr;
	delete[]nameCheckArr;
	checkSize++;
	totalPriceCheckArr = new double[checkSize];
	countCheckArr = new int[checkSize];
	priceCheckArr = new double[checkSize];
	nameCheckArr = new std::string[checkSize];
	for (int i = 0; i < checkSize - 1; i++)
	{
		totalPriceCheckArr[i] = tempTotalPrice[i];
		countCheckArr[i] = tempCount[i];
		priceCheckArr[i] = tempPrice[i];
		nameCheckArr[i] = tempName[i];
	}
	delete[]tempTotalPrice;
	delete[]tempCount;
	delete[]tempPrice;
	delete[]tempName;
}
void Getline(std::string & stringName)
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

/*std::string choose;
while (true)
{
	system("cls");
	std::cout << "1 - ������\n0 - ������\n\n����: ";
	Getline(choose);
	if (choose == "1")
	{

	}
	else if (choose == "0")
	{
		break;
	}
	else
	{
		std::cout << "\n������ �����\n";
	}

}*/