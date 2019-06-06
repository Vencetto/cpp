#include "header.hpp"

void *serialize(void) {
	char chars[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i;

	std::string numb = std::to_string(rand() % RANDOM);
	char *data = new char[numb.length() + 16];

	for (i = 0; i < 8; i++)
		data[i] = chars[rand() % 62];
	for (int k = 0; k < (int)numb.length(); k++, i++)
		data[i] = numb[k];
	for (int k = 0; k < 8; i++, k++)
		data[i] = chars[rand() % 62];
	data[i] = '\0';

	return (reinterpret_cast<void *>(data));
}

Data *deserialize(void * raw)
{
	struct Data *data = new Data;
	char *str = reinterpret_cast<char *>(raw);
	int i;

	for (i = 0; i < 8; i++)
		data->s1 = data->s1 + str[i];

	data->n = 0;
	for (; i < (int)strlen(str) - 8; i++)
		data->n = data->n *10 + (str[i] -'0');

	for (; i < (int)strlen(str); i++)
		data->s2 = data->s2 + str[i];

	return (data);
}


int main() {

	void *info;
	struct Data *data;
	srand(time(NULL));

	info = serialize();
	std::cout << "Here we have information on heap: " << info << std::endl;
	std::cout << "And it looks like: ";
	std::printf("%s\n", info);
	std::cout << "And now its time to deserialize" << std::endl;

	data = deserialize(info);
	std::cout << "data 1: " << data->s1 << std::endl;
	std::cout << "number: " << data->n << std::endl;
	std::cout << "data 2: " << data->s2 << std::endl;
	std::cout << "That's all folks!" << std::endl;

	return 0;
}