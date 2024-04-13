//Magdalena Maksymiuk
#include <string>
#include <cstdarg>

using namespace std;
//funkcje pomocnicze
std::string intToString(int num){
    //funkcja zamieniajaca int na string
    std::string number;

    if(num<0)
    {
        number="-";
        num=-num;
    }

    if(num>9)
    {
        number+=intToString(num/10);

    }
    number+=(char)(num%10 +'0');
    return number;
}

int charToInt(char num)
{
    //funkcja zamieniajaca string na int
    int number;
    if(num =='0')
    {
        number=0;
    }
    else if(num =='1')
    {
        number=1;
    }
    else if(num =='2')
    {
        number=2;
    }
    else if(num =='3')
    {
        number=3;
    }
    else if(num =='4')
    {
        number=4;
    }
    else if(num =='5')
    {
        number=5;
    }
    else if(num =='6')
    {
        number=6;
    }
    else if(num =='7')
    {
        number=7;
    }
    else if(num =='8')
    {
        number=8;
    }
    else if(num =='9')
    {
        number=9;
    }

    return number;
}

std::string reverseNum(std::string num, std::string rnum, int n)
{
    // n to liczba znaków ciagu
    //rnum musi byc pustym ciagiem znakow zeby bledow nie bylo
    rnum = rnum + num[n-1];
    int k = n-1;
    if(n>0){
        return reverseNum(num,rnum,k);

    }
    return rnum;

}
/*std::string reverseNum(std::string num, std::string rnum, int n)
{
    // n to liczba znaków ciagu
    //rnum musi byc pustym ciagiem znakow zeby bledow nie bylo
    rnum = rnum + num[n-1];
    int k = n-1;
    if(n>0){
        return reverseNum(num,rnum,k);

    }
    return rnum;

}*/
std::string addZeroAtBegin(std::string num, int n){
    // n jest liczbą zer jakie trzeba dodać
    std::string zero1="0";
    std::string zNum = zero1+num;
    int k=n-1;
    if(n>1){
        return addZeroAtBegin(zNum,k);
    }
    return zNum;
}
int countHowManyZero(std::string num1, std::string num2){
    //num1 i num2 sa pozbawione znaku +/-
    int n1=num1.length();
    int n2=num2.length();
    int res= n1-n2;
    int result;
    if(res<0)
    {
        result = -res;
    }
    else{
        result = res;
    }
    return result;
}

std::string deleteSign(std::string num){
    if(num[0]=='-' || num[0]=='+')
    {
        num.erase(0,1);
        return num;
    }
    else{
        return num;
    }
}

void deleteZero(std::string& num) {
    if (num.empty()) {
        num = "0";
    } else if (num[0] == '0') {
        num.erase(0, 1);
        deleteZero(num);
    }
}
bool compareStrings(string str1, string str2, int i) {
    //i powinno byc 0
    if (str1[i] == '\0' || str2[i] == '\0') {
        return false;
    }
    if (str1[i] < str2[i]) {
        return true;
    } else if (str1[i] > str2[i]) {
        return false;
    } else {
        return compareStrings(str1, str2, i + 1);
    }
}

bool isNum1IsSmaller(string str1, string str2)
{

    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;
    bool result = compareStrings(str1,str2,0);
    return result;
}

