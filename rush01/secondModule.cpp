#include "secondModule.hpp"

secondModule::secondModule() {
    this->_cpu = new char[20];
	memset(this->_cpu, 0, 20);
}

secondModule::~secondModule() {
    delete this->_cpu;
}

secondModule::secondModule(secondModule const &src) {
	*this = src;
}

secondModule& secondModule::operator=(secondModule const &src) {
	(void)src;
	return *this;
}

char *secondModule::getCpu() {
	
	{
		FILE *fp;

		std::string command = "top -l 1| awk '/CPU us/'";
		
		fp = popen(command.c_str(), "r");
		if (fp == NULL) {
			printf("Failed to run command\n");
			exit(1);
		}

		fgets(this->_cpu, 20, fp);
		pclose(fp);
	}

    return this->_cpu;
}