#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class BigInteger{
private:
    string number;

    string m_equalize(const string &number, int difference)
    {
        string temp = "";
        for(int i=0;i<difference;i++)
        {
            temp += "0";
        }
        if(number[0] == '-')
        {
            return "-" + temp + number.substr(1);
        }
        return temp + number;
    }

    void m_tens_complement(string &this_number)
    {
        bool first_zero = true;
        int sub_from = 10;
        for(int i=this_number.size()-1;i>=0;i--)
        {
            if(first_zero && this_number[i] == '0')
            {
                continue;
            }
            else
            {
                first_zero = false;
            }
            if(sub_from == 10)
            {
                
                char holder = 48 + sub_from - (this_number[i]-'0');
                this_number[i] = holder;
                sub_from--;
            }
            else
            {
                char holder = 48 + sub_from - (this_number[i]-'0');
                this_number[i] = holder;
            }
        }
    }

    void m_remove_head_zeroes(string &s)
    {
        int i = 0;
        if(s[i] == '-') i++;
        bool broke = false;
        while(i< s.size())
        {
            if(s[i] == '0'){
                i++;
            }
            else
            {
                broke = true;
                break;
            }
        }
        if(broke){
            if(s[0] == '-')
            {
                s = "-" + s.substr(i);
            }else
            {
                if(i!=0)
                    s = s.substr(i);
            }
        }else{
            s = "0";
        }
    }
    BigInteger m_single_mul(string num, int m)
    {
        BigInteger t;
        string temp = "";
        int carry = 0;
        for(int i=num.size()-1; i >= 0; i--)
        {
            int a = num[i] - '0';
            int mult = a*m + carry;
            char x = 48 + mult%10;
            temp += x;
            carry = mult/10;
        }
        if(carry) 
        {
            char x = 48 + carry;
            temp += x;
        }
        reverse(temp.begin(), temp.end());
        t = temp;
        return t;
    }

    string m_divide(BigInteger &a, BigInteger &curr, BigInteger &num_two,int ind){
        static string ans = "";
        if(ind > (a.number.size())){
            return ans;
        }
        
        BigInteger hold = curr;
        if(hold < num_two){
            ans += "0";
            string t = "";
            t += a.number[ind++];
            hold.number += t;
            return m_divide(a, hold, num_two, ind);
        }else{
            int i=0;
            while(num_two*(i+1) <= hold){
                i++;
            }
            ans += to_string(i);
            hold = hold - (num_two*i);
            if(ind < a.number.size());
                hold.number += a.number[ind++];
            return m_divide(a, hold, num_two, ind);
        } 
        

    }
    
