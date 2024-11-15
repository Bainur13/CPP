#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(std::string file)
{
    std::ifstream ifile(file.c_str());
    _countLine = 0;
    if (!ifile.is_open())
        throwInvalidFile();
    parseFile(ifile);
}

void BitcoinExchange::parseFile(std::ifstream &infile)
{
    std::string line;

    while (getline(infile, line))
    {
        try
        {
            parseDateValue(line);
            _countLine++;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

void BitcoinExchange::parseDateValue(std::string &line)
{
    float value;
    int pos;
    t_timedef date;

    pos = 0;
    skipSpace(line, DIGIT, pos);
    date.Y = parseInteger(line, pos);
    checkChar(line[pos], '-', pos, line);
    date.M = parseInteger(line, pos);
    checkChar(line[pos], '-', pos, line);
    date.D = parseInteger(line, pos);
    isValidDate(date);
    skipSpace(line, SYM, pos);
    skipSpace(line, DIGIT, pos);
    value = parsefloat(line, pos);
    isValidValue(value);
    checkEndl(line, pos);
    _data = std::make_pair(date, value);
}

int BitcoinExchange::parseInteger(std::string &line, int &pos)
{
    std::string numbs;
    while (isdigit(line[pos]))
    {
        numbs += line[pos];
        pos++;
    }
    try
    {
        return std::stof(numbs);
    }
    catch (const std::invalid_argument &e)
    {
        throwInvalid("Error : Not an int =>" + numbs);
    }
    catch (const std::out_of_range &e)
    {
        throwInvalid("Error : Out of range => " + numbs);
    }
    return 0;
}

float BitcoinExchange::parsefloat(std::string &line, int &pos)
{
    std::string numbs;
    while (isdigit(line[pos]) || line[pos] == '.')
    {
        numbs += line[pos];
        pos++;
    }
    try
    {
        return std::stof(numbs);
    }
    catch (const std::invalid_argument &e)
    {
        throwInvalid("Error : Not a float =>" + numbs);
    }
    catch (const std::out_of_range &e)
    {
        throwInvalid("Error : Out of range => " + numbs);
    }
    return 0.0f;
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
        throwInvalidLine(line);
    else if (type == SYM && line[pos] != '|')
        throwInvalidLine(line);
    pos++;
    return;
}

void BitcoinExchange::checkEndl(std::string &line, int &pos)
{
    while (pos != line.length())
    {
        if (!isspace(line[pos]))
            throwInvalidLine(line);
        pos++;
    }
}

void BitcoinExchange::checkChar(char c, char test, int &pos, std::string &line)
{
    if (c != test)
        throwInvalidLine(line);
    pos++;
}

void BitcoinExchange::isValidDate(t_timedef date)
{
    if (date.Y < 1900 || date.Y > 2100)
    {
        throwInvalid("Error : bad input YEAR => " + date.Y + '-' + date.M + '-' + date.D);
    }
    if (date.M < 1 || date.M > 12)
    {
        throwInvalid("Error : bad input MONTH => " + date.Y + '-' + date.M + '-' + date.D);
    }

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((date.Y % 4 == 0 && date.Y % 100 != 0) || (date.Y % 400 == 0))
    {
        daysInMonth[1] = 29;
    }
    if (date.D < 1 || date.D > daysInMonth[date.M - 1])
    {
        throwInvalid("Error : bad input DAY => " + date.Y + '-' + date.M + '-' + date.D);
    }
}

void BitcoinExchange::isValidValue(float value)
{
    if (value < 0)

}
void BitcoinExchange::throwInvalidFile()
{
    throw std::runtime_error("Error : Invalid file");
}

void BitcoinExchange::throwInvalidLine(std::string line)
{
    std::string error = "Error : bad input => " + line + "/ line nb ";
    error += _countLine;
    throw std::runtime_error(error);
}

void BitcoinExchange::throwInvalid(const std::string &message)
{
    throw std::runtime_error(message);
}