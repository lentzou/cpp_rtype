#include "Sound.hpp"


#ifdef __linux__

extern "C"
{
        IModule  *create_lib(Tools &tools)
        {
                return new Sound(tools);
        }
}

#else

typedef IModule * lib;

extern "C"
{
    lib __declspec(dllexport) create_lib(Tools &tools) {
        return new Sound(tools);
    }
}

#endif



Sound::Sound(Tools &_tools) : tools(_tools)
{
}


void Sound::Exec()
{
	tools.lib->PlaySound(tools.getSounds());
}
