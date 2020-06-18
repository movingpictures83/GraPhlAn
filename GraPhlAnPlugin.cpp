#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "GraPhlAnPlugin.h"

void GraPhlAnPlugin::input(std::string file) {
 inputfile = file;
 annotateFlag = false;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   if (key == "annotations")
         annotateFlag = true;
   std::cout << key << std::endl;
   ifile >> value;
parameters[key] = value;
 }
}

void GraPhlAnPlugin::run() {
   
}

void GraPhlAnPlugin::output(std::string file) {
   //std::string command = "export OLDPATH=${PYTHONPATH}; export PYTHONPATH=${PYTHON2_DIST_PACKAGES}:${PYTHON2_SITE_PACKAGES}:${PYTHONPATH}; "
   // This is a Python2 application, but does not need these to be set (checked TMC)
   std::string command = "";
   if (annotateFlag) {
      command += "graphlan_annotate.py "+parameters["tree"]+" "+file+".annot.xml"+" --annot "+parameters["annotations"]+"; ";
      command += "graphlan.py "+file+".annot.xml"+" "+file+".png"+" --dpi "+parameters["dpi"]+" --size "+parameters["size"];
   }
   else {
      command += "graphlan.py "+parameters["tree"]+" "+file+".png"+" --dpi "+parameters["dpi"]+" --size "+parameters["size"];
   }
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<GraPhlAnPlugin> GraPhlAnPluginProxy = PluginProxy<GraPhlAnPlugin>("GraPhlAn", PluginManager::getInstance());
