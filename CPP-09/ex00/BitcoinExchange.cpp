#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string file, std::map<t_timedef,
															double>
													   data)
{
	std::ifstream ifile(file.c_str());
	_countLine = 0;
	if (!ifile.is_open())
		throwInvalidFile();
	parseFile(ifile, data);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &to_cpy)
{
	_data = to_cpy._data;
	_countLine = to_cpy._countLine;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &to_cpy)
{
	if (this != &to_cpy)
	{
		_data = to_cpy._data;
		_countLine = to_cpy._countLine;
	}
	return (*this);
}

std::pair<t_timedef, float> BitcoinExchange::getData()
{
	return (_data);
}

double BitcoinExchange::compare(std::map<t_timedef, double> data)
{
	double value;

	value = -1;
	for (std::map<t_timedef, double>::iterator it = data.begin(); it != data.end(); it++)
	{
		if (it->first.Y < _data.first.Y)
			value = it->second;
		else if (it->first.Y == _data.first.Y)
		{
			if (it->first.M < _data.first.M)
				value = it->second;
			else if (it->first.M == _data.first.M)
			{
				if (it->first.D <= _data.first.D)
					value = it->second;
				else
					break;
			}
			else
				break;
		}
		else
			break;
	}
	return value;
}

void BitcoinExchange::parseFile(std::ifstream &infile, std::map<t_timedef,
																double>
														   data)
{
	double mult;

	std::string line;
	getline(infile, line);
	if (line.empty())
		std::cerr << "Error file empty" << std::endl;
	while (getline(infile, line))
	{
		try
		{
			parseDateValue(line);
			mult = compare(data);
			if (mult == -1)
				std::cout << "BitCoin wasn't released at this time" << std::endl;
			else
				std::cout << *this << " = " << _data.second * mult << std::endl;
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
	long n;

	std::string numbs;
	if (line[pos] == '-')
	{
		numbs += '-';
		pos++;
		if (!isdigit(line[pos]))
			throwInvalidLine(line);
	}
	while (isdigit(line[pos]))
	{
		numbs += line[pos];
		pos++;
	}
	n = atol(numbs.c_str());
	if (n > INT_MAX || n < INT_MIN)
		throwInvalid("Error : Out of range => " + numbs);
	return (n);
}

float BitcoinExchange::parsefloat(std::string &line, int &pos)
{
	double f;

	std::string numbs;
	while (isdigit(line[pos]) || line[pos] == '.')
	{
		numbs += line[pos];
		pos++;
	}
	f = atof(numbs.c_str());
	if (f > FLT_MAX || f < -FLT_MAX)
		throwInvalid("Error : Out of range => " + numbs);
	return (static_cast<float>(f));
}

void BitcoinExchange::skipSpace(std::string &line, int type, int &pos)
{
	while (line[pos])
	{
		if (!isspace(line[pos]))
			break;
		pos++;
	}
	if (type == DIGIT && (isdigit(line[pos]) || line[pos] == '-'))
		return;
	else if (type == SYM && line[pos] == '|')
	{
		pos++;
		return;
	}
	throwInvalidLine(line);
	return;
}

void BitcoinExchange::checkEndl(std::string &line, int &pos)
{
	while (pos != (int)line.length())
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
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (date.Y < 1900 || date.Y > 2100)
	{
		throwInvalid("Error : bad input YEAR => " + to_string(date.Y) + '-' + to_string(date.M) + '-' + to_string(date.D));
	}
	if (date.M < 1 || date.M > 12)
	{
		throwInvalid("Error : bad input MONTH => " + to_string(date.Y) + '-' + to_string(date.M) + '-' + to_string(date.D));
	}
	if ((date.Y % 4 == 0 && date.Y % 100 != 0) || (date.Y % 400 == 0))
	{
		daysInMonth[1] = 29;
	}
	if (date.D < 1 || date.D > daysInMonth[date.M - 1])
	{
		throwInvalid("Error : bad input DAY => " + to_string(date.Y) + '-' + to_string(date.M) + '-' + to_string(date.D));
	}
}

void BitcoinExchange::isValidValue(float value)
{
	if (value < 0)
	{
		std::string error;
		error = "Error : not a strictly positive number => ";
		error += to_string(value);
		throwInvalid(error);
	}
	if (static_cast<long>(value) > 1000)
	{
		std::string error;
		error = "Error : Too large number => ";
		error += to_string(value);
		throwInvalid(error);
	}
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
std::ostream &operator<<(std::ostream &o, BitcoinExchange &data)
{
	o << data.getData().first.Y << '-';
	if (data.getData().first.M < 10)
	{
		o << '0';
	}
	o << data.getData().first.M << '-';
	if (data.getData().first.D < 10)
	{
		o << '0';
	}
	o << data.getData().first.D << " => ";
	o << data.getData().second;
	return (o);
}
