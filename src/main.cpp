/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 23:04:30 by jgalvani          #+#    #+#             */
/*   Updated: 2018/10/03 16:10:57 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/replace.hpp"

std::string input(std::string prompt){
	std::string entry;
	std::cout << prompt;
	std::getline(std::cin, entry);
	return entry;
}

bool wrongFile(std::ifstream *file, std::string fileName){
	if (*file){
		return true;
	}
	std::cerr << "Can't open file: " << fileName << ".\n";
	return false;
}

std::string * getArguments(int ac, char **av){
	std::string * tab = new std::string[3];
	if (ac !=  4){
		tab[0] = input("write a file path: ");
		tab[1] = input("Word to replace: ");
		tab[2] = input("replacing word: ");
	} else {
		for (int i = 1; i < 4; i++){
			tab[i - 1] = av[i];
		}
	}
	return tab;
}

int main(int ac, char **av){
	std::string line;
	std::string buf;
	std::string * tab = getArguments(ac, av);
	std::ifstream file(tab[FILENAME]);
	if (wrongFile(&file, tab[FILENAME]) == false){
		return -1;
	}

	while (getline(file, line)){
		buf += line + '\n';
	}
	file.close();
	buf = find(buf, tab[S1], tab[S2]);

	std::ofstream newFile(tab[FILENAME] + ".replace");
	newFile << buf;
	newFile.close();
	std::cout << tab[FILENAME] << ".replace was created !\n";
	delete [] tab;
	return 0;
}
