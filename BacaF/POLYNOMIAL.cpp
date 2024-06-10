//Magdalena Maksymiuk

struct FRACTION{
public:
    int numerator;
    int denominator;

    int custom_abs(int value) {
        return value < 0 ? -value : value;
    }

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return custom_abs(a);
    }

    void simplify() {
        int temp = gcd(numerator, denominator);
        numerator /= temp;
        denominator /= temp;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    void negative() {
        if(numerator < 0 && denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
            return;
        }

        if(numerator >= 0 && denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
            return;
        }
    }
};

class POLYNOMIAL {
public:
    int* coefficients;
    int degree;

    //FRACTION fraction;

    int custom_abs(int value) {
        return value < 0 ? -value : value;
    }

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return custom_abs(a);
    }

    void deleteZero() {
        int k = degree;
        for (int i = k; i > 0; --i) {
            if (coefficients[i] == 0) {
                --degree;
                for (int j = i; j < degree; ++j) {
                    coefficients[j] = coefficients[j + 1];
                }
            } else {
                break;
            }
        }
    }

    void simplify() {
        if (degree == 0 && coefficients[0] == 0) return;

        int common_gcd = custom_abs(coefficients[0]);
        for (int i = 1; i <= degree; ++i) {
            if (coefficients[i] != 0) {
                common_gcd = gcd(common_gcd, custom_abs(coefficients[i]));
            }
        }

        if (common_gcd > 1) {
            for (int i = 0; i <= degree; ++i) {
                coefficients[i] /= common_gcd;
            }
        }
    }
    POLYNOMIAL& operator=(const POLYNOMIAL& other) {
        if (this == &other) return *this;
        delete[] coefficients;
        degree = other.degree;
        coefficients = new int[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = other.coefficients[i];
        }
        return *this;
    }