public:
    BigInteger()           { number = ""; }
    
    BigInteger(string num) { number = num; }

    BigInteger(const char* pointer)
    {
        number = string(pointer);
    }
    BigInteger(long long num)
    {
        number = to_string(num);
    }
    void print()
    {
        cout << number << '\n';
    }

    bool operator == (const BigInteger &other){
        if(number.size() != other.number.size())
        {
            return false;
        }
        for(int i=0; i<number.size(); i++){
            if(number[i] != other.number[i])
            {
                return false;
            }
        }
        return true;
    }

    bool operator != (const BigInteger &other)
    {
        BigInteger a = number;
        BigInteger b = other.number;
        return !( a==b );
    }

    bool operator < (const BigInteger &other){
        int neg_degree = 0;
        if(number[0] == '-' && other.number[0] != '-')
        {
            return true;
        }
        if(number[0] != '-' && other.number[0] == '-')
        {
            return false;
        }
        
        if(number[0] == '-' && other.number[0] == '-')
        {
            if(number.size() > other.number.size())
            {
                return true;
            }
            else if(number.size() < other.number.size())
            {
                return false;
            }
            else
            {
                for(int i=1; i<number.size(); i++)
                {
                    int a = number[i]- '0';
                    int b = other.number[i] - '0';
                    if(a < b)
                    {
                        return false;
                    }
                    else if(a > b)
                    {
                        return true;
                    }
                }
                return false;
            }
        }
        else
        {
            if(number.size() < other.number.size())
            {
                return true;
            }
            else if(number.size() > other.number.size())
            {
                return false;
            }
            else
            {
                for(int i=0; i<number.size(); i++)
                {
                    int a = number[i]- '0';
                    int b = other.number[i] - '0';
                    if(a > b)
                    {
                        return false;
                    }
                    else if(a < b)
                    {
                        return true;
                    }
                }
                return false;
            }
        }
    }

    bool operator > (const BigInteger &other){
        BigInteger a = number;
        BigInteger b = other.number;
        if( a == b ) return false; 
        
        return !(a < b);
    }   

    bool operator >= (const BigInteger &other){
        BigInteger a = number;
        BigInteger b = other.number;
        if( a == b ) return true; 
        return !(a < b);
    }  

    bool operator <= (const BigInteger &other){
        BigInteger a = number;
        BigInteger b = other.number;
        if( a == b ) return true; 
        return (a < b);
    } 

    BigInteger operator - ()
    {
        BigInteger temp = number;
        if(number[0] == '-')
        {
            number = number.substr(1);
        }
        else
        {
            number = "-" + number;
        }
        temp.number = number;
        return temp;
    }

    BigInteger operator + (const BigInteger &other)
    {
        BigInteger added_number;
        string number_one = number;
        string number_two = other.number;
        int neg_degree = 0;
        int l1 = number_one.size();
        int l2 = number_two.size();
        bool one_isNeg = false, two_isNeg = false;
        if(number_one[0] == '-')
        {
            l1--;
            one_isNeg = true;
        }
        if(number_two[0] == '-')
        {
            two_isNeg = true;
            l2--;
        }
        if(l1 != l2)
        {
            if(l1 < l2)
            {
                int difference = l2-l1;
                number_one = m_equalize(number_one, difference);
            }
            else
            {
                int difference = l1-l2;
                number_two = m_equalize(number_two, difference);
            }
        }
        int mx = max(l1, l2);
        if(one_isNeg && two_isNeg)
        {
            neg_degree = 2;
            number_one = number_one.substr(1);
            number_two = number_two.substr(1);
        }
        else
        {
            if(one_isNeg)
            { 
                neg_degree = 1;
                number_one = number_one.substr(1);
                m_tens_complement(number_one);
            }
            else if(two_isNeg)
            {
                neg_degree = 1;
                number_two = number_two.substr(1);
                m_tens_complement(number_two);
            }
        }
        string ans = "";
        
        int carry = 0;
        for(int i=mx-1;i>=0;i--)
        {
            int a,b,_sum,sum;
            a = number_one[i] - '0';
            b = number_two[i] - '0';
            _sum = a+b+carry;
            sum = _sum;
            carry = 0;
            if(sum > 9)
            {
                sum = _sum%10;
                carry = _sum/10;
            }
            ans += to_string(sum);
        }
        
        if(neg_degree == 0)
        {
            if(carry) ans+= to_string(carry);
            reverse(ans.begin(), ans.end());
        }
        else if(neg_degree == 1)
        {
            if(carry)
            {
                reverse(ans.begin(), ans.end());
            }
            else
            {
                reverse(ans.begin(), ans.end());
                m_tens_complement(ans);
                ans = "-" + ans;
            }
        }
        else if(neg_degree == 2)
        {
            if(carry) ans += to_string(carry);
            reverse(ans.begin(), ans.end());
            ans = "-" + ans;
        }
        m_remove_head_zeroes(ans);
        added_number.number = ans;
        return added_number;
    }

    BigInteger operator - (const BigInteger &other)
    {
        BigInteger subtracted_number;
        BigInteger number_one = number;
        BigInteger number_two = other.number;
        if(other.number[0] == '-')
        {
            number_two.number = number_two.number.substr(1);
        }
        else
        {
            number_two.number = "-" + number_two.number;
        }
        subtracted_number = number_one + number_two;
        return subtracted_number;
    }
    
    BigInteger operator * (const BigInteger &other)
    {
        BigInteger hold;
        BigInteger carry = "0";
        string space = "";
        string num = number;
        int neg_degree = 0, one_or_zero = 0;
        if(num[0] == '-'){
            num = num.substr(1);
            neg_degree++;
        }
        if(other.number[0] == '-'){
            one_or_zero = 1;
            neg_degree++;
        }
        for(int i=other.number.size()-1; i >= one_or_zero; i--)
        {
            hold = m_single_mul(num, other.number[i] - '0');
            hold.number = hold.number + space;
            hold = hold + carry;
            carry = hold;
            space += "0";
        }
        if(neg_degree == 1){
            hold.number = "-" + hold.number;
        }
        return hold;
    }

    BigInteger operator / (const BigInteger &other)
    {   
        BigInteger num_one = number;
        BigInteger num_two = other;
        int neg_degree=0;
        if(num_one.number[0] == '-')
        {
            neg_degree++;
            num_one.number = num_one.number.substr(1);
        }
        if(num_two.number[0] == '-')
        {
            neg_degree++;
            num_two.number = num_two.number.substr(1);
        }
        BigInteger hold = "";
        string ans= "";
        if(num_one < num_two)
        {
            hold = "0";
            return hold;
        }
        string t = "";
        t += num_one.number[0];
        BigInteger curr = t;
        t = m_divide(num_one, curr, num_two, 1);
        m_remove_head_zeroes(t);
        hold = t;
        if(neg_degree == 1)
        {
            hold.number = "-" + hold.number;
        }
        return hold;
    }

    friend BigInteger operator+(long long , BigInteger& );
    friend BigInteger operator-(long long , BigInteger& );
    friend BigInteger operator*(long long , BigInteger& );
    friend BigInteger operator/(long long , BigInteger& );
    
    friend ostream & operator << (ostream &, const BigInteger &);
    friend istream & operator >> (istream &,  BigInteger &);
};

