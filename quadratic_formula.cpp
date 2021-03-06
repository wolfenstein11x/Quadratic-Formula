// quadratic_formula_class.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>
#include <regex>

class Quadratic {
public:
	double a;
	std::string a2_str;
	double b;
	std::string opp_b_str;
	double c;
	double radicand;
	std::string radicand_str;
	double root_1;
	std::string root_1_str;
	double root_2;
	std::string root_2_str;

	int get_a() {
		std::cout << "Enter the 'A' coefficient: ";
		std::cin >> a;
		return a;
	}

	int get_b() {
		std::cout << "Enter the 'B' coefficient: ";
		std::cin >> b;
		return b;
	}

	int get_c() {
		std::cout << "Enter the 'C' coefficient: ";
		std::cin >> c;
		return c;
	}

	double calc_radicand() {
		radicand = (b*b - (4.0*a*c));
		return radicand;
	}


	std::string calc_root_1() {
		//We use this method when the radicand > 0, and therefore no non-real roots
		root_1 = ((-1.0)*b + sqrt((b*b - (4 * a*c)))) / (2.0*a);
		if (root_1 == 0) {
			root_1_str = "0";
		}
		else {
			root_1_str = std::to_string(root_1);
		}
		
		return root_1_str;
	}

	std::string calc_root_2() {
		//We use this method when the radicand > 0, and therefore no non-real roots
		root_2 = ((-1.0)*b - sqrt((b*b - (4 * a*c)))) / (2.0*a);
		if (root_2 == 0) {
			root_2_str = "0";
		}
		else {
			root_2_str = std::to_string(root_2);
		}
		
		return root_2_str;
	}

	std::string neg_sqrt() {
		radicand = (-1.0)*radicand;
		if (sqrt(radicand) == round(sqrt(radicand))) {
			radicand = sqrt(radicand);
			radicand_str = std::to_string(radicand);
			int cut_off = 0;
			std::regex decimals("[-]{0,1}[0-9]{1,}[.]{1}[0-9]{1,}");

			for (int i = 0; i < radicand_str.size(); i++) {
				if (regex_match(radicand_str.substr(0, i), decimals)) {
					cut_off = i;
					break;
				}
			}
			radicand_str = radicand_str.substr(0, cut_off + 1) + "i";
		}
		else {
			radicand_str = std::to_string(radicand);
			int cut_off = 0;
			std::regex decimals("[-]{0,1}[0-9]{1,}[.]{1}[0-9]{1,}");

			for (int i = 0; i < radicand_str.size(); i++) {
				if (regex_match(radicand_str.substr(0, i), decimals)) {
					cut_off = i;
					break;
				}
			}
			radicand_str = "sqrt[" + radicand_str.substr(0, cut_off + 1) + "]i";
		}
		return radicand_str;
	}

	std::string get_opp_b_str() {
		opp_b_str = std::to_string(-1 * b);
		return opp_b_str;
	}

	std::string get_a2_str() {
		a2_str = std::to_string(2 * a);
		return a2_str;
	}

};

//the trimmer function is a helper function to reduce decimals places
std::string trimmer_str(std::string input) {
	int cut_off = 0;
	std::regex decimals("[-]{0,1}[0-9]{1,}[.]{1}[0-9]{1,}");

	for (int i = 0; i < input.size(); i++) {
		if (regex_match(input.substr(0, i), decimals)) {
			cut_off = i;
			break;
		}
	}
	std::string output = input.substr(0, cut_off + 1);
	return output;
}

int main()
{
	char answer;
	while (true) {
		Quadratic quad_new;
		quad_new.get_a();
		quad_new.get_b();
		quad_new.get_c();
		quad_new.calc_radicand();

		if (quad_new.calc_radicand() >= 0) {
			std::cout << std::endl;
			std::cout << "Root 1: " << trimmer_str(quad_new.calc_root_1()) << std::endl;
			std::cout << "Root 2: " << trimmer_str(quad_new.calc_root_2()) << std::endl;
		}
		else {
			quad_new.neg_sqrt();
			std::string opp_b = trimmer_str(quad_new.get_opp_b_str());
			std::string a2 = trimmer_str(quad_new.get_a2_str());
			std::cout << std::endl;
			if (quad_new.b == 0) {
				std::cout << "Root 1: " << quad_new.radicand_str << " / " << a2 << std::endl;
				std::cout << "Root 2: " << quad_new.radicand_str << " / " << a2 << std::endl;
			}

			else {
				std::cout << "Root 1: " << "(" << opp_b << " + " << quad_new.radicand_str << ")/(" << a2 << ")" << std::endl;
				std::cout << "Root 2: " << "(" << opp_b << " - " << quad_new.radicand_str << ")/(" << a2 << ")" << std::endl;
			}
		}

		std::cout << std::endl;
		std::cout << "Want to do another one? [Y/N]" << std::endl;
		std::cin >> answer;
		if (toupper(answer) == 'N') {
			std::cout << std::endl;
			std::cout << "Have a nice day." << std::endl;
			std::cout << std::endl;
			break;
		}
		else {
			std::cout << std::endl;
			std::cout << "Ok, let's do another one." << std::endl;
			std::cout << std::endl;
		}
	}

	return 0;
}

