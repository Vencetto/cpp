//
// Created by Volodymyr ZOMBER on 2019-04-13.
//

#ifndef RUSH01_FIRSTMODULE_HPP
#define RUSH01_FIRSTMODULE_HPP

#include "IMonitorModule.hpp"

typedef struct	s_os
{
	char *str1;
	char *str2;
	char *str3;
}				t_os;

class firstModule : public IMonitorModule {

public:
	firstModule();
	virtual ~firstModule();
	firstModule(firstModule const & src);
	firstModule &operator=(firstModule const & src);

	char *getHost();
	t_os *getOs();
	char *getTime();
	char *getRam();
	char *getNet();

private:
	t_os _os;
	char *_hostname;
	char *_time;
	char *_net;
	char *_ram;

};

#endif //RUSH01_FIRSTMODULE_HPP
