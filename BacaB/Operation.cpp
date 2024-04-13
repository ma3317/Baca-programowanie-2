//Magdalena Maksymiuk
#include <string>
#include <cstdarg>
using namespace std;
//pomocnicze
void OperationRecursion(std::string* arguments, va_list args, int i, int count) {
    if (i < count) {
        arguments[i] = va_arg(args, const char*);
        OperationRecursion(arguments, args, i + 1, count);
    }
}
//1
std::string Operation(std::string (*function)(int, const std::string*), int count, const std::string* numbers) {
    return function(count, numbers);
}

//2
std::string Operation(std::string (*function)(int, const std::string*), int count, ...) {
    va_list args;
    va_start(args, count);
    std::string* arguments = new std::string[count];
    OperationRecursion(arguments, args, 0, count);
    va_end(args);
    std::string result = function(count, arguments);
    delete[] arguments;
    return result;
}
//3
void Operation(std::string* result, std::string (*function)(int, const std::string*), int count, ...) {
    va_list args;
    va_start(args, count);
    std::string* arguments = new std::string[count];
    OperationRecursion(arguments, args, 0, count);
    va_end(args);
    *result = function(count, arguments);
    delete[] arguments;
}

//4
void Operation(std::string* result,string(*function)(int,const string*), int count, const string* num){
    *result = function(count,num);
}
//5
void Operation(std::string& result, void(*function)(std::string*, int, const string*), int count, const std::string* num){
    std::string temp ="";
    function(&temp,count,num);
    result = temp;

}
//6
void Operation(std::string& result, void (*function)(std::string*, int, const std::string*), int count, ...) {
    std::string temp="";
    va_list args;
    va_start(args, count);
    std::string* arguments = new std::string[count];
    OperationRecursion(arguments, args, 0, count);
    va_end(args);
    function(&temp,count, arguments);
    result = temp;
    delete[] arguments;
}

