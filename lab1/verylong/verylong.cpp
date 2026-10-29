// verylong.cpp
#include "verylong.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

verylong::verylong(const char *str)
{
    number = str;
    if (number[0] == '-')
    {
        sign = '-';
        number.erase(0, 1);
    }
    else
        sign = '+';
    reverse(number.begin(), number.end());
}

ostream &operator<<(ostream &os, const verylong &vl)
{
    if (vl.sign == '-' && vl.number != "0")
        os << vl.sign;
    for (int i = (int)vl.number.size() - 1; i >= 0; i--)
        os << vl.number[i];
    os << endl;
    return os;
}

istream &operator>>(istream &is, verylong &vl)
{
    is >> vl.number;
    if (!vl.number.empty())
    {
        if (vl.number[0] == '-')
        {
            vl.sign = '-';
            vl.number.erase(0, 1);
        }
        else
            vl.sign = '+';
        reverse(vl.number.begin(), vl.number.end());
    }
    return is;
}

verylong::operator int() const
{
    int d = 0;
    int r = 1;
    for (int i = 0; i < (int)number.size(); i++)
    {
        d += (number[i] - '0') * r;
        r *= 10;
    }
    if (sign == '-')
        return -d;
    return d;
}

verylong operator+(const verylong &vl1, const verylong &vl2)
{
    verylong res;
    if (vl1.sign == '-' && vl2.sign == '-')
        res.sign = '-';
    else if (vl1.sign == '+' && vl2.sign == '-')
    {
        vl2.sign = '+';
        res = vl1 - vl2;
        vl2.sign = '-';
        return res;
    }
    else if (vl1.sign == '-' && vl2.sign == '+')
    {
        vl1.sign = '+';
        res = vl2 - vl1;
        vl1.sign = '-';
        return res;
    }
    else
        res.sign = '+';
    int size1 = (int)vl1.number.size();
    int size2 = (int)vl2.number.size();
    int unit, r = 0, i;
    if (size1 < size2)
    {
        for (i = 0; i < size1; i++)
        {
            unit = (vl1.number[i] - '0') + (vl2.number[i] - '0') + r;
            res.number.push_back(unit % 10 + '0');
            r = unit / 10;
        }
        for (i = size1; i < size2; i++)
        {
            unit = (vl2.number[i] - '0') + r;
            res.number.push_back(unit % 10 + '0');
            r = unit / 10;
        }
    }
    else
    {
        for (i = 0; i < size2; i++)
        {
            unit = (vl1.number[i] - '0') + (vl2.number[i] - '0') + r;
            res.number.push_back(unit % 10 + '0');
            r = unit / 10;
        }
        for (i = size2; i < size1; i++)
        {
            unit = (vl1.number[i] - '0') + r;
            res.number.push_back(unit % 10 + '0');
            r = unit / 10;
        }
    }
    if (r > 0)
        res.number.push_back(r + '0');
    return res;
}

verylong &verylong::operator+=(const verylong &vl)
{
    *this = *this + vl;
    return *this;
}

verylong operator+(verylong vl1, int d)
{
    verylong vl2;
    int other = abs(d);
    if (other == 0)
        vl2.number = "0";
    while (other > 0)
    {
        vl2.number.push_back(other % 10 + '0');
        other /= 10;
    }
    vl2.sign = (d < 0) ? '-' : '+';
    return vl1 += vl2;
}

verylong &verylong::operator+=(int d)
{
    *this = *this + d;
    return *this;
}

