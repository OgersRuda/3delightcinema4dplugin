CONTAINER Olightcard
{
	NAME Olightcard;
	INCLUDE Obase;

	GROUP ID_OBJECTPROPERTIES
	{
		COLOR LIGHTCARD_COLOR	   {}
		REAL LIGHTCARD_INTENSITY	{UNIT PERCENT; MIN 0; 		MINSLIDER 0; MAXSLIDER 100; CUSTOMGUI REALSLIDER;}
		REAL LIGHTCARD_EXPOSURE {MINSLIDER -6.0; MAXSLIDER 6.0; CUSTOMGUI REALSLIDER;}

		FILENAME LIGHTCARD_TEXTURE{}
		FILENAME LIGHTCARD_ALPHA{}
		SEPARATOR { LINE; }
	
		REAL LIGHTCARD_WIDTH	   { UNIT METER; MIN 0.0; }
		REAL LIGHTCARD_HEIGHT	   { UNIT METER; MIN 0.0; }

		

		SEPARATOR { LINE; }

		BOOL LIGHTCARD_SEEN_BY_CAMERA{ ANIM OFF;}

	}
}