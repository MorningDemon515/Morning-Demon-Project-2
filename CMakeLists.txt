cmake_minimum_required(VERSION 3.16)

project(mdp2)

function(copy_dll_to_install target dst)
	set(SRC $<TARGET_FILE_DIR:${target}>/${target}.dll)
	set(DST ${CMAKE_SOURCE_DIR}/${dst}.dll)
	add_custom_command(TARGET ${target} POST_BUILD VERBATIM
			COMMAND ${CMAKE_COMMAND} -E echo "Copying ${target} output file \"${SRC}\" to \"${DST}\""
			COMMAND ${CMAKE_COMMAND} -E copy ${SRC} ${DST})
endfunction()

function(copy_exe_to_install target dst)
	set(SRC $<TARGET_FILE_DIR:${target}>/${target}.exe)
	set(DST ${CMAKE_SOURCE_DIR}/${dst}.exe)
	add_custom_command(TARGET ${target} POST_BUILD VERBATIM
			COMMAND ${CMAKE_COMMAND} -E echo "Copying ${target} output file \"${SRC}\" to \"${DST}\""
			COMMAND ${CMAKE_COMMAND} -E copy ${SRC} ${DST})
endfunction()

add_executable(mdp2 WIN32
    Timer.cpp
    Window.cpp 
	Graphics.cpp
	Triangle.cpp
	Scene.cpp
	Shader.cpp
    Main.cpp                     
)

if(MSVC)
    add_compile_options("/utf-8")  
else()
    add_compile_options(-finput-charset=UTF-8 -fexec-charset=UTF-8)  
endif()

target_include_directories(mdp2 PUBLIC
)

target_link_libraries(mdp2 
            winmm
			d3d11
			dxgi
			d3dcompiler
)

copy_exe_to_install(mdp2 mdp2)