verylong operator-(const verylong &vl1, const verylong &vl2)
{
    verylong res;
    if (vl1.sign == '-' && vl2.sign == '-')
    {
        vl1.sign = '+';
        vl2.sign = '+';
        res = vl2 - vl1;
        vl1.sign = '-';
        vl2.sign = '-';
        return res;
    }
    else if (vl1.sign == '+' && vl2.sign == '-')
    {
        vl2.sign = '+';
        res = vl1 + vl2;
        vl2.sign = '-';
        return res;
    }
    else if (vl1.sign == '-' && vl2.sign == '+')
    {
        vl2.sign = '-';
        res = vl1 + vl2;
        vl2.sign = '+';
        return res;
    }
    int size1 = (int)vl1.number.size();
    int size2 = (int)vl2.number.size();
    int unit, r = 0, i;
    if (size1 < size2)
    {
        for (i = 0; i < size1; i++)
        {
            unit = (vl1.number[i] - '0') - (vl2.number[i] - '0') + r + 10;
            res.number.push_back(unit % 10 + '0');
            r = unit / 10 - 1;
        }
        for (i = size1; i < size2; i++)
        {
            unit = 0 - (vl2.number[i] - '0') + r + 10;
            res.number.push_back(unit % 10 + '0');
            r = unit / 10 - 1;
        }
        res.sign = '-';
        if (r < 0)
        {
            r = 0;
            for (i = 0; i < (int)res.number.size(); i++)
            {
                unit = 0 - (res.number[i] - '0') + r + 10;
                res.number[i] = unit % 10 + '0';
                r = unit / 10 - 1;
            }
        }
    }
    else
    {
        for (i = 0; i < size2; i++)
        {
            unit = (vl1.number[i] - '0') - (vl2.number[i] - '0') + r + 10;
            res.number.push_back(unit % 10 + '0');
            r = unit / 10 - 1;
        }
        for (i = size2; i < size1; i++)
        {
            unit = (vl1.number[i] - '0') + r + 10;
            res.number.push_back(unit % 10 + '0');
            r = unit / 10 - 1;
        }
        if (r < 0)
        {
            r = 0;
            for (i = 0; i < (int)res.number.size(); i++)
            {
                unit = 0 - (res.number[i] - '0') + r + 10;
                res.number[i] = unit % 10 + '0';
                r = unit / 10 - 1;
            }
            res.sign = '-';
        }
        else
            res.sign = '+';
    }
    for (i = (int)res.number.size() - 1; res.number[i] == '0' && i > 0; i--)
        res.number.pop_back();
    return res;
}

verylong &verylong::operator-=(const verylong &vl)
{
    *this = *this - vl;
    return *this;
}

verylong operator-(verylong vl1, int d)
{
    verylong vl2;
    int other = abs(d);
    if (other == 0)
        vl2.number = "0";
    while (other > 0)
    {
        vl2.number.push_back(other % 10 + '0');
        other /= 10;
    }
    vl2.sign = (d < 0) ? '-' : '+';
    return vl1 -= vl2;
}

verylong &verylong::operator-=(int d)
{
    *this = *this - d;
    return *this;
}

verylong &verylong::operator++()
{
    return *this += (verylong) "1";
}

verylong verylong::operator++(int)
{
    verylong res = *this;
    *this += (verylong) "1";
    return res;
}

verylong &verylong::operator--()
{
    return *this -= (verylong) "1";
}

verylong verylong::operator--(int)
{
    verylong res = *this;
    *this -= (verylong) "1";
    return res;
}

