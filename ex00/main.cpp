/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:14:54 by mdesrose          #+#    #+#             */
/*   Updated: 2024/02/22 14:23:57 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <fstream>
#include <iostream>
#include <regex.h>
#include <algorithm>

int regexCompare(std::string str, std::string pattern)
{
    regex_t toConvert;

    if (regcomp(&toConvert, pattern.c_str(), REG_EXTENDED) != 0)
        return (0);
    if (regexec(&toConvert, str.c_str(), 0, NULL, 0) == REG_NOMATCH)
    {
        regfree(&toConvert);
        return (0);
    }
    regfree(&toConvert);
    return (1);
}

int check_value(std::string str)
{
    size_t pos = str.find(" | ");
    if (pos != std::string::npos)
    {
        std::string valueStr = str.substr(pos + 2);
        float value = atof(valueStr.c_str());
        if (value > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            return (1);
        }    
        if (value < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            return (1);
        }
    }
    return (0);
}

void    find_value(std::map<std::string, float>& data, std::string& line)
{
    std::string                             date;
    std::string                             valuestr;
    std::map<std::string, float>::iterator  it;
    std::map<std::string, float>::iterator  previous_ite;
    size_t                                  pos = line.find(" | ");
    if (pos != std::string::npos)
    {
        date = line.substr(0, pos);
        if (date.compare(data.begin()->first.c_str()) < 0)
        {
            std::cout << "Error: bad input => " << date << std::endl;
            return;
        }
        valuestr = line.substr(pos + 2);
        float value = atof(valuestr.c_str());
        
        for (it = data.begin(); it != data.end();it++)
        {
            if (it != data.begin() && previous_ite->first.compare(date) < 0 && it->first.compare(date) > 0)
            {
                std::cout << date << " => " << value << " = " << value * previous_ite->second << std::endl;
                break;
            }    
            else if (it->first.compare(date) == 0)
            {
                std::cout << date << " => " << value << " = " << value * it->second << std::endl;
                break;
            }
            previous_ite = it;
        }
        if (it == data.end())
            std::cout << date << " => " << value << " = " << value * previous_ite->second << std::endl;
    }
}

int main(int argc, char *argv[])
{
    std::map<std::string, float>::iterator it;
    std::map<std::string, float>   data;
    std::string                     line;
    std::string                     line2;
    std::string                     key;
    std::string                     valuestr;
    std::ifstream	                infile(argv[1], std::ios::in);
    std::ifstream	                datafile("data.csv", std::ios::in);
    std::string                     pattern = "(^((([0-9][0-9])(([02468][048])|([13579][26]))-02-29)|((([0-9][0-9])([0-9][0-9])))-((((0[0-9])|(1[0-2]))-((0[0-9])|(1[0-9])|(2[0-8])))|((((0[13578])|(1[02]))-31)|(((0[1,3-9])|(1[0-2]))-(29|30))))) \\| -?(([0-9]{1,})|(([0-9]{1,})\\.([0-9]{1,})))$)";
   
    if (argc != 2){
        std::cerr << "Error: could not open file.\n";
        return (1);
    }
	if (!infile || !datafile)
	{
		std::cerr << "Can't open " << argv[1] << " or data.csv" << std::endl;
		return (1);
	}
    getline(datafile, line);
    while (getline(datafile, line))
	{
        size_t pos = line.find(",");
        key = line.substr(0, pos);
        valuestr = line.substr(pos + 1);
        float value = atof(valuestr.c_str());
        data[key] = value;
	}
    try
    {
        getline(infile, line2);
        if (line2 != "date | value")
                throw std::exception();
        while (getline(infile, line2))
	    {
            if (regexCompare(line2, pattern.c_str()))
            {
                if (check_value(line2))
                    continue;
                find_value(data, line2);
            }
            else
                std::cout << "Error: bad input => " << line2 << std::endl;
	    }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Bad Format" << '\n';
    }
    datafile.close();
    infile.close();
    return 0;
}
