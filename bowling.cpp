/* Adharsh Babu */

#include <iostream>
#include <string>

int parse(char s)
{
	return (s == 'X') ? 10 : (s == '-') ? 0 : s - '0';
}

int bowling(const std::string& s)
{
	/* i is an index that iterates through each characer of the string */
	/* c is a counter that makes sure only ten frames are run */

	int sum = 0;

	for(int i = 0, c = 1; i < s.size() && c <= 10; c++)
		if (s[i] == 'X')
		{
			if (s[i + 2] == '/')
				sum += 10 + 10;
			else
				sum += 10 + parse(s[i + 1]) + parse(s[i + 2]);

			i++;
		} else {
			if (s[i + 1] == '/')
				sum += 10 + parse(s[i + 2]);
			else 
				sum += parse(s[i]) + parse(s[i + 1]);

			i += 2;
	}

	return sum;
}

int main()
{
	/* Test Cases */

	std::cout << (bowling("XXXXXXXXXXXX") == 300) << std::endl;
	std::cout << (bowling("9-9-9-9-9-9-9-9-9-9-") == 90) << std::endl;
	std::cout << (bowling("5/5/5/5/5/5/5/5/5/5/5") == 150) << std::endl;
	std::cout << (bowling("X7/9-X-88/-6XXX81") == 167) << std::endl;
				 
	std::cout << (bowling("34") == 7) << std::endl;
	std::cout << (bowling("8/7/34X2/XX8-X8/9") == 170) << std::endl;
	std::cout << (bowling("523550419/5171X52XX2") == 100) << std::endl;
	std::cout << (bowling("--------------------jdsaf29384") == 0) << std::endl;
	std::cout << (bowling("------------------XX9jdsaf29384") == 29) << std::endl;
	std::cout << (bowling("------------------XXXjdsaf29384") == 30) << std::endl;
	std::cout << (bowling("------------------1/Xjdsaf29384") == 20) << std::endl;
}