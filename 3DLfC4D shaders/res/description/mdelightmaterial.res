CONTAINER Mdelightmaterial
{
	NAME Mdelightmaterial;

	INCLUDE Mpreview;
	INCLUDE Mbase;
	


	GROUP Obaselist
	{
		BOOL SURFACE_PAGE { HIDDEN; PAGE; PARENTMSG GROUP_SURFACE; }
		BOOL DISPLACEMENT_PAGE { HIDDEN; PAGE; PARENTMSG GROUP_DISPLACEMENT; }
	}
	
	GROUP ID_MATERIALPROPERTIES
	{
		COLOR 	MATERIAL_COLOR {}
		
	}
	
	GROUP GROUP_SURFACE
	{
		DEFAULT 1;
		SHADERLINK SURFACE_LINK{}
	}
	
	GROUP GROUP_DISPLACEMENT
	{
		SHADERLINK DISPLACEMENT_LINK{}
		REAL DISPLACEMENT_BOUND{UNIT METER; MIN 0;}
	}


	//INCLUDE Millum;
	INCLUDE Massign;
}
