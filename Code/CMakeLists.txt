file(GLOB CORE_SRCS *.cpp)
file(GLOB COLLIDERS_SRCS Colliders/*.cpp)
file(GLOB GRAPHICS_SRCS Graphics/*.cpp)
file(GLOB LEVELEDITOR_SRCS LevelEditor/*.cpp)
file(GLOB OGMOSIS_SRCS Ogmosis/*.cpp)
file(GLOB XML_SRCS XML/*.cpp)

set(CORE_SRCS ${CORE_SRCS}
	${COLLIDERS_SRCS}
	${GRAPHICS_SRCS}
	${LEVELEDITOR_SRCS}
	${OGMOSIS_SRCS}
)

if(WINDOWS)
	file(GLOB WINDOWS_SRCS Windows/*.cpp)
	set(PLATFORM_SRCS ${PLATFORM_SRCS} ${WINDOWS_SRCS})
endif(WINDOWS)

if(LINUX)
	include_directories(${X11_INCLUDE_DIR})
	set(CORE_LINK ${CORE_LINK} ${X11_LIBRARIES})
	file(GLOB LINUX_SRCS Linux/*.cpp)
	set(PLATFORM_SRCS ${PLATFORM_SRCS} ${LINUX_SRCS})
endif(LINUX)

if(WITH_OPENGL)
	include_directories(${OPENGL_INCLUDE_DIR})
	file(GLOB OPENGL_SRCS
		OpenGL/*.cpp
		OpenGL/glpng/*.c
		OpenGL/glpng/*/*.c
	)
	set(CORE_LINK ${CORE_LINK} ${OPENGL_LIBRARIES})
	set(CORE_SRCS ${CORE_SRCS} ${OPENGL_SRCS})
endif(WITH_OPENGL)

if(WITH_OPENAL)
	include_directories(${OPENAL_INCLUDE_DIR})
	file(GLOB OPENAL_SRCS OpenAL/*.cpp)
	set(CORE_LINK ${CORE_LINK} ${OPENAL_LIBRARY})
	set(CORE_SRCS ${CORE_SRCS} ${OPENAL_SRCS})
endif(WITH_OPENAL)

add_library(MonocleCore
	${CORE_SRCS}
	${PLATFORM_SRCS}
)
add_library(TinyXML ${XML_SRCS})

target_link_libraries(MonocleCore TinyXML ${CORE_LINK})

if(BUILD_TESTS)
	add_subdirectory(Tests)
endif(BUILD_TESTS)
