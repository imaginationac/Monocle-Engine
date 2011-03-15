#ifdef MONOCLE_OPENGL

#include "../TextureAsset.h"
#include "../Debug.h"

#include "glpng\glpng.h"

#ifdef MONOCLE_WINDOWS
	#define WIN32_LEAN_AND_MEAN
	#include <Windows.h>
#endif

#include <gl/GL.h>
#include <gl/GLu.h>

namespace Monocle
{
	TextureAsset::TextureAsset()
		: Asset(AT_TEXTURE)
	{
	}

	void TextureAsset::Load(const char *filename)
	{
		// only load png for now
		pngInfo info;
		glGenTextures(1, &texID);
		glBindTexture(GL_TEXTURE_2D, texID);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

		if (pngLoad(filename, PNG_NOMIPMAP, PNG_ALPHA, &info))
		{
			Debug::Log("Loaded with resounding success:");
			Debug::Log(filename);
			//printf("Size=%i,%i Depth=%i Alpha=%i\n", info.Width, info.Height, info.Depth, info.Alpha);
		}
		else
		{
			Debug::Log("Can't load texture:");
			Debug::Log(filename);
		}
	}

	void TextureAsset::Unload()
	{
	}

	void TextureAsset::Bind()
	{

	}
}

#endif