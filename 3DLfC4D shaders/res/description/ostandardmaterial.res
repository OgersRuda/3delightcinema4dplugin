CONTAINER Ostandardmaterial
{
	NAME Ostandardmaterial;
	INCLUDE Obase;

	GROUP COATING_GROUP
	{
		BOOL COATING_ON {ANIM OFF;}
		
		COLOR COATING_COLOR {}
		LINK COATING_COLOR_SHADER {ANIM OFF;}
		
		COLOR COATING_TRANSMITTANCE {}
		LINK COATING_TRANSMITTANCE_SHADER {ANIM OFF;}
		REAL COATING_THICKNESS {UNIT METER; MINEX; MIN 0.0;}
		
		REAL COATING_ROUGHNESS{UNIT PERCENT; MIN 0; MAX 100; MINSLIDER 0; MAXSLIDER 100; CUSTOMGUI REALSLIDER;}
		LINK COATING_ROUGHNESS_SHADER{ANIM OFF;}
		REAL COATING_FR{UNIT PERCENT; MIN 0; MAX 100; MINSLIDER 0; MAXSLIDER 100; CUSTOMGUI REALSLIDER;}

	}
	GROUP DIFFUSE_GROUP
	{
		DEFAULT 1;
		REAL DIFFUSE_WEIGHT{UNIT PERCENT; MIN 0; MAX 100; MINSLIDER 0; MAXSLIDER 100; CUSTOMGUI REALSLIDER;}
		COLOR DIFFUSE_COLOR {}
		LINK DIFFUSE_COLOR_SHADER {ANIM OFF;}
		REAL DIFFUSE_ROUGHNESS {UNIT PERCENT; MIN 0; MAX 100; MINSLIDER 0; MAXSLIDER 100; CUSTOMGUI REALSLIDER;}
		LINK DIFFUSE_ROUGHNESS_SHADER {ANIM OFF;}


	}
	GROUP SPECULAR_GROUP
	{
		
		REAL SPECULAR_WEIGHT{UNIT PERCENT; MIN 0; MAX 100; MINSLIDER 0; MAXSLIDER 100; CUSTOMGUI REALSLIDER;}
		COLOR SPECULAR_COLOR {}
		LINK SPECULAR_COLOR_SHADER {ANIM OFF;}
		REAL SPECULAR_ROUGHNESS{UNIT PERCENT; MIN 0; MAX 100; MINSLIDER 0; MAXSLIDER 100; CUSTOMGUI REALSLIDER;}
		LINK	SPECULAR_ROUGHNESS_SHADER {ANIM OFF;}
		REAL SPECULAR_FR{UNIT PERCENT; MIN 0; MAX 100; MINSLIDER 0; MAXSLIDER 100; CUSTOMGUI REALSLIDER;}
		REAL SPECULAR_ANISOTROPY{ STEP 0.01; MINSLIDER -4; MAXSLIDER 4; CUSTOMGUI REALSLIDER;}
		LINK SPECULAR_ANISOTROPY_SHADER {ANIM OFF;}
		COLOR SPECULAR_ANISOTROPY_DIRECTION{}
		LINK SPECULAR_ANISOTROPY_DIRECTION_SHADER {ANIM OFF;}
	}

	GROUP EMISSION_GROUP
	{
		BOOL EMISSION_ON {ANIM OFF;}
		REAL EMISSION_WEIGHT{UNIT PERCENT; MIN 0; MINSLIDER 0; MAXSLIDER 100; CUSTOMGUI REALSLIDER;}


		COLOR EMISSION_COLOR {}
		LINK EMISSION_COLOR_SHADER {ANIM OFF;}
		
		COLOR COATING_TRANSMITTANCE {}
		LINK COATING_TRANSMITTANCE_SHADER {ANIM OFF;}
		REAL COATING_THICKNESS {UNIT METER; MINEX; MIN 0.0;}
		
	}

	GROUP REFRACTION_GROUP
	{
		BOOL REFRACTION_ON {ANIM OFF;}
		REAL REFRACTION_WEIGHT{UNIT PERCENT; MIN 0; MAX 100; MINSLIDER 0; MAXSLIDER 100; CUSTOMGUI REALSLIDER;}
		COLOR REFRACTION_COLOR {}
		LINK REFRACTION_COLOR_SHADER {ANIM OFF;}
		REAL REFRACTION_ROUGHNESS{UNIT PERCENT; MIN 0; MAX 100; MINSLIDER 0; MAXSLIDER 100; CUSTOMGUI REALSLIDER;}

		LINK	REFRACTION_ROUGHNESS_SHADER {ANIM OFF;}
		REAL REFRACTION_IOR{MIN 0;}


	}



}
