#include <iostream>
// BychkovskayaViktoriya2005
// 42 79 63 68 6b 6f 76 73 6b 61 79 61 56 69 6b 74 6f 72 69 79 61 32 30 30 35 00
// UTF-8 
// 42 79 63 68 6b 6f 76 73 6b 61 79 61 56 69 6b 74 6f 72 69 79 61 32 30 30 35 00
// UTF-16 
// 0042 0079 0063 0068 006b 006f 0076 0073 006b 0061 0079 0061 0056 0069 006b 0074 006f 0072 0069 0079 0061 0032 0030 0030 0035 0000

//БычковскаяВиктория2005
// c1 fb f7 ea ee e2 f1 ea e0 ff c2 e8 ea f2 ee f0 e8 ff 32 30 30 35 00
// UTF-8 
// d091 d18b d187 d0ba d0be d0b2 d181 d0ba d0b0 d18f d092 d0b8 d0ba d182 d0be d180 d0b8 d18f 32 30 30 35 00
// UTF-16 
// 0411 044b 0447 043a 043e 0432 0441 043a 0430 044f 0412 0438 043a 0442 043e 0440 0438 044f 0032 0030 0030 0035 0000

//Бычковская2005Viktoriya
// c1 fb f7 ea ee e2 f1 ea e0 ff 32 30 30 35 56 69 6b 74 6f 72 69 79 61 00
// UTF-8 
// d091 d18b d187 d0ba d0be d0b2 d181 d0ba d0b0 d18f 32 30 30 35 56 69 6b 74 6f 72 69 79 61 00
// UTF-16 
// 0411 044b 0447 043a 043e 0432 0441 043a 0430 044f 0032 0030 0030 0035 0056 0069 006b 0074 006f 0072 0069 0079 0061 0000 0000
int main()
{
	int number = 0x12345678;
	char hello[] = "Hello, ";
	char lfie[] = "BychkovskayaViktoriya2005";
	char rfie[] = "БычковскаяВиктория2005";
	char lr[] = "Бычковская2005Viktoriya";
	
	wchar_t Lfie[] = L"BychkovskayaViktoriya2005";
	wchar_t Rfie[] = L"БычковскаяВиктория2005";
	wchar_t LR[] = L"Бычковская2005Viktoriya";

	std::cout << hello << lfie << std::endl;
	return 0;
}