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

private:
    BitcoinExchange();
    std::map<t_timedef, float> _data;
    void throwInvalidFile();
    void throwInvalidLine();
    void parseFile(std::ifstream &infile);
    void parseDate(std::string &line, int &pos);
    void skipSpace(std::string &line, int type, int &pos);
    void checkChar(std::string, char test);
    ~BitcoinExchange();
};
#endif