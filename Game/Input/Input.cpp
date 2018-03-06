//#include <SFML/Graphics.hpp>
//#include "Tools.hpp"
#include "Input.hpp"


#ifdef __linux__

extern "C"
{
        IModule  *create_lib(Tools &tools)
        {
                return new Input(tools);
        }
}

#else

typedef IModule * lib;

extern "C"
{
    lib __declspec(dllexport) create_lib(Tools &tools) {
        return new Input(tools);
    }
}

#endif


Input::Input(Tools &_tools) : tools(_tools)
{
}



void Input::Exec()
{
	tools.lib->SetInput(tools.getKeys(), tools.getIp(), tools.getPort(), tools.getPortText() == true ? true : false, tools.getStart() == true ? true : false);
}
