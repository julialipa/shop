#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>

//аккаунты
bool isAdmin = false;
int userCount = 2;
std::string* loginArr = new std::string[userCount]{"admin", "user"};
std::string* passArr = new std::string[userCount]{"admin", "user"};
//склад
int size = 10;
int* idArr = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
double* priceArr = new double[size];
//касса
double cash = 9876;
double cashMoney{};
double webMoney{};
//чек
int checkSize = 1;
std::string* nameCheckArr = new std::string[checkSize];
int* countCheckArr = new int[checkSize];
double* priceCheckArr = new double[checkSize];
double* totalPriceCheckArr = new double[checkSize];
//функции
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
	std::cout << "\t\tКвадробер\n\n";
	if (Login() == true)
	{
		if (isAdmin == true)
		{
			std::string choose;
			while (true)
			{
				std::cout << "1 - Использовать готовый склад\n2 - Создать склад\nВвод: ";
				std::getline(std::cin, choose, '\n');
				if (choose == "1")
				{
					//готовый склад
					ShowAdminMenu();
					break;
				}
				else if (choose == "2")
				{
					//динамический склад
					break;
				}
				else
				{
					std::cout << "\n\nОшибка ввода\n\n";
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
		std::cout << "Введите логин: ";
		std::getline(std::cin, login, '\n');
		std::cout << "Введите пароль: ";
		std::getline(std::cin, pass, '\n');
		if (login == loginArr[0] && pass == passArr[0])
		{
			std::cout << "Авторизация пользователя: " << loginArr[0] << "\n\n";
			isAdmin = true;
			return true;
		}
		for (int i = 1; i < userCount; i++)
		{
			std::cout << "Авторизация пользователя: " << loginArr[i] << "\n\n";
			isAdmin = false;
			return true;
		}
	}
	system("cls");
	std::cout << "Неверный логин или пароль\n\n";
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
		"Ошейник", "Поводок", "Шлейка",
		"Миска", "Лежанка", "Когтеточка",
		"Игрушка для кошек", "Игрушка для собак",
		"Корм для кошек", "Корм для собак"
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
		std::cout << "1 - Начать продажу\n";
		std::cout << "2 - Показать склад\n";
		std::cout << "3 - Пополнить склад\n";
		std::cout << "4 - Списать со склада\n";
		std::cout << "5 - Изменить цену\n";
		std::cout << "6 - Изменение склада\n";
		std::cout << "7 - Изменение сотрудников\n";
		std::cout << "8 - Отчёт о прибыли\n";
		std::cout << "0 - Закрыть смену\n";
		std::cout << "Ввод: ";
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
			std::cout << "\nОшибка ввода\n";
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
		std::cout << "1 - Начать продажу\n";
		std::cout << "2 - Показать склад\n";
		std::cout << "3 - Пополнить склад\n";
		std::cout << "4 - Списать со склада\n";
		std::cout << "5 - Отчёт о прибыли\n";
		std::cout << "0 - Закрыть смену\n";
		std::cout << "Ввод: ";
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
			std::cout << "\nОшибка ввода\n";
			Sleep(500);
		}
	}
}
void ShowStorage(int mode)
{
	system("cls");
	if (mode == 0)
	{
		std::cout << "\nID\t" << "Название\t\t\t" << "Кол-во\t" << "Цена\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << countArr[i] << "\t" << priceArr[i] << "\n";
		}
		std::cout << "\n\n";
	}
	else if (mode == 1)
	{
		std::cout << "\nID\t" << "Название\t\t\t" << "Кол-во\t" << "\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << countArr[i] << "\n";
		}
		std::cout << "\n\n";
	}
	else if (mode == 2)
	{
		std::cout << "\nID\t" << "Название\t\t\t" << "Цена\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << "\t" << priceArr[i] << "\n";
		}
		std::cout << "\n\n";
	}
	else if (mode == 3)
	{
		std::cout << "\nID\t" << "Название\n";
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
		std::cout << "Введите ID: ";
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
				std::cout << "\nНекорректное ID\n";
			}
		}
		else
		{
			std::cout << "\nОшибка ввода\n";
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
		std::cout << "1 - Начать\n0 - Отмена\n\nВвод: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(1);
			id = GetID();
			while (true)
			{
				std::cout << "Введите кол-во товара для пополнения: ";
				Getline(chooseCount);
				if (isNumber(chooseCount))
				{
					count = std::stoi(chooseCount);
					if (count > 0 && count <= 1000)
					{
						countArr[id - 1] += count;
						std::cout << "\n\nТовар успешно пополнен";
						Sleep(800);
						break;
					}
					else
					{
						std::cout << "\nОшибка ввода\n";
					}
				}
				else
				{
					std::cout << "\nОшибка ввода\n";
				}
			}
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\nОшибка ввода\n";
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
		std::cout << "1 - Начать\n0 - Отмена\n\nВвод: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(1);
			id = GetID();
			while (true)
			{
				std::cout << "Введите кол-во товара для списания: ";
				Getline(chooseCount);
				if (isNumber(chooseCount))
				{
					count = std::stoi(chooseCount);
					if (count > 0 && count <= countArr[id - 1])
					{
						countArr[id - 1] -= count;
						std::cout << "\n\nТовар успешно списан";
						Sleep(800);
						break;
					}
					else
					{
						std::cout << "\nОшибка ввода\n";
					}
				}
				else
				{
					std::cout << "\nОшибка ввода\n";
				}
			}
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\nОшибка ввода\n";
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
		std::cout << "1 - Начать\n0 - Отмена\n\nВвод: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(2);
			id = GetID();
			while (true)
			{
				std::cout << "Введите новую цену: ";
				Getline(choosePrice);
				if (isNumber(choosePrice))
				{
					price = std::stod(choosePrice);
					if (price >= 0 && price <= 10000.0)
					{
						countArr[id - 1] = price;
						std::cout << "\n\nЦена успешно изменена\n\n";
						Sleep(800);
						break;
					}
					else
					{
						std::cout << "\nОшибка ввода\n";
					}
				}
				else
				{
					std::cout << "\nОшибка ввода\n";
				}
			}
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\nОшибка ввода\n";
		}
	}
}
void ChangeStorage()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - Добавление нового товара\n2 - Редактирование названия\n3 - Удаление товара\n0 - Отмена\n\nВвод: ";
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
			std::cout << "\nОшибка ввода\n";
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
		std::cout << "1 - Начать\n0 - Отмена\n\nВвод: ";
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
				std::cout << "Введите название нового товара: ";
				Getline(nameStr);
				if (nameStr.size() <= 60 && nameStr.size() >= 2)
				{
					nameArr[size - 1] = nameStr;
					break;
				}
				std::cout << "\nОшибка ввода. От 2 до 60 символов\n";
			}
			while (true)
			{
				std::cout << "Введите кол-во товара: ";
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
					std::cout << "\nОшибка ввода\n";
				}
			}
			while (true)
			{
				std::cout << "Введите цену товара: ";
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
					std::cout << "\nОшибка ввода\n";
				}
			}
			idArr[size - 1] = size;
			delete[]tempID;
			delete[]tempCount;
			delete[]tempPrice;
			delete[]tempName;
			std::cout << "\n" << idArr[size - 1] << "\t" << std::left << std::setw(30) << nameArr[size - 1] << "\t" << countArr[size - 1] << "\t" << priceArr[size - 1] << "\n\n";
			std::cout << "Новый товар успешно добавлен\n";
			Sleep(2000);
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\nОшибка ввода\n";
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
		std::cout << "1 - Начать\n0 - Отмена\n\nВвод: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(3);
			id = GetID();
			while (true)
			{
				std::cout << "Введите название нового товара: ";
				Getline(newName);
				if (newName.size() <= 60 && newName.size() >= 2)
				{
					nameArr[id - 1] = newName;
					break;
				}
				std::cout << "\nОшибка ввода. От 2 до 60 символов\n";
			}
			std::cout << "Название изменено\n";
			Sleep(2000);
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\nОшибка ввода\n";
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
		std::cout << "1 - Начать\n0 - Отмена\n\nВвод: ";
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
			std::cout << "Товар успешно удалён\n";
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
			std::cout << "\nОшибка ввода\n";
		}
	}
}
void ChangeEmployee()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - Добавление нового сотрудника\n2 - Редактирование логина/пароля\n3 - Удаление сотрудника\n0 - Отмена\n\nВвод: ";
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
				std::cout << "Нет пользователей для удаления";
			}
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\nОшибка ввода\n";
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
		std::cout << "1 - Начать\n0 - Отмена\n\nВвод: ";
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
				std::cout << "Введите логин нового пользователя: ";
				Getline(newLogin);
				if (newLogin.size() <= 15 && newLogin.size() >= 4)
				{
					loginArr[userCount - 1] = newLogin;
					break;
				}
				std::cout << "\nОшибка ввода. От 4 до 15 символов\n";
			}
			while (true)
			{
				std::cout << "Введите пароль нового пользователя: ";
				Getline(newPass);
				if (newPass.size() <= 15 && newPass.size() >= 4)
				{
					passArr[userCount - 1] = newPass;
					break;
				}
				std::cout << "\nОшибка ввода. От 4 до 15 символов\n";
			}
			std::cout << "Новый пользователь успешно добавлен\n";
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
			std::cout << "\nОшибка ввода\n";
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
		std::cout << "1 - Начать\n0 - Отмена\n\nВвод: ";
		Getline(choose);
		if (choose == "1")
		{
			id = GetID();
			while (true)
			{
				std::cout << "Введите текущий пароль пользователя: " << loginArr[id - 1] << "\n0 - Выход\nВвод: ";
				Getline(currentPass);
				{
					if (currentPass == passArr[id - 1])
					{
						while (true)
						{
							std::cout << "Введите новый пароль пользователя " << loginArr[id - 1] << ": ";
							Getline(newPass);
							if (newPass.size() <= 15 && newPass.size() >= 4)
							{
								passArr[id - 1] = newPass;
								std::cout << "Пароль успешно изменён\n";
								break;
							}
							std::cout << "\nОшибка ввода. От 4 до 15 символов\n";
						}
					}
					else if (currentPass == "0")
					{
						break;
					}
					else
					{
						std::cout << "\nНеверные данные\n";
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
			std::cout << "\nОшибка ввода\n";
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
		std::cout << "1 - Начать\n0 - Отмена\n\nВвод: ";
		Getline(choose);
		if (choose == "1")
		{
			std::string choose;
			int id{};
			while (true)
			{
				system("cls");
				std::cout << "1 - Начать\n0 - Отмена\n\nВвод: ";
				Getline(choose);
				if (userCount <= 1)
				{
					std::cout << "Пользователя больше нет\n";
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
					std::cout << "Пользователь успешно удален";
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
					std::cout << "\nОшибка ввода\n";
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
		std::cout << "1 - Начать новую продажу\n0 - Отмена\n\nВвод: ";
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
				std::cout << "Введите ID товара или \"exit\" завершения покупок\n\nВвод: ";
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
						std::cout << "Введите кол-во " << nameArr[id - 1] << " для покупки: ";
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
									//удаление со склада
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
								std::cout << "\nОшибка кол-ва\n";
								Sleep(1000);
							}
						}
						else
						{
							std::cout << "\nОшибка ввода\n";
							Sleep(1000);
						}
					}
					else
					{
						std::cout << "\nОшибка ID\n";
						Sleep(1000);
					}
				}
				else
				{
					std::cout << "\nОшибка ввода\n";
					Sleep(1000);
				}
			}
			if (!isFirst)
			{
				//принт чека!!!
			}
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\nОшибка ввода\n";
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
	std::cout << "1 - Начать\n0 - Отмена\n\nВвод: ";
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
		std::cout << "\nОшибка ввода\n";
	}

}*/