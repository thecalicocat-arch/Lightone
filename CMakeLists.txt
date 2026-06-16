
# Defines the minimum CMake version needed to read this script.
# If you uses older CMake versions, you need to change this file or update for a newer one.
cmake_minimum_required(VERSION 3.20)

# Initializing the project and the current version.
project(Lightone VERSION 1.0 LANGUAGES CXX)

# We use the modern version of C++20 to compile and run the project.
# If you are using an older version, you must specify it here.
# Important: Older versions may break the project. Be careful.
set(CMAKE_CXX_STANDARD 20)
# A security layer to prevent older compilers from compiling the project in versions older than the one specified above.
set(CMAKE_CXX_STANDARD_REQUIRED ON) 


# --------------------------------------------
# GLFW - Important setup
# --------------------------------------------
# By default, the GLFW repository comes with several test codes. 
# We will disable them using the calls below.
# This helps the compilation process to be much faster and lighter.
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "")

# Adiciona o código-fonte do GLFW ao fluxo de compilação ao CMake
add_subdirectory(libs/glfw)

# We've enabled Vulkan development dependencies to be supplied directly through the SDK installed on the operating system.
# Here, it is mandatory that Vulkan is supported (since initially, the engine will only support Vulkan).
# This method creates VULKAN_INCLUDE_DIRS.
find_package(Vulkan REQUIRED)

# We created a variable that automatically maps all the .cpp files in the project.
# There's no need to manually include files in src.
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Output of the executable file along with its name.
add_executable(app ${SOURCES})

# --------------------------------------------
# Includes
# --------------------------------------------
# Include all project inclusion directories here.
# Any new libraries should be referenced below.
# Tip: If you are experiencing errors in your IDE due to "include not found," consider changing Intellisense to be managed by CMake.
target_include_directories(app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw/include
    ${VULKAN_INCLUDE_DIRS}
)

# --------------------------------------------
# Linker
# --------------------------------------------
# Here, every new library must be linked to the linker.
# Any others will be ignored.
# If you use a library and don't reference it here, a compilation error will occur.
target_link_libraries(app PRIVATE
    glfw
    Vulkan::Vulkan
    opengl32
    gdi32
    user32
    shell32
)