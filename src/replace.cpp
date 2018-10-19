/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 15:13:48 by jgalvani          #+#    #+#             */
/*   Updated: 2018/10/03 16:07:08 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/replace.hpp"

std::string replace(std::string buf, int begin, int len, std::string s2){
	buf.replace(begin, len, s2);
	return buf;
}

bool isSpace(char c){
	std::string whitespace = " \n\t\r";
	for (size_t i = 0; i < whitespace.length(); i++){
		if (whitespace[i] == c){
			return true;
		}
	}
	return false;
}

std::string find(std::string buf, std::string s1, std::string s2){
	std::string word;
	size_t next = 0;
	size_t i = 0;
	bool nothingFound = true;

	while (next < buf.length()){
		while (isSpace(buf[i]) == false){
			word += buf[i];
			i++;
		}
		if (word == s1){
			nothingFound = false;
			buf = replace(buf, next, s1.length(), s2);
		}
		word = "";
		i++;
		next = i;
	}
	if (nothingFound){
		std::cout << "No occurence of s1 was found in the file.\n";
		exit(-1);
	}
	return buf;
}