public:
    static int overloaded;
    POLYNOMIAL() {
        this->degree = 0;
        this->coefficients = new int[0 + 1];
        this->coefficients[0] = 0;
    }
    POLYNOMIAL(int degree, ...) : degree(degree) {
        if(degree <0){
            this->degree = 0;
            this->coefficients = new int[0 + 1];
            //this->coefficients[0] = 0;
            return;
        }
        coefficients = new int[degree + 1];
        //zaincjalizowanie tablicy zerami
        for(int i = 0; i <= degree; i++){
            coefficients[i] = 0;
        }
        va_list args;
        va_start(args, degree);
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = va_arg(args, int);
        }
        va_end(args);
        simplify();
    }

    ~POLYNOMIAL() {
        delete[] coefficients;
    }

    POLYNOMIAL(const POLYNOMIAL& other) : degree(other.degree) {
        coefficients = new int[degree + 1];
        for (int i = 0; i <= degree; i++) {
            coefficients[i] = other.coefficients[i];
        }
    }



    POLYNOMIAL operator-() const {
        POLYNOMIAL result = *this;
        for (int i = 0; i <= result.degree; ++i) {
            result.coefficients[i] = -result.coefficients[i];
        }
        result.simplify(); //??
        result.deleteZero(); //??
        return result;
    }

    int max2(int degree, int degree1) const {
        return (degree > degree1) ? degree : degree1;
    }

    POLYNOMIAL operator+(const POLYNOMIAL& other) const {
        int max_degree = max2(degree, other.degree);
        POLYNOMIAL result(max_degree, 0);
        for (int i = 0; i <= max_degree; ++i) {
            int a = (i <= degree) ? coefficients[i] : 0;
            int b = (i <= other.degree) ? other.coefficients[i] : 0;
            result.coefficients[i] = a + b;
        }
        result.simplify(); //??
        result.deleteZero(); //??
        return result;
    }

    POLYNOMIAL operator-(const POLYNOMIAL& other) const {

        if(other == *this){
            return POLYNOMIAL();
        }

        if (this->degree > other.degree) {
            POLYNOMIAL result = POLYNOMIAL(*this);

            for (int i = 0; i <= other.degree; i++) {
                result.coefficients[i] = this->coefficients[i] - other.coefficients[i];
            }
            result.simplify(); //??
            result.deleteZero(); //??
            return result;
        } else {

            POLYNOMIAL result(other);
            for (int i = 0; i <= other.degree; i++) {
                result.coefficients[i] = - other.coefficients[i];
            }
            for (int i = 0; i <= this->degree; i++) {
                result.coefficients[i] = result.coefficients[i] + this->coefficients[i];
            }
            result.simplify(); //??
            result.deleteZero(); //??
            return result;
        }


    }

    POLYNOMIAL operator*(const POLYNOMIAL& other) const {

        if(other.degree == 0 && other.coefficients[0] == 0){
            POLYNOMIAL temp(*this);
            temp.degree =0;
            delete[] temp.coefficients;
            temp.coefficients = new int[1];
            temp.coefficients[0] = 0;
            return temp;
        }
        if (degree == 0 && coefficients[0] == 0){
            POLYNOMIAL temp(*this);
            temp.degree =0;
            delete[] temp.coefficients;
            temp.coefficients = new int[1];
            temp.coefficients[0] = 0;
            return temp;
        }
        int new_degree = degree + other.degree;
        POLYNOMIAL result(new_degree, 0);

        for (int i = 0; i <= new_degree; ++i) {
            result.coefficients[i] = 0;
        }


        for (int i = 0; i <= degree; ++i) {
            for (int j = 0; j <= other.degree; ++j) {
                result.coefficients[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        result.simplify();
        return result;

    }


    POLYNOMIAL operator/(const POLYNOMIAL& other) {

        if (other.degree == 0 && other.coefficients[0] == 0){
            POLYNOMIAL temp(*this);
            temp.degree =0;
            delete[] temp.coefficients;
            temp.coefficients = new int[1];
            temp.coefficients[0] = 0;
            return temp;
        }
        if (degree == 0 && coefficients[0] == 0){
            POLYNOMIAL temp(*this);
            temp.degree =0;
            delete[] temp.coefficients;
            temp.coefficients = new int[1];
            temp.coefficients[0] = 0;
            return temp;
        }
        if (this->degree < other.degree){
            POLYNOMIAL temp(*this);
            temp.degree =0;
            delete[] temp.coefficients;
            temp.coefficients = new int[1];
            temp.coefficients[0] = 0;
            return temp;
        }
        if (*this == other){
            POLYNOMIAL temp(*this);
            temp.degree =0;
            delete[] temp.coefficients;
            temp.coefficients = new int[1];
            temp.coefficients[0] = 1;
            return temp;
        }
        if (other.degree == 0 && other.coefficients[0] == -1){
            return *this * other;
        }
       if (other.degree == 0 && other.coefficients[0] == 1) {
           return *this;
       }

        int dividentSize = degree + 1;
        int divisorSize = other.degree +1;
        int quotientSize = dividentSize - divisorSize +1;
        if(quotientSize <=0){
            POLYNOMIAL temp(*this);
            //temp.degree =0;
            //delete[] temp.coefficients;
            //temp.coefficients = new int[1];
            //temp.coefficients[0] = 0;
            return temp;
        }
        //return *this;
        FRACTION *divident = new FRACTION[dividentSize];
        FRACTION *divisor = new FRACTION[divisorSize];
        FRACTION *quotient = new FRACTION[quotientSize];


        for(int i = 0; i <= degree ; i++){ //=<
            divident[i].numerator = coefficients[degree -i];
            divident[i].denominator = 1;
        }

        for(int i = 0; i <= other.degree; i++){ //=<
            divisor[i].numerator = other.coefficients[other.degree -i];
            divisor[i].denominator = 1;
        }

        for( int k =0 ; k!= quotientSize; k++){
            quotient[k].numerator = divident[k].numerator * divisor[0].denominator;
            quotient[k].denominator = divident[k].denominator * divisor[0].numerator;
            quotient[k].negative();

            FRACTION *temp_divisor = new FRACTION[divisorSize];

            for (int j = 0; j < divisorSize; j++) {
                temp_divisor[j].numerator = divisor[j].numerator * quotient[k].numerator;
                temp_divisor[j].denominator = divisor[j].denominator * quotient[k].denominator;
                temp_divisor[j].negative();
            }

            for (int j = 0; j < dividentSize; j++) {
                divident[j].numerator *= quotient[0].denominator;
                divident[j].denominator *= quotient[0].denominator;
            }

            for (int i = 0; i < divisorSize; i++) {
                divident[k + i].numerator -= temp_divisor[i].numerator;
            }

            delete[] temp_divisor;

        }

        int temp = divisor[0].numerator;
        int temp2 = divisor[0].numerator;
        if (temp2 < 0) temp2 = -temp2;
        if (temp < 0) temp = -temp;


        for (int i = quotientSize - 2; i >= 0; i--) { //??
            quotient[i].numerator *= temp;
            quotient[i].denominator *= temp;
            temp *= temp2;
        }

        int tmp1 = this->degree;
        int tmp2 = other.degree;

        POLYNOMIAL result(*this);
        result.degree = tmp1 - tmp2;
        result.coefficients = new int[tmp1 - tmp2 + 1];
        for(int x=0 ; x< result.degree; x++){
            result.coefficients[x] = 0;
        }

        for (int i = 0; i < this->degree - other.degree+1; i++) {

            result.coefficients[i] = quotient[this->degree - other.degree - i].numerator;
            //std::cout<<result.coefficients[i];
        }


        delete [] divident;
        delete [] divisor;
        delete [] quotient;

        result.simplify();
        result.deleteZero();
        return result;


    }



    POLYNOMIAL operator%(const POLYNOMIAL& other)  {

        //chyba trzeba rozpatrzyc jeszcze kilka przypadkow ??
        if (other.degree == 0 && other.coefficients[0] == 0) return POLYNOMIAL(*this);
        if (this->degree < other.degree) return POLYNOMIAL(*this);
        if (*this == other){
            POLYNOMIAL temp(*this);
            temp.degree =0;
            delete[] temp.coefficients;
            temp.coefficients = new int[1];
            temp.coefficients[0] = 0;
            return temp;
        }
        if (other.degree == 0 ){ //&& other.coefficients[0] == 0
            POLYNOMIAL temp(*this);
            temp.degree =0;
            delete[] temp.coefficients;
            temp.coefficients = new int[1];
            temp.coefficients[0] = 0;
            return temp;
        }
        if (this->degree < other.degree){
            POLYNOMIAL temp(*this);
            temp.degree =0;
            delete[] temp.coefficients;
            temp.coefficients = new int[1];
            temp.coefficients[0] = 0;
            return temp;
        }
        if (*this == other){
            POLYNOMIAL temp(*this);
            temp.degree =0;
            delete[] temp.coefficients;
            temp.coefficients = new int[1];
            temp.coefficients[0] = 1;
            return temp;
        }

        int dividentSize = degree + 1;
        int divisorSize = other.degree +1;
        int quotientSize = dividentSize - divisorSize +1;
        if(quotientSize <=0){
            POLYNOMIAL temp(*this);
            temp.degree =0;
            delete[] temp.coefficients;
            temp.coefficients = new int[1];
            temp.coefficients[0] = 0;
            return temp;
        }

        FRACTION *divident = new FRACTION[dividentSize];
        FRACTION *divisor = new FRACTION[divisorSize];
        FRACTION *quotient = new FRACTION[quotientSize];


        for(int i = 0; i <= degree; i++){
            divident[i].numerator = coefficients[degree -i];
            divident[i].denominator = 1;
        }

        for(int i = 0; i <= other.degree; i++){
            divisor[i].numerator = other.coefficients[other.degree -i];
            divisor[i].denominator = 1;
        }

        for( int k =0 ; k!= quotientSize; k++){
            quotient[k].numerator = divident[k].numerator * divisor[0].denominator;
            quotient[k].denominator = divident[k].denominator * divisor[0].numerator;
            quotient[k].negative();

            FRACTION *temp_divisor = new FRACTION[divisorSize];

            for (int j = 0; j < divisorSize; j++) {
                temp_divisor[j].numerator = divisor[j].numerator * quotient[k].numerator;
                temp_divisor[j].denominator = divisor[j].denominator * quotient[k].denominator;
                temp_divisor[j].negative();
            }

            for (int j = 0; j < dividentSize; j++) {
                divident[j].numerator *= quotient[0].denominator;
                divident[j].denominator *= quotient[0].denominator;
            }

            for (int i = 0; i < divisorSize; i++) {
                divident[k + i].numerator -= temp_divisor[i].numerator;
            }

            delete[] temp_divisor;

        }

        int temp = divisor[0].numerator;
        int temp2 = divisor[0].numerator;
        if (temp2 < 0) temp2 *= -1;
        if (temp < 0) temp *= -1;

        for (int i = quotientSize - 2; i >= 0; i--) {
            quotient[i].numerator *= temp;
            quotient[i].denominator *= temp;
            temp *= temp2;
        }


        POLYNOMIAL result(0);
        result.degree = other.degree -1;
        result.coefficients = new int[other.degree];
        for(int x=0 ; x< result.degree; x++){
            result.coefficients[x] = 0;
        }
        for(int i =0; result.degree +1 != i; i++){

            result.coefficients[i] = divident[dividentSize - 1 -i].numerator;

        }
        delete[] divident;
        delete[] divisor;
        delete[] quotient;

        result.simplify();
        result.deleteZero();

        return result;

    }




    POLYNOMIAL operator<<(int shift) const {
        if (shift < 0 || (shift > degree)){
            POLYNOMIAL temp(*this);
            temp.degree =0;
            delete[] temp.coefficients;
            temp.coefficients = new int[1];
            temp.coefficients[0] = 0;
            return temp;
        }
        if (shift == 0) return *this;

        POLYNOMIAL result(0);
        result.degree = degree - shift;
        result.coefficients = new int[result.degree +1];
        for (int i = 0; i <= result.degree; i++) {
            result.coefficients[i] = 0;
        }
        for (int i = 0; i <= result.degree; ++i) {
            result.coefficients[i] = coefficients[i+shift];

        }
        result.simplify(); //??
        result.deleteZero(); //??
        return result;
    }

    POLYNOMIAL operator>>(int shift) const {

        if (shift < 0){
            POLYNOMIAL temp(*this);
            temp.degree =0;
            delete[] temp.coefficients;
            temp.coefficients = new int[1];
            temp.coefficients[0] = 0;
            return temp;

        }

        if (shift == 0) return *this;
        POLYNOMIAL result(0);
        result.degree = degree + shift;
        result.coefficients = new int[result.degree +1];
        for (int i = 0; i <= result.degree; i++) {
            result.coefficients[i] = 0;
        }

        for (int i = shift; i <= degree + shift; i++) {

            result.coefficients[i] = coefficients[i - shift];
            //std::cout<<result.coefficients[i]<<std::endl;

        }

        result.simplify(); //??
        result.deleteZero();
        return result;
    }

    POLYNOMIAL& operator+=(const POLYNOMIAL& other) {
        int max_degree = max2(degree, other.degree);
        POLYNOMIAL result(max_degree, 0);
        for (int i = 0; i <= max_degree; ++i) {
            int a = (i <= degree) ? coefficients[i] : 0;
            int b = (i <= other.degree) ? other.coefficients[i] : 0;
            result.coefficients[i] = a + b;
        }
        result.simplify(); //??
        result.deleteZero(); //??

        *this = result;
        return *this;
    }

    POLYNOMIAL& operator-=( POLYNOMIAL& other) {
        other = -other;
        *this +=other;
        other = -other;
        return *this;
    }

    POLYNOMIAL& operator*=(const POLYNOMIAL& other) {
        *this = *this * other;
        return *this;
    }

    POLYNOMIAL& operator/=(const POLYNOMIAL& other) {
        *this = *this / other;
        return *this;
    }

    POLYNOMIAL& operator%=(const POLYNOMIAL& other) {
        *this = *this % other;
        return *this;
    }

    POLYNOMIAL& operator<<=(int shift) {
        *this = *this << shift;
        return *this;
    }

    POLYNOMIAL& operator>>=(int shift) {
        *this = *this >> shift;
        return *this;
    }

    POLYNOMIAL& operator++() {
        for (int i = 0; i <= degree; ++i) {
            ++coefficients[i];
        }
        if(this->degree == 0 && this->coefficients[0] ==0){
            return *this;
        }
        this->simplify();
        this->deleteZero();
        return *this;
    }

    POLYNOMIAL operator++(int) {
        POLYNOMIAL temp(*this);
        operator++();
        return temp;
    }

    POLYNOMIAL& operator--() {
        for (int i = 0; i <= degree; ++i) {
            --coefficients[i];
        }
        if(this->degree == 0 && this->coefficients[0] ==0){
            return *this;
        }
        this->simplify();
        this->deleteZero();
        return *this;
    }

    POLYNOMIAL operator--(int) {
        POLYNOMIAL temp(*this);
        operator--();
        return temp;
    }

    void* operator new(size_t size) {
        overloaded++;
        return ::operator new(size);
    }

    void operator delete(void* ptr) {
        overloaded--;
        ::operator delete(ptr);
    }

    friend std::ostream& operator<<(std::ostream& os, const POLYNOMIAL& poly) {
        POLYNOMIAL poly2 = poly;
        poly2.simplify();
        poly2.deleteZero();
        os << "( ";
        for (int i = 0; i <= poly2.degree; ++i) {
            os << poly2.coefficients[i];
            if (i < poly2.degree) os << ", ";
        }
        os << " )"; //mozliwe ze ze spacja na koncu i poczatku
        return os;
    }

    friend istream& operator>>(istream& is, POLYNOMIAL& poly) {

        poly.simplify();
        is >> poly.degree;
        delete[] poly.coefficients;
        poly.coefficients = new int[poly.degree + 1];
        for (int i = 0; i <= poly.degree; ++i) {
            is >> poly.coefficients[i];
        }
        poly.simplify();
        poly.deleteZero();
        return is;
    }

    friend bool operator<(const POLYNOMIAL& lhs, const POLYNOMIAL& rhs) {
        if (lhs.degree != rhs.degree) return lhs.degree < rhs.degree;
        for (int i = lhs.degree; i >= 0; --i) {
            if (lhs.coefficients[i] != rhs.coefficients[i]) {
                return lhs.coefficients[i] < rhs.coefficients[i];
            }
        }
        return false;
    }

    friend bool operator<=(const POLYNOMIAL& lhs, const POLYNOMIAL& rhs) {
        return !(rhs < lhs);
    }

    friend bool operator==(const POLYNOMIAL& lhs, const POLYNOMIAL& rhs) {
        return !(lhs < rhs) && !(rhs < lhs);
    }

    friend bool operator!=(const POLYNOMIAL& lhs, const POLYNOMIAL& rhs) {
        return !(lhs == rhs);
    }

    friend bool operator>(const POLYNOMIAL& lhs, const POLYNOMIAL& rhs) {
        return rhs < lhs;
    }

    friend bool operator>=(const POLYNOMIAL& lhs, const POLYNOMIAL& rhs) {
        return !(lhs < rhs);
    }
};