verylong operator*(const verylong &vl1, const verylong &vl2)
{
    verylong res;
    if (vl1.sign == '-' && vl2.sign == '-')
        res.sign = '+';
    else if (vl1.sign == '+' && vl2.sign == '-')
        res.sign = '-';
    else if (vl1.sign == '-' && vl2.sign == '+')
        res.sign = '-';
    else
        res.sign = '+';
    if (vl1.number == "0" || vl2.number == "0")
    {
        res.number = "0";
        return res;
    }
    if (vl1.number == "1")
    {
        res.number = vl2.number;
        return res;
    }
    else if (vl2.number == "1")
    {
        res.number = vl1.number;
        return res;
    }
    int size1 = (int)vl1.number.size();
    int size2 = (int)vl2.number.size();
    int unit, r, i, j;
    string buff;
    for (i = 0; i < size2; i++)
    {
        buff = "";
        r = 0;
        for (j = 0; j < size1; j++)
        {
            unit = (vl1.number[j] - '0') * (vl2.number[i] - '0') + r;
            buff.push_back(unit % 10 + '0');
            r = unit / 10;
        }
        if (r > 0)
            buff.push_back(r + '0');
        if (res.number.empty())
            res.number = buff;
        else
        {
            r = 0;
            for (j = 0; i + j < (int)res.number.size(); j++)
            {
                unit = (res.number[i + j] - '0') + (buff[j] - '0') + r;
                res.number[i + j] = unit % 10 + '0';
                r = unit / 10;
            }
            for (j = (int)res.number.size() - i; j < (int)buff.size(); j++)
            {
                unit = (buff[j] - '0') + r;
                res.number.push_back(unit % 10 + '0');
                r = unit / 10;
            }
            if (r > 0)
                res.number.push_back(r + '0');
        }
    }
    return res;
}

verylong &verylong::operator*=(const verylong &vl)
{
    *this = *this * vl;
    return *this;
}

verylong operator*(verylong vl1, int d)
{
    verylong vl2;
    int other = abs(d);
    if (other == 0)
        vl2.number = "0";
    while (other > 0)
    {
        vl2.number.push_back(other % 10 + '0');
        other /= 10;
    }
    vl2.sign = (d < 0) ? '-' : '+';
    return vl1 *= vl2;
}

verylong &verylong::operator*=(int d)
{
    *this = *this * d;
    return *this;
}

verylong operator/(const verylong &vl1, const verylong &vl2)
{
    verylong res;
    if (vl1.sign == '-' && vl2.sign == '-')
        res.sign = '+';
    else if (vl1.sign == '-' && vl2.sign == '+')
        res.sign = '-';
    else if (vl1.sign == '+' && vl2.sign == '-')
        res.sign = '-';
    else
        res.sign = '+';
    if (vl2.number == "0")
    {
        cerr << "Ошибка! Попытка деления на ноль!" << endl;
        exit(1);
    }
    if (vl1.number == "0")
    {
        res.number = "0";
        return res;
    }
    else if (vl1.number == "1")
    {
        res.number = vl2.number;
        return res;
    }
    else if (vl2.number == "1")
    {
        res.number = vl1.number;
        return res;
    }
    int size1 = (int)vl1.number.size();
    int size2 = (int)vl2.number.size();
    if (size1 < size2)
    {
        res.number = "0";
        return res;
    }
    int unit, r, i = size1 - 1, j, d;
    string buff = "";
    bool isless;
    for (j = 0; j < size2 - 1; j++)
    {
        buff.push_back(vl1.number[i]);
        i--;
    }
    while (i >= 0)
    {
        buff.push_back(vl1.number[i]);
        i--;
        d = 0;
        reverse(buff.begin(), buff.end());
        while (true)
        {
            if ((int)buff.size() < size2)
                break;
            isless = false;
            if ((int)buff.size() == size2)
            {
                for (j = size2 - 1; j >= 0; j--)
                {
                    if (buff[j] != vl2.number[j])
                    {
                        if ((buff[j] - '0') < (vl2.number[j] - '0'))
                            isless = true;
                        break;
                    }
                }
            }
            if (isless)
                break;
            r = 0;
            for (j = 0; j < size2; j++)
            {
                unit = (buff[j] - '0') - (vl2.number[j] - '0') + r + 10;
                buff[j] = unit % 10 + '0';
                r = unit / 10 - 1;
            }
            if ((int)buff.size() > size2)
            {
                unit = (buff[j] - '0') - 0 + r + 10;
                buff[j] = unit % 10 + '0';
            }
            for (j = (int)buff.size() - 1; buff[j] == '0' && j >= 0; j--)
                buff.pop_back();
            d++;
        }
        res.number.push_back(d + '0');
        reverse(buff.begin(), buff.end());
    }
    reverse(res.number.begin(), res.number.end());
    for (j = (int)res.number.size() - 1; res.number[j] == '0' && j > 0; j--)
        res.number.pop_back();
    return res;
}

