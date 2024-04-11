#include <iostream>
#include <fstream>
#include <string>

void replaceSubstring(std::string& str, const std::string& replaceStr, const std::string& newStr) {
	if (replaceStr.empty()) {
		std::cout << "HERE" << std::endl;
		return;
	}

	size_t pos = str.find(replaceStr);

	while (pos != std::string::npos) {
		str.erase(pos, replaceStr.length());
		str.insert(pos, newStr);
		pos += newStr.length();
		pos = str.find(replaceStr, pos);
	}
}


int	replace(std::string& rep, std::ifstream& fd, char **argv) {
	std::ofstream	outf(rep.c_str());
	if (!outf) {
		std::cerr << "Failed to create " + rep +" file." << std::endl;
		return 	(1);
	}
	std::string line = "";
	while (std::getline(fd, line)) {
		replaceSubstring(line, argv[2], argv[3]);
		outf << line;
		outf << std::endl;
	}
	outf.close();
	return (0);
}

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Invalid number of arguments." << std::endl;
		return (1);
	}
	std::ifstream	fd(argv[1]);
	if (!fd) {
		std::cerr << "Failed to read from the file." << std::endl;
		return 1;
	}
	std::string rep(argv[1]);
	rep.append(".replace");
	if (replace(rep, fd, argv) != 0) {
		fd.close();
		return 1;
	}
	fd.close();
	return (0);
}
