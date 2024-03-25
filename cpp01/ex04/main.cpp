/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:12:43 by damachad          #+#    #+#             */
/*   Updated: 2024/03/21 14:33:52 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void	ft_sed(std::string filename, std::string s1, std::string s2)
{
	std::ifstream infile;
	infile.open(filename.c_str(), std::ios::in);
	if (infile.is_open())
	{
		std::ofstream outfile;
		outfile.open(filename.append(".replace").c_str(), std::ios::out);
		std::string	buff;
		while (std::getline(infile, buff))
		{
			std::size_t	found = buff.find(s1);
			while (found != std::string::npos)
			{
				buff.erase(found, s1.length());
				buff.insert(found, s2);
				found = buff.find(s1);
			}
			outfile << buff;
			outfile << std::endl;
		}
		outfile.close();
		infile.close();
	}
	else
		std::cout << "Unable to open " << filename << '.' << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string	filename = argv[1];
		std::string	s1 = argv[2];
		std::string	s2 = argv[3];
		if (filename.empty() || s1.empty())
		{
			std::cout << "filename and s1 cannot be empty" << std::endl;
			return (1);
		}
		else
			ft_sed(filename, s1, s2);
	}
	else
		std::cout << "Usage: ./sed <filename> s1 s2" << std::endl;
	return (0);
}