verylong &verylong::operator/=(const verylong &vl)
{
    *this = *this / vl;
    return *this;
}

verylong operator/(verylong vl1, int d)
{
    verylong vl2;
    int other = abs(d);
    if (other == 0)
        vl2.number = "0";
    while (other > 0)
    {
        vl2.number.push_back(other % 10 + '0');
        other /= 10;
    }
    vl2.sign = (d < 0) ? '-' : '+';
    return vl1 /= vl2;
}

verylong verylong::operator/=(int d)
{
    *this = *this / d;
    return *this;
}

bool verylong::operator>(const verylong &vl) const
{
    int size1 = (int)number.size();
    int size2 = (int)vl.number.size();
    if (sign == '-' && vl.sign != '-')
        return false;
    else if (sign != '-' && vl.sign == '-')
        return true;
    else if (sign == '+' && size1 > size2)
        return true;
    else if (sign == '+' && size1 < size2)
        return false;
    else if (sign == '-' && size1 < size2)
        return true;
    else if (sign == '-' && size1 > size2)
        return false;

    for (int i = size1 - 1; i >= 0; i--)
    {
        if (number[i] != vl.number[i])
        {
            if (sign == '+')
                return number[i] > vl.number[i];
            else
                return number[i] < vl.number[i];
        }
    }
    return false;
}

bool verylong::operator<(const verylong &vl) const
{
    int size1 = (int)number.size();
    int size2 = (int)vl.number.size();
    if (sign == '-' && vl.sign != '-')
        return true;
    else if (sign != '-' && vl.sign == '-')
        return false;
    else if (sign == '+' && size1 < size2)
        return true;
    else if (sign == '+' && size1 > size2)
        return false;
    else if (sign == '-' && size1 > size2)
        return true;
    else if (sign == '-' && size1 < size2)
        return false;
    for (int i = size1 - 1; i >= 0; i--)
    {
        if (number[i] != vl.number[i])
        {
            if (sign == '+')
                return number[i] < vl.number[i];
            else
                return number[i] > vl.number[i];
        }
    }
    return false;
}

bool verylong::operator>=(const verylong &vl) const
{
    return !(*this < vl);
}

bool verylong::operator<=(const verylong &vl) const
{
    return !(*this > vl);
}

bool operator>(const verylong &vl1, int d)
{
    verylong vl2;
    int other = abs(d);
    if (other == 0)
        vl2.number = "0";
    while (other > 0)
    {
        vl2.number.push_back(other % 10 + '0');
        other /= 10;
    }
    vl2.sign = (d < 0) ? '-' : '+';
    return vl1 > vl2;
}

bool operator<(const verylong &vl1, int d)
{
    verylong vl2;
    int other = abs(d);
    if (other == 0)
        vl2.number = "0";
    while (other > 0)
    {
        vl2.number.push_back(other % 10 + '0');
        other /= 10;
    }
    vl2.sign = (d < 0) ? '-' : '+';
    return vl1 < vl2;
}

bool operator>=(const verylong &vl, int d)
{
    return !(vl < d);
}

bool operator<=(const verylong &vl, int d)
{
    return !(vl > d);
}

bool verylong::operator==(const verylong &other) const
{
    return (sign == other.sign && number.compare(other.number.c_str()) == 0);
}

bool verylong::operator!=(const verylong &other) const
{
    return (sign != other.sign || (number.compare(other.number.c_str()) != 0));
}

bool operator==(const verylong &vl, int d)
{
    return (static_cast<int>(vl) == d);
}

bool operator!=(const verylong &vl, int d)
{
    return (static_cast<int>(vl) != d);
}
