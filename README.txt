glProject
=========

Just a template for future projects.

Dependencies
------------

- git
- OpenGL 1.x/2.x (Mesa)
- GLEW
- GLUT
- clang
- make

Installation
------------

- Prepare the dependencies:

Arch Linux:
pacman -Sy --noconfirm --needed git clang mesa lib32-mesa glu lib32-glu glew lib32-glew freeglut lib32-freeglut

Msys2 (Windows):
pacman -Sy --noconfirm --needed git $MINGW_PACKAGE_PREFIX-mesa $MINGW_PACKAGE_PREFIX-glew $MINGW_PACKAGE_PREFIX-freeglut
Note: Clang32 is not available in Msys2. You might want to
      install clang with $MINGW_PACKAGE_PREFIX-clang and
      use it under MINGW32 prefix.

- Clone the repository:

git clone https://gitlab.com/KanuX/glProject.git
cd glProject/

- Compile and open:

make -j$(nproc)
bin/glproject

Usage
-----

Going around is easy by using:
  W,A,S,D for the movement.
  Space bar for the action.
  ESC to close.

For developers
--------------

Useful flags:
MESA_GL_VERSION_OVERRIDE - Sets a OpenGL version, eg: 2.1.

Sources
-------

This project would not be possible without tutorials and documentation.

Tutorial      - https://www.swiftless.com/opengltuts.html
Documentation - https://docs.gl/gl2/glClear
