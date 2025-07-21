#include <iostream>
#include <vector>

int comparisons = 0; // Count comparisons for analysis

void splitIntoPairs(std::vector<int>& mainContainer, std::vector< std::vector<int> >& mirrors) {
	if (mainContainer.size() <= 1) {
		std::cout << "Before return: " << mainContainer.back() << std::endl;
		return; // Stop when only one element is left
	}

	std::vector<int>	newMirror;
	std::vector<int>	newMain;
	std::vector<int>	indexes;


	// OVDE LOOPUJEM KROZ GLAVNI(CANONICAL) KONTEJNER I PRAVIM NOVI KONTEJNER NEWMIRROR KOJI CE DA IMA MANJE ELEMENTE
	// ALI TO ZNACI DA SAMO GLAVNI KONTEJNER CEPAM, ALI TREBA DA ODRADIM NA SVIM KONTEJNERIMA KOJI SU U MIRROS VECTORU ISTO STO SAM ODRADIO I NA OVOM CANONICAL
	// STO ZNACI ZAPAMTI INDEXE KOJE SAM POMERAO U NEWMIRROR, ZNACI ONE KOJI IDU DOLE I ONDA TE INDEXE POMERIM U SVIM OSTALIM KONTEJNERIMA U MIRRORS VECTORU.
	// ZNACI POSLE FOR LOOP-A OD GLAVNOG KONTEJNERA TREBA DA LOOP-UJEM KROZ MIRRORS VECTOR I DA PRAVIMO NOVE MIRRORS KOJE TREBA DA PUSH-UJEM U MIRRORS.
	// TO JE TO DO ZA SAD
	for (size_t i = 0; i + 1 < mainContainer.size(); i += 2) {
		++comparisons;
		if (mainContainer[i] > mainContainer[i + 1]) {
			newMain.push_back(mainContainer[i]);
			newMirror.push_back(mainContainer[i + 1]);
			indexes.push_back(i + 1);
		} else {
			newMain.push_back(mainContainer[i + 1]);
			newMirror.push_back(mainContainer[i]);
			indexes.push_back(i);
		}
	}


	// OVDE TREBA DA NAPRAVIM FOR LOOP ZA MIRRORS KONTEJNER DA PRODJE KROZ SVE VECTORE U MIRRORS VECTORU I DA INDEXE KOJI SU U CANONICAL POMERENI DOLE I TO ODRADI OVDE, ALI
	// BEZ IKAKVIH POREDJENJA. STO ZNACI DUPLIRANJE VECTORA U MIRRORS KONTEJNERU.
	size_t	og_size = mirrors.size();
	std::vector<int>	temp;
	if (!mirrors.empty())
		temp = mirrors[0];
	for (size_t i = 0; i < og_size; i++) {
		std::vector<int>	biggerMirror;
		std::vector<int>	smallerMirror;

		std::cout << "\nCURRENT MIRROR: ";
		for (size_t k = 0; k < mirrors[0].size(); k++)
			std::cout << mirrors[0][k] << ", ";
		std::cout << std::endl;

		for (size_t j = 0; j < indexes.size(); j++) {
			int	index = indexes[j];
			smallerMirror.push_back(mirrors[0][index]);
			if (index % 2 == 0)
				biggerMirror.push_back(mirrors[0][index + 1]);
			else
				biggerMirror.push_back(mirrors[0][index - 1]);
		}
		std::cout << "\nSMALLER MIRROR: ";
		for (size_t i = 0; i < smallerMirror.size(); i++)
			std::cout << smallerMirror[i] << ", ";
		std::cout << std::endl;
		std::cout << "\nBIGGER MIRROR: ";
		for (size_t i = 0; i < biggerMirror.size(); i++)
			std::cout << biggerMirror[i] << ", ";
		std::cout << std::endl;
		mirrors.push_back(smallerMirror);
		mirrors.push_back(biggerMirror);
		mirrors.erase(mirrors.begin());
	}

	if (!mirrors.empty() && temp.size() % 2 != 0)
		mirrors[0].push_back(temp.back());


	// OVDE TREBA DA NAPRAVIM LOOP KOJI CE DA UBACI STRAY ELEMENT U ZADNJI VECTOR U MIRRORS.
	if (mainContainer.size() % 2 == 1) {
		newMirror.push_back(mainContainer.back());
		//mirrors[0].push_back(mainContainer.back());
	}

	// Replace mainContainer with the winners (larger values)
	mainContainer = newMain;

	// Store the losers in a new mirror container
	mirrors.push_back(newMirror);

	std::cout << "\nMirrors inside: " << std::endl;
	for (size_t i = 0; i < mirrors.size(); i++) {
		std::cout << "(";
		for (size_t j = 0; j < mirrors[i].size(); j++)
			std::cout << mirrors[i][j] << ",";
		std::cout << ")" << std::endl;
	}
	std::cout << std::endl;

	// Recursive call on the mainContainer
	splitIntoPairs(mainContainer, mirrors);
}

int main() {
	std::vector<int> input;
	input.push_back(3);
	input.push_back(1);
	input.push_back(2);
	input.push_back(5);
	input.push_back(4);
	input.push_back(7);
	input.push_back(9);
	input.push_back(8);
	input.push_back(6);

	std::vector< std::vector<int> > mirrors;

	splitIntoPairs(input, mirrors);

	std::cout << "Final main container (should be one element, the max): ";
	for (size_t i = 0; i < input.size(); ++i)
		std::cout << input[i] << " ";
	std::cout << "\n";

	std::cout << "Mirror containers:\n";
	for (size_t i = 0; i < mirrors.size(); ++i) {
		std::cout << "Mirror " << i << ": ";
		for (size_t j = 0; j < mirrors[i].size(); ++j)
			std::cout << mirrors[i][j] << " ";
		std::cout << "\n";
	}

	std::cout << "Total comparisons: " << comparisons << std::endl;

	return 0;
}
