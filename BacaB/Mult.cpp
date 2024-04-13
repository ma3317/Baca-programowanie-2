//Magdalena Maksymiuk
#include <string>
#include <cstdarg>
using namespace std;
std::string intToString2(int num){
    //funkcja zamieniajaca int na string
    std::string number;

    if(num<0)
    {
        number="-";
        num=-num;
    }

    if(num>9)
    {
        number+=intToString2(num/10);

    }
    number+=(char)(num%10 +'0');
    return number;
}


void multiplyDigits(int i, int j, int len1, int len2, int carry, string num1, string num2, int result[]) {
    if (j >= 0) {
        int n2 = num2[j] - '0';
        int n1 = num1[i] - '0';
        int sum = n1 * n2 + result[i + j + 1] + carry;
        carry = sum / 10;
        result[i + j + 1] = sum % 10;
        multiplyDigits(i, j - 1, len1, len2, carry, num1, num2, result);
    } else if (carry > 0) {
        result[i] += carry;
    }
}

void multiplyNumbers(int i, int len1, int len2, string num1, string num2, int result[]) {
    if (i >= 0) {
        multiplyDigits(i, len2 - 1, len1, len2, 0, num1, num2, result);
        multiplyNumbers(i - 1, len1, len2, num1, num2, result);
    }
}


int helper(int i, int len1, int len2, int result[]) {
    if ((i < len1 + len2) && result[i] == 0) {
        i++;
        return helper(i, len1, len2, result);
    } else {
        return i;
    }
}

string helper2(int i, int len1, int len2, int result[], string s) {
    //generuje nam wynik
    if ((i < len1 + len2)) {
        s+=intToString2(result[i++]);
        //i++;
        return helper2(i, len1, len2, result,s);
    } else {
        return s;
    }
}

void initializeArray(int* tab, int size, int index) {
    //index musi byc 0
    if (index < size) {
        tab[index] = 0;
        initializeArray(tab, size, index + 1);
    }
}


string multiply(const string& num1, const string& num2) {
    int len1 = num1.length();
    int len2 = num2.length();
    if (num1 == "0" || num2 == "0")
        return "0";
    if( num1 =="1" && num2 =="1")
        return "1";
    //if(num1=="1" && num2 != "1")
      //  return num2;
   // if(num2=="1" && num1 != "1")
      //  return num1;

    // wynik w odwrotnej kolejnosci
    int* result = new int [len1 + len2];
    int sizeTab = len1 + len2;
    //inicjalizowanie tablicy zerami
    initializeArray(result,sizeTab,0);

    int k = len1 -1;
    //mnozenie od prawej do lewej
    multiplyNumbers(k,len1,len2,num1,num2,result);

    int i = helper(0,len1,len2,result);

    //  przypadek wynik=="0"
    if (i == len1 + len2)
        return "0";

    // odwrocony wynik
    string s="";
    s = helper2(i,len1,len2,result,s);

    delete[] result;//zwolnienie pamieci
    return s;
}


std::string deleteSign2(std::string num){
    if(num[0]=='-' || num[0]=='+')
    {
        num.erase(0,1);
        return num;
    }
    else{
        return num;
    }
}

void deleteZero2(std::string& num) {
    if (num.empty()) {
        num = "0";
    } else if (num[0] == '0') {
        num.erase(0, 1);
        deleteZero2(num);
    }
}

std::string multTwoNum(std::string num1,std::string num2){
    //funkcja zajmujaca sie rozpatrzeniem przypadkow
    std::string result="";
    //usuwanie dodatkowych zer i znakow
    std::string num_one, num_two;
    num_one =deleteSign2(num1);
    deleteZero2(num_one);
    num_two =deleteSign2(num2);
    deleteZero2(num_two);
   // std::cout<<num_one<<std::endl;
   // std::cout<<num_two<<std::endl;
    if(num_one[0]=='0'){
        return "0";
    }

    if(num_two[0]=='0'){
        return "0";
    }

    //przypadki
    if(num1[0]=='-' && num2[0]=='-'){
        //wynik dodatni
        result = multiply(num_one,num_two);
    }
    else if(num1[0]!='-' && num2[0]!='-'){
        //wynik dodatni
        result = multiply(num_one,num_two);
    }
    else if(num1[0]=='-' && num2[0]!='-'){
        //wynik ujemny
        std::string temp ="-";
        result =temp + multiply(num_one,num_two);

    }
    else if(num2[0]=='-' && num1[0]!='-'){
        //wynik ujemny
        std::string temp ="-";
        result =temp + multiply(num_one,num_two);

    }
    return result;
}

std::string multTab(int count, int iterator, std::string result, const std::string* num){

    if(iterator<count){
        if(iterator ==0){
            result = num[0];
            return multTab(count, iterator+1,result, num);
        }
        else{
            std::string num2 = result;
            std::string temp = multTwoNum(num2,num[iterator]);
            result = temp;
            iterator++;
            if(iterator<count)
                return multTab(count,iterator, result, num);

        }
    }

    return result;
}

std::string multTab2(int count, int iterator, std::string result, std::string* num){

    if(iterator<count){
        if(iterator ==0){
            result = num[0];
            return multTab(count, iterator+1,result, num);
        }
        else{
            std::string num2 = result;
            std::string temp = multTwoNum(num2,num[iterator]);
            result = temp;
            iterator++;
            if(iterator<count)
                return multTab(count,iterator, result, num);

        }
    }

    return result;
}

//funkcje z zadania
//bez va_list

std::string Mult (int count, const string* num){
    std::string result ="";
    std::string temp ="";
    result = multTab(count,0,temp,num);
    return result;
}

void Mult (string* result, int count, const string*num){
    *result ="";
    std::string temp ="";
    *result = multTab(count,0,temp,num);
}

void Mult (string& result, int count, const string*num){
    result ="";
    std::string temp ="";
    result = multTab(count,0,temp,num);
}


//z va_list

void rekValistTab2(std::string* num, va_list args, int i, int count){
    if(i<count){
        num[i]=va_arg(args,const char*);
        rekValistTab2(num,args,i+1,count);
    }
}

std::string Mult (int count, ...){
    std::string result="";
    std::string temp="";

    std::string* num = new std::string[count];
    va_list args;
    va_start(args,count);
    rekValistTab2(num,args,0,count);
    va_end(args);
    result =multTab2(count,0,temp,num);


    delete[] num;
    return result;
}

void Mult ( std::string* result, int count, ...){

    *result="";
    std::string temp="";

    std::string* num = new std::string[count];
    va_list args;
    va_start(args,count);
    rekValistTab2(num,args,0,count);
    va_end(args);
    *result =multTab2(count,0,temp,num);


    delete[] num;

}

void Mult ( std::string& result, int count, ...){
    result="";
    std::string temp="";

    std::string* num = new std::string[count];
    va_list args;
    va_start(args,count);
    rekValistTab2(num,args,0,count);
    va_end(args);
    result =multTab2(count,0,temp,num);


    delete[] num;
}
