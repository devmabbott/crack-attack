/*
 * TextureLoader.h
 * Daniel Nelson - 8/24/0
 *
 * Copyright (C) 2000  Daniel Nelson
 * Copyright (C) 2004  Andrew Sayman
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * Daniel Nelson - aluminumangel.org
 * 174 W. 18th Ave.
 * Columbus, OH  43210
 */

#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include <GL/glut.h>

#include "glext.h"
#include <sstream>

#include "Game.h"
#include "MetaState.h"

#include <cstdlib>
#include <cstring>

#define TL_GARBAGE_TEXTURE_TGA_ID     "Crack Attack! garbage texture"
#define TL_SCREEN_SHOT_TGA_ID         "Crack Attack! screen shot"

/* static */ class TextureLoader {
public:
  static GLubyte *loadImageAlpha ( const std::string &file_name, int _height,
      int _width );
  static GLubyte *loadImageNoAlpha ( const std::string &file_name, int _height,
      int _width );
  static GLubyte *loadImage ( const std::string &file_name, int _height, int _width);
  static void createTGA ( const std::string &tga_file_name, GLubyte *texture,
      int _height, int _width, const std::string &tga_id );
  static bool fileExists ( const std::string &file_name );
  static unsigned long determineImageCheckSum ( const std::string &tga_file_name,
      int _height, int _width );
  static void determineImageSize ( const std::string &tga_file_name, int &height,
      int &width );

  static inline void buildLocalDataDirectoryName ( std::string &dir_name )
  {
    std::ostringstream s;
#ifndef _WIN32
    s << getenv("HOME") << GC_LOCAL_DATA_DIRECTORY;
#else
    s << GC_LOCAL_DATA_DIRECTORY;
#endif
    dir_name = s.str();
  }

  static inline void buildLocalDataFileName ( const std::string &base_name,
   std::string &file_name )
  {
    std::ostringstream s;
#ifndef _WIN32
    s << getenv("HOME") << GC_LOCAL_DATA_DIRECTORY << base_name;
#else
    s << GC_LOCAL_DATA_DIRECTORY << base_name;
#endif
    file_name = s.str();
  }

  static inline std::string buildCubeImageFileName ( std::string file_name )
  {
    if (file_name.rfind("/") == file_name.length())
      return MetaState::cube_tileset_dir + file_name;
    else
      return MetaState::cube_tileset_dir + "/" + file_name;
  }
};

#endif
