list(APPEND SOURCES
     main.cpp
)


include_directories(${SDL2_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS})

add_executable(wowmapeditor ${SOURCES})

target_link_libraries(wowmapeditor
  ${SDL2_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY}
)
