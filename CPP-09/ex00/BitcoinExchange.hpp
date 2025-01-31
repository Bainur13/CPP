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

    bool operator<(const s_timedef& comp) const
    {
        if (this->Y  < comp.Y)
            return (1);
        if (this->Y == comp.Y && this->M < comp.M)
            return (1);
        if (this->Y == comp.Y && this->M == comp.M && this->D < comp.D)
            return (1);
        return 0;
    }
    bool operator>(const s_timedef &comp) const
    {
        if (this->Y  > comp.Y)
            return (1);
        if (this->Y == comp.Y && this->M > comp.M)
            return (1);
        if (this->Y == comp.Y && this->M == comp.M && this->D > comp.D)
            return (1);
        return 0;
    }
    bool operator<=(const s_timedef &comp) const
    {
        if (this->Y  <= comp.Y)
            return (1);
        if (this->Y == comp.Y && this->M <= comp.M)
            return (1);
        if (this->Y == comp.Y && this->M == comp.M && this->D <= comp.D)
            return (1);
        return 0;
    }
    bool operator>=(const s_timedef &comp) const
    {
        if (this->Y  >= comp.Y)
            return (1);
        if (this->Y == comp.Y && this->M >= comp.M)
            return (1);
        if (this->Y == comp.Y && this->M == comp.M && this->D >= comp.D)
            return (1);
        return 0;
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
