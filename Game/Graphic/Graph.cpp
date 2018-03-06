#include "Graph.hpp"

#ifdef __linux__

extern "C"
{
        IModule  *create_lib(Tools &tools)
        {
		
                return new Graph(tools);
        }
}

#else

typedef IModule * lib;

extern "C"
{
    lib __declspec(dllexport) create_lib(Tools &tools) {
        return new Graph(tools);
    }
}

#endif

Graph::Graph(Tools &_tools) : tools(_tools)
{
    tools.init(players, Fires, Enemy);
    current = std::make_shared<StartState>(tools);
    d = 0;
	tools.getKeys() = { false, false, false, false, false, false, false, false };
}

void Graph::SetState(std::shared_ptr<AState> state)
{
	current = state;
}

void Graph::Exec()
{
    if (d > 6.28)
	{
        d = 0.05;
    } else {
        d += 0.05;
    }
	tools.lib->Clear();
//	window->clear();
	tools.lib->StarField();
	if (tools.lib->IsOpen())
	{
		//	if (this->window->isOpen())
			//	{
		current->input(this);
		current->print();
		tools.lib->Display();
		//}
	}
}
