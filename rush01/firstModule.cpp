//
// Created by Volodymyr ZOMBER on 2019-04-13.
//

#include "firstModule.hpp"

firstModule::firstModule() {

	{
		FILE *fp;
		this->_os.str1 = new char[30];
		this->_os.str2 = new char[30];
		this->_os.str3 = new char[30];

		fp = popen("sw_vers", "r");
		if (fp == NULL) {
			printf("Failed to run command\n");
			exit(1);
		}

		fgets(this->_os.str1, 30 - 1, fp);
		fgets(this->_os.str2, 30 - 1, fp);
		fgets(this->_os.str3, 30 - 1, fp);
		pclose(fp);
	}

	{
		FILE *fp;
		this->_hostname = new char[20];
		fp = popen("hostname", "r");
		if (fp == NULL) {
			printf("Failed to run command\n");
			exit(1);
		}
		fgets(this->_hostname, 20 - 1, fp);
		pclose(fp);
	}

	this->_time = new char[30];
	this->_net = new char [60];
	this->_ram = new char [50];

}

firstModule::~firstModule() {
	delete this->_os.str1;
	delete this->_os.str2;
	delete this->_os.str3;
	delete this->_hostname;
	delete this->_time;
	delete this->_ram;
	delete this->_net;
}

firstModule::firstModule(firstModule const &src) {
	*this = src;
}

firstModule& firstModule::operator=(firstModule const &src) {
	(void)src;
	return *this;
}

t_os *firstModule::getOs() {
	return (&this->_os);
}

char *firstModule::getHost() {
	return this->_hostname;
}

char *firstModule::getTime() {
	{
		FILE *fp;
		fp = popen("date \"+ %Y-%m-%d %H:%M:%S\"", "r");
		if (fp == NULL) {
			printf("Failed to run command\n");
			exit(1);
		}
		fgets(this->_time, 30 - 1, fp);
		pclose(fp);
	}
	return this->_time;
}

char *firstModule::getRam() {
	{
		FILE *fp;
		fp = popen("top -l 1 | awk '/PhysMem:/'", "r");
		if (fp == NULL) {
			printf("Failed to run command\n");
			exit(1);
		}
		fgets(this->_ram, 50 - 1, fp);
		pclose(fp);
	}
	return this->_ram;
}

char *firstModule::getNet() {
	{
		FILE *fp;
		fp = popen("top -l 1 | awk '/Networks:/'", "r");
		if (fp == NULL) {
			printf("Failed to run command\n");
			exit(1);
		}
		fgets(this->_net, 60 - 1, fp);
		pclose(fp);
	}
	return this->_net;
}
