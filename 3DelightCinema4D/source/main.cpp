#include "c4d.h"
#include "main.h"

Bool PluginStart()
{
  
	
	if (!RegisterAovGroup())
		return false;
	if (!RegisterMyTreeView())
		return false;
	


	return true;
}

void PluginEnd()
{
	
}

Bool PluginMessage(Int32 id, void *data)
{
	// This example adds a new "Custom Menu" entry to Cinema's menu bar.
	switch (id) {
	case (C4DPL_BUILDMENU):
	{
		BaseContainer* const mainMenu = GetMenuResource("M_EDITOR"_s);
		if (mainMenu == nullptr)
			return false;
		// create a custom menu entry
		BaseContainer menu;
		menu.InsData(MENURESOURCE_SUBTITLE, "3Delight Plugins");
		// adds the command to create a cube to the custom menu
		const String commandString = "PLUGIN_CMD_" + String::IntToString(Ocube);
		menu.InsData(MENURESOURCE_COMMAND, commandString);
		// add new menu entry
		mainMenu->InsData(MENURESOURCE_SUBMENU, menu);
		return true;
		break;
	}


	case C4DPL_INIT_SYS:
	{
		// don't start plugin without resource
		if (!g_resource.Init())
			return false;
		return true;
	}

}
	return false;

}