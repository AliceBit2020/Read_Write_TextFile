#include <windows.h>
#include <iostream>

using namespace std;


//struct Point  //// тип данних Point
//{
//	int x;
//	int y;
//};
//
//
//void PrintPoint(Point* pointPtr)
//{
//	if (pointPtr == nullptr)
//		return;
//	cout << "Point (" << pointPtr->x << ", " << pointPtr->y << ")" << endl;
//}

int main()
{	
	
	//PrintPoint(nullptr);
	
	////1.Для чего
	/*Файлы в компьютере могут хранится в двух вариантах : текстовые файлы и бинарные файлы. Оба варианта хранятся в битовом виде на жестких дисках.
		В зависимости от задачи бывает удобно выбрать один из этих вариантов.Например, для настроек какой - нибудь игры или программы может быть удобно хранить файлы в текстовом виде, чтобы можно было взять открыть любым текстовым редактором и поменять какую - нибудь настройку быстро и просто.А вот сохранения игр удобнее хранить в бинарных файлах.Как минимум это лёгкая защита от применения читов.Ведь что за игра, если тебе система дала 100 монет, а ты открываешь файл, пишешь 1000.000 монет, покупаешь самое крутое и такой прям классный - преклассный игрок.Я к тому, что выбор двоичного или текстового файла может зависеть от ситуации.*/

	////Подход С
	///2. Структура для хранения системных данных о файле
	//// #include <stdio.h>  FILE структура которая содержит информацию
    //// необходимую для работы с файлом, системо зависимая, заполняется самой системой
    ////В том числ содержит дескриптор файла (индекс в таблице открытых файлов)  

	////3. Функция открытия файла. Открыть файл - поставить в соответствие этому файлу поток (для передачи байтов) 
	/////#include <stdio.h>
	////errno_t fopen_s(
	////FILE** pFile,
	////	const char* filename,
	////	const char* mode
	////	);

	///*Parameters
	//	pFile
	//	A pointer to the file pointer that will receive the pointer to the opened file.

	//	filename
	//	Filename.

	//	mode
	//	Type of access permitted.

	//	Return Value
	//	Zero if successful; an error code on failure.*/

	////4. Файл можно открыть в разных режимах чтение/запись/ чтение и запись/ дозапись и тд, что контролируется параметром 
	//// mode

	/*	"r"	Opens for reading.If the file doesn't exist or cannot be found, the fopen_s call fails.
		"w"	Opens an empty file for writing.If the given file exists, its contents are destroyed.
		"a"	Opens for writing at the end of the file(appending) without removing the end - of - file(EOF) marker before new data is written to the file.Creates the file if it doesn't exist.
		"r+"	Opens for both readingand writing.The file must exist.
		"w+"	Opens an empty file for both readingand writing.If the file exists, its contents are destroyed.
		"a+"	Opens for readingand appending.The appending operation includes the removal of the EOF marker before new data is written to the file.The EOF marker isn't restored after writing is completed. Creates the file if it doesn't exist.*/


	SetConsoleOutputCP(65001);

	char filename[MAX_PATH];
	cout << "Введіть шлях до файлу" << endl;///////    ../Files/1.txt   папка віше
	cin >> filename;

	getchar();

	const char* filename = "1.txt";

	FILE * f1 = nullptr;/////  Func(FILE **)  Func(FILE *&)  nullptr=0x00000000
	fopen_s(&f1, filename, "r");////полный путь  D:\Test\Debug\1.txt   сокращенный путь   1.txt файл находится в той же папке что и проект
	if(f1 == nullptr)
	{
		perror("Error opening 1");
		return 0;
	}
	FILE * f2 = nullptr;
	fopen_s(&f2, "copy.txt", "w");//"copy.txt"   "copy.JPG"
	if (f2 == nullptr)
	{
		perror("Error opening 2");
		return 0;
	}
	char buffer[300];//256
	while(!feof(f1))////////пока не достигли конца файла, возвращает 0,
					//////когда пытается читать за пределами конца файла - возвращает не 0
	{
		///fgets - зчитування по одній строчці
		fgets(buffer, 300, f1);////////////читает последовательно 300 символов из файла в буфер, затем в цикле следующие 300 символов


		Sleep(1000);///1sec
		cout<<buffer<<endl;
		
		
		fputs(buffer, f2);///запись из буфера в файл
		
	}
	fclose(f1);///после работы с файлом его нужно закрыть
	fclose(f2);
	cout << endl;



	return 0;

	///////////////////////////////////////////////////////////////////////////////////////////

	//Point A1{ 1,2 };  //// stack

	//cout << "A1 (" << A1.x << ", " << A1.y << ")" << endl;

	//Point* A2 = new Point{ 2,3 };//heap   1 об'єкт у кучі

	//cout << "A2 (" << A2->x << ", " << A2->y << ")" << endl;

	//delete A2; /// дикий вказівник що дивиться на адресу видаленого об'єкту

	//A2 = nullptr;  /// А2 не дивиться на жодний з об'єктів

	//if (A2 != nullptr)  /// чи не нульовий вказівник А2  ?
	//{
	//	cout << "A2 (" << A2->x << ", " << A2->y << ")" << endl;
	//}


	////// fgetc - зчитування по одному символу

	FILE* in = fopen("1.txt", "r");
	

	if (in == NULL ) {
		printf("error\n");
		return 1;
	}

	
	
	char ch;

	while ((ch = fgetc(in)) != EOF) {
		cout << ch << endl;
		Sleep(500);
	}



	fclose(in);



	char* str1 = new char[5] {"abc"};
	char* str2 = new char[5] {"def"};

	if (strcmp(str1, str2)==0)
	{
		cout << "str1=str2" << endl;
	}
	else if (strcmp(str1, str2) >0)
	{
		cout << "str1>str2" << endl;
	}
	else if (strcmp(str1, str2) <0)
	{
		cout << "str1<str2" << endl;
	}


}



///