istream& operator >> (istream &in,  BigInteger &c)
{
    in >> c.number;
    return in;
}

ostream& operator << (ostream &out, const BigInteger &obj) 
{ 
    out << obj.number;
    return out; 
} 
 
BigInteger operator+(long long i, BigInteger& this_number)
{
    return this_number + i;   
}

BigInteger operator-(long long i, BigInteger& this_number)
{
    BigInteger temp = i;
    i = -i;
    return i - this_number;   
}

BigInteger operator*(long long i, BigInteger& this_number)
{
    return this_number * i;   
}

BigInteger operator/(long long i, BigInteger& this_number)
{
    BigInteger temp = i;
    return temp/this_number;   
}

int main(){
    
    /*  Validation test
    long long int x = -10, y = -5;
    BigInteger m = x;
    BigInteger n = y, c = 10001;
    BigInteger p = m/n, q = x/y;
    cout << p << '\n';
    cout << q << '\n';
    cout << (p == q) << '\n';
    */
    
    BigInteger a, b, c;
    cout << "Menu: \n1: Add two big integers.\n2: Subtract 2 big integers\n3: Multiply two big integers\n4: Divide two big integers\n5: Exit\n";
    int choice;
    while(1){
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        if(choice == 5){
            break;
        }
        cout << "Enter first number: ";
        cin >> a;
        cin.ignore();
        cout << "Enter second number: ";
        cin >> b;
        if(choice == 1){
            c = a + b;
        }
        if(choice == 2){
            c = a - b;
        }
        if(choice == 3){
            c = a * b;
        }
        if(choice == 4){
            if(b == "0"){
                cout << "Zero Division Error\n";
            }else{
                c = a / b;
            }
        }
        cout << "Ans: " << c << '\n';
    }




    return 0;
}