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
    int count = 0;

    // Allocation dynamique d'un tableau de std::pair
    std::pair<t_timedef, double> *data = new std::pair<t_timedef, double>[current_size];

    // Lecture du fichier CSV
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cerr << "Error opening database." << std::endl;
        delete[] data;
        return 1;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        t_timedef tmp;
        if (count == current_size)
        {
            // Redimensionnement du tableau
            current_size *= 2;
            std::pair<t_timedef, double> *new_data = new std::pair<t_timedef, double>[current_size];
            for (int i = 0; i < count; ++i)
            {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
        }
        tmp.Y = atoi(line.substr(0, 4).c_str());
        tmp.M = atoi(line.substr(5, 7).c_str());
        tmp.D = atoi(line.substr(8, 10).c_str());
        double value = stringToDouble(line.substr(11));
        data[count] = std::make_pair(tmp, value);
        count++;        
    }

    file.close();

    // Affichage des données
    // for (int i = 0; i < count; ++i)
    // {
    //     std::cout << "Date: " << data[i].first.Y << data[i].first.M << data[i].first.D << ", Price: " << data[i].second << std::endl;
    // }
	try
	{
		BitcoinExchange o(av[1], data, count);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}
