#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){};

BitcoinExchange::BitcoinExchange(std::string file)
{
    std::ifstream ifile(file.c_str());
    if (!ifile.is_open())
        throwInvalidFile();
    parseFile(ifile);
    
}

void BitcoinExchange::parseFile(std::ifstream &infile)
{
    std::string line;
    int pos;

    pos = 0;
    while (getline(infile, line))
    {
        skipSpace(line, DIGIT, pos);
        _data[0] = parseDate(line, pos);
    }
}

void BitcoinExchange::skipSpace(std::string &line, int type, int &pos)
{
    while (line[pos])
    {
        if (!isspace(line[pos]))
            break;
        pos++;
    }
    if (type == DIGIT && !isdigit(line[pos]))
        throwInvalidLine();
    else if (type == SYM && line[pos] != '|')
        throwInvalidLine();
    return ;
}

void BitcoinExchange ::parseDate(std::string &line, int &pos)
{
    std::string numbs;

    while (isdigit(line[pos]))
    {
        numbs += line[pos];
        pos++;
    }
    checkChar(line[pos], '-');
    _data[]
    
}

void BitcoinExchange::checkChar(char c, char test)
{
    if (c != test)
        throwInvalidLine();
}