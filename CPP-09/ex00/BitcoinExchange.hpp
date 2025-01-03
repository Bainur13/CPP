#ifndef BITCOIN_EXCHANGE
#define BITCOIN_EXCHANGE

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <limits.h>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <sstream>

#define DIGIT 1
#define SYM 2

typedef struct s_timedef
{
    int Y;
    int M;
    int D;

    bool operator<(const s_timedef &rhs) const
    {
        if (Y < rhs.Y)
            return true;
        if (Y > rhs.Y)
            return false;
        if (M < rhs.M)
            return true;
        if (M > rhs.M)
            return false;
        if (D < rhs.D)
            return true;
        return false;
    }

    bool operator==(const s_timedef &rhs) const
    {
        return Y == rhs.Y && M == rhs.M && D == rhs.D;
    }

    bool operator!=(const s_timedef &rhs) const
    {
        return !(rhs == *this);
    }

    bool operator>(const s_timedef &rhs) const
    {
        if (rhs == *this)
            return false;
        return !(*this < rhs);
    }

    bool operator<=(const s_timedef &rhs) const
    {
        if (rhs == *this)
            return true;
        return *this < rhs;
    }

    bool operator>=(const s_timedef &rhs) const
    {
        if (rhs == *this)
            return true;
        return *this > rhs;
    }
} t_timedef;

template <typename T>
std::string to_string(T value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

class BitcoinExchange
{
public:
    BitcoinExchange(std::string file, std::map<t_timedef, double> data);
    BitcoinExchange(BitcoinExchange const &to_cpy);

    BitcoinExchange &operator=(BitcoinExchange const &to_cpy);

    std::pair<t_timedef, float> getData();
    void skipSpace(std::string &line, int type, int &pos);
    ~BitcoinExchange();

private:
    BitcoinExchange();

    std::pair<t_timedef, float> _data;
    int _countLine;

    double compare(std::map<t_timedef, double> data);

    void parseFile(std::ifstream &infile, std::map<t_timedef, double> data);
    void parseDateValue(std::string &line);
    float parsefloat(std::string &line, int &pos);
    int parseInteger(std::string &line, int &pos);

    void checkChar(char c, char test, int &pos, std::string &line);
    void checkEndl(std::string &line, int &pos);

    void isValidDate(t_timedef date);
    void isValidValue(float value);

    void throwInvalidFile();
    void throwInvalidLine(std::string line);
    void throwInvalid(const std::string &message);
};

std::ostream &operator<<(std::ostream &o, BitcoinExchange &data);
#endif
