#include "MyForm.h"
#include <Windows.h>
#include <iostream>
#include <chrono>
#include <ctime>  
#include <iomanip>
#include <fstream>
#include <string>
#include <thread>
#include <msclr\marshal_cppstd.h>



using namespace LebedevaYulia;

using namespace std;

time_t t;
std::tm tm;

string num_s, edstr, num_out;
int start = 0;
size_t nulls;

string mas_numbers[10];

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MyForm);

    

   


    return 0;
}