/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 20:09:40 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/11 20:09:42 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int ac, char **av)
{
	std::string s1;
	std::string s2;
	std::string fileName;
	std::string str;

	if (ac == 4)
	{
		fileName = av[1];
		s1 = av[2];
		s2 = av[3];

		std::ifstream inFile(fileName);
		std::ofstream outFile(fileName + ".replace");
		if (inFile.fail() || outFile.fail()) {
			std::cout << "Something bad with file." << std::endl;
			return (0);
		}
		while (std::getline(inFile, str))
		{
			while (str.find(s1) != std::string::npos)
				str.replace(str.find(s1), s1.length(), s2);
			outFile << str << std::endl;
		}
		if (str == "")
			outFile << std::endl;
		inFile.close();
		outFile.close();
	}
	else
		std::cout << "Usage: file <str_to_replace> <str_which_replace>" << std::endl;
	return (0);
}
