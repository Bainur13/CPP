#include "BitcoinExchange.hpp"


double stringToDouble(const std::string &str)
{
    std::stringstream ss(str);
    double value;
    ss >> value;
    return value;
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Invalid args, expected one" << std::endl;
		return (0);
	}

    const int initial_size = 10;
    int current_size = initial_size;

    std::map<t_timedef, double> data;
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cerr << "Error opening database." << std::endl;
        return 1;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        t_timedef tmp;
        tmp.Y = atoi(line.substr(0, 4).c_str());
        tmp.M = atoi(line.substr(5, 7).c_str());
        tmp.D = atoi(line.substr(8, 10).c_str());
        double value = stringToDouble(line.substr(11));
        data[tmp] = value;  
    }
    file.close();
	try
	{
		BitcoinExchange o(av[1], data);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}
