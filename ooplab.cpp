#include <iostream>
using namespace std;

class rational
{
private:
    float num, denom;

public:
    rational()
    {
        num = 0;
        denom = 0;
    }

    rational(float a, float b)
    {
        num = a;

        denom = b;
    }

    void show();

    friend rational operator+(rational, int);
    friend rational operator+(int, rational);

    // output operators
    friend void operator<<(ostream &, const rational);

    // assignment operators
    rational operator=(const rational &ob);
    rational operator+=(const rational &ob);
    rational operator*=(const rational &ob);
    rational operator/=(const rational &ob);
    rational operator-=(const rational &ob);

    // comparison operators
    int operator==(rational);
    int operator!=(rational);
    int operator<=(rational);
    int operator>=(rational);

    // basic operators
    rational operator+(rational);
    rational operator-(rational);
    rational operator*(rational);
    rational operator/(rational);
};

void operator<<(ostream &p, const rational t)
{
    p << t.num << "\n__\n"
      << t.denom << endl;
}
// assignment operators
rational rational::operator=(const rational &ob)
{
    this->num = ob.num;
    this->denom = ob.denom;
    return *this;
}
rational rational::operator+=(const rational &ob)
{
    if (ob.denom == denom)
    {
        this->denom = denom;
        this->num = num + ob.num;
    }
    else
    {
        this->num = (num * ob.denom) + (denom * ob.num);
        this->denom = (denom * ob.denom);
    }
    return *this;
}
rational rational::operator-=(const rational &ob)
{
    if (ob.denom == denom)
    {
        this->denom = denom;
        this->num = num - ob.num;
    }
    else
    {
        this->num = (num * ob.denom) - (denom * ob.num);
        this->denom = (denom * ob.denom);
    }
    return *this;
}
rational rational::operator*=(const rational &ob)
{
    this->num = num * ob.num;
    this->denom = denom * ob.denom;
    return *this;
}
rational rational::operator/=(const rational &ob)
{
    this->num = num * ob.denom;
    this->denom = denom * ob.num;
    return *this;
}

// comparison operators
int rational::operator==(rational ob)
{
    return ((num == ob.num) && (denom == ob.denom)) ? 1 : 0;
}
int rational::operator>=(rational ob)
{
    if (ob.denom == denom)
    {
        if (num > ob.num)
        {
            return 1;
        }
        else
            return 0;
    }
    else
    {
        if ((num * ob.denom) > (ob.num * denom))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
int rational::operator<=(rational ob)
{
    if (ob.denom == denom)
    {
        if (num < ob.num)
        {
            return 1;
        }
        else
            return 0;
    }
    else
    {
        if ((num * ob.denom) < (ob.num * denom))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
int rational::operator!=(rational ob)
{
    return ((num == ob.num) && (denom == ob.denom)) ? 0 : 1;
}

// basic operators with friend functions
rational operator+(rational ob, int a)
{
    rational result;
    result.denom = ob.denom;
    result.num = a * ob.denom + ob.num;
    return result;
}
rational operator+(int a, rational ob)
{
    rational result;
    result.denom = ob.denom;
    result.num = a * ob.denom + ob.num;
    return result;
}
// basic operators
rational rational::operator+(rational ob1)
{
    rational result;
    if (ob1.denom == denom)
    {
        result.denom = denom;
        result.num = num + ob1.num;
    }
    else
    {
        result.num = (num * ob1.denom) + (denom * ob1.num);
        result.denom = (denom * ob1.denom);
    }
    return result;
}

rational rational::operator-(rational ob1)
{
    rational result;
    if (ob1.denom == denom)
    {
        result.denom = denom;
        result.num = num - ob1.num;
    }
    else
    {
        result.num = (num * ob1.denom) - (denom * ob1.num);
        result.denom = (denom * ob1.denom);
    }
    return result;
}
rational rational::operator*(rational ob1)
{
    rational result;
    result.num = num * ob1.num;
    result.denom = denom * ob1.denom;
    return result;
}
rational rational::operator/(rational ob1)
{
    rational result;
    result.num = num * ob1.denom;
    result.denom = denom * ob1.num;
    return result;
}
void rational::show()
{
    cout << num << "\n__\n"
         << denom << endl;
}

int main()
{
    int p, q, r, s;
    cout << "Enter p and q for a rational number (p/q):";
    cin >> p >> q;
    rational a(p, q);
    cout << "Enter p and q for a rational number (p/q):";
    cin >> r >> s;
    rational b(r, s);

    cout << "Verifying friend function operator overloading:" << endl;
    rational fsum = 4 + a;
    cout << fsum;
    rational fsum2 = a + 5;
    cout << fsum2;
    cout << "Verifying increment and addition operator:\n";
    a += b;
    cout << a;

    return 0;
}