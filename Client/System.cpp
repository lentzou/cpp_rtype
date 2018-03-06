
#ifdef _WIN32

#include <stdio.h>
#include <tchar.h> 
#include <strsafe.h>

#elif __linux__

#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <dlfcn.h>
#include <stdio.h>
#endif

#include <vector>
#include "System.hpp"
#include "IGraph.hpp"

System::System()
{

}

System::~System()
{

}

void System::opendirectory(const std::string &path)
{
	#ifdef _WIN32

	WIN32_FIND_DATA ffd;
	LARGE_INTEGER filesize;
	TCHAR szDir[MAX_PATH];
	size_t length_of_arg;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	DWORD dwError = 0;

	std::cout << "test" << std::endl;
	std::cout << MAX_PATH << std::endl;

	StringCchLength(path.c_str(), MAX_PATH, &length_of_arg);
	StringCchCopy(szDir, MAX_PATH, path.c_str());
	StringCchCat(szDir, MAX_PATH, TEXT("*"));

	hFind = FindFirstFile(szDir, &ffd);
	if (INVALID_HANDLE_VALUE == hFind)
	{
		std::cout << "error" << std::endl;
	}
	do
	{
		if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
		}
		else
		{
			filesize.LowPart = ffd.nFileSizeLow;
			filesize.HighPart = ffd.nFileSizeHigh;
			file.push_back(path + ffd.cFileName);
		}
	} while (FindNextFile(hFind, &ffd) != 0);

	dwError = GetLastError();
	if (dwError != ERROR_NO_MORE_FILES)
	{
		std::cerr << "error no more files" << std::endl;
	}

	FindClose(hFind);

	#elif __linux__

	DIR *dir;
	struct dirent *result;

	if ((!(dir = opendir(path.c_str()))))
	{
		std::cerr << "cant open directory " << path.c_str() << std::endl;
		exit (1);
	}
	while ((result = readdir(dir)))
	{
		file.push_back(path + "/" + result->d_name);
	}
	
	
	#endif
}


template<typename T, typename ... Args>
void System::loadLib(const std::string &path, Args& ... args)
{
	T (*create)(Args&...);

	#ifdef _WIN32

	HINSTANCE hGetProcIDDLL = LoadLibrary(path.c_str());
	if (hGetProcIDDLL != NULL)
		create = reinterpret_cast<T (*)(Args&...)>(GetProcAddress(hGetProcIDDLL, "create_lib"));
	else
	{
		std::cout << "LoadLibrary fail with" << path << std::endl;
		return ;
	}

	#elif __linux__

	void *mem;
	if (!(mem = dlopen(path.c_str(), RTLD_LAZY)))
	{
		fprintf(stderr, "dlopen failed: %s\n", dlerror());
		return ;
	}

	if ((!(create = reinterpret_cast<T (*)(Args&...)>(dlsym(mem, "create_lib")))))
	{
		std::cerr << "missing symbol on " << path << std::endl;
		return ;
	}

	#endif
	Tools &tools = Tools::Instance();
	T lib = create(args...);
	if (typeid(T) == typeid(IGraph *))
	{
		if (!(tools.lib = reinterpret_cast<IGraph*>(lib)))
			exit (EXIT_FAILURE);
	}
	else
		_module.push_back(reinterpret_cast<IModule*>(lib));
}


	
	

void System::init()
{
	
#ifdef _WIN32
	opendirectory("..\\Lib\\DLL\\Graphic\\Windows\\Debug\\");

	for (auto it : file)
		{
			if (it.substr(it.rfind(".")) == ".dll")
			{
				std::cout << it.c_str() << std::endl;
				loadLib<IGraph *>(it);

			}
		}
	file.clear();
	opendirectory("..\\Lib\\DLL\\Game\\Windows\\Debug\\");
	
		for (auto it : file)
		{
			if (it.substr(it.rfind(".")) == ".dll")
			{
				std::cout << it.c_str() << std::endl;
				loadLib<IModule *>(it, Tools::Instance());

			}
		}
	
#elif __linux__
		opendirectory("../Lib/DLL/Graphic/Linux/Debug");
		for (auto it : file)
		{
			if (it.substr(it.rfind(".")) == ".so")
			{
				std::cout << it.c_str() << std::endl;
				loadLib<IGraph *>(it);
			}
		}
		file.clear();
		
		
		opendirectory("../Lib/DLL/Game/Linux/Debug");
	
		for (auto it : file)
		{
			if (it.substr(it.rfind(".")) == ".so")
			{
				std::cout << it.c_str() << std::endl;
				loadLib<IModule *>(it, Tools::Instance());
			}
		}

#endif

}


void System::Execute()
{
	if (_module.size() == 0)
		return ;
	while (true) {
		for (auto it : _module) {
			it->Exec();
		}
	}	
}
