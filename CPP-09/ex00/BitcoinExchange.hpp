#ifndef BITCOIN_EXCHANGE
#define BITCOIN_EXCHANGE

#include <iostream>
#include <map>
#include <string>
#include <fstream>

#define DIGIT 1
#define SYM 2

typedef struct s_timedef
{
    int Y;
    int M;
    int D;
} t_timedef;

class BitcoinExchange
{
public:
    BitcoinExchange(std::string file);
    BitcoinExchange(BitcoinExchange const &to_cpy);

    BitcoinExchange &operator=(BitcoinExchange const &to_cpy);

    ~BitcoinExchange();

private:
    BitcoinExchange();

    std::pair<t_timedef, float> _data;
    int _countLine;
    
    void parseFile(std::ifstream &infile);
    void parseDateValue(std::string &line);
    float parsefloat(std::string &line, int &pos);
    int parseInteger(std::string &line, int &pos);

    void skipSpace(std::string &line, int type, int &pos);
    void checkChar(char c, char test, int &pos, std::string &line);
    void checkEndl(std::string &line, int &pos);
    
    void isValidDate(t_timedef date);
    void isValidValue(float value);

    void throwInvalidFile();
    void throwInvalidLine(std::string line);
    void throwInvalid(const std::string &message);
};
#endif