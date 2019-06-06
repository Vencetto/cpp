#ifndef RUSH01_SECONDMODULE_HPP
#define RUSH01_SECONDMODULE_HPP

#include "IMonitorModule.hpp"

class secondModule : public IMonitorModule {

public:
	secondModule();
	virtual ~secondModule();
	secondModule(secondModule const & src);
	secondModule &operator=(secondModule const & src);

    char *getCpu();

private:
    char *_cpu;
};

#endif