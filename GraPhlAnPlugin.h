#ifndef GRAPHLANPLUGIN_H
#define GRAPHLANPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class GraPhlAnPlugin : public Plugin
{
public: 
 std::string toString() {return "GraPhlAn";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::map<std::string, std::string> parameters;
 bool annotateFlag;
};

#endif