void helper1(string str1, string str2, int i, string& str, int diff, int &carry){
    //i=n2-n1-1
    if(i>=0){
        int sub = ((str1[i + diff] - '0') - (str2[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str+=(char)(sub + '0');
        helper1(str1,str2,i-1,str,diff,carry);
    }
}


void subtractStringsRecursively(string &str1, string &str2, int n1, int n2, int diff, int &carry, string &str) {
    if (n2 < 0) {
        return;
    }

    int sub = ((str1[n2 + diff] - '0') - (str2[n2] - '0') - carry);
    if (sub < 0) {
        sub = sub + 10;
        carry = 1;
    } else {
        carry = 0;
    }

    str+=(char)(sub + '0');

    subtractStringsRecursively(str1, str2, n1, n2 - 1, diff, carry, str);
}



void helper(int i, int carry, string& res, string& num1) {
    if (i < 0) {
        return;
    }

    if (num1[i] == '0' && carry) {
        res+=('9');
        helper(i - 1, carry, res, num1);
    } else {
        int sub = ((num1[i] - '0') - carry);
        if (i > 0 || sub > 0) {
            res+=(char)(sub + '0');
        }
        helper(i - 1, 0, res, num1);
    }
}



string subNum(string num1, string num2)
{

    if (isNum1IsSmaller(num1, num2))
        swap(num1, num2);


    string result = "";

    int n1 = num1.length(),
            n2 = num2.length();
    int diff = n1 - n2;


    int carry = 0;
    subtractStringsRecursively(num1, num2, n1, n2, diff, carry, result);

    int k = n1 - n2 -1;
    helper(k,carry,result, num1);

    // reverse resultant string
    deleteZero(result);
    result = reverseNum(result, "", result.length());
    //reverse(result.begin(), result.end());

    return result;
}
string sumNum(string num1, string num2, int carry, string result) {
    if (num1.empty() && num2.empty() && carry == 0) {
        if(result.empty()){
            return "0";
        }else
        {
            return result;
        }
        //return result.empty() ? "0" : result;
    }

    if (!num1.empty()) {
        carry += num1[num1.size() - 1] - '0';
        num1.erase(num1.size() - 1);
    }

    if (!num2.empty()) {
        carry += num2[num2.size() - 1] - '0';
        num2.erase(num2.size() - 1);
    }

    result = (char)(carry % 10 + '0') + result;
    carry /= 10;

    return sumNum(num1, num2, carry, result);
}

/*bool compareStrings(string num1, string num2, int i) {
    //i powinno byc 0
    if (num1[i] == '\0' || num2[i] == '\0') {
        return false;
    }
    if (num1[i] < num2[i]) {
        return true;
    } else if (num1[i] > num2[i]) {
        return false;
    } else {
        return compareStrings(num1, num2, i + 1);
    }
}

bool isNum1IsSmaller(string num1, string num2)
{
    int n1 = num1.length(),
    n2 = num2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;
    bool result = compareStrings(num1, num2, 0);
    return result;
}
string subNum(string num1, string num2, int i, int j, int carry, string result) {
    //num1-num2
    if (i < 0 && j < 0 && carry == 0) {
        string rNum="";
        result =reverseNum(result,rNum,result.length());

        return result.empty() ? "0" : result;
    }

    int sub = carry;
    if (i >= 0) {

        sub += num1[i] - '0';
        i--;
    }
    if (j >= 0) {

        sub -= num2[j] - '0';
        j--;
    }

    if (sub < 0) {
        sub += 10;
        carry = -1;
    } else {
        carry = 0;
    }

    result += (sub + '0');

    return subNum(num1, num2, i, j, carry, result);
}
*/
std::string sumTwoNum(std::string num1, std::string num2){
//do obsluzenia przypadkow
//zwróci wynik dodawania/odejmowania dwóch stringów
    std::string result="";
    std::string temp="";
    //usuwanie znaku jeżeli jest
    std::string num_one=deleteSign(num1);
    deleteZero(num_one);
    std::string num_two=deleteSign(num2);
    deleteZero(num_two);

    //dodawanie zer zeby obie ciagi mialy tyle samo znakow
    //przypadki graniczne z zerami
    if(num_one=="0" && num_two=="0") {
        return "0";
    }
    //sprawdzanie czy jest - gdzies
    int carryFirst =0;
    if(num1[0]=='-' && num2[0]=='-'){
        //dodawanie ujemnych czyli normalne dodawanie
        //trzeba bedzie dodac minus na koniec wyniku
        result="-";
        std::string temp1="";
        //int size = num_one.length() -1;

        temp =sumNum(num_one, num_two,0,temp1);

        deleteZero(result);
        result+=temp;
        return result;
    }
    else if(num1[0]=='-' || num2[0]=='-')
    {

        //odejmowanie
        if(num_one == num_two){
            return "0";
        }
        bool negative = false; //czy wynik  - czy bez
        bool notRightOrder = isNum1IsSmaller(num_one,num_two); //num1<num2
        if(notRightOrder==true){
            std::string temp = num_one;
            num_one = num_two;
            num_two = temp;
        }
        //pomocnicze dla ustalenia znaku wyniku
        // ustalenie ktora liczba ma wiecej znakow albo ktora jest wieksza w kolejnosci leksykograficznej
        if(num1[0]=='-'&& notRightOrder==true){
            //num1<num2
            negative = false;

        }
        if(num1[0]=='-'&& notRightOrder==false){
            //num1<num2
            negative = true;

        }

        if(num2[0]=='-'&& notRightOrder==true){
            //num2>num1
            negative=true;
        }

        if(num2[0]=='-'&& notRightOrder==false){
            //num1>num2
            negative=false;
        }




        //odejmowanie
        result="";
        std::string temp2="";



        temp2 =subNum(num_one,num_two);
        //return temp2;
        //std::cout<<temp;
        //std::string rnum=0;
        //result = reverseNum(temp2,rnum,temp2.length());
        deleteZero(temp2);
        result=temp2;
        if(negative==true){
            result ="-"+temp2;
        }


        return result;
    }
    else if(num1[0]!='-' && num2[0]!='-'){
        //dodawanie dwoch dodatnich

        int size = num_one.length() -1;
        temp="";

        result =sumNum(num_one, num_two, 0,temp);
        //result+=temp;
        deleteZero(result);
        return result;
    }

    return result;
}

std::string sumTab(int count, int iterator, std::string& result, const std::string* num){
    if(iterator < count){
        if(iterator==0){
            result = num[0];
            return sumTab(count,iterator+1,result, num);
        }
        else{
            std::string num2 =result;
            //std::cout<<num2;
            std::string temp = sumTwoNum(num2,num[iterator]);
            result = temp;
            iterator++;
            if(iterator<count)
                return sumTab(count,iterator,result, num);
        }
    }
    return result;
}

std::string sumTab2(int count, int iterator, std::string& result, std::string* num){
    if(iterator < count){
        if(iterator==0){
            result = num[0];
            return sumTab(count,iterator+1,result, num);
        }
        else{
            std::string num2 =result;
            //std::cout<<num2;
            std::string temp = sumTwoNum(num2,num[iterator]);
            result = temp;
            iterator++;
            if(iterator<count)
                return sumTab(count,iterator,result, num);
        }
    }
    return result;
}

std::string Sum(int count,  const std::string* num){
    std::string result="";
    std::string temp="";
    result = sumTab(count,0,temp,num);
    return result;
}
void Sum(std::string* result, int count, const std::string* num){
    *result ="";
    std::string temp="";
    *result = sumTab(count,0,temp,num);

}

void Sum(std::string& result, int count, const std::string* num){
    result ="";
    std::string temp="";
    result = sumTab(count,0,temp,num);
}

//funkcje va_list

void rekValistTab(std::string* num, va_list args, int i, int count){
    if(i<count){
        num[i]=va_arg(args,const char*);
        rekValistTab(num,args,i+1,count);
    }
}

std::string Sum(int count, ...){
    std::string result="";
    std::string temp="";
    std::string* num = new std::string[count];
    va_list args;
    va_start(args,count);

    rekValistTab(num,args,0,count);
    va_end(args);
    result = sumTab2(count,0,temp,num);
    delete[] num;
    return result;
}

void Sum(std::string* result, int count, ...){
    *result ="";
    std::string temp="";
    std::string* num = new std::string[count];
    va_list args;
    va_start(args,count);

    rekValistTab(num,args,0,count);
    va_end(args);
    *result = sumTab2(count,0,temp,num);
    delete[] num;

}

void Sum(std::string& result, int count, ...){
    result ="";
    std::string temp="";
    std::string* num = new std::string[count];
    va_list args;
    va_start(args,count);

    rekValistTab(num,args,0,count);
    va_end(args);
    result = sumTab2(count,0,temp,num);
    delete[] num;

}

