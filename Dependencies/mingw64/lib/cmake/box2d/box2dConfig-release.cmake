#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "box2d::box2d" for configuration "Release"
set_property(TARGET box2d::box2d APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(box2d::box2d PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libbox2d.dll.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libbox2d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS box2d::box2d )
list(APPEND _IMPORT_CHECK_FILES_FOR_box2d::box2d "${_IMPORT_PREFIX}/lib/libbox2d.dll.a" "${_IMPORT_PREFIX}/bin/libbox2d.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
