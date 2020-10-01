/*
Author: Aviral
*/

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
        while(s[i] == '0')
        {
            i++;
        }
        if(s[0] == '-')
        {
            s = "-" + s.substr(i);
        }else
        {
            s = s.substr(i);
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
        //TBC
    }

    BigInteger operator / (const BigInteger &other)
    {   
        //TBC
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
    BigInteger a = "-1111", x;
    BigInteger b = "10000", c = -1000;
    x = -b;
    cout << x << '\n';
    // x = c + a;  //BUGG
    // cin >> x;
    // cout << x << '\n';

    return 0;
}